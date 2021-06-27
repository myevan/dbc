#include "PStringBuilder_std.h"

#include <string.h>

namespace std
{
	PStringBuilder::PStringBuilder(size_t InBlkIdx)
	{
		BlkIdx = InBlkIdx;
	}

	void PStringBuilder::Reserve(size_t InCapacity)
	{
		TotalData.reserve(InCapacity);
	}

	PString PStringBuilder::Add(size_t InSize, const char* InStr)
	{
		size_t NewOff = TotalData.size();
		TotalData.append(InStr, InSize + 1); // with null character
		return PString(InSize, NewOff, BlkIdx);
	}
	PString PStringBuilder::Add(const char* InData)
	{
		return Add(strlen(InData), InData);
	}

	size_t PStringBuilder::GetBlockIndex() const
	{
		return BlkIdx;
	}

	size_t PStringBuilder::GetTotalSize() const
	{
		return TotalData.size();
	}

	const uint8_t* PStringBuilder::GetTotalData() const
	{
		return reinterpret_cast<const uint8_t*>(&TotalData[0]);
	}
}

