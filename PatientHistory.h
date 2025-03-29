#ifndef PATIENTHISTORY_H
#define PATIENTHISTORY_H

#include <iostream>
#include <string>

using namespace std;

class PatientHistory {
private:
    string patientID, patientName, doctorName, treatment, date;
public:
    PatientHistory(string id, string pName, string dName, string treat, string d)
        : patientID(id), patientName(pName), doctorName(dName), treatment(treat), date(d) {}

    void display();
    void edit();
    string getData();
    string getPatientID() { return patientID; }
};

#endif
