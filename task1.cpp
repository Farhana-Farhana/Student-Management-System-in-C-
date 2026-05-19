#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

public:
    void input() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\nRoll Number : " << rollNo;
        cout << "\nName        : " << name;
        cout << "\nMarks       : " << marks << endl;
    }

    int getRollNo() {
        return rollNo;
    }

    // Save student data to file
    void writeToFile() {
        ofstream file("students.txt", ios::app);

        file << rollNo << endl;
        file << name << endl;
        file << marks << endl;

        file.close();

        cout << "\nStudent record added successfully!\n";
    }

    // Display all records
    void readFromFile() {
        ifstream file("students.txt");

        int r;
        string n;
        float m;

        cout << "\n--- Student Records ---\n";

        while (file >> r) {
            file.ignore();
            getline(file, n);
            file >> m;

            cout << "\nRoll Number : " << r;
            cout << "\nName        : " << n;
            cout << "\nMarks       : " << m << endl;
        }

        file.close();
    }

    // Search and update record
    void updateRecord() {
        ifstream file("students.txt");
        ofstream temp("temp.txt");

        int searchRoll;
        bool found = false;

        cout << "\nEnter Roll Number to Update: ";
        cin >> searchRoll;

        int r;
        string n;
        float m;

        while (file >> r) {
            file.ignore();
            getline(file, n);
            file >> m;

            if (r == searchRoll) {
                found = true;

                cout << "\nEnter New Name: ";
                cin.ignore();
                getline(cin, n);

                cout << "Enter New Marks: ";
                cin >> m;

                cout << "\nRecord Updated Successfully!\n";
            }

            temp << r << endl;
            temp << n << endl;
            temp << m << endl;
        }

        file.close();
        temp.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (!found) {
            cout << "\nRecord Not Found!\n";
        }
    }

    // Delete record
    void deleteRecord() {
        ifstream file("students.txt");
        ofstream temp("temp.txt");

        int deleteRoll;
        bool found = false;

        cout << "\nEnter Roll Number to Delete: ";
        cin >> deleteRoll;

        int r;
        string n;
        float m;

        while (file >> r) {
            file.ignore();
            getline(file, n);
            file >> m;

            if (r == deleteRoll) {
                found = true;
                continue;
            }

            temp << r << endl;
            temp << n << endl;
            temp << m << endl;
        }

        file.close();
        temp.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        if (found)
            cout << "\nRecord Deleted Successfully!\n";
        else
            cout << "\nRecord Not Found!\n";
    }
};

int main() {
    Student s;
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Update Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            s.input();
            s.writeToFile();
            break;

        case 2:
            s.readFromFile();
            break;

        case 3:
            s.updateRecord();
            break;

        case 4:
            s.deleteRecord();
            break;

        case 5:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
