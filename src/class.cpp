//
// Created by 崔昌赫 on 2021/6/21.
//

#include "head/class.h"



//学生信息CUDR
void classes::add_Student(student *temp) {
    studs.push_back(temp);
    sortAll();
}

void classes::add_Student_No_Sort(student *temp) {
    studs.push_back(temp);
}
void classes::inset_Student(student *temp, int site) {
    vector<student *>::iterator it;
    studs.insert((it+=site),temp);
    sortAll();
}

student classes::search_via_ID(int id) {
    student temp;
    vector<student *>::iterator it;
    temp.setId(0);
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getId()==id){
            return *(*it);
        }
    }
    return temp;
}

vector<student *> classes::search_via_Name(const string& studentName) {
    vector<student *>::iterator it;
    vector<student *>temp;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getName()==studentName){
            temp.push_back(*it);
        }
    }
    return temp;
}

vector<student *> classes::search_via_StudentID(const string& studentID) {
    vector<student *>::iterator it;
    vector<student *>temp;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getStudentId()==studentID){
            temp.push_back(*it);
        }
    }
    return temp;
}

vector<student *> classes::search_via_Result(double result) {
    vector<student *>::iterator it;
    vector<student *>temp;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getResult()==result){
            temp.push_back(*it);
        }
    }
    return temp;
}

vector<student *> classes::search_via_Phone(const string& phone) {
    vector<student *>::iterator it;
    vector<student *>temp;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getPhone()==phone){
            temp.push_back(*it);
        }
    }
    return temp;
}

bool classes::delete_via_ID(int id) {
    vector<student *>::iterator it;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getId()==id){
            studs.erase(it);
            sortAll();
            return true;
        }
    }
    return false;
}

bool classes::delete_via_Name(const string& studentName) {
    vector<student *>::iterator it;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getName()==studentName){
            studs.erase(it);
            sortAll();
            return true;
        }
    }
    return false;
}

bool classes::delete_via_StudentID(const string& studentID) {
    vector<student *>::iterator it;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getStudentId()==studentID){
            studs.erase(it);
            sortAll();
            return true;
        }
    }
    return false;
}

bool classes::delete_via_Result(double result) {
    vector<student *>::iterator it;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getResult()==result){
            studs.erase(it);
            sortAll();
            return true;
        }
    }
    return false;
}

bool classes::delete_via_Phone(const string& phone) {
    vector<student *>::iterator it;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getPhone()==phone){
            studs.erase(it);
            sortAll();
            return true;
        }
    }
    return false;
}

bool classes::change_via_ID(int id,student * newStudent) {
    vector<student *>::iterator it;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getId()==id){
            studs.erase(it);
            studs.insert(it, newStudent);
            sortAll();
            return true;
        }
    }
    return false;
}

bool classes::change_via_Name(const string& studentName,student * newStudent) {
    vector<student *>::iterator it;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getName()==name){
            studs.erase(it);
            studs.insert(it, newStudent);
            sortAll();
            return true;
        }
    }
    return false;
}

bool classes::change_via_StudentID(const string& studentID,student * newStudent) {
    vector<student *>::iterator it;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getStudentId()==studentID){
            studs.erase(it);
            studs.insert(it, newStudent);
            sortAll();
            return true;
        }
    }
    return false;
}

bool classes::change_via_Result(double result,student * newStudent) {
    vector<student *>::iterator it;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getResult()==result){
            studs.erase(it);
            studs.insert(it, newStudent);
            sortAll();
            return true;
        }
    }
    return false;
}

bool classes::change_via_Phone(const string& phone,student * newStudent) {
    vector<student *>::iterator it;
    for(it=studs.begin();it!=studs.end();it++){
        if((*it)->getPhone()==phone){
            studs.erase(it);
            studs.insert(it, newStudent);
            sortAll();
            return true;
        }
    }
    return false;
}

//重新排序所有id
void classes::sortAll() {
    vector<student*>::iterator it;
    int id=1;
    for(it=studs.begin();it!=studs.end();it++,id++){
        (*it)->setId(id);
    }
}

unsigned int classes::getTotalStudent() {
    return studs.size();
}






