#include <glob.h>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

vector<string> globVector(const string& pattern){
    glob_t glob_result;
    glob(pattern.c_str(),GLOB_TILDE,NULL,&glob_result);
    vector<string> files;
    for(unsigned int i=0;i<glob_result.gl_pathc;++i){
        files.push_back(string(glob_result.gl_pathv[i]));
    }
    globfree(&glob_result);
    return files;
}

int main(){
    vector<string> files = globVector("./files/*");
    for (size_t i = 0; i < 20; i++)
    {
        char buffer[500];
        strcpy(buffer, files[i].c_str());
        cout<<remove(buffer)<<endl;
    }
    // cout<<remove("./files/fg6")<<endl;
    
}