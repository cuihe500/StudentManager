#include <iostream>
#include "src/head/File.h"
int main() {
    File file(R"(D:\c++\studentManager\students\1234)");
    classes cls1("20.6","40","1234");
    student std1("20560640111","cuichanghe","nan",100.0,"15303947216");
    cls1.add_Student(std1);
    file.writeStudent(cls1,std1);
//    vector<string>::iterator it;
//    vector<string> files=file.getAllFiles();
//    if(!files.empty()){
//        for(it=files.begin();it!=files.end();it++){
//            cout << *it<<endl;
//        }
//    }else{
//        cout << "null!" <<endl;
//    }

}
