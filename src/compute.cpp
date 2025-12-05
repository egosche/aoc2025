#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "compute.hpp"

/**
 * @brief Compute the maximum two-digit joltage from a bank of batteries.
 *
 * Given a string of digits, representing battery joltages in order,
 * choose two positions i < j and return the maximum value of:
 *
 *     10 * (digit at i) + (digit at j)
 *
 * This brute-force approach tries all valid pairs.
 *
 * @param s A string of digits ('1' to '9').
 * @return int The largest two-digit value that can be formed.
 */
int max_joltage_from_bank(const std::string &s)
{
    int best = 0;

    for (std::size_t i = 0; i + 1 < s.size(); ++i)
    {
        int a = s[i] - '0';
        for (std::size_t j = i + 1; j < s.size(); ++j)
        {
            int b = s[j] - '0';
            int val = 10 * a + b;
            if (val > best)
                best = val;
        }
    }

    return best;
}

/**
 * @brief Part 2: Compute the largest possible 12-digit number
 *        by selecting exactly 12 digits in order from the string.
 *
 * This uses a greedy monotonic stack approach:
 *
 * - We walk through digits left to right.
 * - We keep a result vector acting like a stack.
 * - While the current digit is better than the last kept digit,
 *   and we can still complete 12 digits later, we pop.
 *
 * @param s The battery bank digits.
 * @return unsigned long long The resulting 12-digit number.
 */
unsigned long long max12_joltage_from_bank(const std::string &s)
{
    const int K = 12;
    int n = s.size();

    std::vector<char> result;
    result.reserve(K);

    int to_pick = K;

    for (int i = 0; i < n; ++i)
    {
        char c = s[i];

        // While we can improve the number by removing the previous digit
        // and still have enough digits left to fill all 12 positions:
        while (!result.empty() &&
               result.back() < c &&
               (int)result.size() - 1 + (n - i) >= to_pick)
        {
            result.pop_back();
        }

        // If we still need more digits, take this one.
        if ((int)result.size() < to_pick)
            result.push_back(c);
    }

    // Convert 12 chars to a 64-bit integer
    unsigned long long value = 0;
    for (char c : result)
    {
        value = value * 10 + (c - '0');
    }
    return value;
}