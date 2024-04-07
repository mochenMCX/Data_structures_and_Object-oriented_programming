#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "GameCharacter.h"
#include "Room.h"
#include "Item.h"

using namespace std;

class Item;

class Player: public GameCharacter
{
private:
    Room* currentRoom;
    Room* previousRoom;
    vector<Item> inventory;
public:
    map<string, bool> ch;
    vector<GameCharacter> gamecharacter;
    virtual bool is_buff_on_time(){};
    Player();
    Player(string a){};
    void eraseItem(Item a);
    void addItem(Item a);
    //void increaseStates(int,int,int);
    void changeRoom(Room* a);
    virtual void put_on_weapon(Item a)final;
    virtual bool passive_check();
    virtual int get_weapon_attack();
    virtual int get_weapon_defense();
    virtual void turn_passive_chance();
    virtual void passive_skill();
    virtual int active_skill();
    virtual bool triggerEvent(Object* a);
    virtual bool is_weapon_on();
    virtual string getweaponname();
    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */

    //bool triggerEvent(Object* a){};

    /* Set & Get function*/
    void setCurrentRoom(Room* a);
    void setPreviousRoom(Room* a);
    void setInventory(vector<Item> a);
    // void setGameacter(){
    //     knight;
    // };
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    vector<Item> getInventory();
    void unlock_character(string a);

    int getmoney();

    // virtual bool is_weapon_on()final{};
    // virtual string getweaponname()final{};
};


#endif // PLAYER_H_INCLUDED
