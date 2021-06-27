#include "DBCHelper_std.h"
#include "DBCData.h"

#include "PStringBlock.h"

namespace std
{
	void DBCHelper::Build(std::vector<uint8_t>& OutBuf, const std::PStringBuilder& SB, size_t RecCnt, size_t RecSize, const uint8_t* RecBlockData)
	{
		DBCHeader Header;
		Header.Magic = *reinterpret_cast<const uint32_t*>(&DBCHeader::FourCC[0]);
		Header.RecCnt = RecCnt;
		Header.RecSize = RecSize;
		Header.StrBlkIdx = SB.GetBlockIndex();
		Header.StrBlkSize = SB.GetTotalSize();

		size_t RecBlkSize = Header.RecCnt * Header.RecSize;
		OutBuf.reserve(sizeof(Header) + RecBlkSize + Header.StrBlkSize);
		OutBuf.insert(OutBuf.end(), reinterpret_cast<const uint8_t*>(&Header), reinterpret_cast<const uint8_t*>(&Header) + sizeof(Header));
		OutBuf.insert(OutBuf.end(), RecBlockData, RecBlockData + RecBlkSize);
		OutBuf.insert(OutBuf.end(), SB.GetTotalData(), SB.GetTotalData() + SB.GetTotalSize());
	}

	bool DBCHelper::Load(DBCData& OutData, std::vector<uint8_t>& InBuf)
	{
		return OutData.Bind(InBuf.size(), &InBuf[0]);
	}

}
