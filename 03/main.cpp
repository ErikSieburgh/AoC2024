#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>

int main()
{
    std::ifstream inputFile("03/input.txt");
    std::ofstream outputFile("03/new_input.txt"); // New_input file (creates/overwrites)

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

    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not open or create new_input file!" << std::endl;
        return 1;
    }
    else
    {
        std::cout << "File is Opened!" << std::endl;
    }

    std::string line;
    bool capturing = true; // Start capturing from the beginning of the line
    std::string current_substring;

    while (std::getline(inputFile, line))
    {
        for (size_t i = 0; i < line.length(); ++i)
        {
            if (line.substr(i, 7) == "don't()")
            {
                if (capturing && !current_substring.empty())
                {
                    // Stop capturing and write the substring to the file
                    outputFile << current_substring << std::endl;
                    current_substring.clear(); // Clear for the next substring
                }
                capturing = false; // Stop capturing when "don't()" is encountered
                i += 6;            // Skip "don't()" to avoid re-matching
                continue;
            }

            if (line.substr(i, 4) == "do()")
            {
                capturing = true; // Resume capturing when "do()" is encountered
                i += 3;           // Skip "do()" to avoid re-matching
                continue;
            }

            // Add characters to the substring if we are capturing
            if (capturing)
            {
                current_substring += line[i];
            }
        }

        // If the line ends while still capturing, write the remaining substring
        if (capturing && !current_substring.empty())
        {
            outputFile << current_substring << std::endl;
            current_substring.clear();
        }
    }
    outputFile.close();

    std::ifstream new_inputFile("03/new_input.txt");

    // Check if file can be opened
    if (!new_inputFile.is_open())
    {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }
    else
    {
        std::cout << "File is Opened!" << std::endl;
    }

    std::string new_line;
    std::regex pattern("\\((\\d+),(\\d+)\\)"); // Capturing groups for two numbers

    int count = 0;

    while (std::getline(new_inputFile, new_line))
    {

        auto words_begin = std::sregex_iterator(new_line.begin(), new_line.end(), pattern);
        auto words_end = std::sregex_iterator();

        // Find all (number1, number2) pattern in new_line.
        for (std::sregex_iterator i = words_begin; i != words_end; ++i)
        {
            // check if 'mul' is infront of it. TODO make a mul_check function

            std::smatch match = *i;

            // Get the position where the match starts
            size_t start_pos = match.position();

            // Check for "mul" before the match
            bool has_mul_before = false;
            if (start_pos >= 3)
            { // "mul" has 3 characters
                std::string substring_before = new_line.substr(start_pos - 3, 3);
                if (substring_before == "mul")
                {
                    has_mul_before = true;
                }
            }

            if (has_mul_before)
            {
                // Extract number1 and number2 using capturing groups.
                int number1 = std::stoi(match[1].str());
                int number2 = std::stoi(match[2].str());

                std::cout << "Match with 'mul' found before at position: " << start_pos << std::endl;
                std::cout << "Number1: " << number1 << " Number2: " << number2 << std::endl;

                // Multiply digits and add to count
                count += number1 * number2;
            }
        }
    }

    std::cout << "Total sum of multiplications: " << count << std::endl;

    // Print result of exercise 03.1
    std::cout << "Hello, Advent of Code!" << std::endl;

    int day = 3;
    std::cout << "Testing Day " << day << "!" << std::endl;

    inputFile.close();
    return 0;
}
