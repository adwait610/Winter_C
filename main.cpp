#include "Doctor.h"
#include "Patient.h"
#include "PatientHistory.h"
#include <vector>
#include <fstream>

vector<Doctor*> doctors;
vector<Patient*> patients;
vector<PatientHistory*> histories;

void loadData() {
    ifstream docFile("doctor.txt"), patFile("patient.txt"), histFile("history.txt");
    string name, email, specialty, hours, hNum, dob, phone, allergy, gender, doc, treat, date;
    
    while (getline(docFile, name, ',')) {
        getline(docFile, email, ',');
        getline(docFile, specialty, ',');
        getline(docFile, hours);
        doctors.push_back(new Doctor(name, email, specialty, hours));
    }

    while (getline(patFile, hNum, ',')) {
        getline(patFile, name, ',');
        getline(patFile, dob, ',');
        getline(patFile, phone, ',');
        getline(patFile, email, ',');
        getline(patFile, allergy, ',');
        getline(patFile, gender);
        patients.push_back(new Patient(name, hNum, dob, phone, email, allergy, gender));
    }

    while (getline(histFile, hNum, ',')) {
        getline(histFile, name, ',');
        getline(histFile, doc, ',');
        getline(histFile, treat, ',');
        getline(histFile, date);
        histories.push_back(new PatientHistory(hNum, name, doc, treat, date));
    }
}

void menu() {
    int choice;
    while (true) {
        cout << "1) View/Edit Patients 2) View/Edit Doctors 3) View/Edit Patient History 0) Exit: ";
        cin >> choice;
        if (choice == 0) break;
        if (choice == 1) patients[0]->display(); 
        if (choice == 2) doctors[0]->display();
        if (choice == 3) histories[0]->display();
    }
}

int main() {
    loadData();
    menu();
    return 0;
}
