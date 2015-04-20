W3 Patch Downloader
===================

*Author: metamaker*

This is helper utility intended to download file archive from the Internet and unpack the contents in specified folder.

Building the utility
--------------------

You need CMake (<http://www.cmake.org/>) to build this library. Example of how to build the utility is for
Visual Studio's nmake but you can use pretty same steps sequence for any other generator. Building steps are
next:

1. Open command line and change current directory with **cd** command to the directory where you unpacked the utility's source code.
2. Create new empty directory **build** and change your working directory to it by running **mkdir build**, **cd build**.
3. Run **cmake -G "NMake Makefiles" ..** to create Makefile.
4. Run **nmake** to build the utility.
5. Optionally you can run **nmake install** to install the utility to default installation directory.

Source code dependencies
------------------------

To compile the utility you need following libraries to be installed on your system:
- **lasote/curl**: <https://www.biicode.com/lasote/curl>

You can use biicode to easily install these dependencies on project's folder.

Binary file depends on 7z. On Windows you need to add 7z.exe to PATH variable or drop this executable to folder with compiled binaries.
On Linux you need to install 7z package.

How to use this utility
-----------------------

Use this utility from command line. Syntax is next:

w3-patch-downloader just-download \<http-address\> \<output-file-path\>

w3-patch-downloader download-and-unzip \<http-address\> [output-directory]


**Usage example:**
w3-patch-downloader just-download http://site.hi/my-file.txt my-file.txt

Available actions:
- **just-download**: download file from *"http-address"* and put it to *"output-directory"*
- **download-and-unzip**: download .zip archive from *"http-address"* and unzip it to *"output-directory"*
    
License agreement
-----------------

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License version 3 as published
by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>
 
Release history
---------------

20.04.2015:
- Initial release
