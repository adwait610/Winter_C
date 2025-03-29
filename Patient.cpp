#include "Patient.h"

void Patient::display() {
    cout << "ID: " << healthNumber << "\nName: " << fullName 
         << "\nDOB: " << dob << "\nPhone: " << phone 
         << "\nEmail: " << email << "\nAllergies: " << allergies 
         << "\nGender: " << gender << endl;
}

void Patient::edit() {
    cout << "1) Name 2) Health Number 3) DOB 4) Phone 5) Email 6) Gender 7) Allergies: ";
    int choice;
    cin >> choice;
    cin.ignore();
    if (choice == 1) getline(cin, fullName);
    else if (choice == 2) getline(cin, healthNumber);
    else if (choice == 3) getline(cin, dob);
    else if (choice == 4) getline(cin, phone);
    else if (choice == 5) getline(cin, email);
    else if (choice == 6) getline(cin, gender);
    else if (choice == 7) getline(cin, allergies);
}

string Patient::getData() {
    return healthNumber + "," + fullName + "," + dob + "," + phone + "," + email + "," + allergies + "," + gender + "\n";
}
