#include <thread>
#include <chrono>
#include <string>
#include <iostream>
using namespace std;

void function1(){
    for (size_t i = 0; i < 200; i++)
    {
        cout<<"+";
    }
}

void function2(){
    for (size_t i = 0; i < 200; i++)
    {
        cout<<"-";
    }
}


int main() {

    std::thread worker1(function1);
    // std::thread worker2(function2);
    cout<<endl;

    return 0;
};
