//
// Created by ����Ţ on 2021/6/21.
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
#include <string>
#include <cstdio>
#define STUDENTMANAGER_FILE_H

//���ļ����в���(�ļ���װ��)
using namespace std;
class File {
private:
    string path;

public:
    explicit File(string path) : path(std::move(path)) {}

    vector<string> getAllDiretorys();//��ȡѧ���洢Ŀ¼�������ļ��е�����
    vector<string> getAllFiles(const string& path);//��ȡѧ���洢Ŀ¼�������ļ�������
    bool writeStudent(classes classes,student stud);//��һ��ѧ��д�뵽�ļ�
    bool writeAllStudents(classes classes);//��һ���༶������ѧ��д�뵽�ļ�
    bool writeAllStudents(classes classes,const string& path);//��һ���༶������ѧ��д�뵽�ļ�
    bool readAllStudent(classes &class1);//��ȡһ���༶��ѧ����������
    bool deleteAnStudent(classes &class1,const student& stud);//ɾ��һ��ѧ����Ϣ�ļ�
};


#endif //STUDENTMANAGER_FILE_H
