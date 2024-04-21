#include "Player.h"

// Player::Player()
// {
//     knight x;
//         gambler y;
//         bad_guy z;
//         gamecharacter.push_back(x);
//         gamecharacter.push_back(y);
//         gamecharacter.push_back(z);
//         ch.insert(make_pair("knight", true));
//         ch.insert(make_pair("gambler", false));
//         ch.insert(make_pair("bak_guy", false));
// }

Player::Player()
{
    gamecharacter = {knight() , gambler() , bad_guy()};
    //sword* tem = new sword(1);
    weapon = {NULL, NULL, NULL};
        ch.insert(make_pair("knight", true));
        ch.insert(make_pair("gambler", false));
        ch.insert(make_pair("8+9", false));

}

void Player::eraseItem(Item &a)
{
    vector<Item>::iterator it;
    vector<Item> b = this->getInventory();
    for (it=b.begin(); it!=b.end(); it++) {
        if (it->getName() == a.getName()) {
            b.erase(it);
            this->setInventory(b);
            break;
        }
    }
}

/*bool Player::is_buff_on_time(){
    return true;
}*/

void Player::addItem(Item a)
{
    inventory.push_back(a);
}

void Player::changeRoom(Room *a)
{
    previousRoom = currentRoom;
        currentRoom = a;
}

bool Player::passive_check()
{
        return false;
}

int Player::get_weapon_attack()
{
        return 0;
}

int Player::get_weapon_defense()
{
        return 0;
}

void Player::turn_passive_chance()
{
}

void Player::passive_skill()
{
}

int Player::active_skill()
{
        return 0;
}

bool Player::triggerEvent(Object *a)
{
        return false;
}

bool Player::is_weapon_on()
{
        return false;
}

string Player::getweaponname()
{
        return string();
}

void Player::put_on_weapon(Item a)
{
}

void Player::setCurrentRoom(Room *a)
{
    currentRoom = a;
}

void Player::setPreviousRoom(Room *a)
{
    previousRoom = a;
}

void Player::setInventory(vector<Item> &a)
{   
    //inventory.resize(a.size());
    inventory = a;
}

Room *Player::getCurrentRoom()
{
        return currentRoom;
}

Room *Player::getPreviousRoom()
{
        return previousRoom;
}

vector<Item> Player::getInventory()
{
       return inventory;
}

void Player::unlock_character(string a)
{
    ch[a] = true;
}

int Player::getmoney()
{ 
    vector<Item>::iterator it;
        vector<Item> b = getInventory();
        if (b.size() == 0) {
            return 0;
        }
        for (it = b.begin(); it->getTag() != "money" && it != b.end(); ++it) {
            if (it->getTag() != "money" && it + 1 == b.end()) {
                break;
            }
        };
        if (it->getTag() != "money" && it + 1 == b.end()) {
            return 0;
        }
        if(it == b.end()) return 0;
        else{
            return it->getamount();
        }
}
