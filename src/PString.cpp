#include "PString.h"
#include "PStringBlock.h"

#include <assert.h>

PString::PString(size_t InSize, size_t InOff, size_t InBlkIdx)
{
	assert(InSize <= 0xffff);
	assert(InOff <= 0xffff);
	BlkIdx = static_cast<uint16_t>(InBlkIdx);
	Size = static_cast<uint16_t>(InSize);
	Off = static_cast<uint16_t>(InOff);
}

PString::PString(const PString& InStr)
{
	BlkIdx = InStr.BlkIdx;
	Size = InStr.Size;
	Off = InStr.Off;
}

const char* PString::operator*() const
{
	return PStringBlock::Get(BlkIdx, Off);
}

size_t PString::GetSize()
{
	return Size;
}

