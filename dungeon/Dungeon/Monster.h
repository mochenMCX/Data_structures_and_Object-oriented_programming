#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Item.h"
#include "GameCharacter.h"
#include "Player.h"

using namespace std;

class Monster: public GameCharacter
{
private:
public:
    Monster();
    Monster(string a,int b,int c,int d);
    virtual int get_weapon_attack()final;
    virtual bool is_buff_on_time()final;
    virtual int get_weapon_defense()final;
    virtual bool passive_check()final;
    virtual void passive_skill()final;
    virtual int active_skill()=0;
    virtual void put_on_weapon(Item a)final;
    virtual bool is_weapon_on()final;
    virtual string getweaponname()final;
    virtual void turn_passive_chance()final;
    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    virtual bool triggerEvent(Object* a)final;
};

class shield:public Monster
{
public:
    shield();
    virtual int active_skill();
};//defense + attack = attack

class soldier:public Monster
{
public:
    soldier();
    virtual int active_skill();
};//every 5 round attack +1 temporary

class boss:public Monster
{
public:
    boss();
    virtual int active_skill();
};//every 3 round +3 HP

class final_boss:public Monster
{
public:
    final_boss();
    virtual int active_skill();
};//every 3 round attack +2 not temporary



#endif // ENEMY_H_INCLUDED
