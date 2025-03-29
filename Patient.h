#ifndef PATIENT_H
#define PATIENT_H

#include "Person.h"

class Patient : public Person {
private:
    string healthNumber, dob, phone, allergies, gender;
public:
    Patient(string name, string hNum, string birth, string ph, string mail, string allergy, string gen)
        : Person(name, mail), healthNumber(hNum), dob(birth), phone(ph), allergies(allergy), gender(gen) {}

    void display() override;
    void edit() override;
    string getData();
    string getHealthNum() { return healthNumber; }
    string getName() { return fullName; }
};

#endif
