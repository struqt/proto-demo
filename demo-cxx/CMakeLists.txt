cmake_minimum_required(VERSION 3.25)
project(demo_cxx)

set(CMAKE_CXX_STANDARD 17)
include(${CMAKE_CURRENT_SOURCE_DIR}/../third-party/install.cmake)

message(STATUS "Run protoc-gen-cxx.sh +")
execute_process(
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
  COMMAND bash ${CMAKE_CURRENT_SOURCE_DIR}/protoc-gen-cxx.sh
)
message(STATUS "Run protoc-gen-cxx.sh -")

function(fn_target_sources_protoc_gen t)
  message(STATUS "- ${t} fn_target_sources_protoc_gen")
  file(GLOB_RECURSE SOURCES_PROTO_GEN "./gen-cxx/*.cc" "./gen-cxx-grpc/*.cc")
  target_sources(${t} PRIVATE ${SOURCES_PROTO_GEN})
  target_include_directories(${t} PUBLIC ${DIR_THIRD_PARTY_OUT}/abseil-cpp/include)
  target_include_directories(${t} PUBLIC ${DIR_THIRD_PARTY_OUT}/protobuf/include)
  target_include_directories(${t} PUBLIC ${DIR_THIRD_PARTY_OUT}/grpc/include)
  target_include_directories(${t} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/gen-cxx)
  target_include_directories(${t} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/gen-cxx-grpc)
  target_link_libraries(
    ${t} PRIVATE
    absl::flags
    absl::flags_parse
    absl::strings
    absl::time
  )
  target_link_libraries(
    ${t} PRIVATE
    protobuf::libprotobuf
    gRPC::grpc++
    gRPC::grpc++_reflection
  )
endfunction()

function(fn_target_compile_options_setup t)
  message(STATUS "- ${t} fn_target_compile_options_setup")
  if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "- ${t} is buildt in debug mode")
    target_compile_options(${t} PRIVATE -Wall -Wextra)
  elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "- ${t} is buildt in release mode")
    target_compile_options(${t} PRIVATE -O3)
  else ()
    message(STATUS "- ${t} is buildt in default mode: ${CMAKE_BUILD_TYPE}")
  endif ()
endfunction()

function(fn_target_depends_demo_cxx_gen t)
  message(STATUS "- ${t} fn_target_depends_demo_cxx_gen")
  fn_target_compile_options_setup(${t})
  target_link_libraries(${t} PRIVATE demo_cxx_gen)
endfunction()


#--------------------------------------------------------------
add_library(demo_cxx_gen STATIC)
fn_target_sources_protoc_gen(demo_cxx_gen)


#--------------------------------------------------------------
add_executable(demo_cxx_hello cmd/hello.cpp)
fn_target_depends_demo_cxx_gen(demo_cxx_hello)


#--------------------------------------------------------------
add_executable(demo_cxx_server_mt)
target_sources(demo_cxx_server_mt PRIVATE cmd/server_mt.cpp)
fn_target_depends_demo_cxx_gen(demo_cxx_server_mt)


#--------------------------------------------------------------
add_executable(demo_cxx_server cmd/server.cpp)
fn_target_depends_demo_cxx_gen(demo_cxx_server)
file(GLOB_RECURSE SRC_SERVER ${CMAKE_CURRENT_SOURCE_DIR}/src/server/*.cpp)
target_sources(demo_cxx_server PRIVATE ${SRC_SERVER})
target_include_directories(demo_cxx_server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/server)


#--------------------------------------------------------------
add_executable(demo_cxx_client cmd/client.cpp)
fn_target_depends_demo_cxx_gen(demo_cxx_client)
