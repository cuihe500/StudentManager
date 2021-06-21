#include <iostream>
#include "src/head/File.h"
int main() {
    File file(R"(D:\c++\studentManager\students\1234)");
    vector<string>::iterator it;
    vector<string> files=file.getAllFiles();
    if(!files.empty()){
        for(it=files.begin();it!=files.end();it++){
            cout << *it<<endl;
        }
    }else{
        cout << "null!" <<endl;
    }
}
