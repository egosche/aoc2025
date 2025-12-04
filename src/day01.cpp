#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("data/day01_input.txt");
    if (!file.is_open())
    {
        std::cerr << "Could not open input file.\n";
        return 1;
    }

    int position = 50;             // Dial starts at 50
    long long end_zero_count = 0;  // Part 1
    long long pass_zero_count = 0; // Part 2 ("click" method)

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        char dir = line[0];
        int dist = std::stoi(line.substr(1));

        // For each click, check passing 0
        if (dir == 'L')
        {
            for (int i = 0; i < dist; i++)
            {
                position--;
                if (position < 0)
                    position = 99;
                if (position == 0)
                    pass_zero_count++;
            }
        }
        else
        { // 'R'
            for (int i = 0; i < dist; i++)
            {
                position++;
                if (position > 99)
                    position = 0;
                if (position == 0)
                    pass_zero_count++;
            }
        }

        // Part 1: Zero at the *end* of a rotation
        if (position == 0)
            end_zero_count++;
    }

    std::cout << "Part 1 (end-zero count): " << end_zero_count << std::endl;
    std::cout << "Part 2 (click-zero count): " << pass_zero_count << std::endl;

    return 0;
}