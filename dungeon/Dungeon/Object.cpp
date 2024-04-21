#include "Object.h"

Object::Object(){
    name = "    ";
    tag = " ";
}

Object::Object(string a):name(a){
    tag = " ";
}

Object::Object(string a, string b) :name(a), tag(b)
{

}

bool Object::triggerEvent(Object* a){
    return true;
}

void Object::setName(string a)
{
    name = a;
}

void Object::setTag(string a)
{
    tag = a;
}

string Object::getName()
{
    return name;
}
int Object::getamount()
{
    return 0;
}

string Object::getTag()
{
    return tag;
}
