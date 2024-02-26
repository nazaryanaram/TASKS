#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile("names.txt");
    if (!outFile) {
       std::cout << "Fail not found" << std::endl;
        return 1;
    }

    std::string names[] = {"AIsurveillance", "picsartClone", "spotify", "krisp", "aygiAI"};

    for (int i = 0; i < 5; ++i) {
        outFile << names[i] << std::endl;
    }

    outFile.close();

    std::ifstream inFile("names.txt");
    if (!inFile) {
        std::cout << "Fail not found" << std::endl;
        return 1;
    }

    std::string name;
    std::cout << "Contents of the file:" << std::endl;
    while (getline(inFile, name)) {
        std::cout << name << std::endl;
    }

    inFile.close();
    return 0;
}