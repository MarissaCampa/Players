#include "Player.h"
#include "Manager.h"
#include <iostream>
#include <cstring>

const int BUFFER_SIZE = 50;

int main() {
    char *mainSel = new char[1];
    Manager mn;
    mn.readPlayersFromFile();
    
    do {
        mn.showMainMenu();
        std::cout << "[USER] Select an option: ";
        std::cin.clear();
        std::cin.sync();
        std::cin.get(mainSel, BUFFER_SIZE);
        
        if (strcmp(mainSel, "a") == 0 || strcmp(mainSel, "A") == 0) 
        {
            mn.printPlayersTable();
        } 
        else if (strcmp(mainSel, "b") == 0 || strcmp(mainSel, "B") == 0) 
        {
            mn.promptToAddNewPlayer();
        } 
        else if (strcmp(mainSel, "c") == 0 || strcmp(mainSel, "C") == 0) 
        {
            mn.promptToCompareTwoPlayerRecords();
        } 
        else if (strcmp(mainSel, "d") == 0 || strcmp(mainSel, "D") == 0) 
        {
            int index = mn.promptToDeletePlayerRecord();
            mn.deletePlayerRecord(index);
        } 
        else if (strcmp(mainSel, "e") == 0 || strcmp(mainSel, "E") == 0) 
        {
            int index = mn.promptToEditPlayerRecord();
            mn.editPlayerRecord(index);
        } 
        else if (strcmp(mainSel, "x") == 0 || strcmp(mainSel, "X") == 0) 
        {
            mn.writePlayersToFile();
            break;
        }
        else {
            mn.showMessage(messages::ERROR, "Invalid");
        }
    } 
    while (strcmp(mainSel, "x") != 0 && strcmp(mainSel, "X") != 0);
    
    delete [] mainSel;
    mn.freePlayersFromMemory();
    std::cout << std::endl;
    return 0;
}

