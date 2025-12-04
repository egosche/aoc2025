#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "range_tools.hpp"

int main()
{
    std::ifstream file("data/day02_input.txt");
    if (!file.is_open())
    {
        std::cerr << "Cannot open input file.\n";
        return 1;
    }

    std::string line;
    std::getline(file, line);

    long long sum_exact_twice = 0;    // Part 1
    long long sum_at_least_twice = 0; // Part 2

    std::stringstream ss(line);
    std::string range;

    while (std::getline(ss, range, ','))
    {
        if (range.empty())
            continue;

        size_t dash = range.find('-');
        long long start = std::stoll(range.substr(0, dash));
        long long end = std::stoll(range.substr(dash + 1));

        for (long long id = start; id <= end; ++id)
        {
            if (is_invalid_exact_twice(id))
                sum_exact_twice += id;

            if (is_invalid_at_least_twice(id))
                sum_at_least_twice += id;
        }
    }

    std::cout << "Part 1 (exact twice): " << sum_exact_twice << std::endl;
    std::cout << "Part 2 (at least twice): " << sum_at_least_twice << std::endl;

    return 0;
}