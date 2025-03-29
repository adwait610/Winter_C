#include "Doctor.h"
#include "Patient.h"
#include "PatientHistory.h"
#include <vector>
#include <fstream>

vector<Doctor*> doctors;
vector<Patient*> patients;
vector<PatientHistory*> histories;

void saveData() {
    ofstream docFile("doctor.txt"), patFile("patient.txt"), histFile("history.txt");
    for (auto d : doctors) docFile << d->getData();
    for (auto p : patients) patFile << p->getData();
    for (auto h : histories) histFile << h->getData();
}

void addDoctor() {
    string name, email, specialty, hours;
    cin.ignore();
    getline(cin, name);
    getline(cin, email);
    getline(cin, specialty);
    getline(cin, hours);
    doctors.push_back(new Doctor(name, email, specialty, hours));
    saveData();
}

void addPatient() {
    string name, hNum, dob, phone, email, allergy, gender;
    cin.ignore();
    getline(cin, hNum);
    getline(cin, name);
    getline(cin, dob);
    getline(cin, phone);
    getline(cin, email);
    getline(cin, allergy);
    getline(cin, gender);
    patients.push_back(new Patient(name, hNum, dob, phone, email, allergy, gender));
    saveData();
}

void deleteDoctor(int index) {
    if (index >= 0 && index < doctors.size()) {
        delete doctors[index];
        doctors.erase(doctors.begin() + index);
        saveData();
    }
}

void deletePatient(int index) {
    if (index >= 0 && index < patients.size()) {
        delete patients[index];
        patients.erase(patients.begin() + index);
        saveData();
    }
}

void menu() {
    int choice;
    while (true) {
        cout << "1) Add Doctor 2) Add Patient 3) Delete Doctor 4) Delete Patient 0) Exit: ";
        cin >> choice;
        if (choice == 0) break;
        if (choice == 1) addDoctor();
        if (choice == 2) addPatient();
        if (choice == 3) {
            int index; cin >> index;
            deleteDoctor(index - 1);
        }
        if (choice == 4) {
            int index; cin >> index;
            deletePatient(index - 1);
        }
    }
}

int main() {
    menu();
    return 0;
}
