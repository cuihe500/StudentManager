//
// Created by 崔昌赫 on 2021/6/21.
//

#include "head/File.h"

vector<string> File::getAllDiretorys() {

    vector<string> files;
    long hFile = 0;
    struct _finddata_t fileInfo{};
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileInfo)) != -1)
    {
        while(_findnext(hFile, &fileInfo) == 0){
            if ((fileInfo.attrib & _A_SUBDIR)) {
                if(strcmp(fileInfo.name, ".") != 0 && strcmp(fileInfo.name, "..") != 0)
                files.emplace_back(fileInfo.name);
            }
        }
        _findclose(hFile);

    } else{
    }
    return files;
}

vector<string> File::getAllFiles() {

    vector<string> files;
    long hFile = 0;
    struct _finddata_t fileInfo{};
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileInfo)) != -1)
    {
        while (_findnext(hFile, &fileInfo) == 0){
            vector<string> temp;
            if(strcmp(fileInfo.name, ".") != 0 && strcmp(fileInfo.name, "..") != 0) {
                util::split(fileInfo.name, temp, ".");
                files.emplace_back(temp[0]);
            }
        }
        _findclose(hFile);
    }
    return files;
}

bool File::writeStudent(classes classes, student stud) {
    return false;
}

bool File::writeAllStudents(classes classes) {
    return false;
}

student File::readStudent(classes classes, string studentName) {
    return student();
}

vector<student> File::readAllStudent(classes classes) {
    return vector<student>();
}

File::File(const string &path) : path(path) {}

