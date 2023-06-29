#include <iostream>
#include "dkmp.h"

using namespace std;

static void testKmpAlgo()
{
    std::string sLine = "absabcabadageh";
    std::string sPattern = "abcaba";
    int32_t iMatchIdx = Dalgo::findFirstMatchWithKmp(sPattern, sLine);
    std::cout << iMatchIdx << std::endl;
}

int main()
{
    testKmpAlgo();
    return 0;
}

