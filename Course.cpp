#include "Course.h"
#include "Group.h"
using namespace  std;



std::list<Group>& Course::VectorOfGroups(){

    return m_groups;
}


 Group* Course::getGroup(std::string name){
    for (Group& curr : m_groups) {
        if (curr.getName() == name) {
            return &curr;
        }
    }
    return nullptr;
  
 }

void Course:: showGroups(){


    cout<<"Group list"<<endl;

    for (Group& curr : m_groups) {
        curr.print();
    }
    
}

void Course:: addGroup(std::string name){
   
    Group newGroup(name, m_faculty, *this);
    m_groups.push_back(newGroup);

}

string Course::getName () const{
    return m_name;
}

void Course::print(){
    cout<<m_name<<endl;
}
