#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

class Object
{
private:
    string name;
    string tag;
public:
    Object();
    Object(string a);
    Object(string a, string b) ;

    /* pure virtual function */
    virtual bool triggerEvent(Object* a);

    /* Set & Get function*/
    void setName(string a);
    void setTag(string a);
    string getName();
    string getTag();
    virtual int getamount();
};



#endif // OBJECT_H_INCLUDED
