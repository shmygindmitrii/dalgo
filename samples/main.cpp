#include <iostream>
#include "dkmp.h"

using namespace std;

static void testKmpAlgo()
{
    std::string sLine = "aaaaaab";
    std::string sPattern = "aaab";
    int32_t iMatchIdx = Dalgo::findFirstMatchWithKmp(sLine, sPattern);
    std::cout << iMatchIdx << std::endl;
}

int main()
{
    testKmpAlgo();
    return 0;
}

