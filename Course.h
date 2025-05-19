#pragma once
#include <list>
#include <iostream>
#include "Group.h"


class Faculty;


class Course
{
private:
    std::string m_name;
    std::list<Group> m_groups;
    Faculty& m_faculty;
public:
 std::list<Group>& VectorOfGroups();
    void showGroups();
    std::string  getName() const;
    void print();
    void addGroup(std::string name);
    Group* getGroup(std::string name);
   Course(std::string name, Faculty& faculty): m_name(name), m_faculty(faculty){};

};