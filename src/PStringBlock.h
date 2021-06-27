#pragma once

class PStringBlock
{
public:
	static const size_t TotalBlockCount = 1024;

public:
	static void Reset(size_t InBlkIdx);
	static void Bind(size_t InBlkIdx, size_t InSize, const char* InData);
	static const char* Get(size_t InBlkIdx, size_t Off);
	
private:
	size_t Size = 0;
	const char* Data = nullptr;

private:
	static PStringBlock TotalBlks[TotalBlockCount];
};
