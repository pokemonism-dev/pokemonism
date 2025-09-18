cmake_minimum_required(VERSION 3.28.3)

project(pokemonism-vulkan LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(ENVIRONMENT_VULKAN_SDK_PATH $ENV{VULKAN_SDK_PATH})

if (NOT ENVIRONMENT_VULKAN_SDK_PATH)
    message(FATAL_ERROR "VULKAN_SDK_PATH environment variable not set. Please install Vulkan SDK.")
else()
    message(STATUS "VULKAN_SDK_PATH is set to: ${ENVIRONMENT_VULKAN_SDK_PATH}")
endif()

set(POKEMONISM_VULKAN_SOURCE                                                        src/pokemonism/vulkan.cc
                                                                                    src/pokemonism/vulkan/physical/device.cc
                                                                                    src/pokemonism/vulkan/process.cc
                                                                                    src/pokemonism/vulkan/window.cc
                                                                                    src/pokemonism/vulkan/device.cc
                                                                                    src/pokemonism/vulkan/surface.cc
                                                                                    src/pokemonism/vulkan/queue.cc
                                                                                    src/pokemonism/vulkan/window/application.cc
                                                                                    src/pokemonism/vulkan/platform/window.cc
                                                                                    src/pokemonism/vulkan/platform/window/application.cc)

set(POKEMONISM_VULKAN_HEADER                                                        src/pokemonism/vulkan.hh
                                                                                    src/pokemonism/vulkan/physical/device.hh
                                                                                    src/pokemonism/vulkan/process.hh
                                                                                    src/pokemonism/vulkan/window.hh
                                                                                    src/pokemonism/vulkan/device.hh
                                                                                    src/pokemonism/vulkan/surface.hh
                                                                                    src/pokemonism/vulkan/queue.hh
                                                                                    src/pokemonism/vulkan/window/application.hh
                                                                                    src/pokemonism/vulkan/platform/window.hh
                                                                                    src/pokemonism/vulkan/platform/window/application.hh)

add_library(pokemonism-vulkan-dev                                                   ${POKEMONISM_VULKAN_SOURCE}
                                                                                    ${POKEMONISM_VULKAN_HEADER})

set(POKEMONISM_VULKAN_COCOA_SOURCE                                                  src/pokemonism/vulkan/platform/cocoa/window.mm
                                                                                    src/pokemonism/vulkan/platform/cocoa/application.mm
                                                                                    src/pokemonism/vulkan/platform/cocoa/surface.mm
                                                                                    src/pokemonism/vulkan/platform/cocoa/metal.mm
                                                                                    src/pokemonism/vulkan/platform/cocoa/metal/surface.mm
                                                                                    src/pokemonism/vulkan/platform/cocoa/metal/process.mm)

set(POKEMONISM_VULKAN_COCOA_HEADER                                                  src/pokemonism/vulkan/platform/cocoa/window.hh
                                                                                    src/pokemonism/vulkan/platform/cocoa/application.hh
                                                                                    src/pokemonism/vulkan/platform/cocoa/surface.hh
                                                                                    src/pokemonism/vulkan/platform/cocoa/metal.hh
                                                                                    src/pokemonism/vulkan/platform/cocoa/metal/surface.hh
                                                                                    src/pokemonism/vulkan/platform/cocoa/metal/process.hh)

target_sources(pokemonism-vulkan-dev                                    PRIVATE     ${POKEMONISM_VULKAN_COCOA_SOURCE}
                                                                                    ${POKEMONISM_VULKAN_COCOA_HEADER})
target_link_options(pokemonism-vulkan-dev                               PRIVATE     -Wl, -rpath "${ENVIRONMENT_VULKAN_SDK_PATH}/macOS/lib")
target_link_directories(pokemonism-vulkan-dev                           PRIVATE     "${ENVIRONMENT_VULKAN_SDK_PATH}/macOS/lib")
target_link_libraries(pokemonism-vulkan-dev                             PRIVATE     "-framework Cocoa"
                                                                                    "-framework IOKit"
                                                                                    "-framework QuartzCore"
                                                                                    "-framework CoreFoundation"
                                                                                    pokemonism-window-dev
                                                                                    pokemonism-sdk
                                                                                    pokemonism-interface-dev
                                                                                    vulkan)
target_include_directories(pokemonism-vulkan-dev                        PRIVATE     "${ENVIRONMENT_VULKAN_SDK_PATH}/macOS/include")


add_executable(pokemonism-vulkan-window-application-run                             test/pokemonism/vulkan/window/application.cc)
target_link_options(pokemonism-vulkan-window-application-run            PRIVATE     -Wl, -rpath "${ENVIRONMENT_VULKAN_SDK_PATH}/macOS/lib")
target_link_directories(pokemonism-vulkan-window-application-run        PRIVATE     "${ENVIRONMENT_VULKAN_SDK_PATH}/macOS/lib")
target_link_libraries(pokemonism-vulkan-window-application-run          PRIVATE     "-framework Cocoa"
                                                                                    "-framework IOKit"
                                                                                    "-framework QuartzCore"
                                                                                    "-framework CoreFoundation"
                                                                                    pokemonism-vulkan-dev
                                                                                    pokemonism-window-dev
                                                                                    pokemonism-sdk
                                                                                    pokemonism-interface-dev
                                                                                    vulkan)
target_include_directories(pokemonism-vulkan-window-application-run     PRIVATE     "${ENVIRONMENT_VULKAN_SDK_PATH}/macOS/include")

