/* 
 * File:   Hand.h
 * Author: Tri Le
 * CSC 17C Project 1 Old Maid Card Game
 * Created on May 8, 2016, 8:42 PM
 */

#ifndef HAND_H
#define	HAND_H

#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>

class Hand {
private:
    std::list<int> cardHand;                              // Any given player's hand of cards
    int curSize;                                          // Current size of the player's hand
public:
    Hand();                                               // Default constructor sets empty list
    Hand(std::stack<int> &, int, int, int &);             // Constructor takes in the shuffled deck and splits it equally
                                                          // among X amount of players and checks who is last to receive cards
    void showHand();                                      // Shows the player's hand
    void sortHand();                                      // Sorts the player's hand
    void throwPairs();                                    // Removes pairs from the player's hand
    void setCurSize();                                    // Sets the player's current hand size
    int getCurSize() { return curSize; }                  // Return the player's current hand size
    int takeCard(int);                                    // Take a card from another player
    void insertCard(int);                                 // Places taken card into player's hand
    int cpuTake(int);                                     // Chooses which card the CPU will take
    void checkWin(bool &);                                // Checks for a win
};

#endif	/* HAND_H */

