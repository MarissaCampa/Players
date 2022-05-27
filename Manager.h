#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
#include "Player.h"

enum class table { title, middle, end };
enum class messages { ERROR, USER, INFO };

// GLOBAL VARIABLES
const int BUFFER_SIZE = 50;
const int MAX_NUM_PLAYERS = 6;
const char FILE_NAME[] = "players.txt";

class Manager 
{
private:
    std::vector<Player*> players;

public:
    void showMainMenu();
    int getNumberFromUser();
    bool getTextFromUser(char *buffer);
    bool areIndexesWithinRange(int index1, int index2);
    bool isIndexWithinRange(int index);

    void promptToAddNewPlayer();
    void promptToCompareTwoPlayerRecords();
    int promptToDeletePlayerRecord();
    int promptToEditPlayerRecord();

    bool isBufferADigit(const char* buffer);
    void readPlayersFromFile();
    void writePlayersToFile();
    bool deletePlayerRecord(int index);
    bool editPlayerRecord(int index);

    void printPlayersTable();
    void printPlayersTableTitle();
    void printPlayersTableMembers(const Player *player, int id);
    void printPlayersTableFooter(table c);
    void freePlayersFromMemory();
    void showMessage(messages m, const char *text, bool new_line = false);
};

#endif // MANAGER_H
