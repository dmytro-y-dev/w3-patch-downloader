W3 Patch Downloader
===================

*Author: metamaker*

This is helper utility intended to download file archive from the Internet and unpack the contents in specified folder.

Building the utility
--------------------

You should use bii (<http://www.biicode.com>) to build this project. Building commands are next:

1. **cd** to project's folder.
2. Run **bii init -L**
3. Run **bii find**
4. Run **bii cpp:configure**. You can specify your CMake generator with -G flag like **bii cpp:configure -G "Visual Studio 12"**
5. Run **bii cpp:build** to build application.

Another possible option is CMake (<http://www.cmake.org/>). Building steps are next:

1. Open command line and change current directory with **cd** command to the directory where you unpacked the utility's source code.
2. Run **cmake -H. -Bbuild -G "Visual Studio 12"** to create Makefile for Visual Studio 2013 (or use other generator if you use other IDE). Don't forget to specify path to **curl** library with -D parameter.
3. Open **build/w3-patch-downloader.sln** and build project in Visual Studio.

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
