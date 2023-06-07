/*Department maintains a student information. The file contains roll number, name,
division and address. Allow user to add, delete information of student. Display
information of particular employee. If record of student does not exist an appropriate
message is displayed. If it is, then the system displays the student details. Use sequential
file to main the data.*/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct Student {
    int roll_no;
    string name;
    string div;
    string address;
};
void add()
{
    Student s1;
    cout << "Enter roll no. :";
    cin >> s1.roll_no;
    cin.ignore();
    cout << "Enter student's name: ";
    getline(cin,s1.name);
    cout << "Enter Division: ";
    getline(cin,s1.div);
    cout << "Enter address: ";
    getline(cin,s1.address);
    ofstream fout("student.txt",ios::app);
    if (fout.is_open())
    {
        fout << s1.roll_no << "," << s1.name << "," << s1.div << "," << s1.address << endl;
        fout.close();
        cout << "Record added Successfully!!"<< endl;
    }
    else{
        cout << "Error!! Unable to open a file."<< endl;
    }
}
void del()
{
    int roll_no;
    cout << "Enter Roll No. to delete: ";
    cin >> roll_no;
    ifstream fin("student.txt");
    ofstream ftemp("temp.txt");
    bool recordFound = false;
    if(fin.is_open() && ftemp.is_open())
    {
        string line;
        while(getline(fin,line))
        {
            int currentroll_no = stoi(line.substr(0,line.find(',')));
            if (currentroll_no != roll_no)
            {
                ftemp << line << endl;
            }
            else{
                recordFound = true;
            }
        }
        fin.close();
        ftemp.close();
        remove("student.txt");
        rename("temp.txt","student.txt");
        if (recordFound)
        {
            cout << "Student record deleted successfully!"<< endl;
        }
        else
        {
            cout << "Student record not found!"<< endl;
        }
    }
    else 
    {
        cout << "Error ! Unable to open file." << endl;
    }
}
void display()
{
    int roll_no;
    cout << "Enter Roll No. to search: ";
    cin >> roll_no;
    ifstream fin("student.txt");
    if (fin.is_open())
    {
        bool recordFound = false;
        string line;
        while (getline(fin, line))
        {
            // Split the line into parts separated by commas
            stringstream ss(line);
            string token;
            getline(ss, token, ',');
            int currentroll_no;
            try {
                currentroll_no = stoi(token);
            }
            catch (const std::invalid_argument& e) {
                // Handle the invalid integer conversion
                cout << "Error: Invalid roll number found in the file." << endl;
                fin.close();
                return;
            }
            
            if (currentroll_no == roll_no)
            {
                recordFound = true;
                cout << "Student Information:" << endl;
                cout << line << endl;
                break;
            }
        }
        if (!recordFound)
        {
            cout << "Student record not found!" << endl;
        }
        fin.close();
    }
    else
    {
        cout << "Error !! Unable to open file" << endl;
    }
}


int main()
{
    int choice;
    while (true)
    {
        cout << "Student Information System" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. Delete Student Record" << endl;
        cout << "3. Display Student Information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting the program..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    }
    return 0;
}
