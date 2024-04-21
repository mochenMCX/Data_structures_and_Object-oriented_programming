#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include<sstream>
#include <map>
#include "Object.h"
// #include "Player.h"
// #include "GameCharacter.h"
// #include "Monster.h"
// #include "NPC.h"
// #include "Room.h"

using namespace std;




class Item: public Object
{
private:
    int health,attack,defense;
    int dollar;
    int amount;
public:
    Item();
    //Item(string a, string b, int c, int d, int e);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    virtual bool triggerEvent(Object* a);

    /* Set & Get function*/
    int getHealth();
    int getAttack();
    int getDefense();
    void setHealth(int a);
    void setdollar(int a);
    int getdollar();
    void setAttack(int a);
    void setDefense(int a);
    void addamount(int a);
    void setamount(int a);
    virtual int getamount()final;
};

class med :public Item
{
public:
    med(int a);
    virtual bool triggerEvent(Object*a);
};

class key:public Item
{
public:
    key();
    virtual bool triggerEvent(Object* a);
};

class sword :public Item
{
public:
    sword(int a);
    //virtual bool triggerEvent(Object* a);
};

class dice :public Item
{
public:
    dice(int a);
};

class winebottle:public Item
{
public:
    winebottle(int a);
};

class money:public Item
{
public:
    money(int a);
    virtual bool triggerEvent(Object* a);
};

class character_frag:public Item
{
public:
    character_frag(int a);
    virtual bool triggerEvent(Object* a);
};

#endif // ITEM_H_INCLUDED
