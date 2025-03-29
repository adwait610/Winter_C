#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string fullName, email;
public:
    Person(string name, string mail) : fullName(name), email(mail) {}
    virtual void display() = 0;
    virtual void edit() = 0;
    virtual ~Person() {}
};

#endif
