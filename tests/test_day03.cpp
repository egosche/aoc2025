#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>
#include "joltage.hpp"

// ------------------------------------------------------------
//  Tests for max_joltage_from_bank (Part 1)
// ------------------------------------------------------------

TEST_CASE("Part 1: Simple pairs", "[max_joltage_from_bank]")
{
    REQUIRE(max_joltage_from_bank("12") == 12);
    REQUIRE(max_joltage_from_bank("21") == 21);
    REQUIRE(max_joltage_from_bank("98") == 98);
}

TEST_CASE("Part 1: Increasing digits", "[max_joltage_from_bank]")
{
    // Best pair is last two digits: 89
    REQUIRE(max_joltage_from_bank("123456789") == 89);
}

TEST_CASE("Part 1: Decreasing digits", "[max_joltage_from_bank]")
{
    // Best pair is first two digits: 98
    REQUIRE(max_joltage_from_bank("987654321") == 98);
}

TEST_CASE("Part 1: Mixed digits", "[max_joltage_from_bank]")
{
    REQUIRE(max_joltage_from_bank("818181911112111") == 92);
    REQUIRE(max_joltage_from_bank("234234234234278") == 78);
}

TEST_CASE("Part 1: Edge cases", "[max_joltage_from_bank]")
{
    REQUIRE(max_joltage_from_bank("9") == 0); // Not enough digits
    REQUIRE(max_joltage_from_bank("") == 0);  // No digits
    REQUIRE(max_joltage_from_bank("1") == 0);
}

// ------------------------------------------------------------
//  Tests for max12_joltage_from_bank (Part 2)
// ------------------------------------------------------------

TEST_CASE("Part 2: selects exactly 12 digits", "[max12_joltage_from_bank]")
{
    std::string s = "987654321111111";
    REQUIRE(max12_joltage_from_bank(s) == 987654321111ULL);
}

TEST_CASE("Part 2: example banks", "[max12_joltage_from_bank]")
{
    REQUIRE(max12_joltage_from_bank("987654321111111") == 987654321111ULL);
    REQUIRE(max12_joltage_from_bank("811111111111119") == 811111111119ULL);
    REQUIRE(max12_joltage_from_bank("234234234234278") == 434234234278ULL);
    REQUIRE(max12_joltage_from_bank("818181911112111") == 888911112111ULL);
}

TEST_CASE("Part 2: short input edge cases", "[max12_joltage_from_bank]")
{
    // If fewer than 12 digits exist, function will return some shorter number.
    // Acceptable unless you choose to validate input length elsewhere.

    REQUIRE(max12_joltage_from_bank("12345678901") == 12345678901ULL); // 11 digits
    REQUIRE(max12_joltage_from_bank("5") == 5ULL);
    REQUIRE(max12_joltage_from_bank("") == 0ULL);
}