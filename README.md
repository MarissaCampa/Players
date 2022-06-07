# Program to Manage Player Records #
<img align="right" src="https://img.shields.io/badge/CMake-064F8C?style=for-the-badge&logo=cmake&logoColor=white"/>
<img align="right" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>

## 🗒️ Summary ##

This project is a C++ application that you can use to manage a player list. It starts by reading player records from a text file called "players.txt" in the same location, if it doesn't find it, it starts with an empty player list. Then it shows a menu of the options you can choose from. You can add players to the list, compare two player records and delete or edit a record.
On exiting the program, it writes the current players to the "players.txt" file, so you have them available next time you load the application.

This project was developed in C++, and I'm using CMake to compile an executable.

https://user-images.githubusercontent.com/3021010/170606338-4203c1bd-b2f4-41c7-a707-ad0b08de39bb.mp4


## ⭐ Project Features ##

The application shows the Program Menu:

a) Display all players 
 * Shows a table with all the player records

b) Add a player
 * Prompts the user to enter a new player's name and life points

c) Compare two player records 
 * Prompts the user to enter two record indexes to compare. It shows that the two records are the same only if they have the same name and life points. It shows [Invalid] if the input is not numeric or if it's out of the list range.

d) Delete a player record 
 * Prompts the user to enter a record index to delete it from the list. It shows [Invalid] if the input is not numeric or if it's out of the list range.

e) Edit a player record 
 * Prompts the user to enter a record index to edit it from the list. It shows [Invalid] if the input is not numeric or if it's out of the list range. After that it prompts the user to choose which field to edit, the name or the life points.

x) Exit
 * Ends the program, writing the player's list to the "players.txt" file.


## 📝 Details  ##

### Main ###
The main program shows the Main Menu, manages the user selection and validates the input. It makes sure that the input is a character and that is a valid option. If is not a valid option, it shows a message [Invalid], and shows the Main Menu again. The main program instanciates an object of the Manager class to call methods to perform adding, deleting or editing a player records, and display all records. It also calls the Manager class methods to read and write the player's list to the "players.txt" file, on the start and end of the program.

### Manager Class ### 
The Manager class has a vector of pointers to the Player class, named 'players'. It the following methods to:
- Show main menu
- Get number or text from user
- Index validation
- Prompt the user to add new player, compare two records, delete or edit a player record
- Read and write player's vector to the "players.txt" file
- Print a table with all player records

### Player Class ### 
The player class has name and life points as member variables. It contains:
* Empty, Two-arg Constructor, Copy Constructor and Move Constructor. When a player objects get's initialized, the constuctor allocates memory on the heap for the member variable name, which is of type char*. 
* Getter functions for its member variables.
* Setter functions for its member variables. Also modifiers to increase or decrease the life points.
* Overloaded copy and move assignment operators.
* Overloaded substraction operator. 
* Global friend functions: 
  * Display function with a const reference to a Player object as parameters. It utilizes the overloaded stream insertion operator to display the player's name and life points.
  * Overloaded stream insertion and extraction operators.
  * Overloaded unary minus operator. Which modifies the player name to all lower case.
  * Overloaded equality operator. It returns true of two Player objects have the same name and life points.


## 🗂️ Files & Directories ##

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


## 💽 Compile and run the project

Please refer to the following section for instructions on how to configure and run this project on ![image](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)

<details>
  <summary><h3> &nbsp; Configure and compile a CMake project</h3></summary>
  
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


## 👋 About Me
My name is Marissa Campa, I'm a Mechatronics Engineer with a Master of Science in Automation.

You can reach me on &nbsp; [![Linkedin Badge](https://img.shields.io/badge/-marissa-blue?style=flat&logo=Linkedin&logoColor=white)](https://www.linkedin.com/in/marissa-campa/) &nbsp; or &nbsp; [![Gmail Badge](https://img.shields.io/badge/-marissag.campa@gmail.com-c14438?style=flat-square&logo=Gmail&logoColor=white&link=mailto:marissag.campa@gmail.com)](mailto:marissag.campa@gmail.com)

  
