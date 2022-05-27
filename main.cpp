/**************************************************************************************
 *                      Program to Manage Player Records
 *  This project is a console application that you can use to manage 
 *  a player list. It starts by reading player records from a text file called 
 *  "players.txt" in the same location, if it doesn't find it, it starts with an
 *  empty player list. Then it shows a menu of the options you can choose. 
 *  You can add players to the list, compare two player records and delete or edit 
 *  a record. On exiting the program, it writes the current players to the 
 *  "players.txt" file, so you have them available next time you load the application.
 *
 *                            Author: Marissa Campa
 *                        E-mail: marissag.campa@gmail.com
****************************************************************************************/
#include "Player.h"
#include "Manager.h"
#include <iostream>
#include <cstring>

int main() 
{
    char mainSel[BUFFER_SIZE];
    // Create an object of the manager class
    // that will act as interface 
    Manager mn;

    // On launch, read existing player records from file
    mn.readPlayersFromFile();
    
    do {
        mn.showMainMenu();
        std::cout << "[USER] Select an option: ";

        // Prompts the user to select an option, and compares the selection
        //  with the available options. If the selection is empty, numeric or 
        //  different, then it shows an invalid messages and prompts again
        if (mn.getTextFromUser(mainSel)) 
        {
            if (strcmp(mainSel, "a") == 0 || strcmp(mainSel, "A") == 0) 
            {
                // Display all players
                mn.printPlayersTable();
            } 
            else if (strcmp(mainSel, "b") == 0 || strcmp(mainSel, "B") == 0) 
            {
                // Prompt user to add a new player
                mn.promptToAddNewPlayer();
            } 
            else if (strcmp(mainSel, "c") == 0 || strcmp(mainSel, "C") == 0) 
            {
                // Prompt user to compare two player records
                mn.promptToCompareTwoPlayerRecords();
            } 
            else if (strcmp(mainSel, "d") == 0 || strcmp(mainSel, "D") == 0) 
            {
                // Prompt user to delete a player record
                int index = mn.promptToDeletePlayerRecord();
                mn.deletePlayerRecord(index);
            } 
            else if (strcmp(mainSel, "e") == 0 || strcmp(mainSel, "E") == 0) 
            {
                // Prompt user to edit a player record
                int index = mn.promptToEditPlayerRecord();
                mn.editPlayerRecord(index);
            } 
            else if (strcmp(mainSel, "x") == 0 || strcmp(mainSel, "X") == 0) 
            {
                // On exit, write player records to file
                mn.writePlayersToFile();
                break;
            }
            else 
            {
                // Show invalid message
                mn.showMessage(messages::ERROR, "Invalid");
            }
        }
        else 
        {
            // Show invalid message
            mn.showMessage(messages::ERROR, "Invalid");
        }
    } 
    while (strcmp(mainSel, "x") != 0 && strcmp(mainSel, "X") != 0);
    
    // Free memory allocated by the players vector
    mn.freePlayersFromMemory();
    std::cout << std::endl;
    return 0;
}

