#include "GameCharacter.h"

GameCharacter::GameCharacter(string a) :Object(a) 
{
}

GameCharacter::GameCharacter(string a, string f, int b, int c, int d, int e):Object(a, f), maxHealth(b), currentHealth(c), attack(d), defense(e) 
{
}

int GameCharacter::gettimer()
{
   return timer+1;
}

void GameCharacter::settimer(int a)
{
    timer = a;
}

void GameCharacter::subtimer()
{
    if(timer != 0){
            timer--;
        }
}

bool GameCharacter::isontimer()
{
        if(timer == 0){
            return true;
        }
        else{
            return false;
        }
}

void GameCharacter::setbuff_timer(int a)
{
    buff_timer = a;
}

void GameCharacter::subbuff_timer()
{
    if(buff_timer != 0){
            buff_timer--;
        }
}

int GameCharacter::getbuff_timer()
{
         return buff_timer;
}

void GameCharacter::setbuff_attack(int a)
{
    buff_attack = a;
}

void GameCharacter::setbuff_defense(int a)
{
    buff_defense = a;
}

int GameCharacter::getbuff_attack()
{
    return buff_attack;
}

int GameCharacter::getbuff_defense()
{
    return buff_defense;
}

bool GameCharacter::checkIsDead()
{
    return currentHealth == 0;
}

int GameCharacter::takeDamage(int n)
{
    int sum = defense + buff_defense;
        if(n>sum) return n-sum;
        else return 0;
}

void GameCharacter::setMaxHealth(int a)
{
    maxHealth = a;
}

void GameCharacter::setCurrentHealth(int a)
{
    currentHealth = a;
}

void GameCharacter::setAttack(int a)
{
    attack = a;
}

void GameCharacter::setDefense(int a)
{
    defense = a;
}

int GameCharacter::getMaxHealth()
{
    return maxHealth;
}

int GameCharacter::getCurrentHealth()
{
    return currentHealth;
}

int GameCharacter::getAttack()
{
    return (attack + buff_attack);
}

int GameCharacter::getDefense()
{
    return (defense + buff_defense);
}

knight::knight() :GameCharacter("knight", "gamecharacter", 10, 10, 3, 3) 
{
    bool passive_chance = true;
        weapon = NULL;
        setbuff_attack(0);
        setbuff_defense(0);
}

int knight::get_weapon_defense()
{
        if(weapon != NULL){
            return weapon->getDefense();
        }
        else{
            return 0;
        }
}

int knight::get_weapon_attack()
{
       if(weapon != NULL){
            return weapon->getAttack();
        }
        else{
            return 0;
        }
}

void knight::turn_passive_chance()
{
    passive_chance = true;
}

bool knight::is_buff_on_time()
{
    if(getbuff_timer()!= 0){
            subbuff_timer();
            return false;
        }
        else{
            return true;
        }
}

int knight::active_skill()
{
        int a =getDefense();
        setbuff_defense(a);
        settimer(3);
        return getAttack();
}

void knight::passive_skill()
{
    if(getCurrentHealth() == 0){
            setCurrentHealth(1);
            passive_chance = false;
        }
}

bool knight::passive_check()
{
        if (getCurrentHealth() <= 0 && passive_chance) {
            return true;
        }
        else return false;
}

void knight::put_on_weapon(Item a)
{
    this->weapon = &a;
}

bool knight::is_weapon_on()
{
    if (weapon == NULL) return false;
        else return true;
}

bool knight::triggerEvent(Object *a)
{
        return false;
}

string knight::getweaponname()
{
        if(is_weapon_on()){
            return weapon->getName();
        }
        else{
            return "No put on weapon.";
        }
}

gambler::gambler() : GameCharacter("gambler", "gamecharacter", 7, 7, 1, 2)
{
    weapon = NULL;
        setbuff_attack(0);
        setbuff_defense(0);
}

void gambler::turn_passive_chance()
{
}

int gambler::get_weapon_defense()
{
        return weapon->getDefense();
}

int gambler::get_weapon_attack()
{
        return weapon->getAttack();
}

int gambler::getAttack()
{
        srand((unsigned)time(NULL));
        int num = rand()%10 + 1;
        return num;
}

bool gambler::is_buff_on_time()
{
        if(getbuff_timer()!= 0){
            subbuff_timer();
            return false;
        }
        else{
            return true;
        }
}

int gambler::active_skill()
{
        settimer(5);
        int a = getCurrentHealth() + 5;
        setCurrentHealth(a);
        if (getCurrentHealth() > 7) setCurrentHealth(7);
        return getAttack();
}

void gambler::passive_skill()
{
    setbuff_timer(10);
        srand((unsigned)time(NULL));
        int num = rand() % 5;
        if(num == 0){
            setbuff_defense(1000);
        }
        else{
            setbuff_defense(0);
        }
}

bool gambler::passive_check()
{
        return true;
}

void gambler::put_on_weapon(Item a)
{
    this->weapon = &a;
}

bool gambler::triggerEvent(Object *a)
{
    return false;
}

bool gambler::is_weapon_on()
{
    if (weapon == NULL) return false;
        else return true;
}

string gambler::getweaponname()
{
        if(is_weapon_on()){
            return weapon->getName();
        }
        else{
            return "No put on weapon.";
        }
}

bad_guy::bad_guy():GameCharacter("8+9", "gamecharacter", 8, 8, 5, 2)
{
    weapon = NULL;
    setbuff_attack(0);
    setbuff_defense(0);
}

void bad_guy::turn_passive_chance()
{
}

int bad_guy::get_weapon_defense()
{
    return weapon->getDefense();
}

int bad_guy::get_weapon_attack()
{
    return weapon->getAttack();
}

bool bad_guy::is_buff_on_time()
{
    if(getCurrentHealth()<5){
            return false;
        }
        else{
            return true;
        }
}

int bad_guy::active_skill()
{
        settimer(2);
        return getAttack() * 2;
}

void bad_guy::passive_skill()
{
    if(getCurrentHealth()<5){
            setbuff_defense(3);
            setbuff_attack(3);
        }
}

bool bad_guy::passive_check()
{
        return true;
}

bool bad_guy::triggerEvent(Object *a)
{
        return false;
}

bool bad_guy::is_weapon_on()
{
        if (weapon == NULL) return false;
        else return true;
}

void bad_guy::put_on_weapon(Item a)
{
    this->weapon = &a;
}

string bad_guy::getweaponname()
{
    if(is_weapon_on()){
            return weapon->getName();
        }
        else{
            return "No put on weapon.";
        }
}
