//
// Created by �޲��� on 2021/6/22.
//

#include "head/window.h"

window::window(vector<classes *> &classd, File &filed) : classd(classd), filed(filed) {}

[[noreturn]] void window::_interface() {
    while(1) {
        cout << "           *************ѧ���ɼ�����ϵͳ*************" << endl;
        cout << "                         1.���ѧ����¼" << endl;
        cout << "                         2.��ʾѧ����¼" << endl;
        cout << "                         3.����ѧ����¼" << endl;
        cout << "                         4.ɾ��ѧ����¼" << endl;
        cout << "                         5.����ѧ����¼" << endl;
        cout << "                         6.����ѧ����¼" << endl;
        cout << "                         7.�˳�ѧ������ϵͳ" << endl;
        cout << "           ***************************************" << endl;
        cout << "����������ѡ��:";
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
                break;
        }
    }
}

void window::_addNewStudent() {
    string info[7];
    cout << "---------�������ѧ��������Ϣ---------"<<endl;
    cout << "��ѧ������ѧԺ:";
    cin >> info[0];
    cout << "��ѧ������ѧԺ�������༶:";
    cin >> info[1];
    cout << "---------�������ѧ��������Ϣ---------"<<endl;
    cout << "����:";
    cin >> info[2];
    cout << "�Ա�(��/Ů):";
    cin >> info[3];
    cout << "ѧ��:";
    cin >> info[4];
    cout << "�ɼ�:";
    cin >> info[5];
    cout << "�绰:";
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
    cout <<"ѧ����Ϣ�Ѿ��������."<<endl;
}

[[noreturn]] void window::_showStudents() {
    unsigned int SumOfStudents=0,SumOfClasses=classd.size();
    vector<classes *>::iterator it;
    for(it=classd.begin();it!=classd.end();it++){
        SumOfStudents+=(*it)->getTotalStudent();
    }
    while(true) {
    cout << "---------��Ϣ����---------"<<endl;
    cout << endl;
    cout <<"Ŀǰ��Ϣ���й���:"<<to_string(SumOfClasses)<<"���༶,��"<<to_string(SumOfStudents)<<"��ѧ��."<<endl;
    cout << endl;
    cout <<"---------�༶��Ϣ---------"<<endl;
    int num=1;
    for(it=classd.begin();it!=classd.end();it++,num++)
        cout<<num<<"."<<(*it)->getMajor()<<" "<<(*it)->getName()<<endl;
    cout <<endl;
        cout << "��������Ҫ�鿴�İ༶���(0.�˳�):";
        int choice;
        cin >> choice;
        cin.get();
        if (choice<=SumOfClasses && choice>0){
            for(int i =1;i<=(*classd[choice-1]).getTotalStudent();i++)
                cout
                <<"ID:"<<(*classd[choice-1]).search_via_ID(i).getId()<<"---"
                <<"����:"<<(*classd[choice-1]).search_via_ID(i).getName()<<"---"
                <<"�Ա�:"<<(*classd[choice-1]).search_via_ID(i).getSex()<<"---"
                <<"ѧ��:"<<(*classd[choice-1]).search_via_ID(i).getStudentId()<<"---"
                <<"�ɼ�:"<<(*classd[choice-1]).search_via_ID(i).getResult()<<"---"
                <<"�绰:"<<(*classd[choice-1]).search_via_ID(i).getPhone()
                <<endl;
            system("pause");
            break;
        }else if(choice == 0) {
            break;
        }else{
            cout << "�������!����������!"<<endl;
        }
    }
}

[[noreturn]] void window::_findAnStudent() {
    while(true) {
    cout<<"---------����ѧ��---------"<<endl;
    cout <<"1.ͨ��ID���в���"<<endl;
    cout <<"2.ͨ���������в���"<<endl;
    cout <<"3.ͨ��ѧ�Ž��в���"<<endl;
    cout <<"4.ͨ���ɼ����в���"<<endl;
    cout <<"5.ͨ���绰���в���"<<endl;
    cout << "0.�˳�"<<endl;
    cout<<endl;
        cout << "���������Ĳ��ҷ�ʽ:" << endl;
        int choice;
        cin >> choice;
        cin.get();
        vector<classes *>::iterator it;
        if (choice == 1) {
            cout << "������ID:" << endl;
            int ID;
            cin >> ID;
            cin.get();
            if (ID >= 0) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if ((*it)->search_via_ID(ID).getId() != 0) {
                        cout<<"---------"<<(*it)->getMajor()<<"  "<<(*it)->getName()<<"---------"<<endl;
                        cout
                                << "ID:" << (*it)->search_via_ID(ID).getId() << "---"
                                << "����:" << (*it)->search_via_ID(ID).getName() << "---"
                                << "�Ա�:" << (*it)->search_via_ID(ID).getSex() << "---"
                                << "ѧ��:" << (*it)->search_via_ID(ID).getStudentId() << "---"
                                << "�ɼ�:" << (*it)->search_via_ID(ID).getResult() << "---"
                                << "�绰:" << (*it)->search_via_ID(ID).getPhone()
                                << endl;
                    }else   continue;
                }
            } else {
                cout << "������������." << endl;
            }
        } else if (choice == 2) {
            cout << "����������:" << endl;
            string name;
            cin >> name;
            if (!name.empty()) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_Name(name).empty()) {
                        cout<<"---------"<<(*it)->getMajor()<<"  "<<(*it)->getName()<<"---------"<<endl;
                        for(int i =0;i<(*it)->search_via_Name(name).size();i++)
                        cout
                                << "ID:" << ((*it)->search_via_Name(name))[i]->getId() << "---"
                                << "����:" << ((*it)->search_via_Name(name))[i]->getName() << "---"
                                << "�Ա�:" << ((*it)->search_via_Name(name))[i]->getSex() << "---"
                                << "ѧ��:" << ((*it)->search_via_Name(name))[i]->getStudentId() << "---"
                                << "�ɼ�:" << ((*it)->search_via_Name(name))[i]->getResult() << "---"
                                << "�绰:" << ((*it)->search_via_Name(name))[i]->getPhone()
                                << endl;
                    }
                }
            } else {
                cout << "������������." << endl;
            }

        } else if (choice == 3) {
            cout << "������ѧ��:" << endl;
            string studentID;
            cin >> studentID;
            if (!studentID.empty()) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_StudentID(studentID).empty()) {
                        cout<<"---------"<<(*it)->getMajor()<<"  "<<(*it)->getName()<<"---------"<<endl;
                        for(int i =0;i<(*it)->search_via_StudentID(studentID).size();i++)
                            cout
                                    << "ID:" << ((*it)->search_via_StudentID(studentID))[i]->getId() << "---"
                                    << "����:" << ((*it)->search_via_StudentID(studentID))[i]->getName() << "---"
                                    << "�Ա�:" << ((*it)->search_via_StudentID(studentID))[i]->getSex() << "---"
                                    << "ѧ��:" << ((*it)->search_via_StudentID(studentID))[i]->getStudentId() << "---"
                                    << "�ɼ�:" << ((*it)->search_via_StudentID(studentID))[i]->getResult() << "---"
                                    << "�绰:" << ((*it)->search_via_StudentID(studentID))[i]->getPhone()
                                    << endl;
                    }
                }
            } else {
                cout << "������������." << endl;
            }

        } else if (choice == 4) {
            cout << "������ɼ�:" << endl;
            double result;
            cin >> result;
            cin.get();
            if (result!=NULL) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_Result(result).empty()) {
                        cout<<"---------"<<(*it)->getMajor()<<"  "<<(*it)->getName()<<"---------"<<endl;
                        for(int i =0;i<(*it)->search_via_Result(result).size();i++)
                            cout
                                    << "ID:" << ((*it)->search_via_Result(result))[i]->getId() << "---"
                                    << "����:" << ((*it)->search_via_Result(result))[i]->getName() << "---"
                                    << "�Ա�:" << ((*it)->search_via_Result(result))[i]->getSex() << "---"
                                    << "ѧ��:" << ((*it)->search_via_Result(result))[i]->getStudentId() << "---"
                                    << "�ɼ�:" << ((*it)->search_via_Result(result))[i]->getResult() << "---"
                                    << "�绰:" << ((*it)->search_via_Result(result))[i]->getPhone()
                                    << endl;
                    }
                }
            } else {
                cout << "������������." << endl;
            }

        } else if (choice == 5) {
            cout << "������绰:" << endl;
            string phone;
            cin >> phone;
            if (!phone.empty()) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_Phone(phone).empty()) {
                        cout<<"---------"<<(*it)->getMajor()<<"  "<<(*it)->getName()<<"---------"<<endl;
                        for(int i =0;i<(*it)->search_via_Phone(phone).size();i++)
                            cout
                                    << "ID:" << ((*it)->search_via_Phone(phone))[i]->getId() << "---"
                                    << "����:" << ((*it)->search_via_Phone(phone))[i]->getName() << "---"
                                    << "�Ա�:" << ((*it)->search_via_Phone(phone))[i]->getSex() << "---"
                                    << "ѧ��:" << ((*it)->search_via_Phone(phone))[i]->getStudentId() << "---"
                                    << "�ɼ�:" << ((*it)->search_via_Phone(phone))[i]->getResult() << "---"
                                    << "�绰:" << ((*it)->search_via_Phone(phone))[i]->getPhone()
                                    << endl;
                    }
                }
            } else {
                cout << "������������." << endl;
            }

        } else if(choice == 0) {
            break;

        }else{
            cout << "������������." << endl;
        }
    }

}

[[noreturn]] void window::_deleteAnStudent() {
    while(true) {
        cout<<"---------ɾ��ѧ��---------"<<endl;
        cout <<"1.ͨ��ID����ɾ��"<<endl;
        cout <<"2.ͨ����������ɾ��"<<endl;
        cout <<"3.ͨ��ѧ�Ž���ɾ��"<<endl;
        cout <<"4.ͨ���ɼ�����ɾ��"<<endl;
        cout <<"5.ͨ���绰����ɾ��"<<endl;
        cout << "0.�˳�"<<endl;
        cout<<endl;
        cout << "���������Ĳ��ҷ�ʽ:" << endl;
        int choice;
        cin >> choice;
        cin.get();
        vector<classes *>::iterator it;
        vector<classes *>deleteList;
        if (choice == 1) {
            cout << "������ID:" << endl;
            int ID;
            cin >> ID;
            cin.get();
            if (ID >= 0) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if ((*it)->search_via_ID(ID).getId() != 0) {
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
            } else {
                cout << "������������." << endl;
            }
            unsigned int SumOfStudents=0;
            vector<student *>ptrOfStudent;
            map<int,classes*>countMap;
            int count =1;
            if(!deleteList.empty()) {
                for (it = deleteList.begin(); it != deleteList.end(); it++){
                    SumOfStudents+=(*it)->getTotalStudent();
                }
                cout << "����ѯ��" << SumOfStudents << "������������ѧ����Ϣ:" << endl;
                for (it = deleteList.begin(); it != deleteList.end(); it++) {
                    cout << "---------" << (*it)->getMajor() << "  " << (*it)->getName() << "---------" << endl;
                    for (int i = 0; i < (*it)->getTotalStudent(); i++,count++) {
                        cout << count << "."
                             << "ID:" << (*it)->getStuds()[i]->getId() << "---"
                             << "����:" << (*it)->getStuds()[i]->getName() << "---"
                             << "�Ա�:" << (*it)->getStuds()[i]->getSex() << "---"
                             << "ѧ��:" << (*it)->getStuds()[i]->getStudentId() << "---"
                             << "�ɼ�:" << (*it)->getStuds()[i]->getResult() << "---"
                             << "�绰:" << (*it)->getStuds()[i]->getPhone()
                             << endl;
                        ptrOfStudent.push_back((*it)->getStuds()[i]);
                        countMap[count-1]=*it;
                    }
                }
            }
            cout << "��������Ҫɾ����ѧ�����(���ŷָ���ɾ�����,��1,2,5,6)"<<endl;
            string choiceOfStudent;
            cin >> choiceOfStudent;
            if(!choiceOfStudent.empty()){
                vector<string>temp;
                util::split(choiceOfStudent,temp,",");
                for(int i =0;i<temp.size();i++){
                    for(it=classd.begin();it!=classd.end();it++){
                        if((*it)->getName()==countMap[atoi(temp[i].c_str())-1]->getName()
                        &&
                        (*it)->getMajor()==countMap[atoi(temp[i].c_str())-1]->getMajor()){
                            (*it)->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())-1]->getId());
                            filed.deleteAnStudent(*(*it),*ptrOfStudent[atoi(temp[i].c_str())-1]);
                        }
                    }
//                    countMap[atoi(temp[i].c_str())]->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())]->getId());
//                    filed.deleteAnStudent(*countMap[atoi(temp[i].c_str())],*ptrOfStudent[atoi(temp[i].c_str())]);
                }
            }else if (atoi(choiceOfStudent.c_str())==0){
                return;
            }else{
                cout<<"��������,����������!";
            }
        } else if (choice == 2) {
            cout << "����������:" << endl;
            string name;
            cin >> name;
            if (!name.empty()) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_Name(name).empty()) {
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
            } else {
                cout << "������������." << endl;
            }
            unsigned int SumOfStudents=0;
            vector<student *>ptrOfStudent;
            map<int,classes*>countMap;
            if(!deleteList.empty()) {
                for (it = deleteList.begin(); it != deleteList.end(); it++){
                    SumOfStudents+=(*it)->getTotalStudent();
                }
                cout << "����ѯ��" << SumOfStudents << "������������ѧ����Ϣ:" << endl;
                int count =1;
                for (it = deleteList.begin(); it != deleteList.end(); it++) {
                    cout << "---------" << (*it)->getMajor() << "  " << (*it)->getName() << "---------" << endl;
                    for (int i = 0; i < (*it)->getTotalStudent(); i++,count++) {
                        cout << count << "."
                             << "ID:" << (*it)->getStuds()[i]->getId() << "---"
                             << "����:" << (*it)->getStuds()[i]->getName() << "---"
                             << "�Ա�:" << (*it)->getStuds()[i]->getSex() << "---"
                             << "ѧ��:" << (*it)->getStuds()[i]->getStudentId() << "---"
                             << "�ɼ�:" << (*it)->getStuds()[i]->getResult() << "---"
                             << "�绰:" << (*it)->getStuds()[i]->getPhone()
                             << endl;
                        ptrOfStudent.push_back((*it)->getStuds()[i]);
                        countMap[count - 1] = *it;
                    }
                }
            }
            cout << "��������Ҫɾ����ѧ�����(���ŷָ���ɾ�����,��1,2,5,6)"<<endl;
            string choiceOfStudent;
            cin >> choiceOfStudent;
            if(!choiceOfStudent.empty()){
                vector<string>temp;
                util::split(choiceOfStudent,temp,",");
                for(int i =0;i<temp.size();i++){
                    for(it=classd.begin();it!=classd.end();it++){
                        if((*it)->getName()==countMap[atoi(temp[i].c_str())-1]->getName()
                           &&
                           (*it)->getMajor()==countMap[atoi(temp[i].c_str())-1]->getMajor()){
                            (*it)->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())-1]->getId());
                            filed.deleteAnStudent(*(*it),*ptrOfStudent[atoi(temp[i].c_str())-1]);
                        }
                    }
//                    countMap[atoi(temp[i].c_str())]->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())]->getId());
//                    filed.deleteAnStudent(*countMap[atoi(temp[i].c_str())],*ptrOfStudent[atoi(temp[i].c_str())]);
                }
            }else if (atoi(choiceOfStudent.c_str())==0){
                return;
            }else{
                cout<<"��������,����������!";
            }
        } else if (choice == 3) {
            cout << "������ѧ��:" << endl;
            string studentID;
            cin >> studentID;
            if (!studentID.empty()) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_StudentID(studentID).empty()) {
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
            } else {
                cout << "������������." << endl;
            }
            unsigned int SumOfStudents=0;
            vector<student *>ptrOfStudent;
            map<int,classes*>countMap;
            if(!deleteList.empty()) {
                for (it = deleteList.begin(); it != deleteList.end(); it++){
                    SumOfStudents+=(*it)->getTotalStudent();
                }
                cout << "����ѯ��" << SumOfStudents << "������������ѧ����Ϣ:" << endl;
                int count =1;
                for (it = deleteList.begin(); it != deleteList.end(); it++) {
                    cout << "---------" << (*it)->getMajor() << "  " << (*it)->getName() << "---------" << endl;
                    for (int i = 0; i < (*it)->getTotalStudent(); i++,count++) {
                        cout << count << "."
                             << "ID:" << (*it)->getStuds()[i]->getId() << "---"
                             << "����:" << (*it)->getStuds()[i]->getName() << "---"
                             << "�Ա�:" << (*it)->getStuds()[i]->getSex() << "---"
                             << "ѧ��:" << (*it)->getStuds()[i]->getStudentId() << "---"
                             << "�ɼ�:" << (*it)->getStuds()[i]->getResult() << "---"
                             << "�绰:" << (*it)->getStuds()[i]->getPhone()
                             << endl;
                        ptrOfStudent.push_back((*it)->getStuds()[i]);
                        countMap[count - 1] = *it;
                    }
                }
            }
            cout << "��������Ҫɾ����ѧ�����(���ŷָ���ɾ�����,��1,2,5,6)"<<endl;
            string choiceOfStudent;
            cin >> choiceOfStudent;
            if(!choiceOfStudent.empty()){
                vector<string>temp;
                util::split(choiceOfStudent,temp,",");
                for(int i =0;i<temp.size();i++){
                    for(it=classd.begin();it!=classd.end();it++){
                        if((*it)->getName()==countMap[atoi(temp[i].c_str())-1]->getName()
                           &&
                           (*it)->getMajor()==countMap[atoi(temp[i].c_str())-1]->getMajor()){
                            (*it)->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())-1]->getId());
                            filed.deleteAnStudent(*(*it),*ptrOfStudent[atoi(temp[i].c_str())-1]);
                        }
                    }
//                    countMap[atoi(temp[i].c_str())]->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())]->getId());
//                    filed.deleteAnStudent(*countMap[atoi(temp[i].c_str())],*ptrOfStudent[atoi(temp[i].c_str())]);
                }
            }else if (atoi(choiceOfStudent.c_str())==0){
                return;
            }else{
                cout<<"��������,����������!";
            }
        } else if (choice == 4) {
            cout << "������ɼ�:" << endl;
            double result;
            cin >> result;
            cin.get();
            if (result!=0) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_Result(result).empty()) {
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
            } else {
                cout << "������������." << endl;
            }
            unsigned int SumOfStudents=0;
            vector<student *>ptrOfStudent;
            map<int,classes*>countMap;
            if(!deleteList.empty()) {
                for (it = deleteList.begin(); it != deleteList.end(); it++){
                    SumOfStudents+=(*it)->getTotalStudent();
                }
                cout << "����ѯ��" << SumOfStudents << "������������ѧ����Ϣ:" << endl;
                int count =1;
                for (it = deleteList.begin(); it != deleteList.end(); it++) {
                    cout << "---------" << (*it)->getMajor() << "  " << (*it)->getName() << "---------" << endl;
                    for (int i = 0; i < (*it)->getTotalStudent(); i++,count++) {
                        cout << count << "."
                             << "ID:" << (*it)->getStuds()[i]->getId() << "---"
                             << "����:" << (*it)->getStuds()[i]->getName() << "---"
                             << "�Ա�:" << (*it)->getStuds()[i]->getSex() << "---"
                             << "ѧ��:" << (*it)->getStuds()[i]->getStudentId() << "---"
                             << "�ɼ�:" << (*it)->getStuds()[i]->getResult() << "---"
                             << "�绰:" << (*it)->getStuds()[i]->getPhone()
                             << endl;
                        ptrOfStudent.push_back((*it)->getStuds()[i]);
                        countMap[count - 1] = *it;
                    }
                }
            }
            cout << "��������Ҫɾ����ѧ�����(���ŷָ���ɾ�����,��1,2,5,6)"<<endl;
            string choiceOfStudent;
            cin >> choiceOfStudent;
            if(!choiceOfStudent.empty()){
                vector<string>temp;
                util::split(choiceOfStudent,temp,",");
                for(int i =0;i<temp.size();i++){
                    for(it=classd.begin();it!=classd.end();it++){
                        if((*it)->getName()==countMap[atoi(temp[i].c_str())-1]->getName()
                           &&
                           (*it)->getMajor()==countMap[atoi(temp[i].c_str())-1]->getMajor()){
                            (*it)->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())-1]->getId());
                            filed.deleteAnStudent(*(*it),*ptrOfStudent[atoi(temp[i].c_str())-1]);
                        }
                    }
//                    countMap[atoi(temp[i].c_str())]->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())]->getId());
//                    filed.deleteAnStudent(*countMap[atoi(temp[i].c_str())],*ptrOfStudent[atoi(temp[i].c_str())]);
                }
            }else if (atoi(choiceOfStudent.c_str())==0){
                return;
            }else{
                cout<<"��������,����������!";
            }
        } else if (choice == 5) {
            cout << "������绰:" << endl;
            string phone;
            cin >> phone;
            if (!phone.empty()) {
                for (it = classd.begin(); it != classd.end(); it++) {
                    if (!(*it)->search_via_Phone(phone).empty()) {
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
            } else {
                cout << "������������." << endl;
            }
            unsigned int SumOfStudents=0;
            vector<student *>ptrOfStudent;
            map<int,classes*>countMap;
            if(!deleteList.empty()) {
                for (it = deleteList.begin(); it != deleteList.end(); it++){
                    SumOfStudents+=(*it)->getTotalStudent();
                }
                cout << "����ѯ��" << SumOfStudents << "������������ѧ����Ϣ:" << endl;
                int count =1;
                for (it = deleteList.begin(); it != deleteList.end(); it++) {
                    cout << "---------" << (*it)->getMajor() << "  " << (*it)->getName() << "---------" << endl;
                    for (int i = 0; i < (*it)->getTotalStudent(); i++, count++) {
                        cout << count << "."
                             << "ID:" << (*it)->getStuds()[i]->getId() << "---"
                             << "����:" << (*it)->getStuds()[i]->getName() << "---"
                             << "�Ա�:" << (*it)->getStuds()[i]->getSex() << "---"
                             << "ѧ��:" << (*it)->getStuds()[i]->getStudentId() << "---"
                             << "�ɼ�:" << (*it)->getStuds()[i]->getResult() << "---"
                             << "�绰:" << (*it)->getStuds()[i]->getPhone()
                             << endl;
                        ptrOfStudent.push_back((*it)->getStuds()[i]);
                        countMap[count - 1] = *it;
                    }
                }
            }
            cout << "��������Ҫɾ����ѧ�����(���ŷָ���ɾ�����,��1,2,5,6)"<<endl;
            string choiceOfStudent;
            cin >> choiceOfStudent;
            if(!choiceOfStudent.empty()){
                vector<string>temp;
                util::split(choiceOfStudent,temp,",");
                for(int i =0;i<temp.size();i++){
                    for(int i =0;i<temp.size();i++){
                        for(it=classd.begin();it!=classd.end();it++){
                            if((*it)->getName()==countMap[atoi(temp[i].c_str())-1]->getName()
                               &&
                               (*it)->getMajor()==countMap[atoi(temp[i].c_str())-1]->getMajor()){
                                (*it)->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())-1]->getId());
                                filed.deleteAnStudent(*(*it),*ptrOfStudent[atoi(temp[i].c_str())-1]);
                            }
                        }
//                    countMap[atoi(temp[i].c_str())]->delete_via_ID(ptrOfStudent[atoi(temp[i].c_str())]->getId());
//                    filed.deleteAnStudent(*countMap[atoi(temp[i].c_str())],*ptrOfStudent[atoi(temp[i].c_str())]);
                    }
                }
            }else if (atoi(choiceOfStudent.c_str())==0){
                return;
            }else{
                cout<<"��������,����������!";
            }
        } else if(choice == 0) {
            break;

        }else{
            cout << "������������." << endl;
        }
    }
}

void window::_saveStudentInfo() {
    cout << "�������±�������ѧ����Ϣ�����Ե�..."<<endl;
    vector<classes *>::iterator it;
    for(it=classd.begin();it!=classd.end();it++){
        filed.writeAllStudents(*(*it));
    }
    cout << "�ļ�����ɹ�!"<<endl;
}

void window::_exportStudentInfo() {
    cout << "�����뵼���ļ�����:"<<endl;
    string nameOfDe;
    cin >> nameOfDe;
    vector<classes *>::iterator it;
    for(it=classd.begin();it!=classd.end();it++){
        if(!filed.writeAllStudents(*(*it),nameOfDe)){
            cout << "�����ļ�ʧ��!"<<endl;
            return;
        }
    }
    cout <<"�����ļ��ɹ�!"<<endl;
    cout << "����·��Ϊ:"<<getcwd(nullptr, 0)<<"\\"<<nameOfDe<<endl;

}



