#include <thread>
#include <chrono>
#include <string>
#include <iostream>
using namespace std;

void function1(){
    for (size_t i = 0; i < 500; i++)
    {
        cout<<"+";
    }
}

void function2(){
    for (size_t i = 0; i < 1000; i++)
    {
        cout<<"-";
    }
}

void function3(){
    for (size_t i = 0; i < 1000; i++)
    {
        cout<<"_";
    }
}

void function4(){
    for (size_t i = 0; i < 1000; i++)
    {
        cout<<"~";
    }
}


int main() {

    std::thread worker1(function1);
    std::thread worker2(function2);
    std::thread worker3(function3);
    std::thread worker4(function4);

    worker1.join();
    worker2.join();
    worker3.join();
    worker4.join();


    cout<<endl;

    return 0;
};
