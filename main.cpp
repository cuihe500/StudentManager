#include <iostream>
#include "src/head/File.h"
int main() {
    File file(R"(C:\Users\Watcher-7\Downloads\Compressed\StudentManager-main\)");
    classes cls1("20.6","40","计算机科学与技术学院");
    student std1("20560640111","cuichanghe","nan",100.0,"15303947216");
    student std2("205606401113","cuichanghe2","nan",100.0,"153039472161");
    classes cls2("20.7","40","5678");
    cls1.add_Student(&std1);
    cls1.add_Student(&std2);
//    file.writeStudent(cls1,std1);
    file.writeAllStudents(cls1);
    file.writeAllStudents(cls2);
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
