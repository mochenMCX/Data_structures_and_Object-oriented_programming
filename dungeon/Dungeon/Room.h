#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Object.h"
#include "GameCharacter.h"
#include "Monster.h"
#include "NPC.h"

using namespace std;

class Room
{
private:
    Room* upstair;
    Room* downstair;
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    bool isExit;
    bool lock;
    int index;
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
public:
    Room();
    Room(int b);
    bool popObject(Object* a);; /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    bool getlock();
    void unlock();
    void setupstairs(Room* a);
    void setdownstairs(Room* a);
    void setUpRoom(Room* a);
    void setDownRoom(Room* a);
    void setLeftRoom(Room* a);
    void setRightRoom(Room* a);
    void setIsExit(bool a);
    void setIndex(int a);
    void setObjects(vector<Object*> a);
    bool getIsExit();
    int getIndex();
    vector<Object*> getObjects();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
    Room* getupstairs();
    Room* getdownstairs();
    bool islock(Player a);
};

class restaurant:public Room
{
public:
    restaurant(int a);
};

class bathroom:public Room
{
public:
    bathroom(int a);
};

class corridor:public Room
{
public:
    corridor(int a);
};

class center:public Room
{
public:
    center(int a);
    
};

class store:public Room
{
public:
    store(int a, string c);
};

#endif // ROOM_H_INCLUDED
