#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    int total_files = 0;
    fstream f;
    cout<<"How many file you want to create: ";
    cin>>total_files;

    for (size_t i = 0; i < total_files; i++)
    {
        f.open("./test/fg"+to_string(i), ios::out);
        if (!f){                 
        cout<<"Error while creating the file: "+to_string(i)<<endl;    
        }else{
            cout<<"File created successfully: "+to_string(i)<<endl;   
            f<<"This is a blog posted on Great Learning: "+to_string(i); 
            f.close();           
        }
    }
    
    return 0;
}