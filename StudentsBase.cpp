#include "StudentsBase.h"
#include "Faculty.h"
#include "Course.h"
using namespace  std;

std::list<Student> StudentsBase::sortByYear(int year){

list<Student> result;
    for(Student& curr: m_students){
        
        if(curr.getBirthYear() > year) result.push_back(curr);
    }

    return result;
    

}

list<Student> StudentsBase::sortByGroup(std::string group){

    list<Student> result;
    for(Student& curr: m_students){
        for(Course& Cource: curr.getFaculty().VectorOfCourses()){

            for(Group& currGr: Cource.VectorOfGroups())

                 if(currGr.getName() == group) result.push_back(curr);

        }
        
    
    }

    return result;

}

list<Student> StudentsBase::sortByFacultyAndCourse(string faculty, string course){
    list<Student> result;
    for(Student& curr: m_students){

        if(curr.getFaculty().getName() == faculty && curr.getCourse().getName()==course) result.push_back(curr);
    }

    return result;
}

list<Student> StudentsBase::sortByFaculty(string faculty){

    list<Student> result;
    for(Student& curr: m_students){

        if(curr.getFaculty().getName() == faculty) result.push_back(curr);
    }

    return result;

}
   
list<Student>& StudentsBase::getBase(){
    return m_students;
}

 string StudentsBase::getName(){
        return m_name;
    }

void StudentsBase::addStudent(Student student){
    m_students.push_back(student);

}