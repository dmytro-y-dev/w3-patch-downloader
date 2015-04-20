#-----------------------------------------------
#  Source code compilation instructions
#-----------------------------------------------

include_directories(include)

FILE(GLOB PROJECT_SOURCE_FILES source/*.cpp)

add_executable(w3-patch-downloader ${PROJECT_SOURCE_FILES})
target_link_libraries(w3-patch-downloader lasote_curl)