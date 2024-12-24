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

## ROS2 Concept  

### Configuring Environment
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

## Learning resources
* Ubuntu Information: https://help.ubuntu.com/community/Installation/SystemRequirements
* how to dual boot: https://gcore.com/learning/dual-boot-ubuntu-windows-setup/
* how to dual boot: https://www.linuxtechi.com/dual-boot-ubuntu-22-04-and-windows-11/
* how to dual boot: https://www.onlogic.com/blog/how-to-dual-boot-windows-11-and-linux/
* Linux basic: https://www.linux.com/what-is-linux/
* ROS@ humble documentation: https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html
* VS Code installation: https://code.visualstudio.com/docs/setup/linux
