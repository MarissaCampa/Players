#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class Player 
{
    // Global friend functions to display a player object
    friend void display(const Player &player);
    friend void display(const Player *player);

    // Overloading operators as global functions
    friend std::ostream &operator<<(std::ostream &os, const Player &player);    // Overloaded stream insertion operator
    friend std::istream &operator>>(std::istream &is, Player &player);          // Overloaded stream extraction operator
    friend Player operator+(const Player &lhs, const Player &rhs);              // Overloaded addition operator
    friend Player operator-(const Player &obj);                                 // Overloaded unary minus operator
    friend bool operator==(const Player &lhs, const Player &rhs);               // Overloaded equality operator
    
private:
    char *name;
    int lifePoints;
public:
    Player();                                   // No-arg constructor
    Player(const char *buffer, int n);          // Two-arg constructor
    Player(const Player &src);                  // Copy constructor
    Player(Player &&src) noexcept;              // Move constructor
    ~Player();
    
    // Member getters
    const char *getName() const { return name; }
    int getLifePoints() const { return lifePoints; }
    
    // Member modifiers
    void setName(const char *buffer);
    void setLifePoints(int p);
    void reduceLifePoints(int p);
    void increaseLifePoints(int p);
   
    Player &operator=(const Player &rhs);       // Overloaded copy assignment operator
    Player &operator=(Player &&rhs);            // Overloaded move assignment operator

    Player operator-(const Player &rhs) const;  // Overloaded substraction operator    
};

#endif // PLAYER_H
