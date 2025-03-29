#include "PatientHistory.h"

void PatientHistory::display() {
    cout << "Patient ID: " << patientID << "\nPatient Name: " << patientName 
         << "\nDoctor: " << doctorName << "\nTreatment: " << treatment 
         << "\nDate: " << date << endl;
}

void PatientHistory::edit() {
    cout << "1) Doctor 2) Treatment 3) Date: ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice == 1) getline(cin, doctorName);
    else if (choice == 2) getline(cin, treatment);
    else if (choice == 3) getline(cin, date);
}

string PatientHistory::getData() {
    return patientID + "," + patientName + "," + doctorName + "," + treatment + "," + date + "\n";
}
