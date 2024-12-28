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

int sum_distances(std::vector<int> left, std::vector<int> right)
{
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    std::vector<int> distance;

    // We have two sorted lists. Now if we just take the distance between each of the rows of the vector, we get the distances we want.
    // TODO compute distance between lists
    for (int i = 0; i < left.size(); ++i)
    {
        int left_element = left.at(i);
        int right_element = right.at(i);
        int temp_distance = std::abs(left_element - right_element);
        distance.push_back(temp_distance);
    }
    // Add distances all together
    auto sum_of_distances = std::reduce(distance.begin(), distance.end());

    return sum_of_distances;
}
// Helper lambda function to print key-value pairs
auto print_key_value = [](const auto &key, const auto &value)
{
    std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
};

int similarity_score(const std::vector<int> left, const std::vector<int> right)
{

    int similarity_score = 0; // Initialize the similarity score to a value.

    std::unordered_map<int, int> right_counts;
    for (int i = 0; i < right.size(); ++i)
    {
        right_counts[right[i]]++;
    }

    for (int i = 0; i < left.size(); ++i)
    {
        int temp = left[i] * right_counts[left[i]];
        similarity_score += temp;
    }
    return similarity_score;
}

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

    // Print result of exercise 01.1
    std::cout << "Hello, Advent of Code!" << std::endl;

    int day = 1;
    std::cout << "Testing Day " << day << "!" << std::endl;

    std::cout << "Results 01.1 =  " << sum_distances(vector1, vector2) << std::endl;

    std::cout << "Results 01.2 =  " << similarity_score(vector1, vector2) << std::endl;

    inputFile.close();
    return 0;
}