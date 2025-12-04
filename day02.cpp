#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Part 1: repeated exactly twice
bool is_invalid_exact_twice(long long n)
{
    std::string s = std::to_string(n);
    int len = s.size();

    // Must be exactly two repeats => even length
    if (len % 2 != 0)
        return false;

    int half = len / 2;
    return s.substr(0, half) == s.substr(half);
}

// Part 2: repeated at least twice
bool is_invalid_at_least_twice(long long n)
{
    std::string s = std::to_string(n);
    int len = s.size();

    // Try all substring lengths L
    // Repeated at least twice → L*2 <= len
    for (int L = 1; L * 2 <= len; ++L)
    {
        if (len % L != 0)
            continue;

        std::string chunk = s.substr(0, L);
        bool ok = true;

        // check if s==chunk repeated len/L times
        for (int pos = L; pos < len; pos += L)
        {
            if (s.compare(pos, L, chunk) != 0)
            {
                ok = false;
                break;
            }
        }
        if (ok)
            return true;
    }
    return false;
}

int main()
{
    std::ifstream file("day02_input.txt");
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