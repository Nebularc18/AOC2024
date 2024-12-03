#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <fstream>

int main() {
    std::ifstream file("Day3.txt");
    std::string input;
    int total_sum = 0;

    // Input string (replace with actual input for real use)
    while (std::getline(file, input))
    {
        // Regular expression to match "mul(x,y)", "do()" and "don't()"
        std::regex instruction_regex(R"(mul\(\d+,\d+\)|do\(\)|don't\(\))");
        std::smatch match;

        bool enabled = true; // Initially, `mul` instructions are enabled
           // To store the sum of results

        // Search for all matches in the input string
        auto it = std::sregex_iterator(input.begin(), input.end(), instruction_regex);
        auto end = std::sregex_iterator();

        for (; it != end; ++it) {
            std::string instr = it->str();

            if (instr == "do()") {
                enabled = true; // Enable future `mul` instructions
            }
            else if (instr == "don't()") {
                enabled = false; // Disable future `mul` instructions
            }
            else if (instr.find("mul") != std::string::npos) {
                if (enabled) {
                    // Extract the two numbers inside "mul(x,y)"
                    std::regex number_regex(R"(\d+)");
                    auto num_it = std::sregex_iterator(instr.begin(), instr.end(), number_regex);

                    int x = std::stoi(num_it->str());
                    int y = std::stoi((++num_it)->str());

                    total_sum += x * y; // Add the product to the total sum
                }
            }
        }

        // Output the result
        

    }
    std::cout << "Total sum: " << total_sum << std::endl;

    return 0;
}
