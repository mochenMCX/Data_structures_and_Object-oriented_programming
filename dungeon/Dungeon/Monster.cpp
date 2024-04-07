#include "Monster.h"

Monster::Monster(string a, int b, int c, int d)
{
    setName(a);
        setAttack(b);
        setCurrentHealth(c);
        setDefense(d);
}

int Monster::get_weapon_attack()
{
        return 0;
}

bool Monster::is_buff_on_time()
{
        return false;
}

int Monster::get_weapon_defense()
{
        return 0;
}

bool Monster::passive_check()
{
        return false;
}

void Monster::passive_skill()
{
}

void Monster::put_on_weapon(Item a)
{
}

bool Monster::is_weapon_on()
{
        return false;
}

string Monster::getweaponname()
{
        return string();
}

void Monster::turn_passive_chance()
{
}

bool Monster::triggerEvent(Object *a)
{
        Player* x = dynamic_cast<Player*>(a);
        GameCharacter* fight = &(x->gamecharacter[0]);
        int damage;
        int hurt;
        char ch;
        x->gamecharacter[0].turn_passive_chance();
        while(1){
            cout<<"knight"<<endl;
            cout<<"HP: "<<x->gamecharacter[0].getCurrentHealth()<<'/'<<x->gamecharacter[0].getMaxHealth()<<endl;
            cout<<"Attack: "<<x->gamecharacter[0].getAttack()<<endl;
            cout<<"Defense: "<< x->gamecharacter[0].getAttack()<<endl;
            cout<<"weapon: "<<x->gamecharacter[0].getweaponname()<<endl;
            if(x->ch["gambler"]){
                cout<<"gambler"<<endl;
                cout<<"HP: "<<x->gamecharacter[1].getCurrentHealth()<<'/'<<x->gamecharacter[1].getMaxHealth()<<endl;
                cout<<"Attack: "<<x->gamecharacter[1].getAttack()<<endl;
                cout<<"Defense: "<< x->gamecharacter[1].getAttack()<<endl;
                cout<<"weapon: "<<x->gamecharacter[1].getweaponname()<<endl;
            }
            else{
                cout<<"gambler"<<endl;
                cout<<"No unlock yet."<<endl;
            }
            if(x->ch["8+9"]){
                cout<<"8+9"<<endl;
                cout<<"HP: "<<x->gamecharacter[2].getCurrentHealth()<<'/'<<x->gamecharacter[2].getMaxHealth()<<endl;
                cout<<"Attack: "<<x->gamecharacter[2].getAttack()<<endl;
                cout<<"Defense: "<< x->gamecharacter[2].getAttack()<<endl;
                cout<<"weapon: "<<x->gamecharacter[2].getweaponname()<<endl;
            }
            else{
                cout<<"8+9"<<endl;
                cout<<"No unlock yet."<<endl;
            }
            cout<<"Now use: "<<fight->getName()<<endl;
            bool flee = false;
            cout<<"Do you want to change character? (Y/N)"<<endl;
            cin >> ch;
            if(ch == 'Y'){
                int choose;
                bool complete = false;
                for(;;){//change character.
                    cout<<"Which one you want to choose?: 0:knight, 1: gambler, 2: 8+9 3: flee"<<endl;
                    cin>>choose;
                    switch(choose){
                    case 0:
                        if(x->gamecharacter[0].getCurrentHealth() == 0){
                            cout<<"This character not recover yet..."<<endl;
                        }
                        else{
                            fight = &(x->gamecharacter[0]);
                            complete = true;
                        }
                        break;
                    case 1:
                        if((x->ch["gambler"])){
                            if(x->gamecharacter[1].getCurrentHealth() == 0){
                                cout<<"This character not recover yet..."<<endl;
                            }
                            else{
                                fight = &(x->gamecharacter[1]);
                                complete = true;
                            }
                        }
                        else{
                            cout<<"This character isn't unlocked yet"<<endl;
                        }
                        break;
                    case 2:
                        if((x->ch["8+9"])){
                            if(x->gamecharacter[2].getCurrentHealth() == 0){
                                cout<<"This character not recover yet..."<<endl;
                            }
                            else{
                                fight = &(x->gamecharacter[2]);
                                complete = true;
                            }
                        }
                        else{
                            cout<<"This character isn't unlocked yet"<<endl;
                        }
                        break;
                    case 3:
                        flee = true;
                        complete = true;
                        break;
                    default:
                        cout<<"No this character..."<<endl;
                        break;
                    }
                    if(complete) break;
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
                    cout<<"Which one you want to choose?: 0:knight, 1: gambler, 2: 8+9"<<endl;
                    cin>>choose;
                    switch(choose){
                    case 0:
                        if(x->gamecharacter[0].getCurrentHealth() == 0){
                            cout<<"This character not recover yet..."<<endl;
                        }
                        else{
                            fight = &(x->gamecharacter[0]);
                            complete = true;
                        }
                        break;
                    case 1:
                        if((x->ch["gambler"])){
                            if(x->gamecharacter[1].getCurrentHealth() == 0){
                                cout<<"This character not recover yet..."<<endl;
                            }
                            else{
                                fight = &(x->gamecharacter[1]);
                                complete = true;
                            }
                        }
                        else{
                            cout<<"This character isn't unlocked yet"<<endl;
                        }
                        break;
                    case 2:
                        if((x->ch["8+9"])){
                            if(x->gamecharacter[2].getCurrentHealth() == 0){
                                cout<<"This character not recover yet..."<<endl;
                            }
                            else{
                                fight = &(x->gamecharacter[2]);
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
            cout<<"Do you want to use medicine? (Y/N)"<<endl;
            cin >> ch;
            if(ch == 'Y'){
                bool complete = false;
                vector<Item> b = x->getInventory();
                for(;;){
                    for(int i = 0;i<b.size();i++){
                        if(b[i].getTag() == "medicine"){
                            cout<<b[i].getName()<<' '<<b[i].getamount()<<endl;
                        }
                    }
                    string choose;
                    cout<<"Which one you use? please enter the name."<<endl;
                    cin >> choose;
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getName()!= choose;it++);
                    if(it == b.end()||it->getamount() <= 0||it->getTag() != "medicine"){
                        cout<<"You don't have this stuff."<<endl;
                    }
                    else{
                        int a = fight->getCurrentHealth();
                        int a1 = it->getHealth();
                        fight->setCurrentHealth(a+a1);
                        it->addamount(-1);
                        x->setInventory(b);
                        complete = true;
                    }
                    if(complete) break;
                }
            }
            x->gamecharacter[0].subtimer();
            x->gamecharacter[1].subtimer();
            x->gamecharacter[2].subtimer();
            if(fight ->is_buff_on_time()){
                fight->setbuff_attack(0);
                fight->setbuff_defense(0);
            }
            for(;;){
                cout<<"Attack!! 0: normal attack. 1: active attack"<<endl;
                bool complete = false;
                int choose;
                cin>>choose;
                switch(choose){
                case 0:
                    damage = fight->getAttack();
                    if(fight->is_weapon_on()){
                        damage+= fight->get_weapon_attack();
                    }
                    complete = true;
                    break;
                case 1:
                    if(fight->isontimer()){
                        damage = fight->active_skill();
                        if(fight->is_weapon_on()){
                            damage+= fight->get_weapon_attack();
                        }
                        complete = true;
                    }
                    else{
                        cout<<"You have to wait for"<<fight->gettimer()<<endl;
                    }
                    break;
                dafault:
                    cout<<"No this order bro."<<endl;
                    break;
                }
                if(complete) break;
            }
            hurt = takeDamage(damage);
            int blood = getCurrentHealth();
            if(hurt > blood) hurt = blood;
            setCurrentHealth(blood - hurt);
            subtimer();
            if(isontimer()){
                damage = active_skill();
            }
            else{
                damage = getAttack();
            }
            hurt = fight->takeDamage(damage);
            if(fight->get_weapon_defense() != 0){
                hurt -= fight->get_weapon_defense();
                cout<<fight->getweaponname()<<" help defense!"<<endl;
            }
            int blood = fight->getCurrentHealth();
            if(hurt>blood) hurt = blood;
            setCurrentHealth(blood - hurt);
            if(x->gamecharacter[0].getCurrentHealth() == 0 && x->gamecharacter[1].getCurrentHealth() == 0 && x->gamecharacter[2].getCurrentHealth() == 0){
                break;//maybe return??
            }
            if(getCurrentHealth == 0){
                cout<<"you win... this monster."<<endl;
                x->getCurrentRoom()->popObject(this);
                break;
            }
            if(flee) break;
        }
        return true;
}

shield::shield():Monster("shield.", 5, 15, 3)
{
    setTag("monster");
        setbuff_attack(0);
        setbuff_defense(0);
}

int shield::active_skill()
{
        settimer(3);
        return getAttack() + getDefense();
}

soldier::soldier():Monster("soldier.", 4, 8, 2)
{
    setTag("monster");
        setbuff_attack(0);
        setbuff_defense(0);
}

int soldier::active_skill()
{
        settimer(5);
        return getAttack() + 1;
}

boss::boss():Monster("Boss", 6, 20, 2)
{
    setTag("monster");
        setbuff_attack(0);
        setbuff_defense(0);
}

int boss::active_skill()
{
        settimer(3);
        int a = getCurrentHealth();
        setCurrentHealth(a+3);
        return getAttack();
}

final_boss::final_boss():Monster("Final boss", 6, 30, 4)
{
    setTag("monster");
        setbuff_attack(0);
        setbuff_defense(0);
}

int final_boss::active_skill()
{
        settimer(3);
        int a = getAttack();
        setAttack(a+2);
        return getAttack();
}
