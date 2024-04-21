#include "Monster.h"

Monster::Monster()
{
    setName(" ");
    setTag("monster");
    setAttack(0);
    setCurrentHealth(0);
    setDefense(0);
    setbuff_attack(0);
    setbuff_defense(0);
}

Monster::Monster(string a, int b, int c, int d)
{
    setName(a);
    setTag("monster");
    setAttack(b);
    setCurrentHealth(c);
    setDefense(d);
    setbuff_attack(0);
    setbuff_defense(0);
}

/*int Monster::get_weapon_attack()
{
        return 0;
}*/

bool Monster::is_buff_on_time()
{
        return false;
}

/*int Monster::get_weapon_defense()
{
        return 0;
}*/

/*bool Monster::passive_check()
{
        return false;
}*/

/*void Monster::passive_skill()
{
}*/


bool Monster::is_weapon_on()
{
        return false;
}

/*string Monster::getweaponname()
{
        return string();
}*/



bool Monster::triggerEvent(Object *a)
{
        Player* x = dynamic_cast<Player*>(a);
        GameCharacter* fight = &(x->gamecharacter[0]);
        Item* fight_weapon = (x->weapon[0]);
        int damage;
        int hurt;
        char ch='x';
        x->gamecharacter[0].passive_chance = true;
        cout << "if you want to flee, just get into change character choose." << endl;
        while(1){
            cout<<"knight"<<endl;
            cout<<"HP: "<<x->gamecharacter[0].getCurrentHealth()<<'/'<<x->gamecharacter[0].getMaxHealth()<<endl;
            cout<<"Attack: "<<x->gamecharacter[0].getAttack()<<endl;
            cout<<"Defense: "<< x->gamecharacter[0].getDefense()<<endl;
            if (x->weapon[0] != NULL) {
                cout << "weapon: " << x->weapon[0]->getName() << endl;
            }
            else {
                cout << "No weapon now" << endl;
            }
            cout << "\n---------------------------------------\n";
            if(x->ch["gambler"]){
                cout<<"gambler"<<endl;
                cout<<"HP: "<<x->gamecharacter[1].getCurrentHealth()<<'/'<<x->gamecharacter[1].getMaxHealth()<<endl;
                cout<<"Attack: "<<x->gamecharacter[1].getAttack()<<endl;
                cout<<"Defense: "<< x->gamecharacter[1].getDefense()<<endl;
                if (x->weapon[1] != NULL) {
                    cout << "weapon: " << x->weapon[1]->getName() << endl;
                }
                else {
                    cout << "No weapon now" << endl;
                }
            }
            else{
                cout<<"gambler"<<endl;
                cout<<"No unlock yet."<<endl;
            }
            cout << "\n---------------------------------------\n";
            if(x->ch["8+9"]){
                cout<<"8+9"<<endl;
                cout<<"HP: "<<x->gamecharacter[2].getCurrentHealth()<<'/'<<x->gamecharacter[2].getMaxHealth()<<endl;
                cout<<"Attack: "<<x->gamecharacter[2].getAttack()<<endl;
                cout<<"Defense: "<< x->gamecharacter[2].getDefense()<<endl;
                if (x->weapon[2] != NULL) {
                    cout << "weapon: " << x->weapon[2]->getName() << endl;
                }
                else {
                    cout << "No weapon now" << endl;
                }
            }
            else{
                cout<<"8+9"<<endl;
                cout<<"No unlock yet."<<endl;
            }
            cout << "\n---------------------------------------\n";
            cout<<"Now use: "<<fight->getName()<<endl;
            bool flee = false;
            cout << "\n" << this->getName();
            cout << "HP: " << this->getCurrentHealth()<<endl;
            cout << "Attack: " << this->getAttack() << endl;
            cout << "Defense: " << this->getDefense() << endl;
            ch = 'x';
            while (!(ch == 'Y' || ch == 'N' || ch == 'n' || ch == 'y')) {
                cout << "Do you want to change character? (Y/N)" << endl;
                string tem;
                stringstream ss;
                cin >> tem;
                ss << tem;
                ss >> ch;
                if (ch != 'Y' && ch != 'N' && ch!= 'y' && ch != 'n') {
                    cout << "follow the rules bro ^_^" << endl;
                }
            }
            if(ch == 'Y'||ch=='y') {
                int choose;
                bool complete = false;
                for(;;){//change character.
                    cout<<"Which one you want to choose?: 1:knight, 2: gambler, 3: 8+9 4: flee"<<endl;
                    string tem;
                    stringstream ss;
                    cin >> tem;
                    ss << tem;
                    ss >> choose;
                    switch(choose){
                    case 1:
                        if(x->gamecharacter[0].getCurrentHealth() == 0){
                            cout<<"This character not recover yet..."<<endl;
                        }
                        else{
                            fight = &(x->gamecharacter[0]);
                            fight_weapon = x->weapon[0];
                            complete = true;
                        }
                        break;
                    case 2:
                        if((x->ch["gambler"])){
                            if(x->gamecharacter[1].getCurrentHealth() == 0){
                                cout<<"This character not recover yet..."<<endl;
                            }
                            else{
                                fight = &(x->gamecharacter[1]);
                                fight_weapon = x->weapon[1];
                                complete = true;
                            }
                        }
                        else{
                            cout<<"This character isn't unlocked yet"<<endl;
                        }
                        break;
                    case 3:
                        if((x->ch["8+9"])){
                            if(x->gamecharacter[2].getCurrentHealth() == 0){
                                cout<<"This character not recover yet..."<<endl;
                            }
                            else{
                                fight = &(x->gamecharacter[2]);
                                fight_weapon = x->weapon[2];
                                complete = true;
                            }
                        }
                        else{
                            cout<<"This character isn't unlocked yet"<<endl;
                        }
                        break;
                    case 4:
                        flee = true;
                        complete = true;
                        break;
                    default:
                        cout<<"No this character..."<<endl;
                        break;
                    }
                    if(complete) break;
                }
                if (flee) {
                    setCurrentHealth(getMaxHealth());
                    if (getName() == "Final boss") {
                        setAttack(getAttack());
                    }
                    break;
                }
            }
            if(fight->passive_check()){
                fight->passive_skill();
            }
            if(fight->getCurrentHealth() == 0){
                cout<<"You have to change one...";
                int choose;
                bool complete = false;
                for(;;){//change character.
                    cout<<"Which one you want to choose?: 1:knight, 2: gambler, 3: 8+9"<<endl;
                    string tem;
                    stringstream ss;
                    cin >> tem;
                    ss << tem;
                    ss >> choose;
                    switch(choose){
                    case 1:
                        if(x->gamecharacter[0].getCurrentHealth() == 0){
                            cout<<"This character not recover yet..."<<endl;
                        }
                        else{
                            fight = &(x->gamecharacter[0]);
                            fight_weapon = x->weapon[0];
                            complete = true;
                        }
                        break;
                    case 2:
                        if((x->ch["gambler"])){
                            if(x->gamecharacter[1].getCurrentHealth() == 0){
                                cout<<"This character not recover yet..."<<endl;
                            }
                            else{
                                fight = &(x->gamecharacter[1]);
                                fight_weapon = x->weapon[1];
                                complete = true;
                            }
                        }
                        else{
                            cout<<"This character isn't unlocked yet"<<endl;
                        }
                        break;
                    case 3:
                        if((x->ch["8+9"])){
                            if(x->gamecharacter[2].getCurrentHealth() == 0){
                                cout<<"This character not recover yet..."<<endl;
                            }
                            else{
                                fight = &(x->gamecharacter[2]);
                                fight_weapon = x->weapon[2];
                                complete = true;
                            }
                        }
                        else{
                            cout<<"This character isn't unlocked yet"<<endl;
                        }
                        break;
                    default:
                        cout<<"No this character..."<<endl;
                        break;
                    }
                    if(complete) break;
                }

            }//onstage character is dead
            ch = 'x';
            while (!(ch == 'Y' || ch == 'N' || ch == 'y' || ch == 'n')) {
                cout << "Do you want to use medicine? (Y/N)" << endl;
                string tem;
                stringstream ss;
                cin >> tem;
                ss << tem;
                ss >> ch;
                if (ch != 'Y' && ch != 'N' && ch != 'n' && ch != 'y') {
                    cout << "Follow the rule bro ^_^" << endl;
                }
            }
            if(ch == 'Y'||ch=='y') {
                bool complete = false;
                vector<Item> b = x->getInventory();
                for(;;){
                    bool jud = false;
                    for (int i = 0; i < b.size(); i++) {
                        if (b[i].getTag() == "medicine" && b[i].getamount() > 0) {
                            jud = true;
                            break;
                        }
                    }
                    if (b.size() == 0||!(jud)) {
                        cout << "Your inventory is empty now." << endl;
                        break;
                    }
                    for(int i = 0;i<b.size();i++){
                        if(b[i].getTag() == "medicine"&&b[i].getamount()>0){
                            cout<<b[i].getName()<<' '<<b[i].getamount()<<endl;
                        }
                    }
                    int choose=0;
                    cout<<"Which one you use? please enter the medicine size."<<endl;
                    cout << "3: +3, 5: +5, 7: +7" << endl;
                    string tem;
                    stringstream ss;
                    cin >> tem;
                    ss << tem;
                    ss >> choose;
                    vector<Item>::iterator it;
                    for (it = b.begin(); it->getHealth() != choose && it != b.end(); it++) {
                        if (it->getHealth() != choose && it + 1 == b.end()) {
                            break;
                        }
                    };
                    if(it->getHealth()!=choose){
                        cout<<"You don't have this stuff."<<endl;
                    }
                    else{
                        if (it->getamount() > 0) {
                            int a = fight->getCurrentHealth();
                            int a1 = it->getHealth();
                            fight->setCurrentHealth(a + a1);
                            it->addamount(-1);
                            x->setInventory(b);
                            complete = true;
                            cout << "recover\n";
                        }
                        else {
                            cout << "You don't have this stuff." << endl;
                        }
                    }
                    if(complete) break;
                }
            }
            for(;;){
                x->gamecharacter[0].subbuff_timer();
                x->gamecharacter[1].subbuff_timer();
                x->gamecharacter[2].subbuff_timer();
                if (fight->is_buff_on_time()) {
                    fight->setbuff_attack(0);
                    fight->setbuff_defense(0);
                }
                cout<<"Attack!!\n1: normal attack.\n2: active attack"<<endl;
                bool complete = false;
                int choose;
                string tem;
                stringstream ss;
                cin>>tem;
                ss << tem;
                ss >> choose;
                switch(choose){
                case 1:
                    fight->subtimer();
                    damage = fight->getAttack();
                    if(fight_weapon != NULL){
                        damage += fight_weapon->getAttack();
                    }
                    complete = true;
                    break;
                case 2:
                    if(fight->isontimer()){
                        cout << fight->getName();//debug code
                        damage = fight->active_skill();
                        if(fight_weapon!=NULL){
                            damage+= fight_weapon->getAttack();
                        }
                        complete = true;
                    }
                    else{
                        cout<<"You have to wait for "<<fight->gettimer()<<endl;
                    }
                    break;
                default:
                    cout<<"No this order bro."<<endl;
                    break;
                }
                if(complete) break;
            }
            hurt = takeDamage(damage);
            if (hurt < 0) hurt = 0;
            int blood = getCurrentHealth();
            if(hurt > blood) hurt = blood;
            cout << "Monster turn!!" << endl;
            cout << "Monster get: " << hurt << endl;
            setCurrentHealth(blood - hurt);
            subtimer();
            if(isontimer()){
                damage = active_skill();
            }
            else{
                damage = getAttack();
            }
            hurt = fight->takeDamage(damage);
            if(fight_weapon!=NULL){
                hurt -= fight_weapon->getDefense();
                cout<<fight_weapon->getName()<<" help defense!"<<endl;
            }
            if (hurt < 0) hurt = 0;
            blood = fight->getCurrentHealth();
            if(hurt>blood) hurt = blood;
            fight->setCurrentHealth(blood - hurt);
            cout << "Get damage: " << hurt << endl;
            if (fight->passive_check() && fight->getName()=="knight") {
                fight->passive_skill();
            }
            if (fight->getName() == "gambler") {
                fight->setbuff_defense(0);
            }
            if((x->gamecharacter[0].getCurrentHealth() == 0) && (x->ch["gambler"] == false || x->gamecharacter[1].getCurrentHealth() == 0) && (x->ch["8+9"] == false || x->gamecharacter[2].getCurrentHealth() == 0)){
                break;//maybe return??
            }
            if(getCurrentHealth() == 0){
                cout<<"you win... this monster."<<endl;
                x->getCurrentRoom()->popObject(this);
                break;
            }
            if(flee) break;
        }
        return true;
}

shield::shield():Monster("shield.", 4, 15, 2)
{
    setTag("monster");
        setbuff_attack(0);
        setbuff_defense(0);
        setMaxHealth(15);
}

int shield::active_skill()
{
        settimer(3);
        cout << "Monster skill:  shield attack: make attack + defense damage" << endl;
        return getAttack() + getDefense();
}

soldier::soldier():Monster("soldier.", 4, 10, 1)
{
    setTag("monster");
        setbuff_attack(0);
        setbuff_defense(0);
        setMaxHealth(10);
}

int soldier::active_skill()
{
        settimer(5);
        return getAttack() + 1;
}

boss::boss():Monster("Boss", 6, 20, 3)
{
    setTag("monster");
        setbuff_attack(0);
        setbuff_defense(0);
        setMaxHealth(20);
}

int boss::active_skill()
{
        settimer(5);
        cout << "Monster skill:   heal +3health" << endl;
        int a = getCurrentHealth();
        setCurrentHealth(a+3);
        return getAttack();
}

final_boss::final_boss():Monster("Final boss", 6, 30, 4)
{
    setTag("monster");
        setbuff_attack(0);
        setbuff_defense(0);
        setMaxHealth(30);
}

int final_boss::active_skill()
{
        settimer(3);
        cout << "Final boss skill:   increase attack: +2 attack forever" << endl;
        int a = getAttack();
        setAttack(a+2);
        return getAttack();
}
