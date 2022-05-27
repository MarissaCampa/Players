# Program to manage player records #

## Description ##

This project is a console application that you can use to manage a player list. It starts by reading player records from a text file called "players.txt" in the same location, if it doesn't find it, it starts with an empty player list. Then it shows a menu of the options you can choose. You can add players to the list, compare two player records and delete or edit a record.
On exiting the program, it writes the current players to the "players.txt" file, so you have them available next time you load the application.

This project was developed in C++, and I'm using CMake to compile an executable.
<img align="right" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
<img align="right" src="https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white"/>

https://user-images.githubusercontent.com/3021010/170606338-4203c1bd-b2f4-41c7-a707-ad0b08de39bb.mp4


## Features ##

The application shows the Program Menu:
<ul>
  <li> a) Display all players</li>
  <li> b) Add a player</li>
  <li> c) Compare two player records</li>
  <li> d) Delete a player record</li>
  <li> e) Edit a player record</li>
  <li> x) Exit</li>
</ul>


## Files & Directories ##

<section>
  <ul>
    <li><b>players</b> - Main application dicrectory</li>
    <ul>
      <li><b>main.cpp</b> - Main applicaton file</li>
      <li><b>Player.h</b> - Player class header</li>
      <li><b>Player.cpp</b> - Player class implementation</li>
      <li><b>Manager.h</b> - Manager class header</li>
      <li><b>Manager.cpp</b> - Manager class implementation</li>
    </ul>
  </ul>
</section>


## Installation ##

Please refer to the following section for instructions on how to configure and run this project on ![image](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)

<details>
  <summary><h3>Configure and compile a CMake project</h3></summary>
  
  <p>This is a CMake project that compiles C++ files and creates an application executable. </p>

  <h4>CMake configuration</h4>
  <p>You can clone this repository into a local folder in your computer.</p>
  
  <h4> Generate configuration files</h4>
  <p>In a terminal, change to the project directory where the CMakeLists.txt file is, and create a new directory called 'build'.</p>
  
  ```bash
  > mkdir build
  ```
  
  <p>Then use the following command to generate the necessary files for your compiler to build the application.</p>
  
  ```bash
  > cmake -S . -B build -G "MinGW Makefiles"
  ```
  
  <p>Where -S is the source directory, where a point specifies current directory, -B is the output build directory, and -G is the CMake Generator to use. You can choose the generator you would like. </p>

  <h4>Compile the project</h4>
  <p>Move to the "build" directory and use the "make" command to create the application executable:</p>
  
  ```bash
  > cd build
  > make
  ```

  <p>To run the program:</p>
    
  ```bash
  > main.exe
  ```
</details>

## Usage


### About Me ###
My name is Marissa Campa, I'm a mechatronics engineer with a master of science in automation.

My e-mail is 📧 (marissag.campa@gmail.com) and my [LinkedIn Profile](https://www.linkedin.com/in/marissa-campa/)
