#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "GameCharacter.h"
// #include "Player.h"
#include "Item.h"

using namespace std;

class Item;
class GameCharacter;


class NPC: public GameCharacter
{
private:
    string script;
    vector<Item> commodity;
public:
    NPC();
    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation
              */
    virtual bool triggerEvent(Object* a);
    virtual int get_weapon_attack()final;
    virtual bool is_buff_on_time()final;
    //virtual int get_weapon_defense()final;
    //virtual bool passive_check()final;
    //virtual int active_skill()final;
    //virtual bool is_weapon_on()final;
    //virtual void put_on_weapon(Item a)final;
    //virtual string getweaponname()final;
    /* Set & Get function*/
    void setScript(string a);
    void setCommodity(vector<Item> a);
    string getScript();
    vector<Item> getCommodity();
};//merchant for med, merchant for fight_med, father for heal,


class merchant_med :public NPC
{
public:
    merchant_med();
    virtual bool triggerEvent(Object* a);
};

class merchant_sword:public NPC
{
public:
    merchant_sword();
    virtual bool triggerEvent(Object* a);

};

class merchant_dice:public NPC
{
public:
    merchant_dice();
    virtual bool triggerEvent(Object* a);
};

class merchant_winebottle:public NPC
{
public:
    merchant_winebottle();
    virtual bool triggerEvent(Object* a);
};

#endif // NPC_H_INCLUDED
