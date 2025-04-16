#include "PatientHistory.h"

void PatientHistory::display() {
    cout << "Patient ID: " << patientID << "\nPatient Name: " << patientName 
         << "\nDoctor: " << doctorName << "\nTreatment: " << treatment 
         << "\nDate: " << date << "\nPrevious Treatments: " << previousTreatments
         << "\nPrevious Surgeries: " << previousSurgeries << "\nLast Visit: " << lastVisit << endl;
}

void PatientHistory::edit() {
    cout << "1) Doctor\n2) Treatment\n3) Date\n4) Previous Treatments\n5) Previous Surgeries\n6) Last Visit\nSelect option to edit: ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice == 1) getline(cin, doctorName);
    else if (choice == 2) getline(cin, treatment);
    else if (choice == 3) getline(cin, date);
    else if (choice == 4) getline(cin, previousTreatments);
    else if (choice == 5) getline(cin, previousSurgeries);
    else if (choice == 6) getline(cin, lastVisit);
    else cout << "Invalid choice!" << endl;
}

string PatientHistory::getData() {
    return patientID + "," + patientName + "," + doctorName + "," + treatment + "," + date + ","
           + previousTreatments + "," + previousSurgeries + "," + lastVisit + "\n";
}
