# Installing the Pandora Framework

This tutorial will explain how to install Pandora framework.



## Requirements

You will need a PC with GNU/Linux installed. The tutorial will explain how to
install Pandora on Ubuntu (release 14.04, Trusty Tahr), but any other distribution
would work (probably with additional effort related to looking for the correct
packages and versions).

### Installing Dependencies
First of all, open a console terminal (like Konsole or xterm) and upgrade your system to the last updates:

```
$ sudo apt-get update
$ sudo apt-get upgrate
```

Once it is done, this is the full list of external dependencies of Pandora, that
need to be installed:

 - XML support
  - `libtinyxml-dev`

 - Cassandra GUI
  - `libdevil-dev`
  - `freeglut3-dev`
  - `libqwt-dev`
  - `libqwt6`, **Ubuntu 16.04**: not needed anymore
  - `libqt4-dev`

 - HDF5 **Ubuntu 16.04**
  - `libhdf5-mpi-dev`, HDF5 *parallel*
  - `libhdf5-dev`, HDF5 *serial*

 - GIS support
  - `libgdal1-dev`

 - MPI support
  - `mpich2`, **Ubuntu 16.04**: libmpich-dev

 - Building Tools
  - `scons`
  - `python`

You can install all of them with this command:
```
sudo apt install libtinyxml-dev libdevil-dev freeglut3-dev libqwt-dev libqwt6 libqt4-dev libqt4-opengl-dev libgdal1-dev mpich2 scons build-essential libboost-random-dev
 libboost-python-dev libboost-filesystem-dev libboost-system-dev libmpich2-dev python3 python3-dev libboost-test-dev libboost-timer-dev libboost-chrono-dev
```

**Ubuntu 16.04**: As usual, the names of some packages have changed, the
handy copy & paste command updated to work with the new Ubuntu is
```
sudo apt install libtinyxml-dev libdevil-dev freeglut3-dev libqwt-dev libqt4-dev libqt4-opengl-dev libgdal1-dev libmpich-dev scons build-essential libboost-random-dev  libboost-python-dev libboost-filesystem-dev libboost-system-dev python3 python3-dev libboost-test-dev libboost-timer-dev libboost-chrono-dev
```

Python 3.x is used by default, but if you want to use python 2.7 this is also
possible (just change the packages `python3` and `python3-dev` for `python2.7`
and `python2.7-dev`).

To make sure that the operating system finds the needed libraries, add library
directories that are not standard to LD_LIBRARY_PATH external variable. It can
be done adding this line to the end of the file `.bashrc` inside your `$HOME`
directory.

```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/hdf5/lib/
```

### Compiling HDF5 (Only for Ubuntu 15.x and older)


Ubuntu dependencies forces you to install the serial version of HDF5 as gdaldependency. For this reason, we will need to download, compile and install hdf5.

First we need to go to the `HDF5` webpage and download the sources:
```
		$ cd ~/
		$ mkdir hdf5
		$ cd hdf5
		$ wget "http://www.hdfgroup.org/ftp/HDF5/current/src/hdf5-1.8.17.tar.bz2"
```

we decompress the file:
```
		$ tar jxvf hdf5-1.8.17.tar.bz2
```
configure the library:
```
		$ cd hdf5-1.8.17
		$ ./configure --enable-parallel --prefix=/usr/local/hdf5 --disable-shared --with-pic
```
if you are curious about other possible configuration options, check the documentation by typing
```
./configure --help
```
Now we're ready to compile and install:
```
		$ make
		$ sudo make install
```

### Compiling Pandora

Go to the folder where Pandora is deployed:
```
		$ cd PATHTOPANDORA/pandora/
```
Compile it:
```
		$ scons
```
note that
 - if you want to compile in debug mode type: ```$ scons debug=1```
 - if you want to use python2.7 type: ```$ scons python2```
you can check the full list of options with: ```$ scons -h```.

### Installing Pandora

Go to the folder where Pandora is deployed:
```
		$ cd PATHTOPANDORA/pandora/
```
execute (requires you to enter the root password):
```
        $ sudo scons install
```
By default Pandora will be installed in `/usr/local/pandora`. If you want to use a different directory use the
option `installDir=$PATH`, for instance:
```
        $ sudo scons install installDir=/opt/
```
You will need to add Pandora directory to your .bashrc, using these lines:
```
        export PANDORAPATH=/usr/local/pandora
        export PATH=$PATH:$PANDORAPATH/bin/
        export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PANDORAPATH/lib/
```
Please change `PANDORAPATH` if you used a different installation directory.

#### Test with an example

Go to any example or app and compile it:
```
		$ cd examples/randomWalkers/
		$ scons
```
Once the compiler finishes, just execute it:
```
		$ ./randomWalkers
```

### Compiling cassandra

Go to the folder where Pandora is deployed:
```
$ cd PATHTOPANDORA/pandora/
```
then execute:
```
        $ scons cassandra
```
once it is finished, hopefully without any error, you can run it with the
following command:
```
		$ ./bin/cassandra
```
Finally, check whether the results of randomWalkers (they should be inside a ``'data'`` directory) are loaded correctly in cassandra.
