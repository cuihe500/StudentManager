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
    string numOfStu;//学生数量
    string major;//所属院系名称
    //存储学生信息
    /*
     * 如果再手动写一个链表太耗时麻烦了，我索性就用c++中的stl容器替代了
     * 你们班的acm的人应该都会用 我觉得应该没啥问题
     * 如果你觉得不行的话 在联系我 我手动给你实现一个vector
     * */
    vector<student> studs;

public:
    //全信息构造函数(除了学生信息 可以理解为设置班级的基本信息)
    classes(const string &name, const string &numOfStu, const string &major) : name(name), numOfStu(numOfStu),
                                                                               major(major) {};
    //无参构造函数
    classes() {};


    //get&set接口 只设置前三个基本信息 并不对学生信息vector进行开放
    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        classes::name = name;
    }

    const string &getNumOfStu() const {
        return numOfStu;
    }

    void setNumOfStu(const string &numOfStu) {
        classes::numOfStu = numOfStu;
    }

    const string &getMajor() const {
        return major;
    }

    void setMajor(const string &major) {
        classes::major = major;
    }

    //学生信息CUDR
    void add_Student(const student& temp);//增加
    void inset_Student(const student& temp,int site);//插入
    //查找学生信息
    student search_via_ID(int id);//通过id查找
    student search_via_Name(const string& studentName);//通过姓名查找
    student search_via_StudentID(const string& studentID);//通过学号查找
    student search_via_Result(double result);//通过成绩查找
    student search_via_Phone(const string& phone);//通过电话查找
    //删除学生信息
    bool delete_via_ID(int id);//通过id删除
    bool delete_via_Name(const string& studentName);//通过姓名删除
    bool delete_via_StudentID(const string& studentID);//通过学号删除
    bool delete_via_Result(double result);//通过成绩删除
    bool delete_via_Phone(const string& phone);//通过电话删除
    //更改学生信息
    bool change_via_ID(int id,const student& newStudent);//通过id删除
    bool change_via_Name(const string& studentName,const student& newStudent);//通过姓名删除
    bool change_via_StudentID(const string& studentID,const student& newStudent);//通过学号删除
    bool change_via_Result(double result,const student& newStudent);//通过成绩删除
    bool change_via_Phone(const string& phone,const student& newStudent);//通过电话删除

    //内置工具方法(util)
    void sortAll();//重新排序所有id
};