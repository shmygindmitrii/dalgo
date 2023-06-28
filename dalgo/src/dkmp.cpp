#include "dkmp.h"
#include <cassert>

void Dalgo::constructPrefixForKmp(std::vector<int32_t>& vLps, std::string& sPattern)
{
    assert(vLps.size() == sPattern.size());
    vLps[0] = 0;
    size_t zPatternMatchLen = 0;
	int32_t iLpsIdx = 1;
    while (iLpsIdx < sPattern.size())
    {
        if (sPattern[iLpsIdx] == sPattern[zPatternMatchLen])
        {
            vLps[iLpsIdx++] = ++zPatternMatchLen;
        }
        else
        {
            if (zPatternMatchLen > 0)
            {
				zPatternMatchLen = vLps[zPatternMatchLen - 1];
            }
            else
            {
                vLps[iLpsIdx++] = 0;
            }
        }
    }
}

int32_t Dalgo::findFirstMatchWithKmp(std::string& sText, std::string& sPattern)
{
    std::vector<int32_t> vLps(sPattern.size(), 0);
	constructPrefixForKmp(vLps, sPattern);
	size_t zPatLen = sPattern.size();
	size_t zPatIdx = 0;
	int32_t iTextLen = sText.size();
	int32_t iTexIdx = 0;
	while (zPatIdx < zPatLen && iTexIdx < iTextLen)
	{
		if (sPattern[zPatIdx] == sText[iTexIdx])
		{
			if (zPatIdx == zPatLen - 1)
			{
				// last character of pattern matches, we found pattern in text
				int32_t iFoundIdx = iTexIdx - zPatLen + 1;
				return iFoundIdx;
			}
			else
			{
				// matches, but it is not the last character
				iTexIdx++;
				zPatIdx++;
			}
		}
		else
		{
			if (zPatIdx > 0)
			{
				zPatIdx = vLps[zPatIdx - 1];
			}
			else
			{
				iTexIdx++;
			}
		}
	}
	return -1;
}
