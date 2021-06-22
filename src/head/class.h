//
// Created by 崔昌赫 on 2021/6/21.
//

#ifndef STUDENTMANAGER_CLASS_H
#define STUDENTMANAGER_CLASS_H
#include <iostream>
#include <vector>
#include "student.h"
#endif //STUDENTMANAGER_CLASS_H

/*
 * 这个是对班级信息进行抽象封装
 * 班级会包括学生:
 * student->class
 * */

class classes{
private:
    //班级基本信息
    string name;//班级名
    string major;//所属院系名称
    //存储学生信息
    /*
     * 如果再手动写一个链表太耗时麻烦了，我索性就用c++中的stl容器替代了
     * 你们班的acm的人应该都会用 我觉得应该没啥问题
     * 如果你觉得不行的话 在联系我 我手动给你实现一个vector
     * */
    vector<student*> studs;

public:
    //全信息构造函数(除了学生信息 可以理解为设置班级的基本信息)
    classes(const string &name, const string &major) : name(name),major(major) {};
    //无参构造函数
    classes() {};


    //get&set接口 只设置前三个基本信息 并不对学生信息vector进行开放
    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        classes::name = name;
    }

    const string &getMajor() const {
        return major;
    }

    void setMajor(const string &major) {
        classes::major = major;
    }
    vector<student*> getStuds(){
        return this->studs;
    }

    void setStuds(const vector<student *> &studs) {
        classes::studs = studs;
    }

    //学生信息CUDR
    void add_Student(student * temp);//增加
    void add_Student_No_Sort(student * temp);//增加(不重排序)
    void inset_Student(student * temp,int site);//插入
    //查找学生信息
    student search_via_ID(int id);//通过id查找(只有一个结果 所以用单指针)
    vector<student *> search_via_Name(const string& studentName);//通过姓名查找
    vector<student *> search_via_StudentID(const string& studentID);//通过学号查找
    vector<student *> search_via_Result(double result);//通过成绩查找
    vector<student *> search_via_Phone(const string& phone);//通过电话查找
    //删除学生信息
    bool delete_via_ID(int id);//通过id删除
    bool delete_via_Name(const string& studentName);//通过姓名删除
    bool delete_via_StudentID(const string& studentID);//通过学号删除
    bool delete_via_Result(double result);//通过成绩删除
    bool delete_via_Phone(const string& phone);//通过电话删除
    //更改学生信息
    bool change_via_ID(int id,student * newStudent);//通过id更改
    bool change_via_Name(const string& studentName,student * newStudent);//通过姓名更改
    bool change_via_StudentID(const string& studentID,student * newStudent);//通过学号更改
    bool change_via_Result(double result,student * newStudent);//通过成绩更改
    bool change_via_Phone(const string& phone,student * newStudent);//通过电话更改

    //内置工具方法(util)
    void sortAll();//重新排序所有id
    unsigned int getTotalStudent();
};