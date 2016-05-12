/* 
 * File:   main.cpp
 * Author: Tri Le
 * CSC 17C Project 1 Old Maid Card Game
 * Created on May 7, 2016, 8:54 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <map>
using namespace std;

#include "Hand.h"

void makeDeck(deque<int> &);                      // Make a deck
void showDeck(deque<int> &);                      // Print the deck
void shuffle(deque<int> &);                       // Shuffle the deck
void stackDeck(stack<int> &, deque<int>);         // Push deck onto a stack to divide into lists later

int main(int argc, char** argv) {

    srand(time(0));
    map<string, string> winOrder;                 // Used to store winners name in order
    string cpu2 = "Computer2";
    string cpu3 = "Computer3";
    string p1;
    cout << "Enter your name: ";
    cin >> p1;
    deque<int> deck;
    makeDeck(deck);
    int deckSize = deck.size();
    cout << "The deck size is " << deckSize << " after the removal of one QUEEN,"
            " which is represented by a (12)." << endl;
    showDeck(deck);
    shuffle(deck);
    showDeck(deck);
    stack<int> newDeck;
    stackDeck(newDeck, deck);
    int playerSz = 3;                                           
    int counter = 0;
    Hand player1(newDeck, playerSz, deckSize, counter);
    player1.showHand();
    player1.sortHand();
    player1.showHand();
    cout << endl;
    Hand player2(newDeck, playerSz, deckSize, counter);
    player2.showHand();
    player2.sortHand();
    player2.showHand();
    cout << endl;
    Hand player3(newDeck, playerSz, deckSize, counter);
    player3.showHand();
    player3.sortHand();
    player3.showHand();
    cout << endl;
    
    player1.setCurSize();
    player2.setCurSize();
    player3.setCurSize();
    cout << "Player 1 has " << player1.getCurSize() << " cards in their hand."
         << endl;
    cout << "Player 2 has " << player2.getCurSize() << " cards in their hand."
         << endl;  
    cout << "Player 3 has " << player3.getCurSize() << " cards in their hand."
         << endl;  
    
    player1.throwPairs();
    player1.showHand();
    player2.throwPairs();
    player2.showHand();
    player3.throwPairs();
    player3.showHand();
    
    player1.setCurSize();
    player2.setCurSize();
    player3.setCurSize();
    
    cout << "Player 1 has " << player1.getCurSize() << " cards in their hand."
         << endl;
    cout << "Player 2 has " << player2.getCurSize() << " cards in their hand."
         << endl;  
    cout << "Player 3 has " << player3.getCurSize() << " cards in their hand."
         << endl;
    
    int turn = 1;                           // Turn counter
    bool p1win = false;                     // Check for P1 Win
    bool p2win = false;                     // Check for P2 Win
    bool p3win = false;                     // Check for P3 Win
    int whichCard = 0;                      // Make sure this number doesn't go out of bounds
    int cardVal = 0;                        // Used to store what card was taken
    
    do{
    // Player 1 takes from Player 2's hand
    cout << "It is turn " << turn << endl;
    cout << "Choose which card to take from Player 2: ";
    do{
        cin >> whichCard;
    }while(whichCard > player2.getCurSize() - 1);
    cardVal = player2.takeCard(whichCard);
    cout << endl;
    cout << "Player 2 has " << player2.getCurSize() << " cards in their hand."
         << endl;  
    cout << "This was taken from Player 2: " << cardVal << endl;
    player2.setCurSize();
    cout << "Player 2 has " << player2.getCurSize() << " cards in their hand."
         << endl; 
    player2.showHand();
    player1.insertCard(cardVal);
    player1.setCurSize();
    cout << "Player 1 has " << player1.getCurSize() << " cards in their hand."
         << endl; 
    player1.showHand();
    player1.throwPairs();
    player1.setCurSize();
    cout << "Player 1 has " << player1.getCurSize() << " cards in their hand."
         << endl; 
    player1.showHand();
    player1.checkWin(p1win);
    turn++;
    // Player 2 takes from Player 3's hand
    cout << "It is turn " << turn << endl;
    whichCard = player3.cpuTake(player3.getCurSize());
    cardVal = player3.takeCard(whichCard);
    cout << endl;
    cout << "Player 3 has " << player3.getCurSize() << " cards in their hand."
         << endl;
    cout << "This was taken from Player 3: " << cardVal << endl;
    player3.setCurSize();
    cout << "Player 3 has " << player3.getCurSize() << " cards in their hand."
         << endl;
    player3.showHand();
    player2.insertCard(cardVal);
    player2.setCurSize();
    cout << "Player 2 has " << player2.getCurSize() << " cards in their hand."
         << endl; 
    player2.showHand();
    player2.throwPairs();
    player2.setCurSize();
    cout << "Player 2 has " << player2.getCurSize() << " cards in their hand."
         << endl; 
    player2.showHand();
    player2.checkWin(p2win);
    turn++;
    //Player 3 takes from Player 1's hand
    cout << "It is turn " << turn << endl;
    whichCard = player1.cpuTake(player1.getCurSize());
    cardVal = player1.takeCard(whichCard);
    cout << endl;
    cout << "Player 1 has " << player1.getCurSize() << " cards in their hand."
         << endl;
    cout << "This was taken from Player 1: " << cardVal << endl;
    player1.setCurSize();
    cout << "Player 1 has " << player1.getCurSize() << " cards in their hand."
         << endl;
    player1.showHand();
    player3.insertCard(cardVal);
    player3.setCurSize();
    cout << "Player 3 has " << player3.getCurSize() << " cards in their hand."
         << endl; 
    player3.showHand();
    player3.throwPairs();
    player3.setCurSize();
    cout << "Player 3 has " << player3.getCurSize() << " cards in their hand."
         << endl; 
    player3.showHand();
    player3.checkWin(p3win);
    turn++;
    // Outputting winner
    if(player1.getCurSize() == 0){
        winOrder[p1] = "First";
        winOrder[cpu2] = "Second";
        winOrder[cpu3] = "Third";
        for(map<string, string>::iterator i = winOrder.begin(); i != winOrder.end(); i++){
            cout << i->first << " " << i->second << endl;
        }
    }
    else if(player2.getCurSize() == 0){
        winOrder[cpu2] = "First";
        winOrder[p1] = "Second";
        winOrder[cpu3] = "Third";
        for(map<string, string>::iterator i = winOrder.begin(); i != winOrder.end(); i++){
            cout << i->first << " " << i->second << endl;
        }
    }
    else if(player3.getCurSize() == 0){
        winOrder[cpu3] = "First";
        winOrder[p1] = "Second";
        winOrder[cpu2] = "Third";
        for(map<string, string>::iterator i = winOrder.begin(); i != winOrder.end(); i++){
            cout << i->first << " " << i->second << endl;
        }
    }
    }while(p1win == false || p2win == false || p3win == false);
    
    return 0;
}

void makeDeck(deque<int> &deck){
    bool flag = false;
    for(int i=1;i<14;i++){
        if(i != 12){
        for(int j=0;j<4;j++){
            deck.push_back(i);
        }
        }
        if(i==12)
            flag = true;
        if(flag == true){
            for(int q=0;q<3;q++){
                deck.push_back(i);
            }
            flag = false;
        }
    }
}

void showDeck(deque<int> &deck){                     // Shows all the cards in the deck for testing purposes
    cout << "Here is the current deck: " << endl << endl;
    for(int i=0;i<deck.size();i++){
        cout << deck[i] << " ";
        if(i==11 || i==23 || i==35 || i==43)
            cout << endl;
    }
    cout << endl << endl;
}

void shuffle(deque<int> &deck){                      // Shuffles all the cards in the deck
    for(int first = 0; first < deck.size(); first++){
        // Create an int called second and set it equal to the random operator
        int second = (rand() + time(0)) % deck.size();
        int temp = deck[first];   
        deck[first] = deck[second];
        deck[second] = temp;
    }
}

void stackDeck(stack<int> &newDeck, deque<int> deck){
    for(int i=0;i<51;i++){
        newDeck.push(deck[i]);
    }
}
