#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <cctype>
using namespace std;

class BloodDonor {
public:
    string name, contact, bloodGroup;
    string address, healthIssue, gender, birthDate, lastDonatedTime;

    void donorRegistration() {
        cout << "Enter Donor's Name: ";
        getline(cin, name);
        cout << "Enter Donor's Blood Group: ";
        cin >> bloodGroup;
        cin.ignore();
        cout << "Enter Donor's Address: ";
        getline(cin, address);
        cout << "Enter Donor's Contact Number: ";
        cin >> contact;
        cin.ignore();
        cout << "Enter Donor's Gender (F/M): ";
        getline(cin, gender);
        cout << "Enter Donor's Birth Date (YYYY-MM-DD): ";
        getline(cin, birthDate);
        cout << "Enter Donor's Health Issue (If you have any, unless    N/A):";
        getline(cin, healthIssue);
        cout << "Enter Last Donated Time (YYYY-MM-DD or N/A): ";
        getline(cin, lastDonatedTime);
        char confirm;
        cout << "\nEnter 'Y' to confirm the registration: ";
        cin >> confirm;
        confirm = toupper(confirm);

        if (confirm == 'Y') {
            ofstream outFile("donorsList.txt", ios::app);
            if (outFile.is_open()) {
                outFile << name << "\n"
                        << bloodGroup << "\n"
                        << address << "\n"
                        << contact << "\n"
                        << gender << "\n"
                        << birthDate << "\n"
                        << healthIssue << "\n"
                        << lastDonatedTime << "\n";
                outFile.close();
                system("cls");

                cout << "CONGRATULATIONS! REGISTRATION IS COMPLETED.\n";
                system("pause");
                system("cls");

            } else {
                cout << "Error opening file!\n";
            }
        } else {
            cout << "\nSORRY! YOU HAVE ENTERED THE WRONG KEYWORD. TRY AGAIN. :(\n";
        }
    }

    void displayDonors(string bloodGroup) {
        ifstream inFile("donorsList.txt");
        if (inFile.is_open()) {
            string name, donorBloodGroup, address, contact, gender, birthDate, healthIssue, lastDonatedTime;
            bool found = false;
            while (getline(inFile, name)) {
                getline(inFile, donorBloodGroup);
                getline(inFile, address);
                getline(inFile, contact);
                getline(inFile, gender);
                getline(inFile, birthDate);
                getline(inFile, healthIssue);
                getline(inFile, lastDonatedTime);

                if (donorBloodGroup == bloodGroup) {
                    cout << "Donor Name: " << name << "  Contact Number: " << contact << "  Last Donated Time: " << lastDonatedTime << "\n";
                    found = true;
                }
            }
            if (!found) {
                cout << "No donors found with blood group " << bloodGroup << ".\n";
            }
            inFile.close();
        } else {
            cout << "Error opening file!\n";
        }
    }

    void displayHospitals(string bloodGroup) {
        ifstream inFile("hospitalsList.txt");
        if (!inFile) {
            cerr << "Unable to open file hospitals.txt";
            return;
        }

        string bg, hospitalName, contactNumber, location;
        bool found = false;

        while (inFile >> bg) {
            inFile.ignore();
            getline(inFile, hospitalName, ';');
            getline(inFile, contactNumber, ';');
            getline(inFile, location);

            if (bg == bloodGroup) {
                cout << "Displaying hospitals for blood group " << bloodGroup << ":\n";
                cout << "Hospital Name: " << hospitalName << "\n";
                cout << "Contact Number: " << contactNumber << "\n";
                cout << "Location: " << location << "\n";
                found = true;
            }
        }

        if (!found) {
            cout << "No specific hospitals found for blood group " << bloodGroup << ".\n";
        }

        inFile.close();
    }
};

int main() {
    system("cls");
    cout << "\n\t\t\t\t\t\t|BLOOD DONOR MANAGEMENT SYSTEM|\n\n";
    cout << "\t\t\t\t\tA bag of blood can be a lifeline for someone ";
                for (int i = 0; i < 3; i++)
                {
                    cout << ".";
                    Sleep(3000);
                }

     cout<<"\n";
    //system("pause");
    system("cls");
    while (true) {
        BloodDonor donor, patient;
        cout << "\n\t\t\t\t\t\t1. For admin panel (Press 1)\n";
        cout << "\t\t\t\t\t\t2. For user panel (Press 2)\n";
        cout << "\t\t\t\t\t\t3. To exit (Press 3)\n\t\t\t\t\t\tEnter choice: ";
        int choice;
        cin >> choice;
        system("cls");
        cin.ignore();

        if (choice == 1) {
            cout << "ADMIN PANEL:\n";
            string username, password;
            cout << "Enter the username: ";
            cin >> username;
            cin.ignore();
            cout << "Enter the password: ";
            cin >> password;
            cin.ignore();
            system("cls");

            if (username == "admin" && password == "Easy") {
                cout << "WELCOME!\n";

                int adminChoice, age;

                cout << "Press 1 to Register donor: ";
                cin >> adminChoice;
                system("cls");

                cin.ignore();
                if (adminChoice == 1) {
                    cout << "What is the age of the donor?\n";
                    cin >> age;
                    cin.ignore();
                    if (age >= 18 && age <= 65) {
                            cout<<"Eligible for donor registration\n";
                            system("pause");
                            system("cls");
                        donor.donorRegistration();

                    } else {
                        cout << "Donor is not eligible for donating blood.\n";
                    }
                }
            } else {
                cout << "WRONG PASSWORD! TRY AGAIN OR CONTACT THE ADMIN!\n";
            }
        } else if (choice == 2) {
            string patientBloodGroup;
            cout << "USER PANEL:\n1. Donor Search (Press 1)\n2. Hospital Search (Press 2)\nEnter: ";
            int d;
            cin >> d;
            cin.ignore();
            system("cls");

            if (d == 1) {
                cout << "Enter your blood group: ";
                cin >> patientBloodGroup;
                cin.ignore();
                cout << "Donor List:\n";
                patient.displayDonors(patientBloodGroup);
            } else if (d == 2) {
                cout << "Enter your blood group: ";
                cin >> patientBloodGroup;
                cin.ignore();
                cout << "\t\tPlease Wait";
                for (int i = 0; i < 3; i++)
                {
                    cout << ".";
                    Sleep(1000);
                }
                cout << "\nHere Is Your Required  Hospital List:\n";
                patient.displayHospitals(patientBloodGroup);
                system("pause");
            }
        } else if (choice == 3) {
            break;
        }
    }
    return 0;
}






