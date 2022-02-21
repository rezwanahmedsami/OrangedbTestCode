#include <thread>
#include <chrono>
#include <string>
#include <iostream>



int main() {

    std::cout << "Type exit to quit." << std::endl;

    // initialize other std::thread handlers here 

    std::string input;
    
    while (input != "exit") {
        std::getline(std::cin, input);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "Cleaning up and quitting" << std::endl;

    return 0;
};
