#include "Doctor.h"
#include "Patient.h"
#include "PatientHistory.h"
#include "Person.h"
#include <vector>
#include <fstream>
#include <limits>

using namespace std;

vector<Doctor*> doctors;
vector<Patient*> patients;
vector<PatientHistory*> histories;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void saveData() {
    ofstream docFile("doctor.txt"), patFile("patient.txt"), histFile("his.txt");
    for (auto d : doctors) docFile << d->getData();
    for (auto p : patients) patFile << p->getData();
    for (auto h : histories) histFile << h->getData();
}

void addDoctor() {
    string name, email, specialty, hours;
    
    cout << "Enter Doctor's Full Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    
    cout << "Enter Email: ";
    getline(cin, email);
    
    cout << "Enter Specialty: ";
    getline(cin, specialty);
    
    cout << "Enter Working Hours: ";
    getline(cin, hours);

    doctors.push_back(new Doctor(name, email, specialty, hours));
    cout << "Doctor added successfully!\n";

    saveData();
}

void addPatient() {
    string name, hNum, dob, phone, email, allergy, gender;
    
    cout << "Enter Health Number: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, hNum);
    
    cout << "Enter Full Name: ";
    getline(cin, name);
    
    cout << "Enter Date of Birth (DD/MM/YYYY): ";
    getline(cin, dob);
    
    cout << "Enter Phone Number: ";
    getline(cin, phone);
    
    cout << "Enter Email: ";
    getline(cin, email);
    
    cout << "Enter Any Allergies (or type 'None'): ";
    getline(cin, allergy);
    
    cout << "Enter Gender: ";
    getline(cin, gender);

    patients.push_back(new Patient(name, hNum, dob, phone, email, allergy, gender));
    cout << "Patient added successfully!\n";

    saveData();
}

void deleteDoctor(int index) {
    if (index >= 0 && index < doctors.size()) {
        delete doctors[index];  // Free memory
        doctors.erase(doctors.begin() + index);
        saveData();
        cout << "Doctor deleted successfully!\n";
    } else {
        cout << "Invalid index! Please try again.\n";
    }
}

void deletePatient(int index) {
    if (index >= 0 && index < patients.size()) {
        delete patients[index];  // Free memory
        patients.erase(patients.begin() + index);
        saveData();
        cout << "✅ Patient deleted successfully!\n";
    } else {
        cout << "❌ Invalid index! Please enter a valid patient number.\n";
    }
}

void viewPatients() {
    if (patients.empty()) {
        cout << "❌ No patients available in the system.\n";
        return;
    }

    cout << "\n===== 🏥 List of Patients =====\n";
    for (size_t i = 0; i < patients.size(); i++) {
        cout << i + 1 << ") ";
        patients[i]->display();
        cout << "----------------------------------\n";
    }
}

void viewDoctors() {
    if (doctors.empty()) {
        cout << "❌ No doctors available in the system.\n";
        return;
    }

    cout << "\n===== 👨‍⚕️ List of Doctors =====\n";
    for (size_t i = 0; i < doctors.size(); i++) {
        cout << i + 1 << ") ";
        doctors[i]->display();
        cout << "----------------------------------\n";
    }
}

void addPatientHistory() {
    if (patients.empty()) {
        cout << "❌ No patients available to link history.\n";
        return;
    }

    int patientIndex;
    cout << "\nSelect a patient to add history for (1-based index):\n";
    viewPatients();
    
    cout << "Enter Patient number to add history: ";
    cin >> patientIndex;
    cin.ignore();

    if (patientIndex < 1 || patientIndex > patients.size()) {
        cout << "❌ Invalid patient selection!\n";
        return;
    }

    Patient* selectedPatient = patients[patientIndex - 1];

    string doctorName, treatment, date;
    string previousTreatments, previousSurgeries, lastVisit;

    cout << "Enter Doctor's Name: ";
    getline(cin, doctorName);
    
    cout << "Enter Treatment: ";
    getline(cin, treatment);
    
    cout << "Enter Treatment Date: ";
    getline(cin, date);

    cout << "Enter Previous Treatments (or type 'None'): ";
    getline(cin, previousTreatments);
    
    cout << "Enter Previous Surgeries (or type 'None'): ";
    getline(cin, previousSurgeries);
    
    cout << "Enter Last Visit to the Hospital (or type 'None'): ";
    getline(cin, lastVisit);

    // Create a new PatientHistory object and add it to the histories vector
    histories.push_back(new PatientHistory(selectedPatient->getHealthNum(), selectedPatient->getName(), doctorName, treatment, date, 
                                            previousTreatments, previousSurgeries, lastVisit));

    cout << "Patient history added successfully!\n";

    saveData();  // Save the data after adding the patient history
}

void viewPatientHistories() {
    if (histories.empty()) {
        cout << "❌ No patient histories available.\n";
        return;
    }

    cout << "\n===== 🏥 Patient Histories =====\n";
    for (size_t i = 0; i < histories.size(); i++) {
        cout << i + 1 << ") ";
        histories[i]->display();
        cout << "----------------------------------\n";
    }
}

void editDoctor() {
    if (doctors.empty()) {
        cout << "❌ No doctors available to edit.\n";
        return;
    }

    int index;
    cout << "Enter Doctor number to edit (1-based index): ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > doctors.size()) {
        cout << "❌ Invalid doctor selection!\n";
        return;
    }

    doctors[index - 1]->edit();  // Call edit method for the selected doctor
    saveData();
}

void editPatient() {
    if (patients.empty()) {
        cout << "❌ No patients available to edit.\n";
        return;
    }

    int index;
    cout << "Enter Patient number to edit (1-based index): ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > patients.size()) {
        cout << "❌ Invalid patient selection!\n";
        return;
    }

    patients[index - 1]->edit();  // Call edit method for the selected patient
    saveData();
}

void menu() {
    int choice;
    while (true) {
        cout << "\n===== 🏥 Hospital Information System =====\n";
        cout << "1) Add Doctor\n2) Add Patient\n3) Edit Doctor\n4) Edit Patient\n";
        cout << "5) Delete Doctor\n6) Delete Patient\n7) View Doctors\n8) View Patients\n";
        cout << "9) Add Patient History\n10) View Patient Histories\n0) Exit\nSelect an option: ";
        cin >> choice;

        cout << "You selected: " << choice << endl;  // Debugging output

        if (choice == 0) {
            cout << "Exiting program... 👋\n";
            break;
        }
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Prevent input skipping

        if (choice == 1) {
            addDoctor();
        } else if (choice == 2) {
            addPatient();
        } else if (choice == 3) {
            editDoctor();
        } else if (choice == 4) {
            editPatient();
        } else if (choice == 5) {
            int index;
            cout << "Enter Doctor number to delete (1-based index): ";
            cin >> index;

            if (cin.fail()) {
                cout << "❌ Invalid input! Please enter a valid number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            deleteDoctor(index - 1);  // Adjust for 0-based indexing
        } else if (choice == 6) {
            int index;
            cout << "Enter Patient number to delete (1-based index): ";
            cin >> index;

            if (cin.fail()) {
                cout << "❌ Invalid input! Please enter a valid number.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            deletePatient(index - 1);
        } else if (choice == 7) {
            viewDoctors();
        } else if (choice == 8) {
            viewPatients();
        } else if (choice == 9) {
            addPatientHistory();
        } else if (choice == 10) {
            viewPatientHistories();
        } else {
            cout << "❌ Invalid option! Please try again.\n";
        }
    }
}

int main() {
    menu();
    
    // Free dynamically allocated memory
    for (auto d : doctors) delete d;
    for (auto p : patients) delete p;
    for (auto h : histories) delete h;
    
    return 0;
}
