#include "GameCharacter.h"

GameCharacter::GameCharacter()
{
    timer = 0;
    buff_timer = 0;
    buff_attack = 0;
    buff_defense = 0;
    maxHealth = 0;
    currentHealth = 0;
    attack = 0;
    defense = 0;
}

GameCharacter::GameCharacter(string a) : Object(a)
{
    timer = 0;
    buff_timer = 0;
    buff_attack = 0;
    buff_defense = 0;
    maxHealth = 0;
    currentHealth = 0;
    attack = 0;
    defense = 0;

}

GameCharacter::GameCharacter(string a, string f, int b, int c, int d, int e):Object(a, f), maxHealth(b), currentHealth(c), attack(d), defense(e) 
{
    timer = 0;
    buff_timer = 0;
    buff_attack = 0;
    buff_defense = 0;
}

int GameCharacter::gettimer()
{
   return timer;
}

void GameCharacter::settimer(int a)
{
    timer = a;
}

void GameCharacter::subtimer()
{
    if(timer > 0){
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

bool GameCharacter::is_buff_on_time()
{   
    if (getbuff_timer() != 0) {
        return false;
    }
    else {
        return true;
    }
    
}

void GameCharacter::setbuff_timer(int a)
{
    buff_timer = a;
}

void GameCharacter::subbuff_timer()
{
    if(buff_timer > 0){
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

bool GameCharacter::passive_check()
{
    if (this->getName() == "knight") {
        if (this->getCurrentHealth() <= 0 && passive_chance) {
            return true;
        }
        else return false;
    }
    if (this->getName() == "gambler" || this->getName()=="8+9") {
        return true;
    }
    return false;
}

bool GameCharacter::triggerEvent(Object *a)
{
    return false;
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
    if (getName() == "gambler") {
        srand((unsigned)time(NULL));
        int num = rand() % 5 + 3;
        return num;
    }
    return (attack + buff_attack);
}

int GameCharacter::getDefense()
{
    return (defense + buff_defense);
}

void GameCharacter::passive_skill()
{
    if (this->getName() == "knight") {
        if (getCurrentHealth() == 0) {
            cout << "trigger the passive skill!! : immune death once!" << endl;
            setCurrentHealth(1);
            passive_chance = false;
        }
    }
    if (this->getName() == "gambler") {
        setbuff_timer(10);
        srand((unsigned)time(NULL));
        int num = rand() % 5;
        if (num == 0) {
            cout << "trigger the passive skill!! : immune next damage!" << endl;
            setbuff_defense(10000);
        }
        else {
            setbuff_defense(0);
        }
    }
    if (this->getName() == "8+9") {
        if (getCurrentHealth() < 5) {
            setbuff_timer(10);
            cout << "trigger the passive skill! : increase the defense and attack!" << endl;
            setbuff_defense(3);
            setbuff_attack(3);
        }
        else {
            setbuff_defense(0);
            setbuff_attack(0);
        }
    }
}

int GameCharacter::active_skill()
{
    if (this->getName() == "knight") {
        cout << "use skill!  defense double!" << endl;
        int a = getDefense();
        setbuff_defense(a);
        setbuff_timer(2);
        settimer(3);
        return getAttack();
    }
    if (this->getName() == "gambler") {
        cout << "use skill!   recover the health" << endl;
        settimer(5);
        int a = getCurrentHealth() + 5;
        setCurrentHealth(a);
        if (getCurrentHealth() > 7) setCurrentHealth(7);
        return getAttack();
    }
    if (this->getName() == "8+9") {
        cout << "use skill!   more damage hit!" << endl;
        settimer(2);
        return getAttack() * 2;
    }
    return 0;
}

bool GameCharacter::is_weapon_on()
{
    return false;
}

/*string GameCharacter::getweaponname()
{
    return weapon->getName();
}*/

void GameCharacter::turn_passive_chance()
{
}

int GameCharacter::get_weapon_attack()
{
    return 0;
}

int GameCharacter::get_weapon_defense()
{
    return 0;
}

// void GameCharacter::put_on_weapon(Item* a)
// {
// }

knight::knight() :GameCharacter("knight", "gamecharacter", 15, 15, 4, 3) 
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

// void knight::put_on_weapon(Item* a)
// {
//     this -> weapon = a;
// }

bool knight::is_weapon_on()
{
    if (weapon == NULL) return false;
        else return true;
}

bool knight::triggerEvent(Object *a)
{
        return false;
}

/*string knight::getweaponname()
{
        if(is_weapon_on()){
            return weapon->getName();
        }
        else{
            return "No put on weapon.";
        }
}*/

gambler::gambler() : GameCharacter("gambler", "gamecharacter", 10, 10, 3, 2)
{
    weapon = NULL;
        setbuff_attack(0);
        setbuff_defense(0);
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
        int num = rand()%10 + 3;
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
        if (getCurrentHealth() > 10) setCurrentHealth(10);
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

// void gambler::put_on_weapon(Item* a)
// {
//     this->weapon = a;
// }

bool gambler::triggerEvent(Object *a)
{
    return false;
}

bool gambler::is_weapon_on()
{
    if (weapon == NULL) return false;
        else return true;
}

/*string gambler::getweaponname()
{
        if(is_weapon_on()){
            return weapon->getName();
        }
        else{
            return "No put on weapon.";
        }
}*/

bad_guy::bad_guy():GameCharacter("8+9", "gamecharacter", 12, 12, 5, 2)
{
    weapon = NULL;
    setbuff_attack(0);
    setbuff_defense(0);
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

// void bad_guy::put_on_weapon(Item* a)
// {
//     this->weapon = a;
// }

/*string bad_guy::getweaponname()
{
    if(is_weapon_on()){
            return weapon->getName();
        }
        else{
            return "No put on weapon.";
        }
}*/
