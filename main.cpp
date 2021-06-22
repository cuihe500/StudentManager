#include <iostream>
#include "src/head/File.h"
#include <direct.h>
#include "src/head/window.h"
#include "src/head/util.h"

vector<classes*> init(File files);
int main() {
    string path=getcwd(nullptr, 0);
    File file(path+"\\");
    vector<classes*> allClasses=init(file);;
    window win(allClasses,file);
    win._interface();
}
vector<classes*> init(File files){
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