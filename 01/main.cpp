#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <vector> // std::vector
#include <numeric>
#include <cmath>

/**
    \file 01_1.cxx

    \author Erik Sieburgh
*/

int main()
{
    std::ifstream inputFile("01/input.txt");

    // Check if file can be opened
    if (!inputFile.is_open())
    {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }
    else
    {
        std::cout << "File is Opened!" << std::endl;
    }

    std::string line;
    std::vector<int> vector1;
    std::vector<int> vector2;

    while (std::getline(inputFile, line))
    {
        // Use a stringstream to parse each line
        std::istringstream iss(line);
        int num1, num2;

        if (iss >> num1 >> num2) // Read two integers and add to vectors
        {
            vector1.push_back(num1);
            vector2.push_back(num2);
        }
        else
        {
            std::cerr << "Failed to parse numbers in line: " << line << std::endl;
        }
    }

    std::sort(vector1.begin(), vector1.end());
    std::sort(vector2.begin(), vector2.end());

    std::vector<int> distance;

    // We have two sorted lists. Now if we just take the distance between each of the rows of the vector, we get the distances we want.
    // TODO compute distance between lists
    for (int i = 0; i < vector1.size(); ++i)
    {
        int vector_element1 = vector1.at(i);
        int vector_element2 = vector2.at(i);
        int temp_distance = std::abs(vector_element1 - vector_element2);
        distance.push_back(temp_distance);
    }

    // Add distances all together
    auto result = std::reduce(distance.begin(), distance.end());

    // Print result of exercise 01.1
    std::cout << "Hello, Advent of Code!" << std::endl;

    int day = 1;
    std::cout << "Testing Day " << day << "!" << std::endl;

    std::cout << "Results 01.1 =  " << result << std::endl;

    inputFile.close();
    return 0;
}
/**


    std::regex pattern("(\d+)\s+(\d+)");
    std::vector<int> list1;
    std::vector<int> list2;

    // Read every line and do the following line separately.
    while (std::getline(inputFile, line))
    {
        auto numbers_begin = std::sregex_iterator(line.begin(), line.end(), pattern);
        auto numbers_end = std::sregex_iterator();

        for (std::sregex_iterator i = numbers_begin; i != numbers_end; ++i)
        {
            std::smatch match = *i;
            std::string match_str = match.str();
            std::cout << match_str << '\n';
        }
    }

    std::cout << "Hello, Advent of Code!" << std::endl;


    return 0;
}


 */