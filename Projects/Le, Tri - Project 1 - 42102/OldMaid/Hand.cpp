/* 
 * File:   Hand.cpp
 * Author: Tri Le
 * CSC 17C Project 1 Old Maid Card Game
 * Created on May 8, 2016, 8:42 PM
 */

#include <cstdlib>
#include <iostream>
#include "Hand.h"

Hand::Hand() {
}
// Constructor makes deck in order
Hand::Hand(std::stack<int> &cards, int players, int limit, int &counter){
    int split;
    if(limit % players == 0){
        split = limit / players;
        for(int i=0; i<split; i++){
            cardHand.push_back(cards.top());
            cards.pop();
        }
    }
    else{
        split = (limit / players) + 1;
        if(counter < players - 1){
            counter++;
            for(int i=0; i<split; i++){
                cardHand.push_back(cards.top());
                cards.pop();
            }
        }
        else{
            for(int i=0; i<split - 1; i++){
                cardHand.push_back(cards.top());
                cards.pop();
            }
        }
    }
}
// Outputs hand
void Hand::showHand(){
    std::cout << "This is your hand: " << std::endl;
    std::list<int>::iterator i;
    for(i = cardHand.begin(); i != cardHand.end(); i++){
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}
// Sorts hand
void Hand::sortHand(){
    cardHand.sort();
}
// Throws away any pairs in the hand
void Hand::throwPairs(){
    for (std::list<int>::iterator i = cardHand.begin(); i != cardHand.end();){
        std::list<int>::iterator n = i; 
        n++;
        if (n == cardHand.end())
            break;
        if (*i == *n){
            i = cardHand.erase(i);
            i = cardHand.erase(i);
        }
        else
            i++;
    }
}

void Hand::setCurSize(){
    curSize = cardHand.size();
}
// Take selected card from other player hand
int Hand::takeCard(int pos){
    int temp;
    if (pos < cardHand.size()){
        std::list<int>::iterator i = cardHand.begin();
        std::advance(i, pos);                                  // 'i' points to the element at index 'N'
        temp = *i;
        i = cardHand.erase(i);
    }
    return temp;
}
// Insert card into player's hand
void Hand::insertCard(int cardVal){
    cardHand.push_back(cardVal);
    cardHand.sort();
}
// Computer randomly choosing index to take from other player's hand
int Hand::cpuTake(int size){
    int temp;
    temp = rand() % size;
    return temp;
}
// Check for a win
void Hand::checkWin(bool &win){
    if(cardHand.empty()){
        win = true;
    }
    else{
        win = false;
    }
}