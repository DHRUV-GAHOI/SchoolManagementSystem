// Student Management system using file handling in c++
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <string_view>
#include <regex>
#include <stdio.h>
using namespace std;
class student
{
private:
    string name, roll_no, course, address, email_id, contact_no;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};
void student::menu()
{
menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Record" << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record" << endl;
    cout << "\t\t\t 4. Search Record" << endl;
    cout << "\t\t\t 5. Delete Record" << endl;
    cout << "\t\t\t 6. Exit" << endl;

    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t Choose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "Enter Your Choose: ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n Add Another Student Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n Invalid choice... Please Try Again..";
    }
    getch();
    goto menustart;
}
void student::insert() // add student details
{
    system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Student Details ---------------------------------------------" << endl;

    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\tEnter Roll No.: ";
    cin >> roll_no;
    cout << "\t\t\tEnter Course: ";
    cin >> course;
    cout << "\t\t\tEnter Email Id: ";
    cin >> email_id;
    cout << "\t\t\tEnter Contact No: ";
    cin >> contact_no;
    cout << "\t\t\tEnter Address: ";
    cin >> address;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();
}

void student::display() // display students details
{
    system("cls");
    fstream file;
    int total = 1;
    int temp = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Record Table --------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        /* code */
        cout << "\n No Data Is Present...";
        file.close();
    }
    else
    {
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Student No.: " << total++ << endl;
            cout << "\t\t\t Student Name: " << name << endl;
            cout << "\t\t\t Student Roll No.: " << roll_no << endl;
            cout << "\t\t\t Student course: " << course << endl;
            cout << "\t\t\t Student Email Id.: " << email_id << endl;
            cout << "\t\t\t Student Contact No.: " << contact_no << endl;
            cout << "\t\t\t Student Address: " << address << endl;
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
            temp++;
        }
        if (temp == 0)
        {
            cout << "\nNo Data Is Present...";
        }
    }
    file.close();
}
void student::modify() // Modify Students Details
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n No Data is Present..";
    }
    else
    {
        cout << "\n\t\t\tEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        if (file.eof())
        {
            cout << "\n No Data is Present..";
        }
        while (!file.eof())
        {
            if (rollno != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                char ch;
                cout << "\n\t\t\tDo you want to modify the name of the student? (Y/N) ";
                cin >> ch;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << "\t\t\tEnter Name: ";
                    cin >> name;
                    cout << "\t\t\tNew Name: ";
                    cout << name;
                }
                else
                {
                    cout << "\t\t\tName: ";
                    cout << name;
                }
                cout << "\n\t\t\tDo you want to modify the Roll No. of the student? (Y/N) ";
                cin >> ch;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << "\t\t\tEnter Roll No.: ";
                    cin >> roll_no;
                    cout << "\t\t\tNew Roll No.: ";
                    cout << roll_no;
                }
                else
                {
                    cout << "\t\t\tRoll No.: ";
                    cout << roll_no;
                }
                cout << "\n\t\t\tDo you want to modify the Course of the student? (Y/N) ";
                cin >> ch;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << "\t\t\tEnter Course: ";
                    cin >> course;
                    cout << "\t\t\tNew Course: ";
                    cout << course;
                }
                else
                {
                    cout << "\t\t\tCourse: ";
                    cout << course;
                }
                cout << "\n\t\t\tDo you want to modify the Email Id of the student? (Y/N) ";
                cin >> ch;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << "\t\t\tEnter Email Id: ";
                    cin >> email_id;
                    cout << "\t\t\tNew Email Id: ";
                    cout << email_id;
                }
                else
                {
                    cout << "\t\t\tEmail Id: ";
                    cout << email_id;
                }
                cout << "\n\t\t\tDo you want to modify the Contact No. of the student? (Y/N) ";
                cin >> ch;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << "\t\t\tEnter Contact No.: ";
                    cin >> contact_no;
                    cout << "\t\t\tNew Contact No.: ";
                    cout << contact_no;
                }
                else
                {
                    cout << "\t\t\tContact No.: ";
                    cout << contact_no;
                }
                cout << "\n\t\t\tDo you want to modify the Address of the student? (Y/N) ";
                cin >> ch;
                if (ch == 'Y' || ch == 'y')
                {
                    cout << "\t\t\tEnter Address: ";
                    cin >> address;
                    cout << "\t\t\tNew Address: ";
                    cout << address;
                }
                else
                {
                    cout << "\t\t\tAddress: ";
                    cout << address;
                }
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\n Student Roll No. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
void student::search() // search data of student
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n No Data Is Present...";
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data ------------------------------------------" << endl;
        cout << "\n Enter Roll No. of Student Which You Want to Search: ";
        cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\t\t\t Student Name: " << name << endl;
                cout << "\t\t\t Student Roll No.: " << roll_no << endl;
                cout << "\t\t\t Student course: " << course << endl;
                cout << "\t\t\t Student Email Id.: " << email_id << endl;
                cout << "\t\t\t Student Address: " << address << endl;
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\n Student Roll No. Not Found...";
        }
        file.close();
    }
}
void student::deleted()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\nNo Data is Present..";
        file.close();
    }
    else if (file.eof())
    {
        cout << "\n No Data is Present..";
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n Successfully Delete Data";
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\n Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
int main()
{
    student project;
    project.menu();
    return 0;
}
