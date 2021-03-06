# 512hash
Creates SHA-512 hash from the given password

Comes as two tools - command line and GUI.

1) Command line just takes a plaintext password as a parameter and throws out the hash.
Available switches are:
$ 512hash [-v] [--version]
$ 512hash [-h] [--help]

2) GUI allows user to generate random password or multiple runs.
Password can be copied form clipboard, hash can be copied to.

Zipped distribution files have been provided for Windows and macOS.
There is little sense using this on Linux ;)

# Requirements

## macOS

GUI version comes as self contained bundle.
Console version comes with the framework and OSSL crypto library required, all zipped in
a folder.

## Windows

Both version are x64. Zip files contain all the libraries needed to run.

# Installation and running

No installation required.

## macOS

GUI version might require you to head over to System preferences -> Security and privacy ->
General and click "allow" at the bottom. The code is not signed so it is likely that 
Gatekeepr will complain and consequently require you to do this.

Console version is just unpack and run (the framework and crypto librariy files included in
the zip are required).

## Windows

Both versions are portable with all the libraries needed in the folders. Unpack, enter the folder
and run.

# LEGAL

In general this comes with LGPL ver. 3.0 licence for my part. Please see LICENCE file.
I used Qt to write this, all Qt libraries that are distributed come with same LGPL 3.0 licence.
Please see Qt-LICENCE file.

Any version uses OpenSSL crypto library. It comes under dual licence, please see OSSL-LICENSE.

# BUT I WANT TO BUILD IT

Sure, no problem. You will need Qt framework, that can be obtained from https://qt.io/

## macOS

No additional requirements.

## Windows

Since I need to rely on OpenSSL which I needed to build the choice was mingw32-64. This library source
can be downloaded from https://www.opnessl.org - from whole thing you just need libcrypto library.
You'll need to adjust paths in the headers and .pro files to point out where the OSSL includes are.

# CONTACT

Please raise the issue on GitHub: https://github.com/artwaw/512hash/issues

