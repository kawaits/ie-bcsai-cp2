#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::ifstream inFile("student_wishes.csv");
    if (!inFile) {
        std::cerr << "Failed to open student_wishes.csv" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::vector<std::string>> data;

    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string cell;
        std::vector<std::string> row;

        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }

    for (const auto& row : data) {
        for (const auto& cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }

    inFile.close();
    return 0;
}

