//
// Created by 徐恺泞 on 2021/6/22.
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

//界面绘制及功能实现类
using namespace std;
class window {
private:
    vector<classes*>& classd;//存储班级
    File& filed;//文件操作

    void _addNewStudent();//增加一个学生信息
    [[noreturn]] void _showStudents();//显示学生信息
    [[noreturn]] void _findAnStudent();//查找学生信息
    [[noreturn]] void _deleteAnStudent();//删除一个学生信息
    void _saveStudentInfo();//保存学生信息
    void _exportStudentInfo();//导出学生信息
public:
    window(vector<classes *> &classd, File &filed);//构造函数
    [[noreturn]] void _interface();//主界面

};


#endif //STUDENTMANAGER_WINDOW_H
