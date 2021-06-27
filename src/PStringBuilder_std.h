#pragma once

#include "PString.h"

#include <string>

namespace std
{
	class PStringBuilder
	{
	public:
		PStringBuilder(size_t InBlkIdx);

		void Reserve(size_t InCapacity);

		PString Add(size_t InSize, const char* InStr);
		PString Add(const char* InData);

		size_t GetBlockIndex() const;
		size_t GetTotalSize() const;

		const uint8_t* GetTotalData() const;

	private:
		size_t BlkIdx;

	private:
		std::string TotalData;
	};

}

