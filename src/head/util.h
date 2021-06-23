//
// Created by 徐恺泞 on 2021/6/21.
//

#ifndef STUDENTMANAGER_UNIT_H
#include<iostream>
#include<vector>
#define STUDENTMANAGER_UNIT_H

//工具类
using namespace std;
class util {
public:
    //分割字符串
    static void split(const string& s, vector<string>& tokens, const string& delimiters);
};


#endif //STUDENTMANAGER_UNIT_H
