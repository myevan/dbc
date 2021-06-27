#include "PStringBlock.h"

#include <assert.h>

PStringBlock PStringBlock::TotalBlks[TotalBlockCount];

void PStringBlock::Reset(size_t InBlkIdx)
{
	assert(InBlkIdx < TotalBlockCount);
	PStringBlock& Blk = TotalBlks[InBlkIdx];
	Blk.Size = 0;
	Blk.Data = nullptr;
}

void PStringBlock::Bind(size_t InBlkIdx, size_t InSize, const char* InData)
{
	assert(InBlkIdx < TotalBlockCount);
	PStringBlock& Blk = TotalBlks[InBlkIdx];
	assert(Blk.Data == nullptr);
	Blk.Data = InData;
	Blk.Size = InSize;
}

const char* PStringBlock::Get(size_t InBlkIdx, size_t Off)
{
	assert(InBlkIdx < TotalBlockCount);
	PStringBlock& Blk = TotalBlks[InBlkIdx];
	assert(Blk.Data != nullptr);
	assert(Off < Blk.Size);
	return Blk.Data + Off;
}
