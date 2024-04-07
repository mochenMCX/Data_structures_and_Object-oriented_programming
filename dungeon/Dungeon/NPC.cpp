#include "NPC.h"


void NPC::listCommodity()
{
    for (int i = 0; i < commodity.size(); i++) {
            cout << commodity[i].getName() << ' ' << commodity[i].getdollar()<<endl;
        }
}

int NPC::get_weapon_attack()
{
        return 0;
}

bool NPC::is_buff_on_time()
{
        return false;
}

int NPC::get_weapon_defense()
{
        return 0;
}

bool NPC::passive_check()
{
        return false;
}

void NPC::passive_skill()
{
}

int NPC::active_skill()
{
        return 0;
}

bool NPC::is_weapon_on()
{
        return false;
}

void NPC::put_on_weapon(Item a)
{
}

void NPC::turn_passive_chance()
{
}

string NPC::getweaponname()
{
        return string();
}

void NPC::setScript(string a)
{
    script = a;
}

void NPC::setCommodity(vector<Item> a)
{
    for (int i = 0; i < a.size(); i++) {
            commodity.push_back(a[i]);
        }
}

string NPC::getScript()
{
        return script;
}

vector<Item> NPC::getCommodity()
{
        return commodity;
}

merchant_med::merchant_med()
{
    setName("Charlatan");
        setScript("Maybe I can treat you, maybe.");
        setTag("NPC");
        vector<Item> a = {med(3), med(5), med(7)};
        setCommodity(a);
}

bool merchant_med::triggerEvent(Object *a)
{
       Player* x = dynamic_cast<Player*>(a);
        cout<<getScript()<<endl;
        listCommodity();
        bool complete = false;
        int num, spend;
        vector<Item> b = x->getInventory();
        for(;;){
            cout<<"Which one you want to buy?: "<<endl;
            cout<<"1: +3 HP medicine.(30 for one)"<<endl;
            cout<<"2: +5 HP medicine. (40 for one)"<<endl;
            cout<<"3: +7 HP medicine. (50 for one)"<<endl;
            int ch;
            cin >> ch;
            switch(ch){
            case 1:
                cout<<"amount?: "<<endl;
                cin>>num;
                spend = num * med(3).getdollar();
                if(x->getmoney()<spend){
                    cout<<"OH, your money isn't enough..."<<endl;
                }
                else{
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="money";++it);
                    it->addamount((spend * -1));
                    med a = med(3); a.setamount(num);
                    a.triggerEvent(x);
                    cout<<"You buy medicine for"<<num<<endl;
                    cout<<"You have money: "<<it->getamount()<<endl;
                    complete = true;
                }
                break;
            case 2:
                cout<<"amount?: "<<endl;
                cin>>num;
                spend = num * med(5).getdollar();
                if(x->getmoney()<spend){
                    cout<<"OH, your money isn't enough..."<<endl;
                }
                else{
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="money";++it);
                    it->addamount((spend * -1));
                    med a = med(5); a.setamount(num);
                    a.triggerEvent(x);
                    cout<<"You buy medicine for"<<num<<endl;
                    cout<<"You have money: "<<it->getamount()<<endl;
                    complete = true;
                }
                break;
            case 3:
                cout<<"amount?: "<<endl;
                cin>>num;
                spend = num * med(7).getdollar();
                if(x->getmoney()<spend){
                    cout<<"OH, your money isn't enough..."<<endl;
                }
                else{
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="money";++it);
                    it->addamount((spend * -1));
                    med a = med(7); a.setamount(num);
                    a.triggerEvent(x);
                    cout<<"You buy medicine for"<<num<<endl;
                    cout<<"You have money: "<<it->getamount()<<endl;
                    complete = true;
                }
                break;
            default:
                cout<<"No this order~~"<<endl;
                break;
            if(complete) break;
        }
        }
        return true;
}

merchant_sword::merchant_sword()
{
    setName("blacksmith");
        setScript("go go fight!!");
        setTag("NPC");
        vector<Item> a = {sword(1), sword(3), sword(5)};
        setCommodity(a);
}

bool merchant_sword::triggerEvent(Object *a)
{
        Player* x = dynamic_cast<Player*>(a);
        cout<<getScript()<<endl;
        listCommodity();
        bool complete = false;
        int num, spend;
        vector<Item> b = x->getInventory();
        for(;;){
            cout<<"Which one you want? "<<endl;
            cout<<"1: normal sword. spend: 60"<<endl;
            cout<<"2: good sword. spend: 100"<<endl;
            cout<<"3: GOOD GOOD sword. spend 200"<<endl;
            cout<<"NOTE: don't buy the weapon is lower level than you have right now, unless you want to increase the difficulty."<<endl;
            cout<<"you weapon: "<<x->gamecharacter[0].getweaponname()<<endl;
            int ch;
            cin>>ch;
            switch(ch){
            case 1:
                spend = sword(1).getdollar();
                if(x->getmoney()<spend){
                    cout<<"Your money is not enough..."<<endl;
                }
                else{
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="money";++it);
                    it->addamount((spend * -1));
                    sword a = sword(1);
                    a.triggerEvent(x);
                    cout<<"Thanks for buying~~"<<endl;
                    complete = true;
                }
                break;
            case 2:
                spend = sword(3).getdollar();
                if(x->getmoney()<spend){
                    cout<<"Your money is not enough..."<<endl;
                }
                else{
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="money";++it);
                    it->addamount((spend * -1));
                    sword a = sword(3);
                    a.triggerEvent(x);
                    cout<<"Thanks for buying~~"<<endl;
                    complete = true;
                }
                break;
            case 3:
                spend = sword(5).getdollar();
                if(x->getmoney()<spend){
                    cout<<"Your money is not enough..."<<endl;
                }
                else{
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="money";++it);
                    it->addamount((spend * -1));
                    sword a = sword(5);
                    a.triggerEvent(x);
                    cout<<"Thanks for buying~~"<<endl;
                    complete = true;
                }
                break;
            default:
                cout<<"Come on~~"<<endl;
                break;
            }
            if(complete) break;
        }
        return true;
}

merchant_dice::merchant_dice()
{
    setName("profiteer");
        setScript("Money~~");
        setTag("NPC");
        vector<Item> a = {dice(1), dice(2), dice(3)};
        setCommodity(a);
}

bool merchant_dice::triggerEvent(Object *a)
{
       Player* x = dynamic_cast<Player*>(a);
        cout<<getScript()<<endl;
        listCommodity();
        bool complete = false;
        int num, spend;
        vector<Item> b = x->getInventory();
        for(;;){
            cout<<"Which one you want? "<<endl;
            cout<<"1: normal dice. spend: 50"<<endl;
            cout<<"2: good dice. spend: 80"<<endl;
            cout<<"3: glorious dice. spend 150"<<endl;
            cout<<"4: unlock the new character. 4 fragment."<<endl;
            cout<<"NOTE: don't buy the weapon is lower level than you have right now, unless you want to increase the difficulty."<<endl;
            cout<<"you weapon: "<<x->gamecharacter[1].getweaponname()<<endl;
            int ch;
            cin>>ch;
            switch(ch){
            case 1:
                spend = dice(1).getdollar();
                if(x->getmoney()<spend){
                    cout<<"Your money is not enough..."<<endl;
                }
                else{
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="money";++it);
                    it->addamount((spend * -1));
                    dice a = dice(1);
                    a.triggerEvent(x);
                    cout<<"Thanks for buying~~"<<endl;
                    complete = true;
                }
                break;
            case 2:
                spend = dice(2).getdollar();
                if(x->getmoney()<spend){
                    cout<<"Your money is not enough..."<<endl;
                }
                else{
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="money";++it);
                    it->addamount((spend * -1));
                    dice a = dice(2);
                    a.triggerEvent(x);
                    cout<<"Thanks for buying~~"<<endl;
                    complete = true;
                }
                break;
            case 3:
                spend = dice(3).getdollar();
                if(x->getmoney()<spend){
                    cout<<"Your money is not enough..."<<endl;
                }
                else{
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="money";++it);
                    it->addamount((spend * -1));
                    dice a = dice(3);
                    a.triggerEvent(x);
                    cout<<"Thanks for buying~~"<<endl;
                    complete = true;
                }
                break;
            case 4:
                if(x->ch["gambler"] == false){
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="frag"; it++);
                    if(it == b.end()||it->getamount()<4){
                        cout<<"Your character fragment isn't enough."<<endl;
                    }
                    else{
                        it->addamount((-4));
                        x->ch["gambler"] = true;
                        cout<<"Unlock the character!"<<endl;
                        complete = true;
                    }
                }
                else{
                    cout<<"Already unlock"<<endl;
                }
                break;
            default:
                cout<<"Come on~~"<<endl;
                break;
            }
            x->setInventory(b);
            if(complete) break;
        }
        return true;
}

merchant_winebottle::merchant_winebottle()
{
    setName("drunkard");
        setScript("I'm not groggy");
        setTag("NPC");
        vector<Item> a ={winebottle(1), winebottle(2), winebottle(4)};
        setCommodity(a);
}

bool merchant_winebottle::triggerEvent(Object *a)
{
        Player* x = dynamic_cast<Player*>(a);
        cout<<getScript()<<endl;
        listCommodity();
        bool complete = false;
        int num, spend;
        vector<Item> b = x->getInventory();
        for(;;){
            cout<<"Which one you want? "<<endl;
            cout<<"1: Taiwan beer. spend: 55"<<endl;
            cout<<"2: Baiwei beer. spend: 90"<<endl;
            cout<<"3: Spirytus Rektyfikowany. spend 160"<<endl;
            cout<<"4: Unlock the new character. 4 fragment."<<endl;
            cout<<"NOTE: don't buy the weapon is lower level than you have right now, unless you want to increase the difficulty."<<endl;
            cout<<"you weapon: "<<x->gamecharacter[2].getweaponname()<<endl;
            int ch;
            cin>>ch;
            switch(ch){
            case 1:
                spend = winebottle(1).getdollar();
                if(x->getmoney()<spend){
                    cout<<"Your money is not enough..."<<endl;
                }
                else{
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="money";++it);
                    it->addamount((spend * -1));
                    winebottle a = winebottle(1);
                    a.triggerEvent(x);
                    cout<<"Thanks for buying~~"<<endl;
                    complete = true;
                }
                break;
            case 2:
                spend = winebottle(2).getdollar();
                if(x->getmoney()<spend){
                    cout<<"Your money is not enough..."<<endl;
                }
                else{
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="money";++it);
                    it->addamount((spend * -1));
                    winebottle a = winebottle(2);
                    a.triggerEvent(x);
                    cout<<"Thanks for buying~~"<<endl;
                    complete = true;
                }
                break;
            case 3:
                spend = winebottle(4).getdollar();
                if(x->getmoney()<spend){
                    cout<<"Your money is not enough..."<<endl;
                }
                else{
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="money";++it);
                    it->addamount((spend * -1));
                    winebottle a = winebottle(4);
                    a.triggerEvent(x);
                    cout<<"Thanks for buying~~"<<endl;
                    complete = true;
                }
                break;
            case 4:
                if(x->ch["8+9"] == false){
                    vector<Item>::iterator it;
                    for(it = b.begin();it->getTag()!="frag"; it++);
                    if(it == b.end()||it->getamount()<4){
                        cout<<"Your character fragment isn't enough."<<endl;
                    }
                    else{
                        it->addamount((-4));
                        x->ch["8+9"] = true;
                        cout<<"Unlock the character!"<<endl;
                        complete = true;
                    }
                }
                else{
                    cout<<"Already unlock"<<endl;
                }
                break;
            default:
                cout<<"Come on~~"<<endl;
                break;
            }
            if(complete) break;
        }
        return true;
}
