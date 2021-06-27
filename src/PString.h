#pragma once

#include <stdint.h>

class PString
{
public:
	PString(size_t InSize, size_t InOff, size_t InBlkIdx);
	PString(const PString& InStr);

	const char* operator*() const;

	size_t GetSize();

private:
	uint16_t BlkIdx;
	uint16_t Size;
	uint32_t Off;
};
