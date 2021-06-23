#include <iostream>
#include "src/head/File.h"
#include <direct.h>
#include "src/head/window.h"
#include "src/head/util.h"

//主调函数
vector<classes*> _15_xkn_1_init(File files);//初始化函数(读取信息)

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
    cout<<"共找到:"<<to_string(sumOfClasses)<<"个班级"<<", "+to_string(sumOfStudent)+"个学生."<<endl;
    cout << "全部载入完毕."<<endl;
    return classesd;
}