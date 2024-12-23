#!/usr/bin/python3 env 
import rclpy
from rclpy.node import Node
import rclpy.parameter 

class parameters(Node):
    def __init__(self): 
        super().__init__('parameters')
        self.declare_parameter('p1', 'p2')
        self.timer = self.create_timer(1, self.timer_callback)

    def timer_callback(self):
        param = self.get_parameter('p1').get_parameter_value().string_value
        self.get_logger().infor('Hello, %s!' %param)
        new_param = rclpy.parameter.Parameter('new_p', rclpy.Parameter.Type.STRING, 'world')
        all_new_param = [new_param]
        self.set_parameters(all_new_param)\
        
def main():
    rclpy.inti()
    node = parameters()
    rclpy.spin(node)

if __name__ == '__main__':
    main()