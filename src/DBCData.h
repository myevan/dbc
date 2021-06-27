#pragma once

#include <stdint.h>
#include <assert.h>

#pragma pack(push, 1)

struct DBCHeader
{
	uint32_t Magic;
	uint32_t RecCnt;
	uint32_t RecSize;
	uint32_t StrBlkIdx;
	uint32_t StrBlkSize;

	static const char FourCC[4];
};

#pragma pack(pop)

class DBCData
{
public:
	bool Bind(size_t InSize, const uint8_t* InData);

	size_t GetCount();

protected:
	const DBCHeader* Header = nullptr;
	const uint8_t* RecBlkData = nullptr;
	const char* StrBlkData = nullptr;
};

template<typename T>
class DBCTable : public DBCData
{
public:
	const T* GetRecords() const
	{
		assert(Header != nullptr);
		assert(sizeof(T) == Header->RecSize);
		return reinterpret_cast<const T*>(RecBlkData);
	}

	const T& GetRecordAt(size_t RecIdx) const
	{
		const T* Records = GetRecords();
		assert(RecIdx < Header->RecCnt);
		return Records[RecIdx];
	}

};