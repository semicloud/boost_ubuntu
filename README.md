# How to compile and run Boost on Ubuntu
This article is used to give a guide to install Boost package on Ubuntu and run it. The article has three parts, namely, 1) install Boost package; 2) set running environment and 3) run it, let's begin.

**Caution!!!**: Before begin, you must install `gcc` and `g++`，`make` tool on your system.

## install Boost
As we all know, Boost is almost the standard library of C++. In this part, we will install Boost on a clean *Ubuntu* system.

Follows are the steps:

1. download boost via the offical site: 
> sudo wget https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.zip

2. unzip the library to `/usr`
> sudo unzip boost_1_71_0.zip -d /usr

after this step, the boost library will released at `\usr\boost_1_7_0` folder

3. compling 
the compling procedure has two parts, first run `bootstrap.sh` and second `b2`
> sudo .\bootstrap gcc
> sudo .\b2 --build-type=complete --toolset=gcc **--layout**=tagged

**Beware**, if you like to compile Boost with *complete* library, you must set is `--layout` argument  **tagged** or **system**, `--layout` is the naming mechaism used by Boost to name different library type, such as 32 bit or 64 bit, single or mutiple threading, and so on.

If you compile boost successfully, you will see a message on console:
> The Boost C++ Libraries were successfully built!

Next, install headers and compiled library to the system.

4. install
> sudo .\b2 install

By default, boost will install the headers to `\usr\local\includes` and library to `\usr\local\lib`. You will find headers and librarys at those folders.

So, the installation of boost is success. Before we use it daily, we test it first. As you knwon, C++ has two linking manner: static and dynamic, we will test it respectively.

## Use boost as dynamic library

g++ version: 7.4.0

First, let's see the test code, which is use boost library: log, filesystem and thread.

``` c++
#include <boost/log/trivial.hpp>
#include <boost/filesystem.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <iostream>

boost::mutex m;

void say_bye();

void say_bye()
{
    boost::lock_guard<boost::mutex> guard(m);
    std::cout << "Bye. (in thread " << boost::this_thread::get_id() << ")" << std::endl;
}

int main(int argc, char **argv)
{
    boost::filesystem::path p("\\usr\\local");
    if (boost::filesystem::is_directory(p))
    {
        BOOST_LOG_TRIVIAL(debug) << p << " is a directory";
    }
    else
    {
        BOOST_LOG_TRIVIAL(debug) << p << " is not a directory";
    }
    BOOST_LOG_TRIVIAL(info) << "Bye.";
    boost::thread t(say_bye);
    t.join();

    return 0;
}
```


Firstly, we compile it and secondly we link the .o file with the library. So, the `dynamic.mk` should seems like follows:

```make
code.out: code.o
	g++ code.o -lboost_log -lboost_filesystem -lboost_thread -pthread -o code.out

code.o: code.cc
	g++ -std=c++0x -Wall -DBOOST_ALL_DYN_LINK -I/usr/local/include -c code.cc

```

**Beware**: when you want to use boost as **dynamic** manner, you must add `-DBOOST_ALL_DYN_LINK` preprocess argument to the compile command. And for boost.log, there is another preprocessor called `
BOOST_LOG_DYN_LINK` to indicate that the linking manner of boost.log.

`-pthread` is used as we using boost::thread.

Ok, make file is ready, let's execute it:
> sudo make -f dynamic.mk

Emmm, oh ha, it is seems like we gotta a problem:

```
./code.out: error while loading shared libraries: libboost_log.so.1.71.0: cannot open shared object file: No such file or directory
```

The error message is obvious, the executable can not find the boost library that we compiled before. The solution for this problem is simple, too. We need to configure our `LD_LIBRARY_PATH` to the system. I prefer to edit configuration files to **permanetly** update the link setting. 

> echo '/usr/local/lib' | sudo tee /etc/ld.so.conf.d/mylib.conf > /dev/null

Above command will create `mylib.conf` file under `/etc/ld.so.conf.d/`, `/dev/null` implies that we do not need the output to console. `tee` is a command, and it has an argument called `--append`, this argument will append the text to existed file instead of create a new file.

Then, we update ldconfig:

> sudo ldconfig

That's it. Now you run `sudo ./code.out` and you can get the output normally.

*further_reading*:  [How to set LD_LIBRARY_PATH in Ubuntu](https://stackoverflow.com/questions/13428910/how-to-set-the-environmental-variable-ld-library-path-in-linux)

## Use boost as static library

Use boost as static library is as seem as dynamic library, simply add a `-static` argument to linking command. Beware that some boost library can not be used as static library, such as boost.log under a multi-threading environment.

```make
code.out: code.o
        g++ code.o -static -pthread -lboost_log -lboost_filesystem -lboost_thread -o code.out

code.o: code.cc
        g++ -Wall -std=c++0x -c code.cc
```

There are two points worth to mention:
* there is no `-DBOOST_ALL_DYN_LINK` in the compiling command;
* there is a `-static` argument in linking command; :-)

Ok. that is it.
