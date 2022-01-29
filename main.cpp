/**
CS219 Project 1
file main.cpp
author Nicholas Larson
version 2.0 1/28/22
First version had separate files for given operations, however for the first project it seemed unnecessary 
**/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdint.h>

int main(){

    // Set the .txt file we obtain our machine instructions to a const string for later reference
    const std::string filename = "Programming-Project-1.txt";

    // These vectors will hold the information we pull in from the file
    std::vector<std::string> operation,stringoperand1, stringoperand2;
    std::vector<unsigned int> operand1, operand2;
    
    // Create the in stream in order to read from the .txt file
    std::ifstream fileReader(filename, std::ios::in);

    // While the in stream is properly functioning, do...
    while(fileReader.good()){
        
        // Temporary strings to hold information we pull in from the .txt file
        std::string tempoperation;
        std::string tempop1, tempop2;

        // Temporary ints to hold the converted hexadecimal values as integers for easy calculation
        unsigned int tempoperand1, tempoperand2;

        // Reading in the strings from the .txt file
        fileReader >> tempoperation >> tempop1 >> tempop2;

        // If we've reached the end of file during reading in, escape the while loop
        if (fileReader.eof()) break;

        // Store the hex strings we've obtained into vectors for use later when printing to the terminal
        stringoperand1.push_back(tempop1);
        stringoperand2.push_back(tempop2);

        // std::hex needs to be used with a form of stream, istringstreams allow us to use a set string 
        // as a stream so std::hex can function. This takes in the temporary hex string variable and converts
        // it to numerical values for calculation. 
        std::istringstream(tempop1) >> std::hex >> tempoperand1;
        std::istringstream(tempop2) >> std::hex >> tempoperand2;

        // Stores the operation string, and both operands that were converted into integers in their
        // associated vectors.
        operation.push_back(tempoperation);
        operand1.push_back(tempoperand1);
        operand2.push_back(tempoperand2);
    }

    // For loop that will go through the vectors and do the requested operation on it's given operands
    // then return the value to the terminal.
    for (int i = 0; operation.size() > i; i++){
        if (operation.at(i) == "ADD"){

            uint32_t total = operand1.at(i) + operand2.at(i);
            std::ostringstream hexoutput;
            hexoutput << std::hex << total;
            std::string result = hexoutput.str();
            std::cout << stringoperand1.at(i) << " + " << stringoperand2.at(i) << " = 0x" << result << std::endl;

        }

    }
    
    return 0;
}