#include "range_tools.hpp"
#include <string>

/**
 * @brief Check if a number consists of exactly two identical halves.
 *
 * Examples:
 *   - 1212  -> true  (12 | 12)
 *   - 5555  -> true  (55 | 55)
 *   - 1234  -> false
 *   - 123   -> false (odd length)
 *
 * @param n The number to evaluate.
 * @return true if the number is of even length and the first half equals the second.
 */
bool is_invalid_exact_twice(long long n)
{
    std::string s = std::to_string(n);
    int len = s.size();
    if (len % 2 != 0)
        return false;
    int half = len / 2;
    return s.substr(0, half) == s.substr(half);
}

/**
 * @brief Check if a number is composed of repeated identical chunks (length L),
 *        where the number contains at least two repetitions.
 *
 * The chunk length L must divide the total length.
 *
 * Examples:
 *   - 1212     -> true (chunk "12")
 *   - 123123   -> true (chunk "123")
 *   - 4444     -> true (chunk "4")
 *   - 1234     -> false
 *
 * @param n The number to evaluate.
 * @return true if the number’s string representation repeats a chunk at least twice.
 */
bool is_invalid_at_least_twice(long long n)
{
    std::string s = std::to_string(n);
    int len = s.size();

    for (int L = 1; L * 2 <= len; ++L)
    {
        if (len % L != 0)
            continue;
        std::string chunk = s.substr(0, L);
        bool ok = true;
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