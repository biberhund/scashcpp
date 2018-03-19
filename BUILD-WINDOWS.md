WINDOWS BUILD NOTES
====================

Some notes on how to build Scash for Windows.

These steps can be performed on, for example, an Ubuntu VM. The depends system
will also work on other Linux distributions, however the commands for
installing the toolchain will be different.

First install the toolchains:

    sudo apt-get install g++-mingw-w64-i686 mingw-w64-i686-dev g++-mingw-w64-x86-64 mingw-w64-x86-64-dev

Install curl that is required for depends scripts:

    sudo apt-get install curl

To build executables for Windows 64-bit:

    cd buildsystem
    
This step can take up to 30-40 minutes:

    make --file=Depends.mk HOST=x86_64-w64-mingw32 -j4
    
Then run the following command:

    ./autogen.sh
    
Some warnings may be produced, but this is normal.

This also can take long time:

    ./configure --prefix=`pwd`/x86_64-w64-mingw32
    
And finally run build process itself:

    make

====================

There is also possible to build project manually on target system (Win 10). 
Tested configuration is VS2015 + Qt5.10.0 + OpenSSL 1.0.1u + boost 1.60.0 + libbdb-4.8.30


