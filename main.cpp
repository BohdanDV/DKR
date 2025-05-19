#include <iostream>
#include <iomanip> 
#include "Faculty.h"
#include "Course.h"
#include "Group.h"
#include "Logger.h"
#include "StudentsBase.h"
using namespace std;
void createStudent();
void showBase(list<Student> base);
list<Faculty> faculties;
list<StudentsBase> dataBase;




int main() {
    Logger logger("logfile.txt");
    logger.log(INFO, "Program started.");
    string faculty, cource, group;
    int  year;

  createStudent();
 createStudent();
 /*
cout <<"Enter Sorting Faculty";
cin>>faculty;
cout <<"Enter Sorting Cource";
cin>>cource;

cout <<"Enter Sorting Cource";
cin>>group;

*/
cout <<"Enter Sorting year";
cin>>year;
  showBase(dataBase.front().sortByYear(year));

    return 0;
}

void createStudent() {

    string baseName,facultyName,courseName,groupName,studentSurname,studentName;
    int birthYear,phoneNumber;

    cout << "Enter base name: ";
    getline(cin, baseName);

    StudentsBase* base = nullptr;
    for (StudentsBase& curr : dataBase) {
        if (curr.getName() == baseName) {
            base = &curr;
            break;
        }
    }
    if (!base) {
        dataBase.emplace_back(baseName);
        base = &dataBase.back();
    }

   
    cout << "Enter faculty: ";
    getline(cin, facultyName);

    cout << "Enter course: ";
    getline(cin, courseName);

    cout << "Enter group: ";
    getline(cin, groupName);

   
    cout << "Enter student surname: ";
    getline(cin, studentSurname);

    cout << "Enter student name: ";
    getline(cin, studentName);

    cout << "Enter birth year: ";
    cin >> birthYear;

    cout << "Enter phone number: ";
    cin >> phoneNumber;
    cin.ignore(); 

    
    Faculty* faculty = nullptr;
    for (Faculty& curr : faculties) {
        if (curr.getName() == facultyName) {
            faculty = &curr;
            break;
        }
    }
    if (!faculty) {
        faculties.emplace_back(facultyName);
        faculty = &faculties.back();
    }

    Course* course = faculty->getCourse(courseName);
    if (!course) {
        faculty->addCourse(courseName);
        course = &faculty->VectorOfCourses().back();
    }

    Group* group = course->getGroup(groupName);
    if (!group) {
        course->addGroup(groupName);
        group = &course->VectorOfGroups().back();
    }

    Student newStudent(studentSurname, studentName, *faculty, *course, *group, birthYear, phoneNumber);

    base->addStudent(newStudent);

    cout << "Student added successfully to base '" << baseName << "'.\n";
}

    
void showBase(list<Student> base){
  
    if (base.empty()) {
        cout << "The student base is empty." << endl;
        return;
    }

    cout << left 
         << setw(15) << "Surname"
         << setw(15) << "Name"
         << setw(15) << "Faculty"
         << setw(15) << "Course"
         << setw(15) << "Group"
         << setw(12) << "Birth Year"
         << setw(15) << "Phone"
         << endl;

    cout << string(97, '-') << endl; 

   
    for (const Student& s : base) {
        cout << left
             << setw(15) << s.getSurname()
             << setw(15) << s.getName()
             << setw(15) << s.getFaculty().getName()
             << setw(15) << s.getCourse().getName()
             << setw(15) << s.getGroup().getName()
             << setw(12) << s.getBirthYear()
             << setw(15) << s.getPhoneNumber()
             << endl;
    }
}
