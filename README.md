# ros2_ws
ROS2 (Robotic Operating System 2) is a set of software development tools and libraries for building robot applications. 

## Prerequisite 
Before you go on to installing ROS2, you should be operating on linux; windows is fine, but there are a lot of issues, so my suggestion is operating it on linux like Ubuntu. For this, I will be using ROS2 humble and Ubuntu Linux - Jammy (22.04) dual boot on my laptop.

## System requirements
* Internet access 
* Operating System: Ubuntu Linux - Jammy (22.04) 64-bit

## How to dual boot 

### Prerequisite 
* A USB at least 25GB

### What is Ubuntu? 
Ubuntu is an open source Linux distribution based on Debain Linux. Linux is an operating system that consists of: 
* Bootloader: manages the boot process of the computer.
* Kernel: the core of the system that manages CPU, memory, and peripheral devices.
* Init system: a subsystem that bootstraps the user space and is charged with controlling daemons.
* Daemons: background services that startup during boot or after you logged into desktop.
* Graphical server: displays the graphics on your monitor.
* Desktop environment: the piece that the user interact with; it includes built-in applications.
* Applications

A distribution is  version of the operating system. Ubuntu is one of the linux distribution. 

### Dual booting guide 

#### Change BIOS setting

* First, restart your computer, while it’s restarting click the key F2 or F10 or F12 (based on computer model, for my laptop, I used F2).
* Find “Boot Mode”, “Boot Options”, or “Boot configuration”.
* Set the “Boot Mode” to “UEFI”
* Save the setting and exit.

#### Disk partitioning 

* Open Disk Management, then select the partition that you wanna shrink to boot Ubuntu
* Right click on that partition, then select “Shrink Volume”
* Follow the instruction on your screen, once, it’s done, the partition should be labeled “Unallocated”

#### Boot Ubuntu into USB 

* Insert USB into your laptop.
* Go to Ubuntu website (https://releases.ubuntu.com/jammy/), then install the iso file (“ubuntu-22.04.5-desktop-amd64.iso”)
* Go to Rufus website (https://rufus.ie/en/), then download and install the software.
* Once the installation is done, open it.
* Under the label “Device” click on the drop down menu, select your USB device.
* Under the label “Boot selection” select the ubuntu iso file you just downloaded.
* Under the label “Partition scheme” select “GPT”, then click “START”, you will be asked to select the mode you wanna use, select “Write in ISO image mode”, then click “OK”
* Once it’s done close the software.

#### Installing Ubuntu 

* First, hold the shift key, then restart your computer.
* Select “Use a device”, then select your USB drive, and then click Enter key to boot into Ubuntu.
* Select “Install Ubuntu”, then follow the instruction on the screen. Choose “something else” when you got asked about the partition.
* Select the partition you made for booting Ubuntu, then click “Change .>.”, next ti the label “Use as:” select “Ext4”, then click “OK”
* Click “Install now”, then follow the instruction on the screen. Once the installation is done, click “Restart Now”, then you can remove your USB, then click Enter.

## ROS2 Installation guide

### System requirements 

* Operating system: Ubuntu 22.04 (since we will be installing ROS2 humble)
* CPU: 64-bit, multi-core processor
* RAM: 4GB RAM or higher, 8GB RAM recommended
* Disk space: 20 GB or more
* Dependencies: Python 3.10 and C++ 14 or later

### Set locales 
Your locales must support UTF-8 
    
``` bash
    locale  # check for UTF-8
    sudo apt update && sudo apt install locales
    sudo locale-gen en_US en_US.UTF-8
    sudo update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
    export LANG=en_US.UTF-8

    locale  # verify settings
```

### Setup source 
* Ensure that Ubuntu universe repository is enabled

``` bash
    sudo apt install software-properties-common
    sudo add-apt-repository universe
```

* Add ROS2 GPG key

``` bash
    sudo apt update && sudo apt install curl -y
    sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg
```

* Add the repository to your sources list. 

``` bash
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(. /etc/os-release && echo $UBUNTU_CODENAME) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
```
### Install ROS2 packages 
* Update your apt caches after setup the repository

``` bash
    sudo apt update 
```

* Ensure that ur system is up to date

``` bash 
    sudo apt upgrade 
```

* Install ROS2

``` bash
    sudo apt install ros-humble-desktop
    sudo apt install ros-humble-ros-base
    sudo apt install ros-dev-tools
```

### Environment setup 
Source the setup script 

``` bash
    source /opt/ros/humble/setup.bash
```
## VS Code Installation Guide 

Ubuntu isn't an IDE (Integrated Development Environment). We need VS Code to write, compile, and run code, so for now, after installing Ubuntu and ROS2 successfully, I will cover VS Code Installation for Ubuntu (deb package). 

* Installing the deb package

``` bash
    sudo apt install ./<file>.deb 
```

* Installing deb package will prompt to install apt repository and signing for automatically update.

``` bash
    echo "code code/add-microsoft-repo boolean true" | sudo debconf-set-selections
```

* update and install the apt repository key

``` bash
    sudo install apt-transport-https
    sudo apt update
    sudo apt install code
```

To open the VS Code, run this command:

``` bash
    ./code
```

## SSH (optional)

When it comes to coding and controlling robots, we may need remote development extensions, so I will be shwoing how to use SSH.
* Open VS Code
* Install the extension "Remote SSH" in VS Code
* Open your terminal, search for the ip address of the port you need to connect to
Run this command:

``` bash
    ip a
```

The IP address will be shown next to "inet" in the terminal. Another way to do it, if you know the number, for exmple 192.xxx.xx.xx, then you can use this command:

``` bash
    nmap -sn 192.xxx.xx.0/24

    #before you can use nmap, you need to install it
    #to install it, run these command
    sudo apt install nmap 
```
* Now, open the command pallete on VS Code, then type "Remote-SSH: connect to host"
* Type in the IP address and hostname, "username(host)@192.xxx.xx.xx". If this is the first time, you will be asked to open config file, so accept the prompt. You will be asked to input password, type in the password, then click Enter.
* Once, connected, you can open the folder and run the code in the folder.

## Configuring Environment
When developing ROS2, you will be using combination of workspaces. The term workspace refers to the location in your system that you use top develop ROS2. But with before you develop or runnign any code, you need to configure the environement first, otherwise, you won't be able to use ROS2. Now, we will learn to setup the environment. 

#### Source the setup files 
Note that each time you open new terminal, you need to source the setup files with this command: 

``` bash
    source /opt/ros/humble/setup.bash
```

#### Add sourcing to your startup shell 

```  bash
    echo "source /opt/ros/humble/seyup.bash" >> ~/.bashrc
```

#### Check environment variables 

``` bash
    printenv | grep -i ROS
```
This command will return your ROS distro (distribution) and version; it should be something like this: 

``` bash
    ROS_VERSION=2
    ROS_PYTHON_VERSION=3
    ROS_DISTRO=humble
```

If it is not set correctly, you need to the installarion again. 

* ROS_DOMAIN_ID: when you have determined a unique integer of your group of ROS2 nodes, you can set the environment varible.

``` bash
    export ROS_DOMAIN_ID=<your domain id>
    echo "export ROS_DOMAIN_ID=<your domain id>" >> ~/.bashrc #add it to your startup script
```

* ROS_LOCALHOST_ONLY: since ROS2 communication is not limited to local host, it may disrupt your communicaation in your robots, to ensure efficient communication, you can setup the "ROS_LOCALHOST_ONLY" environment with this command:

``` bash
    export ROS_LOCALHOST_ONLY=1
    echo "export ROS_LOCALHOST_ONLY=1" >> ~/.bashrc
```
## Creating ROS2 workspace

### What is a workspace? 
In ROS2, workspace is where your store your packages to development robotic applications and organize them. To build a workspace, follow this instruction:

### Source ROS2 environment 
``` bash
    source /opt/ros/humble/setup.bash
```

### Create a new directory
you have to create a directory to store everything for workspace. 
``` bash
    mkdir -p ~/ros2_ws/src #ros2_ws is the dorectory name
    cd ~/ros2_ws 
```

### build the workspace 
use "colcon build" to build your workspace 
``` bash
    colcon build
```

### Source the workspace 
``` bash
    source install/setup.bash
```

To make it is sourced automatically for every terminal: 
``` bash
    echo "source install/setuo.bash" >> ~/.bashrc
    source ~/.bashrc
```

### Verify your workspace 
Now, cehck if the workspace is built correctly
``` bash
    ls
```

## Creating ROS2 package 

### What is ROS2 package? 
Package is where you store and organize your code, log, build files to develop the software. You can release the package nad allow people to use and build upon it. 

### Structure of ROS2 package
ROS2 package can be built using python or C++. For this, I will focus on building python package. 

Each package in ROS2 consist of: 
* package.xml: containing meta information of the package
* resource/<package name>: marker file for the package
* setup.cfg: when you have install, it is required for ROS2 to be able to run it
* setup.py: containing instructions how to install the package 
* <package name>: used by ROS2 to find your package; it contains "__init__.py"

When you build package, you store it in the "src" directory in your workspace, so that your workspace looks clean.

### How to build ROS2 package 
#### Create a package 
* Open your workspace
``` bash
    cd ~/ros2_ws/src
```

Note that you also need to source your workspace before doing this. If you have run this command before, it's alright as it is automatically sourced alredy. 
``` bash
    echo "source install/setuo.bash" >> ~/.bashrc
    source ~/.bashrc
``` 
* Create a package
``` bash
    ros2 pkg create <package name> --build-type ament_python --license Apache-2.0 --dependencies rclpy
    #if C++ package use "ament_cmake
    #dependencies and license can be added manually (later), but if you add it here, it's easier
```

#### Build the package 
After you writing code and make necessary changes in the package, you can build the packge using "colcon build". To correctly building the package: 

#### Return to root of the workspace 
``` bash
    cd ~/ros2_ws
```

#### Building the package 
``` bash
    colcon build
```

### Using the package 

#### Source the package 
``` bash
    source install/setup.bash
```

#### Run the package 
``` bash
    ros2 run <pacakge name> <executable name>
    #usually, <executable name> is the name the code file
```

## Writing publisher and subscriber node 




    

## Learning resources
* Ubuntu Information: https://help.ubuntu.com/community/Installation/SystemRequirements
* Basic Ubuntu commands: https://github.com/rashakil-ds/Shell-Programming-in-Linux/blob/main/Linux%20Ubuntu%20Commands.pdf
* how to dual boot: https://gcore.com/learning/dual-boot-ubuntu-windows-setup/
* how to dual boot: https://www.linuxtechi.com/dual-boot-ubuntu-22-04-and-windows-11/
* how to dual boot: https://www.onlogic.com/blog/how-to-dual-boot-windows-11-and-linux/
* Linux basic: https://www.linux.com/what-is-linux/
* ROS2 humble documentation: https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html
* ROS2 cheat sheet (basic commands): https://www.theconstruct.ai/wp-content/uploads/2021/10/ROS2-Command-Cheat-Sheets-updated.pdf
* VS Code installation: https://code.visualstudio.com/docs/setup/linux
* Building ROS2 workspace: https://automaticaddison.com/how-to-create-a-ros-2-workspace-iron/
