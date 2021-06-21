//
// Created by 崔昌赫 on 2021/6/21.
//

#ifndef STUDENTMANAGER_STUDENT_H
#define STUDENTMANAGER_STUDENT_H
#include <iostream>
#endif //STUDENTMANAGER_STUDENT_H

using namespace std;


/*
 * 这个头文件是对单个学生信息进行抽象封装
 * */

class student{
private:
    int ID; //这个是序号 到时候会会自动排序
    string studentId;//学号
    string name;//学生姓名
    string sex;//性别
    double result;//成绩
    string phone;//电话

public:
    //全信息构造函数
    student(int id, const string &studentId, const string &name, const string &sex, const double &result,
            const string &phone) : ID(id), studentId(studentId), name(name), sex(sex), result(result), phone(phone) {};
    //无参构造函数
    student() {};

    //get&set接口

    int getId() const {
        return ID;
    }

    void setId(int id) {
        ID = id;
    }

    const string &getStudentId() const {
        return studentId;
    }

    void setStudentId(const string &studentId) {
        student::studentId = studentId;
    }

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        student::name = name;
    }

    const string &getSex() const {
        return sex;
    }

    void setSex(const string &sex) {
        student::sex = sex;
    }

    const double &getResult() const {
        return result;
    }

    void setResult(const double &result) {
        student::result = result;
    }
    const string &getPhone() const {
        return phone;
    }

    void setPhone(const string &phone) {
        student::phone = phone;
    }
};

