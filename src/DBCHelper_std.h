#pragma once

#include "PStringBuilder_std.h"
#include "DBCData.h"

#include <vector>

namespace std
{
	class DBCHelper
	{
	public:
		static void Build(std::vector<uint8_t>& OutBuf, const std::PStringBuilder& SB, size_t RecordCnt, size_t RecordSize, const uint8_t* RecordData);

		static bool Load(DBCData& OutData, std::vector<uint8_t>& InBuf);
	};
}
