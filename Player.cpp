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

// Member modifiers  (Setters)
void Player::setName(const char *buffer) {
    delete [] name;
    name = new char[strlen(buffer) + 1];
    strcpy(name, buffer);
}

void Player::setLifePoints(int p) {
    lifePoints = p;
}

void Player::reduceLifePoints(int p) {
    lifePoints -= p;
}

void Player::increaseLifePoints(int p) {
    lifePoints += p;
}


//  MEMBER FUNCTIONS, OVERLOADED OPERATORS

// Overloaded copy assignment
Player &Player::operator=(const Player &rhs) {
    if (this == &rhs)
        return *this;
    delete [] name;
    name = new char[strlen(rhs.name) + 1];
    strcpy(name, rhs.name);
    lifePoints = rhs.lifePoints;
    return *this;
}

// Overloaded move assignment
Player &Player::operator=(Player &&rhs) {
    if (this == &rhs)
        return *this;
    delete [] name;
    name = rhs.name;
    lifePoints = rhs.lifePoints;
    rhs.name = nullptr;
    return *this;
}

// Overloaded substraction operator
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


// GOBAL FUNCTIONS, FRIEND FUNCTIONS

// Display by object reference
void display(const Player &player) {
    std::cout << player.name << ", " << player.lifePoints << std::endl;
}

// Display function by object pointer
void display(const Player *player) {
    std::cout << player->getName() << ", " << player->getLifePoints() << std::endl;
}

// Overloaded stream insertion operator
std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << player.name << ", " << player.lifePoints;
    return os;
}

// Overloaded stream extraction operator (only for name)
std::istream &operator>>(std::istream &is, Player &player) {
    char buff[50];
    is.get(buff, 50);
    delete [] player.name;
player.name = new char[strlen(buff) + 1];
    strcpy(player.name, buff);
}

// Global function, addition operator
Player operator+(const Player &lhs, const Player &rhs) {
    char *buff = new char[strlen(lhs.name) + strlen(rhs.name) + 1];
    strcpy(buff, lhs.name);
    strcat(buff, " ");
    strcat(buff, rhs.name);
    Player temp {buff, lhs.lifePoints + rhs.lifePoints};
    delete [] buff;
    return temp;
}

// Global function, equality operator (player object reference)
bool operator==(const Player &lhs, const Player &rhs) {
    return (strcmp(lhs.name, rhs.name) == 0 && lhs.lifePoints == rhs.lifePoints);
}

// Global function, unary minus operator
Player operator-(const Player &obj) {
//    std::cout << "Global unary minus operator" << std::endl;
    char *buff = new char[strlen(obj.name) + 1];
    strcpy(buff, obj.name);
    for (int i = 0; i < strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Player temp {buff, obj.lifePoints};
    delete [] buff;
    return temp;
}