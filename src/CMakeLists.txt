# 프로젝트 정보
project( test_libcsp )
set(OUTPUT_PROGRAM_NAME test_libcsp)

#cmake_minimum_required(VERSION 2.8)
#set(CMAKE_C_COMPILER "gcc")

message(" -- PROJECT_NAME   : "${PROJECT_NAME})
message(${CMAKE_PROJECT_NAME})
message(${PROJECT_BINARY_DIR})
message(${PROJECT_SOURCE_DIR})
# NST_Subsystem_Data_Simul_Project
# /home/user/workspace/testcpp_white/build
# /home/user/workspace/testcpp_white

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

#link_directories(${PROJECT_SOURCE_DIR}/${INCLUDE_DIR}/csp/)

#add_library(${PROJECT_SOURCE_DIR}/${INCLUDE_DIR}/csp/libcsp.so)

include_directories(${INCLUDE_DIR})

add_compile_options(-W -Wall -Wno-all -std=gnu99) #-lwebsockets

add_executable(${OUTPUT_PROGRAM_NAME} ${APP_SOURCES})

target_link_libraries(${OUTPUT_PROGRAM_NAME} PUBLIC zmq)
target_link_libraries(${OUTPUT_PROGRAM_NAME} PUBLIC ${LIB_CSP})

# if(MAKE_OWN_MODE)
# install(TARGETS ${OUTPUT_PROGRAM_NAME} ${LIB_NAME}
#     RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/build
#     LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/build)
# else()
# install(TARGETS ${OUTPUT_PROGRAM_NAME} ${LIB_NAME}
#     RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/../../build
#     LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/../../build)
# endif()