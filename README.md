# 512hash
Creates SHA-512 hash from the given password

Comes as two tools - command line and GUI.

1) Command line just takes a plaintext password as a parameter and throws out the hash.

2) GUI allows user to generate random password or multiple runs.
Password can be copied form clipboard, hash can be copied to.

Zipped distribution files have been provided for Windows and macOS.
There is little sense using this on Linux ;)

# Requirements

## macOS

GUI version comes as self contained bundle.
Console version comes with the framework required, all zipped in a folder.

## Windows

Both version are x64. Zip files contain all the libraries needed to run.

# Installation and running

## macOS

No installation required.

GUI version might require you to head over to System preferences -> Security and privacy ->
General and click "allow" at the bottom. The code is not signed so it is likely that 
Gatekeepr will complain and consequently require you to do this.

Console version is just unpack and run (the framework file included in the zip is required).

## Windows

Both versions are portable with all the libraries needed in the folders. Unpack, enter the folder
and run.

# LEGAL

In general this comes with LGPL ver. 3.0 licence for my part. Please see LICENCE file.
I used Qt to write this, all Qt libraries that are distributed come with same LGPL 3.0 licence.
Please see Qt-LICENCE file.

ON WINDOWS additonaly I had to use MSYS2 libraries, those come with BSD 3-Clause "New" or "Revised" License
Please see MSYS2-LICENCE file.

# BUT I WANT TO BUILD IT

Sure, no problem. You will need Qt framework, that can be obtained from https://qt.io/

## macOS

No additional requirements.

## Windows

Since I need to rely on glibc crypt(3) the choice was mingw32-64. This environment can be downloaded from
https://www.msys2.org - from whole thing you just need libcrypt package (in msys2 run pacman -S libcrypt and
pacman -S libcrypt-devel). You'll need to adjust paths in the headers and .pro files to point out where the crypt.h file is.

