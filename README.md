# DBC

DataBaseClient

## How to use

### Modeling

```cpp
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
```

### Building

```cpp
std::PStringBuilder PCharSB(0);

PCharacter PCharDB[2] =
{
    { 101, 3, 1, 1, 1, PCharSB.Add("Warrior")},
    { 102, 1, 3, 1, 1, PCharSB.Add("Archer")},
};

std::DBCHelper::Build(OutBuf, PCharSB, sizeof(PCharDB) / sizeof(PCharacter), sizeof(PCharacter), reinterpret_cast<uint8_t*>(PCharDB));
```

### Loading

```cpp
DBCTable<PCharacter> CharTable;
if (std::DBCHelper::Load(CharTable, CharBuf))
{
    for (size_t PCharIdx = 0; PCharIdx != CharTable.GetCount(); ++PCharIdx)
    {
        const PCharacter& PChar = CharTable.GetRecordAt(PCharIdx);
        std::cout << *PChar.PCharID << ":" << *PChar.Name << std::endl;
    }
}
```

## How to build

### Windows

```bat
> cd __build
> cmake ..
> msbuild
```

## References

* <https://wowdev.wiki/DBC>

