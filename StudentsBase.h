#pragma once
#include <list>
#include <iostream>
#include "Student.h"


class Group;




class StudentsBase
{

private:
    std::string m_name;
    std::list<Student> m_students;
   
    
public:
    std::string getName();
    std::list<Student>& getBase();
    StudentsBase(std::string name): m_name(name){};
    void addStudent(Student student);
    void deleteStudent(int index);//
    std::list<Student> sortByFaculty(std::string faculty);
    std::list<Student> sortByFacultyAndCourse(std::string faculty, std::string course);
    std::list<Student> sortByGroup(std::string group);
    std::list<Student> sortByYear(int year);

};