#include "Item.h"

Item::Item()
{
}

Item::Item(string a, string b, int c, int d, int e)
{
    health = c;
    attack = d;
    defense = e;
}

bool Item::triggerEvent(Object* a)
{
    return false;
}

int Item::getHealth()
{
    return health;
}

int Item::getAttack()
{
    return attack;
}

int Item::getDefense()
{
    return defense;
}

void Item::setHealth(int a)
{
    health = a;
}

void Item::setdollar(int a)
{
    dollar = a;
}

int Item::getdollar()
{
    return dollar;
}

void Item::setAttack(int a)
{
    attack = a;
}

void Item::setDefense(int a)
{
    defense = a;
}

void Item::addamount(int a)
{
    amount += a;
}

void Item::setamount(int a)
{
    amount = a;
}

int Item::getamount()
{
    return amount;
}

med::med(int a)
{
    setTag("medicine");
        setHealth(a);
        setamount(1);
        stringstream ss;
        ss << "medicine for "<<a;
        string str;
        ss >> str;
        setName(str);
        if(a == 3) setdollar(30);
        if(a == 5) setdollar(40);
        if(a == 7) setdollar(50);
}

bool med::triggerEvent(Object *a)
{
        Player* x = dynamic_cast<Player*>(a);
        vector<Item>::iterator it;
        vector<Item> b = x->getInventory();
        if(getName() == "medicine for 3"){
            for(it = b.begin();it->getName() != "medicine for 3";it++){};
            if(it == b.end()){
                x->addItem(med(3));
            }
            else{
                it->addamount(1);
                x->setInventory(b);
            }
        }
        else if(getName() == "medicine for 5"){
            for(it = b.begin();it->getName() != "medicine for 5";it++){};
            if(it == b.end()){
                x->addItem(med(5));
            }
            else{
                int am = getamount();
                it->addamount(am);
                x->setInventory(b);
            }
        }
        else if(getName() == "medicine for 7"){
            for(it = b.begin();it->getName() != "medicine for 7";it++){};
            if(it == b.end()){
                x->addItem(med(7));
            }
            else{
                it->addamount(1);
                x->setInventory(b);
            }
        }
        return true;
}

key::key()
{
    setTag("key");
        setamount(1);
}

bool key::triggerEvent(Object *a)
{
        Player* x = dynamic_cast<Player*>(a);
        x->addItem(key());
        return true;
}

sword::sword(int a)
{
    setAttack(a);
        if (a == 1) {
            setName("normal sword");
            setTag("sword");
            setDefense(0);
            setHealth(0);
            setdollar(60);
        }
        if (a == 3) {
            setName("good sword");
            setTag("sword");
            setDefense(1);
            setHealth(0);
            setdollar(100);
        }
        if (a == 5) {
            setName("GOOD GOOD sword");
            setTag("sword");
            setDefense(4);
            setHealth(0);
            setdollar(200);
        }
}

bool sword::triggerEvent(Object *a)
{
        Player* x = dynamic_cast<Player*>(a);
        Item* tem = this;
        x->gamecharacter[0].put_on_weapon(*tem);
        return true;
}

dice::dice(int a)
{
    setAttack(a);
        setTag("dice");
        if(a == 1){
            setName("normal dice");
            setDefense(0);
            setHealth(0);
            setdollar(50);
        }
        if(a == 2){
            setName("good dice");
            setDefense(2);
            setHealth(0);
            setdollar(80);
        }
        if(a == 3){
            setName("glorious dice");
            setDefense(4);
            setHealth(0);
            setdollar(150);
        }
}

bool dice::triggerEvent(Object *a)
{
        Player* x = dynamic_cast<Player*>(a);
        Item* tem = this;
        x->gamecharacter[1].put_on_weapon(*tem);
        return true;
}

winebottle::winebottle(int a)
{
    setAttack(a);
        setTag("winebottle");
        if(a == 1){
            setName("Taiwan beer");
            setDefense(0);
            setHealth(0);
            setdollar(55);
        }
        if(a == 2){
            setName("Baiwei beer");
            setDefense(2);
            setHealth(0);
            setdollar(90);
        }
        if(a == 4){
            setName("Spirytus Rektyfikowany");
            setDefense(4);
            setHealth(0);
            setdollar(160);
        }
}

bool winebottle::triggerEvent(Object *a)
{
        Player* x = dynamic_cast<Player*>(a);
        Item* tem = this;
        x->gamecharacter[2].put_on_weapon(*tem);
        return true;
}

money::money(int a)
{
    setamount(a);
        setName("money");
        setTag("money");
}

bool money::triggerEvent(Object *a)
{
        Player* x = dynamic_cast<Player*>(a);
        vector<Item>::iterator it;
        vector<Item> b = x->getInventory();
        for(it = b.begin();it->getName() != "money";it++){};
            if(it == b.end()){
                Item* tem = this;
                x->addItem(*tem);
            }
            else{
                int am = this->getamount();
                it->addamount(am);
                x->setInventory(b);
            }
        return true;
}

character_frag::character_frag(int a)
{
    setamount(a);
        setTag("frag");
        setName("character fragment");
}

bool character_frag::triggerEvent(Object *a)
{
        Player* x = dynamic_cast<Player*>(a);
        vector<Item>::iterator it;
        vector<Item> b = x->getInventory();
        for(it = b.begin();it->getName() != "character fragment";it++){};
            if(it == b.end()){
                Item* tem = this;
                x->addItem(*tem);
            }
            else{
                int am = this->getamount();
                it->addamount(am);
                x->setInventory(b);
            }
        return true;
}
