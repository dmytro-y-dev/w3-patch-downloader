#-----------------------------------------------
#  Source code compilation instructions
#-----------------------------------------------

include_directories(include)

FILE(GLOB PROJECT_SOURCE_FILES source/*.cpp)

find_package(curl REQUIRED)

add_executable(w3-patch-downloader ${PROJECT_SOURCE_FILES})

if (CURL_FOUND)
    target_link_libraries(w3-patch-downloader curl)
else()
    target_link_libraries(w3-patch-downloader lasote_curl)
endif()