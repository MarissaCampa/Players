#include "Player.h"
#include <iostream>
#include <cstring>

// No-args constructor
Player::Player() : lifePoints(0) {
    name = new char[1];
    name[0] = '\0';
}

// Two-arg constructor with default value for lifePoints
Player::Player(const char* buffer, int n = 10) : lifePoints(n) {
    if (buffer == nullptr) {
        name = new char[1];
        name[0] = '\0';
    } else {
        name = new char[strlen(buffer) + 1];
        strcpy(name, buffer);        
    }
}

// Copy constructor
Player::Player(const Player &src) 
    : Player(src.name, src.lifePoints) {
}

// Move constructor
Player::Player(Player &&src) noexcept
    : name(src.name), lifePoints(src.lifePoints) {
    src.name = nullptr;
}

// Destructor
Player::~Player() {
    delete [] name;
    name = nullptr;
}

// Allocates memory for current name and performs
// a deep copy from {char*} buffer
void Player::setName(const char *buffer) {
    delete [] name;
    name = new char[strlen(buffer) + 1];
    strcpy(name, buffer);
}

// Sets the life points to {int} p
void Player::setLifePoints(int p) {
    lifePoints = p;
}

// Reduces the current life points by {int} p
void Player::reduceLifePoints(int p) {
    lifePoints -= p;
}

// Increases the current life points by {int} p
void Player::increaseLifePoints(int p) {
    lifePoints += p;
}


/***********************************************
    OVERLOADED OPERATORS AS MEMBER FUNCTIONS
          OF THE PLAYER CLASS
***********************************************/

/**
 * Overloaded copy assignment operator (Member function)
 * It allocates new memory for the player's name and performs
 * a deep copy of the rhs player name. It copies the life points.
 * of the rhs object (because it's a nameless transient object)
 * @param {Player&} rhs Player object by const reference
 * @return {Player&} Returns a reference to itself after copy
 */
Player &Player::operator=(const Player &rhs) {
    if (this == &rhs)
        return *this;
    delete [] name;
    name = new char[strlen(rhs.name) + 1];
    strcpy(name, rhs.name);
    lifePoints = rhs.lifePoints;
    return *this;
}

/**
 * Overloaded move assignment operator (Member function)
 * It assigns the member values of the rhs object to 
 * it's current member values, and nullifies the pointer
 * of the rhs object (because it's a nameless transient object)
 * @param {Player&&} rhs Player r-value object
 * @return {Player&} Returns a reference to itself
 */
Player &Player::operator=(Player &&rhs) {
    if (this == &rhs)
        return *this;
    delete [] name;
    name = rhs.name;
    lifePoints = rhs.lifePoints;
    rhs.name = nullptr;
    return *this;
}

/**
 * Overloaded substraction operator (Member function)
 * Returns a player object with a player's name resulting of taking
 * the substring of the current object's name minus the right-hand side player's name
 * It only proceeds when the rhs is a substring of the current, if the current object's
 * name does not contain the rhs's name, then it returns itself unchanged.
 *    Usage example:
 *      Player p1 ("Elizabeth Bennet", 15);
 *      Player p2 ("Bennet", 1);
 *      Player p3 = p1 + p2     // "p3.name = Elizabeth "
 * @param {Player&} rhs Righ-hand side player object const reference
 * @return {Player} Returns a player object with the new name.
 */
Player Player::operator-(const Player &rhs) const {
    if (strlen(name) > strlen(rhs.name)) {
        size_t size = strlen(rhs.name);
        char *buff = new char[size + 1];
        for (int i = 0; i < strlen(rhs.name); i++)
            buff[i] = name[strlen(name) - size + i];
        buff[size] = '\0';

        if (strcmp(buff, rhs.name) == 0) {
            delete [] buff;
            size = strlen(name) - strlen(rhs.name);
            buff = new char[size + 1];
            for (int i = 0; i < size; i++)
                buff[i] = name[i];
            buff[size] = '\0';
            Player temp {buff, lifePoints};
            delete [] buff;
            return temp;            
        } else {
            // First player name does not contain the second parameter
            return Player(*this);            
        }
    } else {
        return Player(*this);
    }
}



/*******************************************
    GlOBAL FUNCTIONS THAT ARE FRIEND 
    FUNCTIONS TO THE PLAYER CLASS
********************************************/

/**
 * Displays a player's name and life points. (Global friend function)
 * @param {Player&} player Player object by const reference
 */
void display(const Player &player) {
    std::cout << player.name << ", " << player.lifePoints << std::endl;
}


/**
 * Displays a player's name and life points. (Global friend function)
 * @param {Player*} player Player object by pointer
 */
void display(const Player *player) {
    std::cout << player->getName() << ", " << player->getLifePoints() << std::endl;
}


/**
 * Overloaded stream insertion operator (Global friend function)
 * Inserts the player's name and life points into the output stream
 * @param {ostream&} os output stream object reference
 * @param {Player&} player Player object const reference
 * @return {ostream&} os Returns a reference to the output stream object
 */
// 
std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << player.name << ", " << player.lifePoints;
    return os;
}


/**
 * Overloaded stream extraction operator (Global friend function)
 * It extracts from the input stream a text and allocates enough memory
 * to copy it into the player's name 
 * @param {istream&} is stream input object reference
 * @param {Player&} player Player object to modify the name
 * @return {istream&} temp Returns a reference to the input stream object
 */
// 
std::istream &operator>>(std::istream &is, Player &player) {
    char buff[50];
    is.get(buff, 50);
    delete [] player.name;
    player.name = new char[strlen(buff) + 1];
    strcpy(player.name, buff);
}


/**
 * Overloaded addition operator (Global friend function)
 * It concatenates two player object names and returns a new player object by value
 * @param {Player&} lhs Left-hand side player object const reference
 * @param {Player&} rhs Right-hand side player object const reference
 * @return {Player} temp New player with the concatenated names of
 *          the lhs and rhs player objects
 */
Player operator+(const Player &lhs, const Player &rhs) {
    char *buff = new char[strlen(lhs.name) + strlen(rhs.name) + 1];
    strcpy(buff, lhs.name);
    strcat(buff, " ");
    strcat(buff, rhs.name);
    Player temp {buff, lhs.lifePoints + rhs.lifePoints};
    delete [] buff;
    return temp;
}


/**
 * Overloaded equality operator (Global friend function)
 * Returns true if two players are equal in name and life points
 * @param {Player&} lhs Left-hand side player object const reference
 * @param {Player&} rhs Right-hand side player object const reference
 * @return {bool} Returns true if the two players are equal in name and 
 *              life points
 */
bool operator==(const Player &lhs, const Player &rhs) {
    return (strcmp(lhs.name, rhs.name) == 0 && lhs.lifePoints == rhs.lifePoints);
}


/**
 * Overloaded unary minus operator (Global friend function)
 * It returns a new player object by value with the player's name in lower case
 * @param {Player&} obj Player object const reference
 * @return {Player} Returns a player object with the name in lower case
 */
Player operator-(const Player &obj) {
    char *buff = new char[strlen(obj.name) + 1];
    strcpy(buff, obj.name);
    for (int i = 0; i < strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Player temp {buff, obj.lifePoints};
    delete [] buff;
    return temp;
}