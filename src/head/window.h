//
// Created by ����Ţ on 2021/6/22.
//

#ifndef STUDENTMANAGER_WINDOW_H
#include<iostream>
#include "File.h"
#include <direct.h>
#include <map>
#include<algorithm>
#define STUDENTMANAGER_WINDOW_H

#define __ONE__ 1
#define __TWO__ 2
#define __THREE__ 3
#define __FOUR__ 4
#define __FIVE__ 5
#define __SIX__ 6
#define __SEVEN__ 7
#define __EIGHT__ 8
#define __NIGNT__ 9

//������Ƽ�����ʵ����
using namespace std;
class window {
private:
    vector<classes*>& classd;//�洢�༶
    File& filed;//�ļ�����

    void _addNewStudent();//����һ��ѧ����Ϣ
    [[noreturn]] void _showStudents();//��ʾѧ����Ϣ
    [[noreturn]] void _findAnStudent();//����ѧ����Ϣ
    [[noreturn]] void _deleteAnStudent();//ɾ��һ��ѧ����Ϣ
    void _saveStudentInfo();//����ѧ����Ϣ
    void _exportStudentInfo();//����ѧ����Ϣ
public:
    window(vector<classes *> &classd, File &filed);//���캯��
    [[noreturn]] void _interface();//������

};


#endif //STUDENTMANAGER_WINDOW_H
