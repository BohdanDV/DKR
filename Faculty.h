#pragma once
#include <list>
#include <iostream>
#include "Course.h"


class Faculty
{
private:
   std::string m_name;
   std::list<Course> m_cources;
   
    
public:
    std::string  getName() ;
    std::list<Course>& VectorOfCourses();
    

    Faculty(std::string name): m_name(name){};
    Course* getCourse(std::string name);
    void addCourse(std::string name);
    void showCourses();

    
    
   // ~Faculty();
};
/*
Faculty::Faculty()
{
}

Faculty::~Faculty()
{
}
*/