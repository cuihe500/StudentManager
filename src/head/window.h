//
// Created by ´Þ²ýºÕ on 2021/6/22.
//

#ifndef STUDENTMANAGER_WINDOW_H
#include<iostream>
#include "File.h"
#include <direct.h>
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

using namespace std;
class window {
private:
    vector<classes*>& classd;
    File& filed;
    void _addNewStudent();
    [[noreturn]] void _showStudents();

    [[noreturn]] void _findAnStudent();

    [[noreturn]] void _deleteAnStudent();
    void _saveStudentInfo();
    void _exportStudentInfo();
public:
    window(vector<classes *> &classd, File &filed);

    [[noreturn]] void _interface();

};


#endif //STUDENTMANAGER_WINDOW_H
