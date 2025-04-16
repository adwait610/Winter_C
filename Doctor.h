#ifndef DOCTOR_H
#define DOCTOR_H

#include "Person.h"

class Doctor : public Person {
private:
    string specialty, workingHours;
public:
    Doctor(string name, string mail, string spec, string hours) 
        : Person(name, mail), specialty(spec), workingHours(hours) {}

    void display() override;
    void edit() override;
    string getData();
    string getName() { return fullName; }
};

#endif
