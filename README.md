toomuch-tray
============

Another Pomodoro Technique Tray App

# Compiling

## Libraries

* Lib cURL 4

sudo apt-get install libcurl4-gnutls-dev

* Boost 1.56

Project looks for $HOME/lib/boost.
Install, compile and create a symbolic link to boost root directory.

My environment looks like this:
```
$ ls -l ~/lib/boost
lrwxrwxrwx 1 cassiano cassiano 13 Ago 22 21:33 /home/cassiano/lib/boost -> boost_1_56_0/
```

## Compiling Using Qt Creator

* Open project (toomuch-tray.pro)

* Click **Compile** button

## Compiling Using Command Line

qmake toomuch-tray.pro -r -spec linux-g++-64

make in ../build-toomuch-tray-Desktop-Release

# I don't want to compile it!!!

Ok! Try out a [compiled binary](https://github.com/cassianoalves/toomuch-tray/blob/master/release/toomuch-tray?raw=true).
Compiled on a Mint Linux 17 (x64).
