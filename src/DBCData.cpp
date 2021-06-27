#include "DBCData.h"
#include "PStringBlock.h"

#include <memory.h>

const char DBCHeader::FourCC[4] = { 'X', 'D', 'B', 'C' };

bool DBCData::Bind(size_t InSize, const uint8_t* InData)
{
	if (InSize < sizeof(DBCHeader::FourCC))
		return false;
	
	if (memcmp(InData, DBCHeader::FourCC, sizeof(DBCHeader::FourCC) != 0))
		return false;
	
	const DBCHeader* InHeader = reinterpret_cast<const DBCHeader*>(InData);
	
	size_t StrBlkOffset = sizeof(DBCHeader);
	StrBlkOffset += InHeader->RecCnt * InHeader->RecSize;
	const char* StrBlkData = reinterpret_cast<const char*>(InData + StrBlkOffset);
	PStringBlock::Bind(InHeader->StrBlkIdx, InHeader->StrBlkSize, StrBlkData);

	const uint8_t* InRecBlkData = InData + sizeof(DBCHeader);
	Header = InHeader;
	RecBlkData = InRecBlkData;
	StrBlkData = StrBlkData;
	return true;
}

size_t DBCData::GetCount()
{
	assert(Header != nullptr);
	return Header->RecCnt;
}