#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "compute.hpp"

/**
 * @brief Program entry point.
 *
 * Reads the puzzle input from data/day03_input.txt, where each line
 * represents a bank of batteries as a sequence of digits (1–9).
 *
 * For each bank:
 *   - Part 1: Computes the maximum possible 2-digit joltage using
 *             max_joltage_from_bank(), which selects two digits in order
 *             that form the largest possible value.
 *
 *   - Part 2: Computes the maximum possible 12-digit joltage using
 *             max12_joltage_from_bank(), which selects exactly twelve digits
 *             in order to form the lexicographically largest possible number.
 *
 * The program accumulates the total joltage for both parts and prints:
 *   - "Part 1 total output joltage"
 *   - "Part 2 total output joltage"
 *
 * @return 0 on success, nonzero on file open failure.
 */
int main()
{
    std::ifstream file("data/day03_input.txt");
    if (!file.is_open())
    {
        std::cerr << "Could not open input file.\n";
        return 1;
    }

    long long part1_total = 0;
    unsigned long long part2_total = 0;

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        // Part 1: best 2-digit number
        part1_total += max_joltage_from_bank(line);

        // Part 2: best 12-digit number
        part2_total += max12_joltage_from_bank(line);
    }

    std::cout << "Part 1 total output joltage: " << part1_total << std::endl;
    std::cout << "Part 2 total output joltage: " << part2_total << std::endl;

    return 0;
}