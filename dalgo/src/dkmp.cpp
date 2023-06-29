#include "dkmp.h"
#include <cassert>
#if VERBOSE_OUTPUT
#include <iostream>
#endif

void Dalgo::constructPrefixForKmp(std::string& sPattern, std::vector<int32_t>& vLps)
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

int32_t Dalgo::findFirstMatchWithKmp(std::string& sPattern, std::string& sText)
{
    std::vector<int32_t> vLps(sPattern.size(), 0);
	constructPrefixForKmp(sPattern, vLps);
	size_t zPatLen = sPattern.size();
	size_t zPatIdx = 0;
	int32_t iTextLen = sText.size();
	int32_t iTexIdx = 0;
#if VERBOSE_OUTPUT
	int32_t iCompareIdx = 1;
#endif
	while (zPatIdx < zPatLen && iTexIdx < iTextLen)
	{
#if VERBOSE_OUTPUT
		std::cout << "compare " << iCompareIdx++ << ": sText[" << iTexIdx << "] = " << sText[iTexIdx] << " and sPattern[" << zPatIdx << "] = " << sPattern[zPatIdx] << std::endl;
#endif
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

int32_t Dalgo::findFirstMatchingNaive(std::string& sPattern, std::string& sText)
{
	if (sText.size() < sPattern.size()) return -1;
	int32_t iTexIdx = 0;
	int32_t iPatIdx = 0;
#if VERBOSE_OUTPUT
	int32_t iCompareIdx = 1;
#endif
	while (iTexIdx < sText.size() - sPattern.size() + 1)
	{
		int iTexCurIdx = iTexIdx;
		while (iTexCurIdx < sText.size() && iPatIdx < sPattern.size())
		{
#if VERBOSE_OUTPUT
			std::cout << "compare " << iCompareIdx++ << ": sText[" << iTexCurIdx << "] = " << sText[iTexCurIdx] << " and sPattern[" << iPatIdx << "] = " << sPattern[iPatIdx] << std::endl;
#endif
			if (sText[iTexCurIdx] == sPattern[iPatIdx])
			{
				iTexCurIdx++;
				iPatIdx++;
			}
			else
			{
				iPatIdx = 0;
				break;
			}
		}
		if (iPatIdx == sPattern.size()) return iTexIdx;
		iTexIdx++;
	}
	return -1;
}
