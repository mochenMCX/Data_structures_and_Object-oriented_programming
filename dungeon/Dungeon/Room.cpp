#include "Room.h"

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
    for (int i = 0; i < a.size(); i++) {
            objects[i] = a[i];
        }
}

bool Room::getIsExit()
{
        return isExit;
}

int Room::getIndex()
{
        return index;
}

vector<Object *> Room::getObjects()
{
       return objects;
}

Room *Room::getUpRoom()
{
       return upRoom;
}

Room *Room::getDownRoom()
{
       return downRoom;
}

Room *Room::getLeftRoom()
{
       return leftRoom;
}

Room *Room::getRightRoom()
{
       return rightRoom;
}

Room *Room::getupstairs()
{
       return upstair;
}

Room *Room::getdownstairs()
{
       return downstair;
}

bool Room::islock(Player a)
{
       vector<Item> invent;
        invent = a.getInventory();
        vector<Item>::iterator it;
        for(it = invent.begin();it -> getTag() != "key" && it != invent.end();++it);
        if(it == invent.end()) return false;
        else{
            a.eraseItem(key());
            unlock();
            return true;
        }
}

restaurant::restaurant(int a):Room(a)
{
    vector<Object*> b(3);
        b[0] = &soldier();
        b[1] = &soldier();
        b[2] = &shield();
        setObjects(b);
}

bathroom::bathroom(int a):Room(a)
{
    vector<Object*> b(3);
        b[0] = &soldier();
        b[1] = &shield();
        b[2] = &shield();
        setObjects(b);
}

corridor::corridor(int a):Room(a)
{
    vector<Object*> b;
        b.push_back(&money(5));
        setObjects(b);
}

center::center(int a):Room(a)
{
    vector<Object*> b;
        b.push_back(&soldier());
        b.push_back(&soldier());
        b.push_back(&boss());
        if(a == 34){
            b.push_back(&final_boss());
        }
        setObjects(b);
}

store::store(int a, string c):Room(a)
{
    vector<Object*> b;
        if(c == "sword"){
            b.push_back(&merchant_sword());
        }
        else if(c == "dice"){
            b.push_back(&merchant_dice());
        }
        else if(c == "winebottle"){
            b.push_back(&merchant_winebottle());
        }
        else if(c == "medicine"){
            b.push_back(&merchant_med());
        }
        setObjects(b);
}
