#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdint.h>

int main(){
    
    const std::string filename = "Programming-Project-1.txt";

    std::vector<std::string> operation,stringoperand1, stringoperand2;
    std::vector<unsigned int> operand1, operand2;
    
    std::ifstream fileReader(filename, std::ios::in);

    while(fileReader.good()){

        std::string tempoperation;
        std::string tempop1, tempop2;
        unsigned int tempoperand1, tempoperand2;

        fileReader >> tempoperation >> tempop1 >> tempop2;
        if (fileReader.eof()) break;

        stringoperand1.push_back(tempop1);
        stringoperand2.push_back(tempop2);

        std::istringstream(tempop1) >> std::hex >> tempoperand1;
        std::istringstream(tempop2) >> std::hex >> tempoperand2;

        operation.push_back(tempoperation);
        operand1.push_back(tempoperand1);
        operand2.push_back(tempoperand2);
    }

    for (int i = 0; operation.size() > i; i++){
        if (operation.at(i) == "ADD"){

            uint32_t total = operand1.at(i) + operand2.at(i);
            std::stringstream hexoutput;
            hexoutput << std::hex << total;
            std::string result = hexoutput.str();
            std::cout << stringoperand1.at(i) << " + " << stringoperand2.at(i) << " = 0x" << result << std::endl;

        }

    }
    
    return 0;
}