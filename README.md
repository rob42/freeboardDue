freeboardDue
============

freeboardPLC port to the Arduino Due board.

To install:
===========

* Download the Arduino IDE Arduino 1.5.7 ( http://arduino.cc/en/Main/Software#toc3 )
* Download http://www.baeyens.it/eclipse/download/product/linux64.2014-07-12_02-06-35.tar.gz - (you will need the one for your environment)
* Unpack and install the Arduino IDE
* Unpack and install the Eclipse IDE for baeyens
* Configure eclipse to use the Arduino IDE (Windows>Preferences>Arduino)

(Clone this project, and make a local repository on your PC.)

In Eclipse use the git integration to extract a new project:
* File>Import>Project from Git>etc
* Open, clean and build your new project

Notes:
======

This is a first cut, not all the functionality is ported yet, and its untested. Outstanding items are configuation (no EEPROM in Due, so it always boots to defaults), and no SoftwareSerial, so no NMEASerial object - (this is the NMEA talker port). Other NMEA prots should work ok.

Ive commited my .settings and .cproject files, so your project should be fully set up. But the .settings may cause your project to look for my dir structure, which will probably cause problems. In this case you will need to check the following:

* In Project>Properties>Arduino set the boards.txt file, and select the Due processor.
* In Project>Properties>C++ Comiler>Settings>Include folders:
  "${workspace_loc:/freeboardDue/arduino/core}"
  "${workspace_loc:/freeboardDue/arduino/variant}"
  "${workspace_loc:/${ProjName}/lib/DueTimer}"
  "${workspace_loc:/${ProjName}/lib/Kangaroo}"
  "${workspace_loc:/freeboardDue/Libraries/SPI}"
  "${workspace_loc:/${ProjName}/lib/MultiSerial}"
  "${workspace_loc:/${ProjName}/lib/JsonStream}"
  "${workspace_loc:/${ProjName}/lib/NMEA}"
  "${workspace_loc:/${ProjName}/lib/PString}"
  "${workspace_loc:/${ProjName}/lib/AverageList}"
  "${workspace_loc:/${ProjName}/lib/PID_v1}"

***check they really are there!

* In Project>Properties>C Compiler>Settings>Include folders:
  "${workspace_loc:/freeboardDue/arduino/core}"
  "${workspace_loc:/freeboardDue/arduino/variant}"
  "${workspace_loc:/freeboardDue/Libraries/SPI}"

***Look in your /freeboardDue/Libraries/, make sure SPI is actually there!