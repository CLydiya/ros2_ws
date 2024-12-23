#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
import can
import subprocess
import signal
import time

def run_subprocess(cmd):
    """Executes a command in the subprocess and returns the result."""
    return subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

class CanDriver(Node, can.Listener):
    def __init__(self):
        Node.__init__(self, 'can_driver_node')
        self.error_timer = time.perf_counter()
        
        self.setup_can_interface()
        self.shutdown_requested = False
        
        # Set up signal handlers
        signal.signal(signal.SIGINT, self.signal_handler)
        signal.signal(signal.SIGTERM, self.signal_handler)

    def setup_can_interface(self):
        self.canMsgData = [0, 0, 0, 0, 0, 0, 0, 0]

        try:
            """Checks and sets up the CAN interface."""
            result = run_subprocess(["ip", "link", "show", "can0"])
            if b"state UP" in result.stdout:
                self.get_logger().info("CAN interface is already up")
            else:
                result = run_subprocess(["sudo", "ip", "link", "set", "can0", "up", "type", "can", "bitrate", "1000000"])
                if result.returncode == 0:
                    self.get_logger().info("CAN interface is up")
                else:
                    self.get_logger().info("CAN failed to setup")

            self.bus = can.interface.Bus(bustype='socketcan', channel='can0', bitrate=1000000)
            self.notifier = can.Notifier(self.bus, [self])
        except:
            result = run_subprocess(["sudo", "ip", "link", "set", "can0", "down"])
            
            if hasattr(self, 'bus'):
                try:
                    self.bus.shutdown()
                except Exception as e:
                    print(f"Error shutting down bus: {e}")
                finally:
                    delattr(self, 'bus')

            if hasattr(self, 'notifier'):
                try:
                    self.notifier.stop()
                except Exception as e:
                    print(f"Error stopping notifier: {e}")
                finally:
                    delattr(self, 'notifier')

            time.sleep(1)
            self.setup_can_interface()

    def on_message_received(self, msg):
        print(msg.arbitration_id, msg.data)

    def on_error(self,  exc):
        if time.perf_counter() - self.error_timer > 1.0:
            self.setup_can_interface()
            self.error_timer = time.perf_counter()

    def signal_handler(self, signum, frame):
        """Handle shutdown signals gracefully."""
        self.get_logger().info(f"Received signal {signum}. Initiating shutdown...")
        self.shutdown_requested = True

    def shutdown(self):
        """Shuts down the CAN interface and other resources gracefully."""
        if self.shutdown_requested:
            return
        
        self.get_logger().info("Shutdown requested. Cleaning up...")
        self.shutdown_requested = True

        # Stop all ongoing operations
        self.notifier.stop()
        
        # Close the CAN bus
        self.bus.shutdown()
        
        # Shutdown the can0 interface
        result = run_subprocess(["sudo", "ip", "link", "set", "can0", "down"])
        if result.returncode == 0:
            self.get_logger().info("CAN interface successfully shut down.")
        else:
            self.get_logger().error("Failed to shut down CAN interface.")
        
        # Destroy the node.
        self.destroy_node()
        self.get_logger().info("Node destroyed. Shutdown complete.")

def main(args=None):
    rclpy.init(args=args)
    can_driver_node = CanDriver()
    try:
        while rclpy.ok() and not can_driver_node.shutdown_requested:
            rclpy.spin_once(can_driver_node, timeout_sec=0.1)
    except KeyboardInterrupt:
        can_driver_node.shutdown()
    finally:
        rclpy.shutdown()

if __name__ == '__main__':
    main()
