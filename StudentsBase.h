#pragma once
#include <list>
#include <iostream>
#include "Student.h"
#include <fstream>
#include <iomanip>

class Group;




class StudentsBase
{

private:
    std::string m_name;
    std::list<Student> m_students;
   
    
public:

    void loadFromFile(const std::string& filename, std::list<Faculty>& faculties);
    StudentsBase(const std::string name): m_name(name){};
    void saveToFile( const std::string& filename);
    std::string getName();
    std::list<Student>& getBase();
    void addStudent(Student student);
     std::list<Student> getStudents();
    void deleteStudent(int index);//
    std::list<Student> sortByFaculty(std::string faculty);
    std::list<Student> sortByFacultyAndCourse(std::string faculty, std::string course);
    std::list<Student> sortByGroup(std::string group);
    std::list<Student> sortByYear(int year);

};