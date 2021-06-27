project (dbc)

set(CORE_SRCS
	src/PString.cpp
	src/PStringBlock.cpp
	src/DBCData.cpp)

set(STD_SRCS
	src/DBCHelper_std.cpp
	src/PStringBuilder_std.cpp)

set(EX01_SRCS
	src/DBCExample01.cpp)

add_library(dbc_core STATIC ${CORE_SRCS})
add_library(dbc_std STATIC ${STD_SRCS})

add_executable(dbc_example_01 ${EX01_SRCS})
target_link_libraries(dbc_example_01 dbc_core dbc_std)