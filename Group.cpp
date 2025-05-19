#include "Group.h"
using namespace std;

string Group::getName () const{
    return m_name;
}

void Group::print(){
    cout<<m_name<<endl;
}