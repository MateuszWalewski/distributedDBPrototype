set(SOURCE_FILES ColumnNodeImpl.cpp)

add_library(ColumnNodeEngine STATIC ${SOURCE_FILES})

target_link_libraries(ColumnNodeEngine PRIVATE Tools TCPChannel TBB::tbb)
target_include_directories(ColumnNodeEngine INTERFACE .)

add_subdirectory(test)