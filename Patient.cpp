#include "Patient.h"

void Patient::display() {
    cout << "\n===== Patient Information =====" << endl;
    cout << "Health Number: " << healthNumber << "\nName: " << fullName 
         << "\nDOB: " << dob << "\nPhone: " << phone 
         << "\nEmail: " << email << "\nAllergies: " << allergies 
         << "\nGender: " << gender << endl;
}

void Patient::edit() {
    cout << "\nWhich detail would you like to edit?" << endl;
    cout << "1) Name\n2) Health Number\n3) DOB\n4) Phone\n5) Email\n6) Gender\n7) Allergies\nSelect an option: ";
    
    int choice;
    cin >> choice;
    cin.ignore();
    
    cout << "Enter new value: ";
    if (choice == 1) getline(cin, fullName);
    else if (choice == 2) getline(cin, healthNumber);
    else if (choice == 3) getline(cin, dob);
    else if (choice == 4) getline(cin, phone);
    else if (choice == 5) getline(cin, email);
    else if (choice == 6) getline(cin, gender);
    else if (choice == 7) getline(cin, allergies);
    else cout << "Invalid choice!" << endl;
}

string Patient::getData() {
    return healthNumber + "," + fullName + "," + dob + "," + phone + "," + email + "," + allergies + "," + gender + "\n";
}
