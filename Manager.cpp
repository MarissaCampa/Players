#include "Manager.h"
#include "Player.h"
#include <vector>
#include <limits>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

/*******************************************************
    FUNCTION IMPLEMENTATIONS FOR THE MANAGER CLASS
*******************************************************/

/**
 * Shows the main menu and options.
 */
void Manager::showMainMenu() {
    std::cout 
        << '\n' 
        << char(218) << std::string(40, char(196)) << char(191) << '\n'
        << std::left
        << char(179) << std::setw(40) << " Program to manage player records" << char(179) << '\n'
        << char(195) << std::string(40, char(196)) << char(180) << '\n'
        << char(179) << std::setw(40) << " a) Display all players" << char(179) << '\n'
        << char(179) << std::setw(40) << " b) Add a player" << char(179) << '\n'
        << char(179) << std::setw(40) << " c) Compare two player records" << char(179) << '\n'
        << char(179) << std::setw(40) << " d) Delete a player record" << char(179) << '\n'
        << char(179) << std::setw(40) << " e) Edit a player record" << char(179) << '\n'
        << char(179) << std::setw(40) << " x) Exit" << char(179) << '\n'
        << char(192) << std::string(40, char(196)) << char(217) << '\n'; 
}


/**
 * Prompts the user for a numeric input and returns
 * the number only if is a digit and is not empty, 
 * if not it returns -1.
 *
 * @return {int} number inputted by the user
 */
int Manager::getNumberFromUser() {
    char buffer[BUFFER_SIZE];
    std::cin.clear();
    std::cin.sync();
    std::cin.get(buffer, BUFFER_SIZE);
    if (!isBufferADigit(buffer) || strlen(buffer) == 0)
        return -1;
    return atoi(buffer);    
}


/**
 * Prompts the user for a text input and updates
 * the char array pointed to by the input
 *
 * @param {char *} buffer Text variable to update
 * @return {bool} Returns true only if the text entered
 *          by the user is not a digit and is not empty
 */
bool Manager::getTextFromUser(char *buffer) {
    char text[BUFFER_SIZE];
    std::cin.clear();
    std::cin.sync();
    std::cin.get(text, BUFFER_SIZE);
    if (isBufferADigit(text) || strlen(text) == 0)
        return false;
    strcpy(buffer, text);
    return true;
}


/**
 * Verifies that two indexes are within range
 * of the players vector
 *
 * @param {int} index1 First index to verify
 * @param {int} index2 Second index to verify
 * @return {bool} Returns true only if the params are within range
 */
bool Manager::areIndexesWithinRange(int index1, int index2) {
    return  index1 >= 0 && index1 < players.size() && 
            index2 >= 0 && index2 < players.size() && index1 != index2;
}


/**
 * Verifies that an index is within range
 * of the players vector
 * @param {int} index Index to verify
 * @return {bool} Returns true only if index is within range
 */
bool Manager::isIndexWithinRange(int index) {
    return  index >= 0 && index < players.size();
}


/**
 * Prompts the user for the name, and the life points 
 * of the new player, and it updates the players vector
 * with a new player object pointer
 */
void Manager::promptToAddNewPlayer() {
    if (players.size() < MAX_NUM_PLAYERS) {
        char buffer[BUFFER_SIZE];
        int points{-1};
        std::cout << "\n[USER] Enter the player's name: ";
        if (!getTextFromUser(buffer)) {
            showMessage(messages::ERROR, "Invalid");
            return;
        }
        std::cout << "[USER] Enter the player's life points: ";
        points = getNumberFromUser();
        if (points < 0) {
            showMessage(messages::ERROR, "Invalid");
            return;                        
        }
        players.push_back(new Player(buffer, points)); 
        showMessage(messages::INFO, "Player added sucessfully");
    }
    else {
        showMessage(messages::INFO, 
            "Maximum number of players reached, delete a player to add a new one");
    }
}


/**
 * Prompts the user for two player record numbers
 * and displays if they are have the same name and
 * life points, or if they are different.
 */
void Manager::promptToCompareTwoPlayerRecords() {
    if (players.size() >= 2) {
        int index1{0}, index2{0};
        while (true) {
            std::cout << "\n[USER] Enter the first index (1-" << players.size() << "): ";
            index1 = getNumberFromUser();
            if (!isIndexWithinRange(index1 - 1)) {
                showMessage(messages::ERROR, "Invalid");
                return;
            }
            std::cout << "[USER] Enter the second index (1-" << players.size() << "): ";
            index2 = getNumberFromUser();
            if (!isIndexWithinRange(index2 - 1)) {
                showMessage(messages::ERROR, "Invalid");
                return;
            }

            if ( index1 != index2 ){
                std::cout << "[INFO] Records at index: " << index1 << ", " << index2 << " are ";
                if (*(players[index1 - 1]) == *(players[index2 - 1])) 
                    std::cout << "the same" << std::endl;
                else 
                    std::cout << "diferent" << std::endl;
                return;
            }
            else {
                showMessage(messages::ERROR, "Invalid");
                return;
            }
        }
    } else {
        std::cout << "[INFO] Not enough players to compare" << std::endl;
    }
}


/**
 * Prompts the user for a player record number to delete
 * @return {int} Returns an index selected by the user
 */
int Manager::promptToDeletePlayerRecord() {
    if (players.empty()) return -1;
    if (players.size() == 1)
        std::cout << "[USER] Enter 1 to confirm delete only record: ";
    else 
        std::cout << "[USER] Enter an index between " << 1 << " and " << players.size() << ": ";
    return getNumberFromUser() - 1;
}


/**
 * Prompts the user for a player record number to edit
 * @return {int} Returns an index selected by the user
 */
int Manager::promptToEditPlayerRecord() {
    if (players.empty()) return -1;
    if (players.size() == 1)
        std::cout << "[USER] Enter 1 to confirm edit only record: ";
    else 
        std::cout << "[USER] Enter an index between " << 1 << " and " << players.size() << ": ";
    return getNumberFromUser() - 1;
}


/**
 * Returns true if the input text is a digit
 *
 * @param {char *} buffer Text variable to verify
 * @return {bool} Returns true if the text is a digit
 */
bool Manager::isBufferADigit(const char* buffer) {
    for (int i = 0; i < strlen(buffer); i++) {
        if (!isdigit(buffer[i]))
            return false;
    }    
    return true;
}


/**
 * Reads a player list from the text file "players.txt"
 * generates a new player object for each row and adds its 
 * object pointer to the players vector
 */
void Manager::readPlayersFromFile() {
    std::ifstream myFile(FILE_NAME, std::ios::in);
    if (myFile.is_open()) {
        std::string line;
        char buff[50];
        int points{0};
        while (std::getline(myFile, line)) {
            std::istringstream ss(line);
            ss.getline(buff, 50, ',');
            ss >> points;
            players.push_back(new Player(buff, points));
        }
        myFile.close();
    } else {
        showMessage(messages::ERROR, "Could not open file");
    }
}


/**
 * Writes to the text file "players.txt", a row for each
 * player object name and life points in the players vector
 *     playerName, lifePoints
 */
void Manager::writePlayersToFile() {
    std::ofstream myFile;
    myFile.open(FILE_NAME, std::ios::out);
    if (myFile.is_open()) {
        for (const auto &player : players) {
            myFile << player->getName() << ',';
            myFile << player->getLifePoints() << '\n';
        }
        myFile.close();
    } else {
        showMessage(messages::ERROR, "Could not open file");
    }
}


/**
 * Returns true if it succeded in deleting a player record
 * It verifies that the parameter index is within the players vector 
 * range, and deletes the player object from it
 * @param {int} index Index of the record to delete
 * @return {bool} Returns true if it was deleted successfully
 */
bool Manager::deletePlayerRecord(int index) {
    if (!isIndexWithinRange(index)) {
        showMessage(messages::ERROR, "Invalid");
        return false;
    }
    players.erase(players.begin() + index);
    showMessage(messages::INFO, "Deleted sucessfully");
    return true;
}


/**
 * Returns true of it a player record has been edited successfuly.
 * It verifies that the parameter index is within the players vector
 * range, and prompts the user to edit either the name field
 * or the life points field
 * @param {int} index Index of the record to edit
 * @return {bool} Returns true if it was edited successfully
 */
bool Manager::editPlayerRecord(int index) {
    if (!isIndexWithinRange(index)) {
        showMessage(messages::ERROR, "Invalid");
        return false;
    }
    std::cout   << "\n[INFO] Editing player: " << players[index]->getName() 
                << " with life points " << players[index]->getLifePoints() << '\n'
                << "\nFields to edit:\n (a) Name\n (b) Life Points\n"
                << "[USER] Enter an option (a or b): ";
    char buffer[BUFFER_SIZE];
    std::cin.clear();
    std::cin.sync();
    std::cin.get(buffer, BUFFER_SIZE);

    if (strcmp(buffer, "a") == 0) 
    {
        char buffer[BUFFER_SIZE];
        std::cout << "\n[USER] Enter new name: ";
        if (!getTextFromUser(buffer)) {
            showMessage(messages::ERROR, "Invalid");
            return false;
        }
        players[index]->setName(buffer);
    }
    else if (strcmp(buffer, "b") == 0) 
    {
        std::cout << "\n[USER] Enter new life points: ";
        int points = getNumberFromUser();
        if (points < 0) {
            showMessage(messages::ERROR, "Invalid");
            return false;                        
        }
        players[index]->setLifePoints(points);
    }
    else 
    {
        showMessage(messages::ERROR, "Invalid");
        return false;
    }
    showMessage(messages::INFO, "Edited successfully");
    return true;
}


/**
 * Prints a table with all the records in the players vector
 * with three columns, the first column is the 1-indexed record number,
 * the second column is the player name, and the third column is the 
 * player life points.
 */
void Manager::printPlayersTable() {
    if (!players.empty()) {
        showMessage(messages::INFO, "Showing all players: ", true);
        printPlayersTableTitle();
        int size = players.size();
        for (int i = 0; i < players.size(); i++) {
            printPlayersTableMembers(players[i], i + 1);    
            if (i < size - 1)
                printPlayersTableFooter(table::middle);
            else 
                printPlayersTableFooter(table::end);        
        }
    } else {
        showMessage(messages::INFO, "There are no player records", true);
    }
}


/**
 * Prints the table title fo the records table
 */
void Manager::printPlayersTableTitle() {
    std::cout 
        << '\n' << char(218) 
        << std::string(10, char(196))  << char(194)
        << std::string(24, char(196)) << char(194)
        << std::string(14, char(196)) << char(191) << '\n'
        << char(179) << std::setw(10) << " Index"
        << char(179) << std::setw(24) << " Player Name"
        << char(179) << std::setw(14) << " Life Points" << char(179) << '\n'
        << char(195) 
        << std::string(10, char(196)) << char(197)
        << std::string(24, char(196)) << char(197)
        << std::string(14, char(196)) << char(180) << '\n';
}


/**
 * Prints the table members fo the records table
 */
void Manager::printPlayersTableMembers(const Player *player, int id) {
    std::cout << std::left
        << char(179) << " " << std::setw(8) << id << " " 
        << char(179) << " " << std::setw(22) << player->getName() << " " 
        << char(179) << " " << std::setw(12) << player->getLifePoints() << " " 
        << char(179) << '\n';    
}


/**
 * Prints the table middle section or footer section
 */
void Manager::printPlayersTableFooter(table c) {
    if (c == table::middle) {
        std::cout << char(195) 
            << std::string(10, char(196)) << char(197)
            << std::string(24, char(196)) << char(197)
            << std::string(14, char(196)) << char(180) << '\n';        
    } else if (c == table::end) {
        std::cout << char(192) 
            << std::string(10, char(196)) << char(193)
            << std::string(24, char(196)) << char(193)
            << std::string(14, char(196)) << char(217) << '\n';                
    }    
}


/**
 * Free allocated memory of all the player objects
 * in the players vector
 */
void Manager::freePlayersFromMemory() {
    for (auto &player : players)
        delete player;
}


/**
 * Helper function to display a formatted message
 * @param {enum class} m Type of message to include
 * @param {char *} text Message to display
 * @param {bool} new_line If true, add a new line at the begining of the message
 */
void Manager::showMessage(messages m, const char *text, bool new_line) {
    if (new_line)
        std::cout << std::endl;
    if (m == messages::ERROR)
        std::cout << "[ERROR] ";
    else if (m == messages::INFO)
        std::cout << "[INFO] ";
    else if (m == messages::USER)
        std::cout << "[USER] ";

    std::cout << text << std::endl;
}
