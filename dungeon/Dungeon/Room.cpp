#include "Room.h"

Room::Room()
{
    //index = 0;
    isExit = true;
    upstair = NULL;
    downRoom = NULL;
    downstair = NULL;
    leftRoom = NULL;
    rightRoom = NULL;
    upRoom = NULL;
}
Room::Room(int b)
{
    index = b;
        isExit = true;
        upstair = NULL;
        downRoom = NULL;
        downstair= NULL;
        leftRoom = NULL;
        rightRoom = NULL;
        upRoom = NULL;
}

bool Room::popObject(Object *a)
{
         vector<Object*>::iterator it;
        for(it = objects.begin();*it != a;it++);
        objects.erase(it);
        return true;
}

void Room::addItem(Object* a)
{
    objects.push_back(a);
}

bool Room::getlock()
{
        return lock;
}

void Room::unlock()
{
    lock = true;
}

void Room::setupstairs(Room *a)
{
    upstair = a;
}

void Room::setdownstairs(Room *a)
{
    downstair = a;
}

void Room::setUpRoom(Room *a)
{
    this->upRoom = a;
}

void Room::setDownRoom(Room *a)
{
    this->downRoom =a;
}

void Room::setLeftRoom(Room *a)
{
    this->leftRoom = a;
}

void Room::setRightRoom(Room *a)
{
    this->rightRoom = a;
}

void Room::setIsExit(bool a)
{
    isExit = a;
}

void Room::setIndex(int a)
{
    index = a;
}

void Room::setObjects(vector<Object *> a)
{
    if (this->objects.size() > a.size()) {
        for (int i = 0; i < a.size(); i++) {
            objects[i] = a[i];
        }
    }
    else if (this->objects.size() == 0) {
        for (int i = 0; i < a.size(); i++) {
            this->objects.push_back(a[i]);
        }
    }
    else {
        for (int i = 0; i < this -> objects.size(); i++) {
            objects[i] = a[i];
        }
    }
}

bool Room::getIsExit()
{
        return isExit;
}

int Room::getIndex()
{
        return this -> index;
}

vector<Object *> Room::getObjects()
{
       return this->objects;
}

Room *Room::getUpRoom()
{
       return this ->upRoom;
}

Room *Room::getDownRoom()
{
       return this->downRoom;
}

Room *Room::getLeftRoom()
{
       return this->leftRoom;
}

Room *Room::getRightRoom()
{
       return this->rightRoom;
}

Room *Room::getupstairs()
{
       return this->upstair;
}

Room *Room::getdownstairs()
{
       return this->downstair;
}

bool Room::islock(Player &a)//have problem
{
       vector<Item> invent;
        invent = a.getInventory();
        vector<Item>::iterator it;
        if (invent.size() == 0) {
            return false;
        }
        for (it = invent.begin(); it->getTag() != "key" && it != invent.end(); ++it) {
            if (it->getTag() != "key" && it + 1 == invent.end()) {
                return false;
            }
            if (it->getTag() == "key") {
                
                unlock();
                return true;
            }
        };
        if(it == invent.end()) return false;
        else{
            key k = key();
            a.eraseItem(k);
            unlock();
            /*vector<Item>b = a.getInventory();
            vector<Item>::iterator it;
            for (it = b.begin(); it != b.end(); it++) {
                if (it + 1 == b.end() || it->getName() == "key") {
                    b.erase(it);
                    break;
                }
            }
            a.setInventory(b);*/
            return true;
        }
}

restaurant::restaurant(int a)//soldier soldier shield
{
    setIndex(a);
    vector<Object*> b;
    Object* tem = new soldier;
    b.push_back(tem);
    tem = new soldier;
    b.push_back(tem);
    tem = new money(30);
    b.push_back(tem);
    tem = new med(3);
    b.push_back(tem);
    setObjects(b);
}

bathroom::bathroom(int a)//soldier shield shield
{
    setIndex(a);
    vector<Object*> b;
    Object* tem = new soldier;
    b.push_back(tem);
    tem = new shield;
    b.push_back(tem);    
    tem = new money(30);
    b.push_back(tem);
    tem = new med(5);
    b.push_back(tem);
    setObjects(b);
}

corridor::corridor(int a)
{
    setIndex(a);
    vector<Object*> b;
    Object* tem = new money(5);
    b.push_back(tem);
    setObjects(b);
}

center::center(int a)//soldier soldier boss or final boss
{
    setIndex(a);
    vector<Object*> b;
    Object* tem = new boss;
    b.push_back(tem);
    if(a == 34){
        tem = new final_boss;
         b.push_back(tem);
    }
    tem = new med(7);
    b.push_back(tem);
    tem = new med(5);
    b.push_back(tem);
    tem =new money(50);
    b.push_back(tem);
    setObjects(b);
}

store::store(int a, string c)
{
    setIndex(a);
    vector<Object* > b;
        if(c == "sword"){
            Object* tem = new merchant_sword;
            b.push_back(tem);
        }
        else if(c == "dice"){
            Object* tem = new merchant_dice;
            b.push_back(tem);
        }
        else if(c == "winebottle"){
            Object* tem = new merchant_winebottle;
            b.push_back(tem);
        }
        else if(c == "medicine"){
            Object* tem = new merchant_med;
            b.push_back(tem);
        }
        setObjects(b);
}
