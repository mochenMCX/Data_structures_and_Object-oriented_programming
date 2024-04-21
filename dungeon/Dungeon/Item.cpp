#include "Item.h"
#include "GameCharacter.h"
#include "Player.h"


Item::Item()
{
}

// Item::Item(string a, string b, int c, int d, int e)
// {
//     health = c;
//     attack = d;
//     defense = e;
// }

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
        ss << a;
        string tem;
        ss >> tem;
        string str = "medicine for +" + tem;
        setName(str);
        if(a == 3) setdollar(30);
        if(a == 5) setdollar(40);
        if(a == 7) setdollar(50);
}

bool med::triggerEvent(Object *a)//have amount problem
{
        Player* x = dynamic_cast<Player*>(a);
        vector<Item>::iterator it;
        vector<Item> b = x->getInventory();
        if(getName() == "medicine for +3"){
            if (b.size() == 0) {
                med m = med(3);
                x->addItem(m);
                return true;
            }
            for(it = b.begin();it->getName() != "medicine for +3" && it!=b.end();it++){
                if (it + 1 == b.end() && it->getName() != "medicine for +3") {
                    med m = med(3);
                    x->addItem(m);
                    return true;
                }
                else if (it + 1 == b.end()) {
                    break;
                }
            };
            it->addamount(this->getamount());
            x->setInventory(b);
        }
        else if(getName() == "medicine for +5"){
            if (b.size() == 0) {
                med m = med(5);
                x->addItem(m);
                return true;
            }
            for(it = b.begin();it->getName() != "medicine for +5" && it!=b.end();it++){
                if (it + 1 == b.end() && it->getName() != "medicine for +5") {
                    med m = med(5);
                    x->addItem(m);
                    return true;
                }
                else if (it + 1 == b.end()) {
                    break;
                }
            };
            int am = getamount();
            it->addamount(am);
            x->setInventory(b);
        }
        else if(getName() == "medicine for +7"){
            if (b.size() == 0) {
                med m = med(7);
                x->addItem(m);
                return true;
            }
            for(it = b.begin();it->getName() != "medicine for +7" &&it!=b.end();it++){
                if (it + 1 == b.end() && it->getName() != "medicine for +7") {
                    med m = med(7);
                    x->addItem(m);
                    return true;
                }
                else if (it + 1 == b.end()) {
                    break;
                }
            };
            it->addamount(this->getamount());
            x->setInventory(b);
        }
        return true;
}

key::key()
{
    setName("key");
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
            setDefense(1);
            setHealth(0);
            setdollar(60);
        }
        if (a == 3) {
            setName("good sword");
            setTag("sword");
            setDefense(2);
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

/*bool sword::triggerEvent(Object *a)
{
    Player* x = dynamic_cast<Player*>(a);
    return true;
}*/

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
        if (b.size() == 0) {
            int num = this->getamount();
            money mon = money(num);
            x->addItem(mon);
            return true;
        }
        for(it = b.begin();it->getName() != "money" && it!=b.end();it++){
            if (it + 1 == b.end() && it->getName() != "money") {
                int num = this->getamount();
                money mon = money(num);
                x->addItem(mon);
                return true;
            }
            else if (it + 1 == b.end()) {
                break;
            }
        };
        int am = this->getamount();
        it->addamount(am);
        x->setInventory(b);
            /*if (it == b.end()) {
                int num = this->getamount();
                money mon = money(num);
                x->addItem(mon);
            }
            else{
                int am = this->getamount();
                it->addamount(am);
                x->setInventory(b);
            }*/
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
        if (b.size() == 0) {
            int num = this->getamount();
            Item frag = character_frag(num);
            x->addItem(frag);
            //Item* tem = this;
           // x->addItem(*tem);
            return true;
        }
        for (it = b.begin(); it->getName() != "character fragment" && it != b.end(); it++) {
            if (it + 1 == b.end()&&it->getName()!="character fragment") {
                int num = this->getamount();
                Item frag = character_frag(num);
                x->addItem(frag);
                return true;
            }
            else if (it + 1 == b.end()) {
                break;
            }
        };//have bug!!
        int am = this->getamount();
        it->addamount(am);
        x->setInventory(b);
           /* if (it + 1 == b.end()) {
                int num = this->getamount();
                Item frag = character_frag(num);
                x->addItem(frag);
                //Item* tem = this;
                //x->addItem(*tem);
            }
            else{
                int am = this->getamount();
                it->addamount(am);
                x->setInventory(b);
            }*/
        return true;
}
