#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include<stdlib.h>
#include <time.h>
#include "Object.h"
#include "Item.h"
using namespace std;

class Item;


class GameCharacter: public Object
{
private:
    int timer;
    int buff_timer;
    int buff_attack;
    int buff_defense;
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
public:
    Item* weapon;
    bool passive_chance;
    GameCharacter();
    GameCharacter(string a);
    GameCharacter(string a, string f, int b, int c, int d, int e);
    int gettimer();
    void settimer(int a);
    void subtimer();
    bool isontimer();//show have to +1
    virtual bool is_buff_on_time();
    void setbuff_timer(int a);
    void subbuff_timer();
    int getbuff_timer();
    void setbuff_attack(int a);
    void setbuff_defense(int a);
    int getbuff_attack();
    int getbuff_defense();
    bool checkIsDead();
    virtual bool passive_check();
    virtual bool triggerEvent(Object* a);
    int takeDamage(int n);

    /* Set & Get function*/
    void setMaxHealth(int a);
    void setCurrentHealth(int a);
    void setAttack(int a);
    void setDefense(int a);
    int getMaxHealth();
    int getCurrentHealth();
    virtual int getAttack();
    int getDefense();
    //virtual void put_on_weapon(Item* a);
    //temporary not pure virtual
    virtual void passive_skill();
    virtual int active_skill();
    virtual bool is_weapon_on();
    //virtual string getweaponname();
    virtual void turn_passive_chance();
    virtual int get_weapon_attack();
    virtual int get_weapon_defense();
};



class knight :public GameCharacter
{
public:
    knight();
    virtual int get_weapon_defense();
    virtual int get_weapon_attack();
    virtual void turn_passive_chance();
    virtual bool is_buff_on_time();
    virtual int active_skill()override;
    virtual void passive_skill();
    virtual bool passive_check();
    //virtual void put_on_weapon(Item* a);
    virtual bool is_weapon_on();
    virtual bool triggerEvent(Object* a);//not yet

    //virtual string getweaponname();
};

class gambler :public GameCharacter
{
public:
    gambler();
    virtual int get_weapon_defense();
    virtual int get_weapon_attack();
    virtual int getAttack();
    virtual bool is_buff_on_time();
    virtual int active_skill();
    virtual void passive_skill();
    virtual bool passive_check();
    //virtual void put_on_weapon(Item* a);
    virtual bool triggerEvent(Object* a);//not yet

    virtual bool is_weapon_on();
    //virtual string getweaponname();
};
class bad_guy :public GameCharacter
{
public:
    bad_guy();
    virtual int get_weapon_defense();
    virtual int get_weapon_attack();
    virtual bool is_buff_on_time();
    virtual int active_skill();
    virtual void passive_skill();
    virtual bool passive_check();
    virtual bool triggerEvent(Object*);//not yet

    virtual bool is_weapon_on();

    //virtual void put_on_weapon(Item* a);

    //virtual string getweaponname();
};


#endif // GAMECHARACTER_H_INCLUDED
