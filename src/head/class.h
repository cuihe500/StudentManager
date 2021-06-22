//
// Created by �޲��� on 2021/6/21.
//

#ifndef STUDENTMANAGER_CLASS_H
#define STUDENTMANAGER_CLASS_H
#include <iostream>
#include <vector>
#include "student.h"
#endif //STUDENTMANAGER_CLASS_H

/*
 * ����Ƕ԰༶��Ϣ���г����װ
 * �༶�����ѧ��:
 * student->class
 * */

class classes{
private:
    //�༶������Ϣ
    string name;//�༶��
    string numOfStu;//ѧ������
    string major;//����Ժϵ����
    //�洢ѧ����Ϣ
    /*
     * ������ֶ�дһ������̫��ʱ�鷳�ˣ������Ծ���c++�е�stl���������
     * ���ǰ��acm����Ӧ�ö����� �Ҿ���Ӧ��ûɶ����
     * �������ò��еĻ� ����ϵ�� ���ֶ�����ʵ��һ��vector
     * */
    vector<student*> studs;

public:
    //ȫ��Ϣ���캯��(����ѧ����Ϣ �������Ϊ���ð༶�Ļ�����Ϣ)
    classes(const string &name, const string &numOfStu, const string &major) : name(name), numOfStu(numOfStu),
                                                                               major(major) {};
    //�޲ι��캯��
    classes() {};


    //get&set�ӿ� ֻ����ǰ����������Ϣ ������ѧ����Ϣvector���п���
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
    vector<student*> getStuds(){
        return this->studs;
    }



    //ѧ����ϢCUDR
    void add_Student(student * temp);//����
    void inset_Student(student * temp,int site);//����
    //����ѧ����Ϣ
    student* search_via_ID(int id);//ͨ��id����
    student* search_via_Name(const string& studentName);//ͨ����������
    student* search_via_StudentID(const string& studentID);//ͨ��ѧ�Ų���
    student* search_via_Result(double result);//ͨ���ɼ�����
    student* search_via_Phone(const string& phone);//ͨ���绰����
    //ɾ��ѧ����Ϣ
    bool delete_via_ID(int id);//ͨ��idɾ��
    bool delete_via_Name(const string& studentName);//ͨ������ɾ��
    bool delete_via_StudentID(const string& studentID);//ͨ��ѧ��ɾ��
    bool delete_via_Result(double result);//ͨ���ɼ�ɾ��
    bool delete_via_Phone(const string& phone);//ͨ���绰ɾ��
    //����ѧ����Ϣ
    bool change_via_ID(int id,student * newStudent);//ͨ��id����
    bool change_via_Name(const string& studentName,student * newStudent);//ͨ����������
    bool change_via_StudentID(const string& studentID,student * newStudent);//ͨ��ѧ�Ÿ���
    bool change_via_Result(double result,student * newStudent);//ͨ���ɼ�����
    bool change_via_Phone(const string& phone,student * newStudent);//ͨ���绰����

    //���ù��߷���(util)
    void sortAll();//������������id
};