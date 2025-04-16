#include "Doctor.h"

void Doctor::display() {
    cout << "\n===== Doctor Information =====" << endl;
    cout << "Name: " << fullName << "\nSpecialty: " << specialty 
         << "\nWorking Hours: " << workingHours << "\nEmail: " << email << endl;
}

void Doctor::edit() {
    cout << "\nWhich detail would you like to edit?" << endl;
    cout << "1) Name\n2) Specialty\n3) Working Hours\n4) Email\nSelect an option: ";
    
    int choice;
    cin >> choice;
    cin.ignore();
    
    cout << "Enter new value: ";
    if (choice == 1) getline(cin, fullName);
    else if (choice == 2) getline(cin, specialty);
    else if (choice == 3) getline(cin, workingHours);
    else if (choice == 4) getline(cin, email);
    else cout << "Invalid choice!" << endl;
}

string Doctor::getData() {
    return fullName + "," + email + "," + specialty + "," + workingHours + "\n";
}
