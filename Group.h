#pragma once
#include <list>
#include <iostream>
#include "StudentsBase.h"

class Faculty;
class Course;



class Group
{
private:
    std::string m_name;
    Faculty& m_faculty;
    Course& m_course;
   
public:
    std::string  getName() const;
    void print();
    Group (std::string name, Faculty& faculty, Course& course 
         ): m_name(name),m_faculty(faculty), m_course(course) {};
};