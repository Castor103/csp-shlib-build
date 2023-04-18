# 프로젝트 정보
project( csp_shlib_test )
set(OUTPUT_PROGRAM_NAME csp_shlib_test)

message("---------------------------")

set(ROOT src)
set(INCLUDE_DIR include)
set(EXCLUDE_PATHS ${PROJECT_SOURCE_DIR}/build)

message("  : exclude path")
message("  : ${EXCLUDE_PATHS}")

file(GLOB_RECURSE APP_SOURCES "*.c")
foreach(TMP_PATH ${APP_SOURCES})
    foreach(EXCLUDE_PATH ${EXCLUDE_PATHS})
        string(FIND ${TMP_PATH} ${EXCLUDE_PATH} RESULT)
        if(NOT ${RESULT} EQUAL -1)
            list(REMOVE_ITEM APP_SOURCES ${TMP_PATH})
        endif()
    endforeach(EXCLUDE_PATH)
endforeach(TMP_PATH)

message("---------------------------")
message("  : ${APP_SOURCES}")
message("---------------------------")

find_package(Threads)
find_library(LIB_CSP libcsp.so PATHS ${INCLUDE_DIR}/csp)

include_directories(${INCLUDE_DIR})
add_compile_options(-W -Wall -Wno-all -std=gnu99) #-lwebsockets

add_executable(${OUTPUT_PROGRAM_NAME} ${APP_SOURCES})
target_link_libraries(${OUTPUT_PROGRAM_NAME} PUBLIC zmq)
target_link_libraries(${OUTPUT_PROGRAM_NAME} PUBLIC ${LIB_CSP})
