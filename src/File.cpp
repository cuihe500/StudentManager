//
// Created by 崔昌赫 on 2021/6/21.
//

#include "head/File.h"

vector<string> File::getAllDiretorys() {

    vector<string> files;
    long hFile = 0;
    struct _finddata_t fileInfo{};
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\studentInfo").append("\\*").c_str(), &fileInfo)) != -1)
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

vector<string> File::getAllFiles(const string& paths) {

    vector<string> files;
    long hFile = 0;
    struct _finddata_t fileInfo{};
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\").append("studentInfo\\").append(paths).append("\\*").c_str(), &fileInfo)) != -1)
    {
        while (_findnext(hFile, &fileInfo) == 0){
            vector<string> temp;
            if(strcmp(fileInfo.name, ".") != 0 && strcmp(fileInfo.name, "..") != 0) {
                files.emplace_back(fileInfo.name);
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
    ofstream1.open(paths+"\\"+"studentInfo\\"+classes.getName()+" "+stud.getName()+".txt");
    if(!ofstream1.is_open()){
        return false;
    }
    ofstream1 <<stud.getId()<<"    "
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
        ofstream1.open(paths+"\\"+"studentInfo\\"+ classes.getName() + " " + (*it)->getName() + ".txt");
        if (!ofstream1.is_open()) {
            return false;
        }
        ofstream1 << (*it)->getId() << "    "
                  << "姓名:" << (*it)->getName() << "    "
                  << "性别:" << (*it)->getSex() << "    "
                  << "学号:" << (*it)->getStudentId() << "    "
                  << "成绩:" << (*it)->getResult() << "    "
                  << "电话:" << (*it)->getPhone();
        ofstream1.close();
    }
    return true;

}


bool File::readAllStudent(classes &class1) {
    string paths=path+"\\studentInfo\\"+class1.getMajor()+" "+class1.getName();
    vector<string>fileName = getAllFiles(class1.getMajor()+" "+class1.getName());
    vector<string>::iterator it;
    for(it=fileName.begin();it!=fileName.end();it++){
        ifstream ifStream1(paths+"\\"+ *it);
        if(!ifStream1.is_open())    continue;
        string temp;
        student* tempStud = new student;
        vector<string>tempInfos;
        vector<string>::iterator itForInfo;
        vector<string>Infos;
        while(getline(ifStream1,temp))
        {
            util::split(temp,tempInfos,"    ");
            for(itForInfo=tempInfos.begin()+1;itForInfo!=tempInfos.end();itForInfo++){
                vector<string>tempInfo;
                util::split(*itForInfo,tempInfo,":");
                Infos.push_back(tempInfo[1]);
            }

            if(!Infos.empty()) {
                tempStud->setId(atoi(tempInfos[0].c_str()));
                tempStud->setName(Infos[0]);
                tempStud->setSex(Infos[1]);
                tempStud->setStudentId(Infos[2]);
                tempStud->setResult(atof(Infos[3].c_str()));
                tempStud->setPhone(Infos[4].c_str());
                class1.add_Student(tempStud);
            }else return false;
        }
    }

    return true;
}

bool File::writeAllStudents(classes classes, const string& pathd) {
    vector<student *>::iterator it;
    vector<student *> temp = classes.getStuds();
    string apath=path+pathd;
    CreateDirectory(apath.c_str(), NULL);
    string paths=path+"\\"+pathd+"\\"+classes.getMajor()+" "+classes.getName();
    CreateDirectory(paths.c_str(), NULL);
    for(it=temp.begin();it!=temp.end();it++) {
        ofstream ofstream1;
        ofstream1.open(paths+"\\"+ classes.getName() + " " + (*it)->getName() + ".txt");
        if (!ofstream1.is_open()) {
            return false;
        }
        ofstream1 << (*it)->getId() << "    "
                  << "姓名:" << (*it)->getName() << "    "
                  << "性别:" << (*it)->getSex() << "    "
                  << "学号:" << (*it)->getStudentId() << "    "
                  << "成绩:" << (*it)->getResult() << "    "
                  << "电话:" << (*it)->getPhone();
        ofstream1.close();
    }
    return true;

    return false;
}

bool File::deleteAnStudent(classes &class1, const student& stud1) {
    string paths=path+"\\studentInfo\\"+class1.getMajor()+" "+class1.getName()+"\\"+ class1.getName() + " " + stud1.getName() + ".txt";
    if(remove(paths.c_str())!=EOF){
        return true;
    }else return false;
}




