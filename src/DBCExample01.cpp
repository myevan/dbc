#include "PProperty.h"
#include "PString.h"
#include "PStringBlock.h"
#include "PStringBuilder_std.h"
#include "DBCHelper_std.h"

#include <stdint.h>

#include <iostream>
#include <vector>

#pragma pack(push, 1)

class PCharacter
{
public:
	PProperty<uint32_t> PCharID;
	PProperty<int16_t> Str;
	PProperty<int16_t> Dex;
	PProperty<int16_t> Int;
	PProperty<int16_t> Wis;
	PString Name;
};

class PItem
{
public:
	PProperty<uint32_t> PItemID;
	PProperty<uint32_t> Attr1;
	PProperty<int16_t> Value1;
	PProperty<uint32_t> Attr2;
	PProperty<int16_t> Value2;
	PString Name;
};

#pragma pack(pop)

void BuildCharacterDBC(std::vector<uint8_t>& OutBuf, size_t BlkIdx)
{
	std::PStringBuilder PCharSB(BlkIdx);
	PCharacter PCharDB[2] =
	{
		{ 101, 3, 1, 1, 1, PCharSB.Add("Warrior")},
		{ 102, 1, 3, 1, 1, PCharSB.Add("Archer")},
	};

	std::DBCHelper::Build(OutBuf, PCharSB, sizeof(PCharDB) / sizeof(PCharacter), sizeof(PCharacter), reinterpret_cast<uint8_t*>(PCharDB));
}

void BuildItemDBC(std::vector<uint8_t>& OutBuf, size_t BlkIdx)
{
	std::PStringBuilder PItemSB(BlkIdx);
	PItem PItemDB[2] =
	{
		{ 10001, 3, 1, 1, 1, PItemSB.Add("Healing Potion")},
		{ 10002, 1, 3, 1, 1, PItemSB.Add("Man Potion")},
	};
	
	std::DBCHelper::Build(OutBuf, PItemSB, sizeof(PItemDB) / sizeof(PCharacter), sizeof(PItem), reinterpret_cast<uint8_t*>(PItemDB));
}

int main()
{
	std::vector<uint8_t> CharBuf;
	std::vector<uint8_t> ItemBuf;

	BuildCharacterDBC(CharBuf, 0);
	BuildItemDBC(ItemBuf, 1);
	
	DBCTable<PCharacter> CharTable;
	if (std::DBCHelper::Load(CharTable, CharBuf))
	{
		for (size_t PCharIdx = 0; PCharIdx != CharTable.GetCount(); ++PCharIdx)
		{
			const PCharacter& PChar = CharTable.GetRecordAt(PCharIdx);
			std::cout << *PChar.PCharID << ":" << *PChar.Name << std::endl;
		}
	}

	DBCTable<PItem> ItemTable;
	if (std::DBCHelper::Load(ItemTable, ItemBuf))
	{
		for (size_t PItemIdx = 0; PItemIdx != ItemTable.GetCount(); ++PItemIdx)
		{
			const PItem& PItem = ItemTable.GetRecordAt(PItemIdx);
			std::cout << *PItem.PItemID << ":" << *PItem.Name << std::endl;
		}
	}
	return 0;
}
