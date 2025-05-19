#include "StudentsBase.h"
#include "Faculty.h"
#include "Course.h"
#include "Student.h"

using namespace  std;

void StudentsBase:: loadFromFile(const std::string& filename,  std::list<Faculty>& faculties) {
    string line;
    
        string surname, name, facultyName, courseName, groupName;
        string birthYearStr, phoneStr;
    ifstream inFile(filename);
  
    

    if (!inFile) {
        cerr << "Cannot open file for reading: " << filename << std::endl;
       
    }

    
    

    while (getline(inFile, line)) {
        

        istringstream ss(line);

        getline(ss, surname, ',');
        getline(ss, name, ',');
        getline(ss, facultyName, ',');
        getline(ss, courseName, ',');
        getline(ss, groupName, ',');
        getline(ss, birthYearStr, ',');
        getline(ss, phoneStr, ',');
    

        int birthYear = std::stoi(birthYearStr);
        int phone = std::stoi(phoneStr);

       
        Faculty* faculty = nullptr;
        for (Faculty& f : faculties) {
            if (f.getName() == facultyName) {
                faculty = &f;
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

        Student student(surname, name, *faculty, *course, *group, birthYear, phone, *this);

      
    addStudent(student);
    }
}

  



 std::list<Student> StudentsBase::getStudents(){
    return m_students;
 }

 void StudentsBase::saveToFile(const std::string& filename){

    std::ofstream outFile(filename);
     if (!outFile) {
        std::cerr << "Cannot open file for writing: " << filename << std::endl;
        return;
    }

     for (Student&  curr :  m_students) {
        outFile << curr.getSurname() << ','
                << curr.getName() << ','
                << curr.getFaculty().getName() << ','
                << curr.getCourse().getName() << ','
                << curr.getGroup().getName() << ','
                << curr.getBirthYear() << ','
                << curr.getPhoneNumber() << '\n';
    }
}

 





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