#include<iostream>
#include<fstream>
#include "./json.hpp"
using namespace std;
using json = nlohmann::json;
int main()
{
    std::ifstream i(".table.config");
    json j;
    i >> j;

    j["inttest"] = 7;
    ofstream myfile;
    myfile.open (".table.config");
    myfile<<j.dump(4);
    // std::cout<<j["inttest"]<<std::endl;
    std::cout << j.dump(4) << std::endl;
    return 0;
}