#include "Faculty.h"
#include "Course.h"
using namespace std;

std::list<Course>& Faculty::VectorOfCourses(){

    return m_cources;
}
string Faculty::getName () const{
    return m_name;
}

 Course* Faculty::getCourse(std::string name){
    for (Course& curr : m_cources) {
        if (curr.getName() == name) {
            return &curr;
        }
    }
    return nullptr;
  
 }

void Faculty:: addCourse(std::string name){
   

    Course newCourse(name, *this); 
    m_cources.push_back(newCourse);

}

void Faculty:: showCourses(){


    cout<<"Courses list"<<endl;

    for (Course& curr : m_cources) {
        curr.print();
    }
    
}
