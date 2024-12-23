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

*Add the repository to your sources list. 

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
