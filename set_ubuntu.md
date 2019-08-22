# How to set ubuntu firstly

## Preconsition

Ubuntu version: 18.04 LTS English edition

## Change apt source to aliyun

* create a backup file in case mess it up: `sudo cp /etc/apt/sources.list /ect/apt/sources.list.bak`
* edit _sources.list_, `sudo gedit \etc\apt\sources.list`
* use `lsb_release -c` command to get the **system code**, for 18_04, which is **bionic**
* add followed lines to sources.list, **beware that the system code need adapting Ubuntu version**

> deb http://mirrors.aliyun.com/ubuntu/ **bionic** main restricted universe multiverse
> deb-src http://mirrors.aliyun.com/ubuntu/ **bionic** main restricted universe multiverse
> deb http://mirrors.aliyun.com/ubuntu/ **bionic**-security main restricted universe multiverse
> deb-src http://mirrors.aliyun.com/ubuntu/ **bionic**-security main restricted universe multiverse
> deb http://mirrors.aliyun.com/ubuntu/ **bionic**-updates main restricted universe multiverse
> deb-src http://mirrors.aliyun.com/ubuntu/ **bionic**-updates main restricted universe multiverse
> deb http://mirrors.aliyun.com/ubuntu/ **bionic**-backports main restricted universe multiverse
> deb-src http://mirrors.aliyun.com/ubuntu/ **bionic**-backports main restricted universe multiverse
> deb http://mirrors.aliyun.com/ubuntu/ **bionic**-proposed main restricted universe multiverse
> deb-src http://mirrors.aliyun.com/ubuntu/ **bionic**-proposed main restricted universe multiverse
> 
* now refresh the apt source using `sudo apt update `
* if you want to upgrade your packages have already been installed on your computer, use `sudo apt upgrade`

## Other useful apt-get commands

* sudo apt-get update: update sources
* sudo apt-get install _package_: install the package
* sudo apt-get remove _package_: remove the package from OS
* sudo apt-cache search _package_: search package
* sudo apt-cache show _package_: show packages information such as description, size and version
* sudo apt-get install _package_ --reinstall: reinstall package
* sudo apt-get -f install _package_: repairing install package 
* sudo apt-get remove _package_ --purge: remove package, including configuration files
* sudo apt-get build-dep _package_: install compiling environment related to the package
* sudo apt-get upgrade: upgrade installed package
* sudo apt-get dist-upgrade: upgrade system
* sudo apt-cache depends _package_: get the package's dependencies information
* sudo apt-cache rdepends _package_: get the packages which depend this _package_ 
* sudo apt-get source _package_: get the package sources
* sudo apt-get clean && sudo apt-get autoclean: cleaning useless package
* sudo apt-get check: check if exists broken packages

## Other useful sources

### USTC

> deb https://mirrors.ustc.edu.cn/ubuntu/ bionic main restricted universe multiverse
> deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
> deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
> deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
> deb https://mirrors.ustc.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
> deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic main restricted universe multiverse
> deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
> deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
> deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
> deb-src https://mirrors.ustc.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse

### Tsinghua

> deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
> deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
> deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
> deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
> deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
> deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic main restricted universe multiverse
> deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-updates main restricted universe multiverse
> deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-backports main restricted universe multiverse
> deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-security main restricted universe multiverse
> deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ bionic-proposed main restricted universe multiverse
