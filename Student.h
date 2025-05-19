#pragma once
#include <iostream>



class Faculty;
class Group;
class Course;


class Student
{
private:
    std::string m_name;
    std::string m_surname;
    Faculty& m_faculty;
    Course& m_course;
    Group& m_group;
   
    int m_date;
    int m_phoneNumber;
public:

    Student();


    Student( std::string surname,  std::string name, Faculty& faculty, Course& course, Group& group, int date, int phoneNumber):m_name(name), m_surname(surname), m_faculty(faculty)
    , m_course(course), m_group(group), m_date(date), m_phoneNumber(phoneNumber){};


    std::string getSurname() const;
    std::string getName() const;
    int getBirthYear() const;
    int getPhoneNumber() const;
    Faculty& getFaculty() const;
    Course& getCourse() const;
    Group& getGroup() const;
};