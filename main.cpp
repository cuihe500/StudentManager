#include <iostream>
#include "src/head/File.h"
#include <direct.h>
#include "src/head/window.h"
#include "src/head/util.h"

//��������
vector<classes*> _15_xkn_1_init(File files);//��ʼ������(��ȡ��Ϣ)

int main() {
    string path=getcwd(nullptr, 0);
    File _15_xkn_2_file(path+"\\");
    vector<classes*> _15_xkn_3_allClasses=_15_xkn_1_init(_15_xkn_2_file);;
    window win(_15_xkn_3_allClasses,_15_xkn_2_file);
    win._interface();
}
vector<classes*> _15_xkn_1_init(File files){
    vector<classes *> classesd;
    vector<string>Diretorys=files.getAllDiretorys();
    vector<string>::iterator it;
    vector<string> slips[2];
    unsigned int sumOfStudent=0;
    int sumOfClasses=Diretorys.size();
    for(it=Diretorys.begin();it!=Diretorys.end();it++){
        vector<string> temps;
        util::split(*it,temps," ");
        slips[0].push_back(temps[0]);
        slips[1].push_back(temps[1]);
    }
    for(int i =0 ;i < Diretorys.size();i++){
        classes* temp = new classes((slips[1])[i],(slips[0])[i]);
        files.readAllStudent(*temp);
        sumOfStudent+=temp->getTotalStudent();
        classesd.push_back(temp);
    }
    cout<<"���ҵ�:"<<to_string(sumOfClasses)<<"���༶"<<", "+to_string(sumOfStudent)+"��ѧ��."<<endl;
    cout << "ȫ���������."<<endl;
    return classesd;
}