#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <exception>//find how to use
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include "Room.h"
#include "Item.h"

using namespace std;

class Player;
class Room;

class Dungeon{
private:
    Player origin;
    vector<Room> rooms;
public:
    Dungeon();
    /* Create a new player, and give him/her basic status */
    void createPlayer();

    void interaction();

    /* Create a map, which include several different rooms */
    void createMap();

    void showplayerstatus();

    /* Deal with player's moveing action */
    void handleMovement();

    void showmap();//not yet

    /* Deal with player's iteraction with objects in that room */
    // void handleEvent(Object*);

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame(); 

    /* Deal with the player's action     */
    /* including showing the action list */
    /* that player can do at that room   */
    /* and dealing with player's input   */
    void chooseAction();//not yet
    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */
    bool checkGameLogic();///have bug!!!

    /* Deal with the whole game process */
    void runDungeon();

    
};


#endif // DUNGEON_H_INCLUDED
