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

    bool running = true;
    while (running) {
        cout << "\n=== Student database menu ===\n";
        cout << "1. Add student\n";
        cout << "2. Show students from base\n";
        cout << "3. Save base to file\n";
        cout << "4. Load base from file\n";
        cout << "5. Filter by faculty\n";
        cout << "6. Filter by faculty and course\n";
        cout << "7. Filter by group\n";
        cout << "8. Filter by birth year\n";
        cout << "9. Exit\n";
        cout << "Select action: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again.\n";
            logger.log(WARNING, "Invalid input in menu");
            continue;
        }
        cin.ignore(10000, '\n');

        switch (choice) {
            case 1:
                createStudent();
                break;

            case 2: {
                if (dataBase.empty()) {
                    cout << "No database available. Add a student first.\n";
                    logger.log(WARNING, "Show students requested but database empty");
                    break;
                }
                cout << "Enter base name: ";
                string baseName;
                getline(cin, baseName);

                bool found = false;
                list<StudentsBase>::iterator it;
                for (it = dataBase.begin(); it != dataBase.end(); ++it) {
                    if (it->getName() == baseName) {
                        showBase(it->getBase());
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Base '" << baseName << "' not found.\n";
                    logger.log(ERROR, "Base '" + baseName + "' not found for show");
                }
                break;
            }

            case 3: {
                if (dataBase.empty()) {
                    cout << "No database to save.\n";
                    logger.log(WARNING, "Save requested but database empty");
                    break;
                }
                cout << "Enter base name to save: ";
                string baseName;
                getline(cin, baseName);

                bool found = false;
                list<StudentsBase>::iterator it;
                for (it = dataBase.begin(); it != dataBase.end(); ++it) {
                    if (it->getName() == baseName) {
                        it->saveToFile("test2.txt");
                        cout << "Base '" << baseName << "' saved to file.\n";
                        logger.log(INFO, "Base '" + baseName + "' saved");
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Base '" << baseName << "' not found.\n";
                    logger.log(ERROR, "Base '" + baseName + "' not found for save");
                }
                break;
            }

            case 4: {
                cout << "Enter base name to load: ";
                string baseName;
                getline(cin, baseName);
                dataBase.emplace_back(baseName);
                StudentsBase basePtr = dataBase.back();
                basePtr.loadFromFile("test2", faculties);
                cout << "Base '" << baseName << "' loaded.\n";
                logger.log(INFO, "Base '" + baseName + "' loaded");
                break;
            }

            case 5: {
                if (dataBase.empty()) {
                    cout << "No database available.\n";
                    logger.log(WARNING, "Filter by faculty requested but database empty");
                    break;
                }
                cout << "Enter base name: ";
                string baseName;
                getline(cin, baseName);

                StudentsBase* basePtr = NULL;
                list<StudentsBase>::iterator it;
                for (it = dataBase.begin(); it != dataBase.end(); ++it) {
                    if (it->getName() == baseName) {
                        basePtr = &(*it);
                        break;
                    }
                }
                if (basePtr == NULL) {
                    cout << "Base '" << baseName << "' not found.\n";
                    logger.log(ERROR, "Base '" + baseName + "' not found for filter by faculty");
                    break;
                }
                cout << "Enter faculty name: ";
                string facultyName;
                getline(cin, facultyName);

                list<Student> filtered = basePtr->sortByFaculty(facultyName);
                showBase(filtered);
                logger.log(INFO, "Filtered by faculty '" + facultyName + "' in base '" + baseName + "'");
                break;
            }

            case 6: {
                if (dataBase.empty()) {
                    cout << "No database available.\n";
                    logger.log(WARNING, "Filter by faculty and course requested but database empty");
                    break;
                }
                cout << "Enter base name: ";
                string baseName;
                getline(cin, baseName);

                StudentsBase* basePtr = NULL;
                list<StudentsBase>::iterator it;
                for (it = dataBase.begin(); it != dataBase.end(); ++it) {
                    if (it->getName() == baseName) {
                        basePtr = &(*it);
                        break;
                    }
                }
                if (basePtr == NULL) {
                    cout << "Base '" << baseName << "' not found.\n";
                    logger.log(ERROR, "Base '" + baseName + "' not found for filter by faculty and course");
                    break;
                }
                cout << "Enter faculty name: ";
                string facultyName;
                getline(cin, facultyName);
                cout << "Enter course name: ";
                string courseName;
                getline(cin, courseName);

                list<Student> filtered = basePtr->sortByFacultyAndCourse(facultyName, courseName);
                showBase(filtered);
                logger.log(INFO, "Filtered by faculty '" + facultyName + "' and course '" + courseName + "' in base '" + baseName + "'");
                break;
            }

            case 7: {
                if (dataBase.empty()) {
                    cout << "No database available.\n";
                    logger.log(WARNING, "Filter by group requested but database empty");
                    break;
                }
                cout << "Enter base name: ";
                string baseName;
                getline(cin, baseName);

                StudentsBase* basePtr = NULL;
                list<StudentsBase>::iterator it;
                for (it = dataBase.begin(); it != dataBase.end(); ++it) {
                    if (it->getName() == baseName) {
                        basePtr = &(*it);
                        break;
                    }
                }
                if (basePtr == NULL) {
                    cout << "Base '" << baseName << "' not found.\n";
                    logger.log(ERROR, "Base '" + baseName + "' not found for filter by group");
                    break;
                }
                cout << "Enter group name: ";
                string groupName;
                getline(cin, groupName);

                list<Student> filtered = basePtr->sortByGroup(groupName);
                showBase(filtered);
                logger.log(INFO, "Filtered by group '" + groupName + "' in base '" + baseName + "'");
                break;
            }

            case 8: {
                if (dataBase.empty()) {
                    cout << "No database available.\n";
                    logger.log(WARNING, "Filter by birth year requested but database empty");
                    break;
                }
                cout << "Enter base name: ";
                string baseName;
                getline(cin, baseName);

                StudentsBase* basePtr = NULL;
                list<StudentsBase>::iterator it;
                for (it = dataBase.begin(); it != dataBase.end(); ++it) {
                    if (it->getName() == baseName) {
                        basePtr = &(*it);
                        break;
                    }
                }
                if (basePtr == NULL) {
                    cout << "Base '" << baseName << "' not found.\n";
                    logger.log(ERROR, "Base '" + baseName + "' not found for filter by birth year");
                    break;
                }
                cout << "Enter birth year: ";
                int year;
                if (!(cin >> year)) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid input for year.\n";
                    logger.log(WARNING, "Invalid year input for filter");
                    break;
                }
                cin.ignore(10000, '\n');

                list<Student> filtered = basePtr->sortByYear(year);
                showBase(filtered);
                logger.log(INFO, "Filtered by birth year '" + to_string(year) + "' in base '" + baseName + "'");
                break;
            }

            case 9:
                cout << "Exit program.\n";
                logger.log(INFO, "Program ended by user.");
                running = false;
                break;

            default:
                cout << "Invalid option. Try again.\n";
                logger.log(WARNING, "Invalid menu option");
                break;
        }
    }

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

    Student newStudent(studentSurname, studentName, *faculty, *course, *group, birthYear, phoneNumber, *base);

 
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
