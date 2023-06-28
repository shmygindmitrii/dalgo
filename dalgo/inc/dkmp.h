#include <string>
#include <vector>
#include <cstdint>

namespace Dalgo
{
    void constructPrefixForKmp(std::string& sPattern, std::vector<int32_t>& vLps);
    int32_t findFirstMatchWithKmp(std::string& sPattern, std::string& sText);
}
