#include<iostream>
#include<fstream>
#include "./json.hpp"
using namespace std;
using json = nlohmann::json;
int main()
{
    std::ifstream i("file.json");
    json j;
    i >> j;
    std::cout<<j["ts"]<<std::endl;
    return 0;
}