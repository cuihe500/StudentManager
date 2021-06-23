//
// Created by 徐恺泞 on 2021/6/21.
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

//对文件进行操作(文件封装类)
using namespace std;
class File {
private:
    string path;

public:
    explicit File(string path) : path(std::move(path)) {}

    vector<string> getAllDiretorys();//获取学生存储目录下所有文件夹的名字
    vector<string> getAllFiles(const string& path);//获取学生存储目录下所有文件的名字
    bool writeStudent(classes classes,student stud);//将一个学生写入到文件
    bool writeAllStudents(classes classes);//将一个班级的所有学生写入到文件
    bool writeAllStudents(classes classes,const string& path);//将一个班级的所有学生写入到文件
    bool readAllStudent(classes &class1);//读取一个班级的学生到程序中
    bool deleteAnStudent(classes &class1,const student& stud);//删除一个学生信息文件
};


#endif //STUDENTMANAGER_FILE_H
