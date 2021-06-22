//
// Created by 崔昌赫 on 2021/6/21.
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

    vector<string> getAllDiretorys();//获取学生存储目录下所有文件夹的名字
    vector<string> getAllFiles();//获取学生存储目录下所有文件的名字
    bool writeStudent(classes classes,student stud);//将一个学生写入到文件
    bool writeAllStudents(classes classes);//将一个班级的所有学生写入到文件
    student readStudent(classes classes,string studentName);//读取一个学生到程序中
    vector<student> readAllStudent(classes classes);//读取一个班级的学生到程序中
};


#endif //STUDENTMANAGER_FILE_H
