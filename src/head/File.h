//
// Created by �޲��� on 2021/6/21.
//

#ifndef STUDENTMANAGER_FILE_H
#include <iostream>
#include <utility>
#include <vector>
#include "class.h"
#include <io.h>
#include <fstream>
#include "util.h"
#include <windows.h>
#define STUDENTMANAGER_FILE_H


using namespace std;
class File {
private:
    string path;

public:
    File(const string &path);

    vector<string> getAllDiretorys();//��ȡѧ���洢Ŀ¼�������ļ��е�����
    vector<string> getAllFiles();//��ȡѧ���洢Ŀ¼�������ļ�������
    bool writeStudent(classes classes,student stud);//��һ��ѧ��д�뵽�ļ�
    bool writeAllStudents(classes classes);//��һ���༶������ѧ��д�뵽�ļ�
    student readStudent(classes classes,string studentName);//��ȡһ��ѧ����������
    vector<student> readAllStudent(classes classes);//��ȡһ���༶��ѧ����������
};


#endif //STUDENTMANAGER_FILE_H
