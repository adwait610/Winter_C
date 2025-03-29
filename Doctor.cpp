#include "Doctor.h"

void Doctor::display() {
    cout << "Name: " << fullName << "\nSpecialty: " << specialty 
         << "\nWorking Hours: " << workingHours << "\nEmail: " << email << endl;
}

void Doctor::edit() {
    cout << "1) Name 2) Specialty 3) Working Hours 4) Email: ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice == 1) getline(cin, fullName);
    else if (choice == 2) getline(cin, specialty);
    else if (choice == 3) getline(cin, workingHours);
    else if (choice == 4) getline(cin, email);
}

string Doctor::getData() {
    return fullName + "," + email + "," + specialty + "," + workingHours + "\n";
}
