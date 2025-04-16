#ifndef PATIENTHISTORY_H
#define PATIENTHISTORY_H

#include <iostream>
#include <string>

using namespace std;

class PatientHistory {
private:
    string patientID, patientName, doctorName, treatment, date;
    string previousTreatments, previousSurgeries, lastVisit;

public:
    // Constructor with new attributes
    PatientHistory(string id, string pName, string dName, string treat, string d, 
                   string prevTreatments, string prevSurgeries, string lastVisit)
        : patientID(id), patientName(pName), doctorName(dName), treatment(treat), date(d),
          previousTreatments(prevTreatments), previousSurgeries(prevSurgeries), lastVisit(lastVisit) {}

    // Display patient history details
    void display() {
        cout << "\n===== Patient History =====" << endl;
        cout << "Patient ID: " << patientID << "\nPatient Name: " << patientName
             << "\nDoctor: " << doctorName << "\nTreatment: " << treatment
             << "\nDate: " << date << "\nPrevious Treatments: " << previousTreatments
             << "\nPrevious Surgeries: " << previousSurgeries << "\nLast Visit: " << lastVisit << endl;
    }

    // Edit patient history details
    void edit() {
        cout << "\nWhat would you like to edit?" << endl;
        cout << "1) Doctor\n2) Treatment\n3) Date\n4) Previous Treatments\n5) Previous Surgeries\n6) Last Visit\nSelect an option: ";

        int choice;
        cin >> choice;
        cin.ignore();

        cout << "Enter new value: ";
        if (choice == 1) getline(cin, doctorName);
        else if (choice == 2) getline(cin, treatment);
        else if (choice == 3) getline(cin, date);
        else if (choice == 4) getline(cin, previousTreatments);
        else if (choice == 5) getline(cin, previousSurgeries);
        else if (choice == 6) getline(cin, lastVisit);
        else cout << "Invalid choice!" << endl;
    }

    // Retrieve formatted patient history data
    string getData() {
        return patientID + "," + patientName + "," + doctorName + "," + treatment + "," + date + "," 
               + previousTreatments + "," + previousSurgeries + "," + lastVisit + "\n";
    }

    // Getter functions
    string getPatientID() { return patientID; }
    string getPatientName() { return patientName; }
    string getDoctorName() { return doctorName; }
    string getTreatment() { return treatment; }
    string getDate() { return date; }
};

#endif
