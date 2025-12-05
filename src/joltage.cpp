#include "joltage.hpp"
#include <string>
#include <vector>
#include <algorithm> // for std::max
#include <cstdint>   // ensure uint64_t is defined

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
 * @return int The largest two-digit number that can be formed.
 */
int max_joltage_from_bank(const std::string &s)
{
    int best = 0;

    for (size_t i = 0; i + 1 < s.size(); ++i)
    {
        int a = s[i] - '0';
        for (size_t j = i + 1; j < s.size(); ++j)
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
 * Greedy monotonic-stack logic:
 *
 * - Traverse digits left to right.
 * - Maintain a stack (vector<char>) storing chosen digits.
 * - If the current digit is larger than the last chosen digit AND
 *   there are enough characters remaining to complete a 12-digit result,
 *   pop the previous digit.
 *
 * This ensures the lexicographically largest possible 12-digit number.
 *
 * @param s The battery bank digits.
 * @return uint64_t The resulting 12-digit number.
 */
uint64_t max12_joltage_from_bank(const std::string &s)
{
    constexpr size_t K = 12;
    const size_t n = s.size();

    std::vector<char> result;
    result.reserve(K);

    for (size_t i = 0; i < n; ++i)
    {
        char c = s[i];
        size_t remaining = n - i;

        // While current digit is better than last chosen digit
        // AND we can still form a full 12-digit number afterward.
        while (!result.empty() &&
               result.back() < c &&
               (result.size() - 1 + remaining >= K))
        {
            result.pop_back();
        }

        // Take digit if we still need more to reach 12
        if (result.size() < K)
            result.push_back(c);
    }

    // Convert char digits to integer
    uint64_t value = 0;
    for (char c : result)
        value = value * 10 + (c - '0');

    return value;
}