#include "Object.h"

Object::Object(string a): name(a){}

Object::Object(string a, string b) :name(a), tag(b)
{
    
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

string Object::getTag()
{
    return tag;
}
