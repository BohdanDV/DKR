
#include "Student.H"
using namespace std;


string Student::getSurname() const {
    return m_surname;
}

string Student::getName() const {
    return m_name;
}

int Student::getBirthYear() const {
    return m_date;
}

int Student::getPhoneNumber() const {
    return m_phoneNumber;
}

Faculty& Student::getFaculty() const {
    return m_faculty;
}

Course& Student::getCourse() const {
    return m_course;
}

Group& Student::getGroup() const {
    return m_group;
}