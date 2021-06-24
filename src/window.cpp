//
// Created by 崔昌赫 on 2021/6/22.
//

#include "head/window.h"

window::window(vector<classes *> &classd, File &filed) : classd(classd), filed(filed) {}

[[noreturn]] void window::_interface() {
    while(1) {
        cout << "           *************学生成绩管理系统*************" << endl;
        cout << "                         1.添加学生记录" << endl;
        cout << "                         2.显示学生记录" << endl;
        cout << "                         3.查找学生记录" << endl;
        cout << "                         4.删除学生记录" << endl;
        cout << "                         5.保存学生记录" << endl;
        cout << "                         6.导出学生记录" << endl;
        cout << "                         7.退出学生管理系统" << endl;
        cout << "           ***************************************" << endl;
        cout << "请输入您的选择:";
        int choice;
        cin >> choice;
        cin.get();
        switch (choice) {
            case __ONE__:
                _addNewStudent();
                break;
            case __TWO__:
                _showStudents();
                break;
            case __THREE__:
                _findAnStudent();
                break;
            case __FOUR__:
                _deleteAnStudent();
                break;
            case __FIVE__:
                _saveStudentInfo();
                break;
            case __SIX__:
                _exportStudentInfo();
                break;
            case __SEVEN__:
                exit(EXIT_SUCCESS);
                break;
            default:
                cout<<"输入错误!请重新输入."<<endl;
                break;
        }
    }
}

void window::_addNewStudent() {
    string info[7];
    cout << "---------请输入该学生所属信息---------"<<endl;
    cout << "该学生所在学院:";
    cin >> info[0];
    cout << "该学生所在学院的行政班级:";
    cin >> info[1];
    cout << "---------请输入该学生个人信息---------"<<endl;
    cout << "姓名:";
    cin >> info[2];
    cout << "性别(男/女):";
    cin >> info[3];
    cout << "学号:";
    cin >> info[4];
    cout << "成绩:";
    cin >> info[5];
    cout << "电话:";
    cin >> info[6];
    vector<classes *>::iterator it;
    bool isExsit=false;
    for(it=classd.begin();it!=classd.end();it++){
        if((*it)->getMajor()==info[0] && (*it)->getName()==info[1]) {
            isExsit = true;
            student * tempForStudent = new student(info[4],info[2],info[3], atof(info[5].c_str()),info[6]);
            (*it)->add_Student(tempForStudent);
            filed.writeStudent(*(*it),*tempForStudent);
        }

    }
    if(!isExsit){
        classes *tempForClass = new classes(info[1],info[0]);
        student * tempForStudent = new student(info[4],info[2],info[3], atof(info[5].c_str()),info[6]);
        tempForClass->add_Student(tempForStudent);
        classd.push_back(tempForClass);
        filed.writeStudent(*tempForClass,*tempForStudent);
    }
    cout <<"学生信息已经建立完毕."<<endl;
}

[[noreturn]] void window::_showStudents() {
    unsigned int SumOfStudents=0,SumOfClasses=classd.size();
    vector<classes *>::iterator it;
    for(it=classd.begin();it!=classd.end();it++){
        SumOfStudents+=(*it)->getTotalStudent();
    }
    while(true) {
    cout << "---------信息总览---------"<<endl;
    cout << endl;
    cout <<"目前信息库中共有:"<<to_string(SumOfClasses)<<"个班级,共"<<to_string(SumOfStudents)<<"个学生."<<endl;
    cout << endl;
    cout <<"---------班级信息---------"<<endl;
    int num=1;
    for(it=classd.begin();it!=classd.end();it++,num++)
        cout<<num<<"."<<(*it)->getMajor()<<" "<<(*it)->getName()<<endl;
    cout <<endl;
        cout << "请输入您要查看的班级序号(0.退出):";
        int choice;
        cin >> choice;
        cin.get();
        if (choice<=SumOfClasses && choice>0){
            for(int i =1;i<=(*classd[choice-1]).getTotalStudent();i++)
                cout
                <<"ID:"<<(*classd[choice-1]).search_via_ID(i).getId()<<"---"
                <<"姓名:"<<(*classd[choice-1]).search_via_ID(i).getName()<<"---"
                <<"性别:"<<(*classd[choice-1]).search_via_ID(i).getSex()<<"---"
                <<"学号:"<<(*classd[choice-1]).search_via_ID(i).getStudentId()<<"---"
                <<"成绩:"<<(*classd[choice-1]).search_via_ID(i).getResult()<<"---"
                <<"电话:"<<(*classd[choice-1]).search_via_ID(i).getPhone()
                <<endl;
            system("pause");
            break;
        }else if(choice == 0) {
            break;
        }else{
            cout << "输入错误!请重新输入!"<<endl;
        }
    }
}

[[noreturn]] void window::_findAnStudent() {
    while(true) {
    cout<<"---------查找学生---------"<<endl;
    cout <<"1.通过ID进行查找"<<endl;
    cout <<"2.通过姓名进行查找"<<endl;
    cout <<"3.通过学号进行查找"<<endl;
    cout <<"4.通过成绩进行查找"<<endl;
    cout <<"5.通过电话进行查找"<<endl;
    cout << "0.退出"<<endl;
    cout<<endl;
        cout << "请输入您的查找方式:" << endl;
        int choice;
        cin >> choice;
        cin.get();
        bool hasFind= false;
        vector<classes *>::iterator it;
        if (choice == 1) {
            cout << "请输入ID:" << endl;
            int ID;
            cin >> ID;
            cin.get();
            if (ID >= 0) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if ((*it)->search_via_ID(ID).getId() != 0) {
                        hasFind=true;
                        cout<<"---------"<<(*it)->getMajor()<<"  "<<(*it)->getName()<<"---------"<<endl;
                        cout
                                << "ID:" << (*it)->search_via_ID(ID).getId() << "---"
                                << "姓名:" << (*it)->search_via_ID(ID).getName() << "---"
                                << "性别:" << (*it)->search_via_ID(ID).getSex() << "---"
                                << "学号:" << (*it)->search_via_ID(ID).getStudentId() << "---"
                                << "成绩:" << (*it)->search_via_ID(ID).getResult() << "---"
                                << "电话:" << (*it)->search_via_ID(ID).getPhone()
                                << endl;
                        system("pause");
                    }else   continue;
                }
                if(!hasFind){
                    cout << "未找到学生信息库内对应数据!"<<endl;
                    system("pause");
                }
            } else {
                cout << "输入有误！请检查." << endl;
            }
        } else if (choice == 2) {
            cout << "请输入姓名:" << endl;
            string name;
            cin >> name;
            if (!name.empty()) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_Name(name).empty()) {
                        hasFind=true;
                        cout<<"---------"<<(*it)->getMajor()<<"  "<<(*it)->getName()<<"---------"<<endl;
                        for(int i =0;i<(*it)->search_via_Name(name).size();i++)
                        cout
                                << "ID:" << ((*it)->search_via_Name(name))[i]->getId() << "---"
                                << "姓名:" << ((*it)->search_via_Name(name))[i]->getName() << "---"
                                << "性别:" << ((*it)->search_via_Name(name))[i]->getSex() << "---"
                                << "学号:" << ((*it)->search_via_Name(name))[i]->getStudentId() << "---"
                                << "成绩:" << ((*it)->search_via_Name(name))[i]->getResult() << "---"
                                << "电话:" << ((*it)->search_via_Name(name))[i]->getPhone()
                                << endl;
                    }
                }
                if(!hasFind){
                    cout << "未找到学生信息库内对应数据!"<<endl;
                    system("pause");
                }
            } else {
                cout << "输入有误！请检查." << endl;
            }

        } else if (choice == 3) {
            cout << "请输入学号:" << endl;
            string studentID;
            cin >> studentID;
            if (!studentID.empty()) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_StudentID(studentID).empty()) {
                        hasFind=true;
                        cout<<"---------"<<(*it)->getMajor()<<"  "<<(*it)->getName()<<"---------"<<endl;
                        for(int i =0;i<(*it)->search_via_StudentID(studentID).size();i++)
                            cout
                                    << "ID:" << ((*it)->search_via_StudentID(studentID))[i]->getId() << "---"
                                    << "姓名:" << ((*it)->search_via_StudentID(studentID))[i]->getName() << "---"
                                    << "性别:" << ((*it)->search_via_StudentID(studentID))[i]->getSex() << "---"
                                    << "学号:" << ((*it)->search_via_StudentID(studentID))[i]->getStudentId() << "---"
                                    << "成绩:" << ((*it)->search_via_StudentID(studentID))[i]->getResult() << "---"
                                    << "电话:" << ((*it)->search_via_StudentID(studentID))[i]->getPhone()
                                    << endl;
                    }
                }
                if(!hasFind){
                    cout << "未找到学生信息库内对应数据!"<<endl;
                    system("pause");
                }
            } else {
                cout << "输入有误！请检查." << endl;
            }

        } else if (choice == 4) {
            cout << "请输入成绩:" << endl;
            double result;
            cin >> result;
            cin.get();
            if (result!=NULL) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_Result(result).empty()) {
                        hasFind=true;
                        cout<<"---------"<<(*it)->getMajor()<<"  "<<(*it)->getName()<<"---------"<<endl;
                        for(int i =0;i<(*it)->search_via_Result(result).size();i++)
                            cout
                                    << "ID:" << ((*it)->search_via_Result(result))[i]->getId() << "---"
                                    << "姓名:" << ((*it)->search_via_Result(result))[i]->getName() << "---"
                                    << "性别:" << ((*it)->search_via_Result(result))[i]->getSex() << "---"
                                    << "学号:" << ((*it)->search_via_Result(result))[i]->getStudentId() << "---"
                                    << "成绩:" << ((*it)->search_via_Result(result))[i]->getResult() << "---"
                                    << "电话:" << ((*it)->search_via_Result(result))[i]->getPhone()
                                    << endl;
                    }
                }
                if(!hasFind){
                    cout << "未找到学生信息库内对应数据!"<<endl;
                    system("pause");
                }
            } else {
                cout << "输入有误！请检查." << endl;
            }

        } else if (choice == 5) {
            cout << "请输入电话:" << endl;
            string phone;
            cin >> phone;
            if (!phone.empty()) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_Phone(phone).empty()) {
                        hasFind=true;
                        cout<<"---------"<<(*it)->getMajor()<<"  "<<(*it)->getName()<<"---------"<<endl;
                        for(int i =0;i<(*it)->search_via_Phone(phone).size();i++)
                            cout
                                    << "ID:" << ((*it)->search_via_Phone(phone))[i]->getId() << "---"
                                    << "姓名:" << ((*it)->search_via_Phone(phone))[i]->getName() << "---"
                                    << "性别:" << ((*it)->search_via_Phone(phone))[i]->getSex() << "---"
                                    << "学号:" << ((*it)->search_via_Phone(phone))[i]->getStudentId() << "---"
                                    << "成绩:" << ((*it)->search_via_Phone(phone))[i]->getResult() << "---"
                                    << "电话:" << ((*it)->search_via_Phone(phone))[i]->getPhone()
                                    << endl;
                    }
                }
                if(!hasFind){
                    cout << "未找到学生信息库内对应数据!"<<endl;
                    system("pause");
                }
            } else {
                cout << "输入有误！请检查." << endl;
            }

        } else if(choice == 0) {
            break;

        }else{
            cout << "输入有误！请检查." << endl;
        }
    }

}

[[noreturn]] void window::_deleteAnStudent() {
    while(true) {
        cout<<"---------删除学生---------"<<endl;
        cout <<"1.通过ID进行删除"<<endl;
        cout <<"2.通过姓名进行删除"<<endl;
        cout <<"3.通过学号进行删除"<<endl;
        cout <<"4.通过成绩进行删除"<<endl;
        cout <<"5.通过电话进行删除"<<endl;
        cout << "0.退出"<<endl;
        cout<<endl;
        cout << "请输入您的查找方式:" << endl;
        int choice;
        cin >> choice;
        cin.get();
        vector<classes *>::iterator it;
        vector<classes *>deleteList;
        bool hasFind=false;
        if (choice == 1) {
            cout << "请输入ID:" << endl;
            int ID;
            cin >> ID;
            cin.get();
            if (ID >= 0) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if ((*it)->search_via_ID(ID).getId() != 0) {
                        hasFind=true;
                        classes* temp = new classes((*it)->getName(),(*it)->getMajor());
                            student *tempOfStudent = new student;
                            tempOfStudent->setId((*it)->search_via_ID(ID).getId());
                            tempOfStudent->setName((*it)->search_via_ID(ID).getName());
                            tempOfStudent->setSex((*it)->search_via_ID(ID).getSex());
                            tempOfStudent->setStudentId((*it)->search_via_ID(ID).getStudentId());
                            tempOfStudent->setResult((*it)->search_via_ID(ID).getResult());
                            tempOfStudent->setPhone((*it)->search_via_ID(ID).getPhone());
                            temp->add_Student_No_Sort(tempOfStudent);
                            deleteList.push_back(temp);
                    }else   continue;
                }
                if(!hasFind){
                    cout << "未找到学生信息库内对应数据!"<<endl;
                    system("pause");
                    continue;
                }
            } else {
                cout << "输入有误！请检查." << endl;
            }
            unsigned int SumOfStudents=0;
            vector<student *>ptrOfStudent;
            map<int,classes*>countMap;
            int count =1;
            if(!deleteList.empty()) {
                for (it = deleteList.begin(); it != deleteList.end(); it++){
                    SumOfStudents+=(*it)->getTotalStudent();
                }
                cout << "共查询到" << SumOfStudents << "个符合条件的学生信息:" << endl;
                for (it = deleteList.begin(); it != deleteList.end(); it++) {
                    cout << "---------" << (*it)->getMajor() << "  " << (*it)->getName() << "---------" << endl;
                    for (int i = 0; i < (*it)->getTotalStudent(); i++,count++) {
                        cout << count << "."
                             << "ID:" << (*it)->getStuds()[i]->getId() << "---"
                             << "姓名:" << (*it)->getStuds()[i]->getName() << "---"
                             << "性别:" << (*it)->getStuds()[i]->getSex() << "---"
                             << "学号:" << (*it)->getStuds()[i]->getStudentId() << "---"
                             << "成绩:" << (*it)->getStuds()[i]->getResult() << "---"
                             << "电话:" << (*it)->getStuds()[i]->getPhone()
                             << endl;
                        ptrOfStudent.push_back((*it)->getStuds()[i]);
                        countMap[count-1]=*it;
                    }
                }
            }
            while(true) {
                cout << "请输入您要删除的学生序号(逗号分隔可删除多个,如1,2,5,6)" << endl;
                string choiceOfStudent;
                cin >> choiceOfStudent;
                if (!choiceOfStudent.empty()) {
                    vector<string> temp;
                    vector<string>::iterator tempOfIterator;
                    util::split(choiceOfStudent, temp, ",");
                    sort(temp.begin(), temp.end());
                    if (atoi(temp[temp.size() - 1].c_str()) > SumOfStudents || atoi(temp[0].c_str())<=0) {
                        cout << "您输入的数字不在范围之内,请重新输入!" << endl;
                        temp.clear();
                        continue;
                    }else if(temp.size()==1 && temp[0]=="0"){
                        return;
                    }
                    for (int i = 0; i < temp.size(); i++) {
                        for (it = classd.begin(); it != classd.end(); it++) {
                            if ((*it)->getName() == countMap[atoi(temp[i].c_str()) - 1]->getName()
                                &&
                                (*it)->getMajor() == countMap[atoi(temp[i].c_str()) - 1]->getMajor()) {
                                (*it)->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str()) - 1]->getId());
                                filed.deleteAnStudent(*(*it), *ptrOfStudent[atoi(temp[i].c_str()) - 1]);
                                cout << "删除成功！"<<endl;
                                system("pause");
                                return;
                            }
                        }
//                    countMap[atoi(temp[i].c_str())]->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())]->getId());
//                    filed.deleteAnStudent(*countMap[atoi(temp[i].c_str())],*ptrOfStudent[atoi(temp[i].c_str())]);
                    }
                } else if (atoi(choiceOfStudent.c_str()) == 0) {
                    return;
                } else {
                    cout << "输入有误,请重新输入!";
                }
            }
        } else if (choice == 2) {
            cout << "请输入姓名:" << endl;
            string name;
            cin >> name;
            if (!name.empty()) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_Name(name).empty()) {
                        hasFind=true;
                        classes* temp = new classes((*it)->getName(),(*it)->getMajor());
                        for(int i =0;i<(*it)->search_via_Name(name).size();i++) {
                            student* tempOfStudent = new student;
                            tempOfStudent->setId((*it)->search_via_Name(name)[i]->getId());
                            tempOfStudent->setName((*it)->search_via_Name(name)[i]->getName());
                            tempOfStudent->setSex((*it)->search_via_Name(name)[i]->getSex());
                            tempOfStudent->setStudentId((*it)->search_via_Name(name)[i]->getStudentId());
                            tempOfStudent->setResult((*it)->search_via_Name(name)[i]->getResult());
                            tempOfStudent->setPhone((*it)->search_via_Name(name)[i]->getPhone());
                            temp->add_Student_No_Sort(tempOfStudent);
                        }
                        deleteList.push_back(temp);
                    }else   continue;
                }
                if(!hasFind){
                    cout << "未找到学生信息库内对应数据!"<<endl;
                    system("pause");
                    continue;
                }
            } else {
                cout << "输入有误！请检查." << endl;
            }
            unsigned int SumOfStudents=0;
            vector<student *>ptrOfStudent;
            map<int,classes*>countMap;
            int count =1;
            if(!deleteList.empty()) {
                for (it = deleteList.begin(); it != deleteList.end(); it++){
                    SumOfStudents+=(*it)->getTotalStudent();
                }
                cout << "共查询到" << SumOfStudents << "个符合条件的学生信息:" << endl;
                for (it = deleteList.begin(); it != deleteList.end(); it++) {
                    cout << "---------" << (*it)->getMajor() << "  " << (*it)->getName() << "---------" << endl;
                    for (int i = 0; i < (*it)->getTotalStudent(); i++,count++) {
                        cout << count << "."
                             << "ID:" << (*it)->getStuds()[i]->getId() << "---"
                             << "姓名:" << (*it)->getStuds()[i]->getName() << "---"
                             << "性别:" << (*it)->getStuds()[i]->getSex() << "---"
                             << "学号:" << (*it)->getStuds()[i]->getStudentId() << "---"
                             << "成绩:" << (*it)->getStuds()[i]->getResult() << "---"
                             << "电话:" << (*it)->getStuds()[i]->getPhone()
                             << endl;
                        ptrOfStudent.push_back((*it)->getStuds()[i]);
                        countMap[count - 1] = *it;
                    }
                }
            }
            while(true) {
                cout << "请输入您要删除的学生序号(逗号分隔可删除多个,如1,2,5,6)" << endl;
                string choiceOfStudent;
                cin >> choiceOfStudent;
                if (!choiceOfStudent.empty()) {
                    vector<string> temp;
                    util::split(choiceOfStudent, temp, ",");
                    sort(temp.begin(), temp.end());
                    if (atoi(temp[temp.size() - 1].c_str()) > SumOfStudents || atoi(temp[0].c_str())<=0) {
                        cout << "您输入的数字不在范围之内,请重新输入!" << endl;
                        temp.clear();
                        continue;
                    }else if(temp.size()==1 && temp[0]=="0"){
                        return;
                    }
                    for (int i = 0; i < temp.size(); i++) {
                        for (it = classd.begin(); it != classd.end(); it++) {
                            if ((*it)->getName() == countMap[atoi(temp[i].c_str()) - 1]->getName()
                                &&
                                (*it)->getMajor() == countMap[atoi(temp[i].c_str()) - 1]->getMajor()) {
                                (*it)->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str()) - 1]->getId());
                                filed.deleteAnStudent(*(*it), *ptrOfStudent[atoi(temp[i].c_str()) - 1]);
                                cout << "删除成功！"<<endl;
                                system("pause");
                                return;
                            }
                        }
//                    countMap[atoi(temp[i].c_str())]->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())]->getId());
//                    filed.deleteAnStudent(*countMap[atoi(temp[i].c_str())],*ptrOfStudent[atoi(temp[i].c_str())]);
                    }
                } else if (atoi(choiceOfStudent.c_str()) == 0) {
                    return;
                } else {
                    cout << "输入有误,请重新输入!";
                }
            }
        } else if (choice == 3) {
            cout << "请输入学号:" << endl;
            string studentID;
            cin >> studentID;
            if (!studentID.empty()) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_StudentID(studentID).empty()) {
                        hasFind=true;
                        classes* temp = new classes((*it)->getName(),(*it)->getMajor());
                        for(int i =0;i<(*it)->search_via_StudentID(studentID).size();i++) {
                            student* tempOfStudent = new student;
                            tempOfStudent->setId((*it)->search_via_StudentID(studentID)[i]->getId());
                            tempOfStudent->setName((*it)->search_via_StudentID(studentID)[i]->getName());
                            tempOfStudent->setSex((*it)->search_via_StudentID(studentID)[i]->getSex());
                            tempOfStudent->setStudentId((*it)->search_via_StudentID(studentID)[i]->getStudentId());
                            tempOfStudent->setResult((*it)->search_via_StudentID(studentID)[i]->getResult());
                            tempOfStudent->setPhone((*it)->search_via_StudentID(studentID)[i]->getPhone());
                            temp->add_Student_No_Sort(tempOfStudent);
                        }
                        deleteList.push_back(temp);
                    }else   continue;
                }
                if(!hasFind){
                    cout << "未找到学生信息库内对应数据!"<<endl;
                    system("pause");
                    continue;
                }
            } else {
                cout << "输入有误！请检查." << endl;
            }
            unsigned int SumOfStudents=0;
            vector<student *>ptrOfStudent;
            map<int,classes*>countMap;
            int count =1;
            if(!deleteList.empty()) {
                for (it = deleteList.begin(); it != deleteList.end(); it++){
                    SumOfStudents+=(*it)->getTotalStudent();
                }
                cout << "共查询到" << SumOfStudents << "个符合条件的学生信息:" << endl;
                for (it = deleteList.begin(); it != deleteList.end(); it++) {
                    cout << "---------" << (*it)->getMajor() << "  " << (*it)->getName() << "---------" << endl;
                    for (int i = 0; i < (*it)->getTotalStudent(); i++,count++) {
                        cout << count << "."
                             << "ID:" << (*it)->getStuds()[i]->getId() << "---"
                             << "姓名:" << (*it)->getStuds()[i]->getName() << "---"
                             << "性别:" << (*it)->getStuds()[i]->getSex() << "---"
                             << "学号:" << (*it)->getStuds()[i]->getStudentId() << "---"
                             << "成绩:" << (*it)->getStuds()[i]->getResult() << "---"
                             << "电话:" << (*it)->getStuds()[i]->getPhone()
                             << endl;
                        ptrOfStudent.push_back((*it)->getStuds()[i]);
                        countMap[count - 1] = *it;
                    }
                }
            }
            while(true) {
                cout << "请输入您要删除的学生序号(逗号分隔可删除多个,如1,2,5,6)" << endl;
                string choiceOfStudent;
                cin >> choiceOfStudent;
                if (!choiceOfStudent.empty()) {
                    vector<string> temp;
                    util::split(choiceOfStudent, temp, ",");
                    sort(temp.begin(), temp.end());
                    if (atoi(temp[temp.size() - 1].c_str()) > SumOfStudents || atoi(temp[0].c_str())<=0) {
                        cout << "您输入的数字不在范围之内,请重新输入!" << endl;
                        temp.clear();
                        continue;
                    }else if(temp.size()==1 && temp[0]=="0"){
                        return;
                    }
                    for (int i = 0; i < temp.size(); i++) {
                        for (it = classd.begin(); it != classd.end(); it++) {
                            if ((*it)->getName() == countMap[atoi(temp[i].c_str()) - 1]->getName()
                                &&
                                (*it)->getMajor() == countMap[atoi(temp[i].c_str()) - 1]->getMajor()) {
                                (*it)->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str()) - 1]->getId());
                                filed.deleteAnStudent(*(*it), *ptrOfStudent[atoi(temp[i].c_str()) - 1]);
                                cout << "删除成功！"<<endl;
                                system("pause");
                                return;
                            }
                        }
//                    countMap[atoi(temp[i].c_str())]->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())]->getId());
//                    filed.deleteAnStudent(*countMap[atoi(temp[i].c_str())],*ptrOfStudent[atoi(temp[i].c_str())]);
                    }
                } else if (atoi(choiceOfStudent.c_str()) == 0) {

                    return;
                } else {
                    cout << "输入有误,请重新输入!";
                }
            }
        } else if (choice == 4) {
            cout << "请输入成绩:" << endl;
            double result;
            cin >> result;
            cin.get();
            if (result!=0) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_Result(result).empty()) {
                        hasFind= true;
                        classes* temp = new classes((*it)->getName(),(*it)->getMajor());
                        for(int i =0;i<(*it)->search_via_Result(result).size();i++) {
                            student* tempOfStudent = new student;
                            tempOfStudent->setId((*it)->search_via_Result(result)[i]->getId());
                            tempOfStudent->setName((*it)->search_via_Result(result)[i]->getName());
                            tempOfStudent->setSex((*it)->search_via_Result(result)[i]->getSex());
                            tempOfStudent->setStudentId((*it)->search_via_Result(result)[i]->getStudentId());
                            tempOfStudent->setResult((*it)->search_via_Result(result)[i]->getResult());
                            tempOfStudent->setPhone((*it)->search_via_Result(result)[i]->getPhone());
                            temp->add_Student_No_Sort(tempOfStudent);
                        }
                        deleteList.push_back(temp);
                    }else   continue;
                }
                if(!hasFind){
                    cout << "未找到学生信息库内对应数据!"<<endl;
                    system("pause");
                    continue;
                }
            } else {
                cout << "输入有误！请检查." << endl;
            }
            unsigned int SumOfStudents=0;
            vector<student *>ptrOfStudent;
            map<int,classes*>countMap;
            int count =1;
            if(!deleteList.empty()) {
                for (it = deleteList.begin(); it != deleteList.end(); it++){
                    SumOfStudents+=(*it)->getTotalStudent();
                }
                cout << "共查询到" << SumOfStudents << "个符合条件的学生信息:" << endl;
                for (it = deleteList.begin(); it != deleteList.end(); it++) {
                    cout << "---------" << (*it)->getMajor() << "  " << (*it)->getName() << "---------" << endl;
                    for (int i = 0; i < (*it)->getTotalStudent(); i++,count++) {
                        cout << count << "."
                             << "ID:" << (*it)->getStuds()[i]->getId() << "---"
                             << "姓名:" << (*it)->getStuds()[i]->getName() << "---"
                             << "性别:" << (*it)->getStuds()[i]->getSex() << "---"
                             << "学号:" << (*it)->getStuds()[i]->getStudentId() << "---"
                             << "成绩:" << (*it)->getStuds()[i]->getResult() << "---"
                             << "电话:" << (*it)->getStuds()[i]->getPhone()
                             << endl;
                        ptrOfStudent.push_back((*it)->getStuds()[i]);
                        countMap[count - 1] = *it;
                    }
                }
            }
            while(true) {
                cout << "请输入您要删除的学生序号(逗号分隔可删除多个,如1,2,5,6)" << endl;
                string choiceOfStudent;
                cin >> choiceOfStudent;
                if (!choiceOfStudent.empty()) {
                    vector<string> temp;
                    util::split(choiceOfStudent, temp, ",");
                    sort(temp.begin(), temp.end());
                    if (atoi(temp[temp.size() - 1].c_str()) > SumOfStudents || atoi(temp[0].c_str())<=0) {
                        cout << "您输入的数字不在范围之内,请重新输入!" << endl;
                        temp.clear();
                        continue;
                    }else if(temp.size()==1 && temp[0]=="0"){
                        return;
                    }
                    for (int i = 0; i < temp.size(); i++) {
                        for (it = classd.begin(); it != classd.end(); it++) {
                            if ((*it)->getName() == countMap[atoi(temp[i].c_str()) - 1]->getName()
                                &&
                                (*it)->getMajor() == countMap[atoi(temp[i].c_str()) - 1]->getMajor()) {
                                (*it)->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str()) - 1]->getId());
                                filed.deleteAnStudent(*(*it), *ptrOfStudent[atoi(temp[i].c_str()) - 1]);
                                cout << "删除成功！"<<endl;
                                system("pause");
                                return;
                            }
                        }
//                    countMap[atoi(temp[i].c_str())]->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())]->getId());
//                    filed.deleteAnStudent(*countMap[atoi(temp[i].c_str())],*ptrOfStudent[atoi(temp[i].c_str())]);
                    }
                } else if (atoi(choiceOfStudent.c_str()) == 0) {
                    return;
                } else {
                    cout << "输入有误,请重新输入!";
                }
            }
        } else if (choice == 5) {
            cout << "请输入电话:" << endl;
            string phone;
            cin >> phone;
            if (!phone.empty()) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_Phone(phone).empty()) {
                        hasFind=true;
                        classes* temp = new classes((*it)->getName(),(*it)->getMajor());
                        for(int i =0;i<(*it)->search_via_Phone(phone).size();i++) {
                            student* tempOfStudent = new student;
                            tempOfStudent->setId((*it)->search_via_Phone(phone)[i]->getId());
                            tempOfStudent->setName((*it)->search_via_Phone(phone)[i]->getName());
                            tempOfStudent->setSex((*it)->search_via_Phone(phone)[i]->getSex());
                            tempOfStudent->setStudentId((*it)->search_via_Phone(phone)[i]->getStudentId());
                            tempOfStudent->setResult((*it)->search_via_Phone(phone)[i]->getResult());
                            tempOfStudent->setPhone((*it)->search_via_Phone(phone)[i]->getPhone());
                            temp->add_Student_No_Sort(tempOfStudent);
                        }
                        deleteList.push_back(temp);
                    }else   continue;
                }
                if(!hasFind){
                    cout << "未找到学生信息库内对应数据!"<<endl;
                    system("pause");
                    continue;
                }
            } else {
                cout << "输入有误！请检查." << endl;
            }
            unsigned int SumOfStudents=0;
            vector<student *>ptrOfStudent;
            map<int,classes*>countMap;
            int count =1;
            if(!deleteList.empty()) {
                for (it = deleteList.begin(); it != deleteList.end(); it++){
                    SumOfStudents+=(*it)->getTotalStudent();
                }
                cout << "共查询到" << SumOfStudents << "个符合条件的学生信息:" << endl;
                for (it = deleteList.begin(); it != deleteList.end(); it++) {
                    cout << "---------" << (*it)->getMajor() << "  " << (*it)->getName() << "---------" << endl;
                    for (int i = 0; i < (*it)->getTotalStudent(); i++, count++) {
                        cout << count << "."
                             << "ID:" << (*it)->getStuds()[i]->getId() << "---"
                             << "姓名:" << (*it)->getStuds()[i]->getName() << "---"
                             << "性别:" << (*it)->getStuds()[i]->getSex() << "---"
                             << "学号:" << (*it)->getStuds()[i]->getStudentId() << "---"
                             << "成绩:" << (*it)->getStuds()[i]->getResult() << "---"
                             << "电话:" << (*it)->getStuds()[i]->getPhone()
                             << endl;
                        ptrOfStudent.push_back((*it)->getStuds()[i]);
                        countMap[count - 1] = *it;
                    }
                }
            }
            while(true) {
                cout << "请输入您要删除的学生序号(逗号分隔可删除多个,如1,2,5,6)" << endl;
                string choiceOfStudent;
                cin >> choiceOfStudent;
                if (!choiceOfStudent.empty()) {
                    vector<string> temp;
                    util::split(choiceOfStudent, temp, ",");
                    sort(temp.begin(), temp.end());
                    if (atoi(temp[temp.size() - 1].c_str()) > SumOfStudents || atoi(temp[0].c_str())<=0) {
                        cout << "您输入的数字不在范围之内,请重新输入!" << endl;
                        temp.clear();
                        continue;
                    }else if(temp.size()==1 && temp[0]=="0"){
                        return;
                    }
                    for (int i = 0; i < temp.size(); i++) {
                        for (int i = 0; i < temp.size(); i++) {
                            for (it = classd.begin(); it != classd.end(); it++) {
                                if ((*it)->getName() == countMap[atoi(temp[i].c_str()) - 1]->getName()
                                    &&
                                    (*it)->getMajor() == countMap[atoi(temp[i].c_str()) - 1]->getMajor()) {
                                    (*it)->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str()) - 1]->getId());
                                    filed.deleteAnStudent(*(*it), *ptrOfStudent[atoi(temp[i].c_str()) - 1]);
                                    cout << "删除成功！"<<endl;
                                    system("pause");
                                    return;
                                }
                            }
//                    countMap[atoi(temp[i].c_str())]->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())]->getId());
//                    filed.deleteAnStudent(*countMap[atoi(temp[i].c_str())],*ptrOfStudent[atoi(temp[i].c_str())]);
                        }
                    }
                } else if (atoi(choiceOfStudent.c_str()) == 0) {
                    return;
                } else {
                    cout << "输入有误,请重新输入!";
                }
            }
        } else if(choice == 0) {
            break;

        }else{
            cout << "输入有误！请检查." << endl;
        }
    }
}

void window::_saveStudentInfo() {
    cout << "即将重新保存所有学生信息，请稍等..."<<endl;
    vector<classes *>::iterator it;
    for(it=classd.begin();it!=classd.end();it++){
        filed.writeAllStudents(*(*it));
    }
    cout << "文件保存成功!"<<endl;
}

void window::_exportStudentInfo() {
    cout << "请输入导出文件夹名:"<<endl;
    string nameOfDe;
    cin >> nameOfDe;
    vector<classes *>::iterator it;
    for(it=classd.begin();it!=classd.end();it++){
        if(!filed.writeAllStudents(*(*it),nameOfDe)){
            cout << "导出文件失败!"<<endl;
            return;
        }
    }
    cout <<"导出文件成功!"<<endl;
    cout << "导出路径为:"<<getcwd(nullptr, 0)<<"\\"<<nameOfDe<<endl;

}



