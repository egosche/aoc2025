#include "range_tools.hpp"
#include <string>

bool is_invalid_exact_twice(long long n)
{
    std::string s = std::to_string(n);
    int len = s.size();
    if (len % 2 != 0)
        return false;
    int half = len / 2;
    return s.substr(0, half) == s.substr(half);
}

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