//
// Created by ����Ţ on 2021/6/21.
//

#ifndef STUDENTMANAGER_STUDENT_H
#define STUDENTMANAGER_STUDENT_H
#include <iostream>
#endif //STUDENTMANAGER_STUDENT_H

using namespace std;


/*
 * ���ͷ�ļ��ǶԵ���ѧ����Ϣ���г����װ
 * */

class student{
private:
    int ID; //�������� ��ʱ�����Զ�����
    string studentId;//ѧ��
    string name;//ѧ������
    string sex;//�Ա�
    double result;//�ɼ�
    string phone;//�绰

public:
    //ȫ��Ϣ���캯��
    student(const string &studentId, const string &name, const string &sex, const double &result,
            const string &phone) :  studentId(studentId), name(name), sex(sex), result(result), phone(phone) {};
    //�޲ι��캯��
    student() {};

    //get&set�ӿ�

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

