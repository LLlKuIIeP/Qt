#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <limits>

#define GB 1024*1024*1024

int main(int argc, char *argv[])
{
    std::ofstream out_file("array.txt", std::ios_base::trunc);

    std::mt19937 generator(time(0));
    std::uniform_real_distribution<double> urd(std::numeric_limits<double>::min(), std::numeric_limits<double>::max());

    while (out_file.tellp() < GB) {
        out_file << urd(generator) << std::endl;
        out_file.flush();
    }

    out_file.close();
    return 0;
}
