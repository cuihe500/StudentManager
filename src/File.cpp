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
//                if(strcmp(fileInfo.name, ".") != 0 && strcmp(fileInfo.name, "..") != 0)
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
    string paths=path+classes.getMajor()+" "+classes.getName();
    CreateDirectory(paths.c_str(), NULL);
    ofstream ofstream1;
    ofstream1.open(paths+"\\"+classes.getName()+" "+stud.getName()+".txt");
    if(!ofstream1.is_open()){
        return false;
    }
    ofstream1 <<stud.getId()<<"."
    <<"姓名:"<<stud.getName()<<"    "
    <<"性别:"<<stud.getSex()<<"    "
    <<"学号:"<<stud.getStudentId()<<"    "
    <<"成绩:"<<stud.getResult()<<"    "
    <<"电话:"<<stud.getPhone();
    ofstream1.close();
    return true;

}

bool File::writeAllStudents(classes classes) {
    vector<student *>::iterator it;
    vector<student *> temp = classes.getStuds();
    string paths=path+classes.getMajor()+" "+classes.getName();
    CreateDirectory(paths.c_str(), NULL);
    for(it=temp.begin();it!=temp.end();it++) {
        ofstream ofstream1;
        ofstream1.open(paths+"\\"+ classes.getName() + " " + (*it)->getName() + ".txt");
        if (!ofstream1.is_open()) {
            return false;
        }
        ofstream1 << (*it)->getId() << "."
                  << "姓名:" << (*it)->getName() << "    "
                  << "性别:" << (*it)->getSex() << "    "
                  << "学号:" << (*it)->getStudentId() << "    "
                  << "成绩:" << (*it)->getResult() << "    "
                  << "电话:" << (*it)->getPhone();
        ofstream1.close();
    }
    return true;

}

student File::readStudent(classes classes, string studentName) {
    return student();
}

vector<student> File::readAllStudent(classes classes) {
    return vector<student>();
}

File::File(const string &path) : path(path) {}

