#include <string>
#include <vector>
#include <cstdint>

namespace Dalgo
{
    void constructPrefixForKmp(std::vector<int32_t>& vLps, std::string& sPattern);
    int32_t findFirstMatchWithKmp(std::string& sText, std::string& sPattern);
}
