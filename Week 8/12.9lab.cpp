#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

/*
    Given a program that searches for a student's ID or name in a text file, complete the FindID() and FindName() functions.
    Then, insert a try/catch statement in main() to catch any exceptions thrown by FindID() or FindName(), and output the
    exception message. Each line in the text file contains a name and ID separated by a space.

    Function FindID() has two parameters: a student's name (string) and the text file's contents (ifstream). The function
    FindID() returns the ID associated with the student's name if the name is in the file, otherwise the function throws a
    runtime_error with the message "Student ID not found for studentName", where studentName is the name of the student.

    Function FindName() has two parameters: a student's ID (string) and the text file's contents (ifstream). The function
    FindName() returns the name associated with the student's ID if the ID is in the file, otherwise the function throws a
    runtime_error with the message "Student name not found for studentID", where studentID is the ID of the student.

    The main program takes three inputs from a user: the name of a text file (string), the search option for finding the ID
    or name of a student (int), and the ID or name of a student (string). If the search option is 0, FindID() is invoked with
    the student's name as an argument. If the search option is 1, FindName() is invoked with the student's ID as an argument.
    The main program outputs the search result or the caught exception message.
*/

string FindID(string name, ifstream &infoFS) 
{
    string line, fileName;
    while (getline(infoFS, line))
    {
        size_t pos = line.find(' ');
        if (pos != string::npos)
        {
            string studentName = line.substr(0, pos);
            string studentID = line.substr(pos + 1);
            
            if (studentName == name)
            {
                return studentID;
            }
        }
    }
    throw runtime_error("Student ID not found for " + name);
}

string FindName(string ID, ifstream &infoFS) 
{
    string line;
    while (getline(infoFS, line))
    {
        size_t pos = line.find(' ');
        if (pos != string::npos)
        {
            string studentName = line.substr(0, pos);
            string studentID = line.substr(pos + 1);
            
            if (studentID == ID)
            {
                return studentName;
            }
        }
    }
    throw runtime_error("Student name not found for " + ID);
}

int main() {
    int userChoice;
    string studentName;
    string studentID;
    
    string studentInfoFileName;
    ifstream studentInfoFS;
    
    cout << "Enter the file name: ";
    cin >> studentInfoFileName;
    
    studentInfoFS.open(studentInfoFileName);
    
    if (!studentInfoFS.is_open()) {
        cerr << "Error: Could not open file " << studentInfoFileName << endl;
        return 1;
    }
    
    cout << "Enter 0 to search by name or 1 to search by ID: ";
    cin >> userChoice;
    
    try
    {
        studentInfoFS.clear();
        studentInfoFS.seekg(0, ios::beg);

        if (userChoice == 0) 
        {
            cout << "Enter student name: ";
            cin >> studentName;
            studentID = FindID(studentName, studentInfoFS);
            cout << "Student ID: " << studentID << endl;
        }
        else if (userChoice == 1)
        {
            cout << "Enter student ID: ";
            cin >> studentID;
            studentName = FindName(studentID, studentInfoFS);
            cout << "Student Name: " << studentName << endl;
        }
        else
        {
            cout << "Invalid option." << endl;
        }
    }
    catch (const runtime_error& e)
    {
        cout << "Exception: " << e.what() << endl;
    }
    
    studentInfoFS.close();
    return 0;
}