cmake_minimum_required(VERSION 3.28.3)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMONISM_SDK_SOURCE               src/pokemonism/sdk/log.cc
                                        src/pokemonism/sdk/string.cc
                                        src/pokemonism/sdk/stream.cc
                                        src/pokemonism/sdk/linked/list.cc
                                        src/pokemonism/sdk/dictionary/binary/search.cc
                                        src/pokemonism/sdk/dictionary/red/black.cc
                                        src/pokemonism/sdk/continuous.cc
                                        src/pokemonism/sdk/typographer.cc
                                        src/pokemonism/sdk/application.cc
                                        src/pokemonism/sdk/exception.cc
                                        src/pokemonism/sdk/allocator.cc
                                        src/pokemonism/sdk/memorizer.cc
                                        src/pokemonism/sdk/synchronizer.cc
                                        src/pokemonism/sdk/synchronizer/guard.cc
                                        src/pokemonism/sdk/memorizer/primitivable.cc
                                        src/pokemonism/sdk/memorizer/primitivable/one.cc)

set(POKEMONISM_SDK_HEADER               src/pokemonism/sdk/log.hh
                                        src/pokemonism/sdk/string.hh
                                        src/pokemonism/sdk/stream.hh
                                        src/pokemonism/sdk/linked/list.hh
                                        src/pokemonism/sdk/dictionary/binary/search.hh
                                        src/pokemonism/sdk/dictionary/red/black.hh
                                        src/pokemonism/sdk/continuous.hh
                                        src/pokemonism/sdk/typographer.hh
                                        src/pokemonism/sdk/application.hh
                                        src/pokemonism/sdk/exception.hh
                                        src/pokemonism/sdk/allocator.hh
                                        src/pokemonism/sdk/memorizer.hh
                                        src/pokemonism/sdk/synchronizer.hh
                                        src/pokemonism/sdk/synchronizer/guard.hh
                                        src/pokemonism/sdk/memorizer/primitivable.hh
                                        src/pokemonism/sdk/memorizer/primitivable/one.hh)

add_library(pokemonism-sdk              ${POKEMONISM_SDK_SOURCE}
                                        ${POKEMONISM_SDK_HEADER})

# --- CI 제국을 위한 '가상 훈련장' 건설 ---
# Google Test 프레임워크를 도입해서, 우리의 실험적인 무기들을
# 1나노초 단위까지 정밀하게 측정하고 검증할 수 있는 환경을 구축합니다. ㅋㅋㅋ
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# For Windows:
# FetchContent_MakeAvailable(googletest)

# For other OSs:
set(gtest_build_tests OFF)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

# 모든 테스트를 위한 공통 라이브러리를 만듭니다.
add_library(pokemonism-sdk-test INTERFACE)
target_link_libraries(pokemonism-sdk-test INTERFACE pokemonism-sdk GTest::gtest_main)

add_executable(pokemonism-sdk-test-synchronizer-guard                       src/pokemonism/sdk/synchronizer/guard.cc)
target_compile_options(pokemonism-sdk-test-synchronizer-guard   PRIVATE     -D__EXPORT_POKEMONISM_SDK_SYNCHRONIZER_GUARD)
# 이제 테스트 실행 파일은 pokemonism-sdk-test 라이브러리를 링크하기만 하면 됩니다.
target_link_libraries(pokemonism-sdk-test-synchronizer-guard PRIVATE pokemonism-sdk-test)
