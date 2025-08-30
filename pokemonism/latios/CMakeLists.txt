cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

set(LATIOS_ROOT_HEADER              ../latios.hh)

set(LATIOS_ROOT_SOURCE              ../latios.cc)

set(LATIOS_HEADER                   engine.hh
                                    event.hh
                                    command.hh
                                    process.hh
                                    descriptor.hh
                                    socket.hh)

set(LATIOS_SOURCE                   engine.cc
                                    event.cc
                                    command.cc
                                    process.cc
                                    descriptor.cc
                                    socket.cc)

set(LATIOS_EXTERNAL_HEADER          external/event.hh
                                    external/engine.hh
                                    external/message.hh
                                    external/subscription.hh)

set(LATIOS_EXTERNAL_SOURCE          external/event.cc
                                    external/engine.cc
                                    external/message.cc
                                    external/subscription.cc)

set(LATIOS_GENERAL_HEADER           general/node.hh
                                    general/event.hh
                                    general/queue.hh
                                    general/engine.hh
                                    general/processor.hh
                                    general/generator.hh
                                    general/subscription.hh)

set(LATIOS_GENERAL_SOURCE           general/node.cc
                                    general/event.cc
                                    general/queue.cc
                                    general/engine.cc
                                    general/processor.cc
                                    general/generator.cc
                                    general/subscription.cc)

set(LATIOS_PACKAGE_HEADER           package/pack.hh
                                    package/pack/command.hh
                                    package/processor.hh
                                    package/generator.hh
                                    package/eventable.hh
                                    package/eventable/command.hh
                                    package/observable.hh)

set(LATIOS_PACKAGE_SOURCE           package/pack.cc
                                    package/pack/command.cc
                                    package/processor.cc
                                    package/generator.cc
                                    package/eventable.cc
                                    package/eventable/command.cc
                                    package/observable.cc)

set(LATIOS_INTERNAL_HEADER          internal/node.hh
                                    internal/event.hh
                                    internal/pack.hh
                                    internal/subscription.hh)

set(LATIOS_INTERNAL_SOURCE          internal/node.cc
                                    internal/event.cc
                                    internal/pack.cc
                                    internal/subscription.cc)

set(LATIOS_INTERNAL_COMMAND_HEADER  internal/command/node.hh
                                    internal/command/event.hh
                                    internal/command/generator.hh
                                    internal/command/subscription.hh
                                    internal/process/event.hh)

set(LATIOS_INTERNAL_COMMAND_SOURCE  internal/command/node.cc
                                    internal/command/event.cc
                                    internal/command/generator.cc
                                    internal/command/subscription.cc
                                    internal/process/event.cc)

set(LATIOS_INTERNAL_DESCRIPTOR_HEADER   internal/descriptor/event.hh
                                        internal/socket/event.hh)

set(LATIOS_INTERNAL_DESCRIPTOR_SOURCE   internal/descriptor/event.cc
                                        internal/socket/event.cc)

add_library(latios-dev              ${LATIOS_ROOT_HEADER}
                                    ${LATIOS_ROOT_SOURCE}
                                    ${LATIOS_HEADER}
                                    ${LATIOS_SOURCE}
                                    ${LATIOS_EXTERNAL_HEADER}
                                    ${LATIOS_EXTERNAL_SOURCE}
                                    ${LATIOS_GENERAL_HEADER}
                                    ${LATIOS_GENERAL_SOURCE}
                                    ${LATIOS_PACKAGE_HEADER}
                                    ${LATIOS_PACKAGE_SOURCE}
                                    ${LATIOS_INTERNAL_HEADER}
                                    ${LATIOS_INTERNAL_SOURCE}
                                    ${LATIOS_INTERNAL_COMMAND_HEADER}
                                    ${LATIOS_INTERNAL_COMMAND_SOURCE}
                                    ${LATIOS_INTERNAL_DESCRIPTOR_HEADER}
                                    ${LATIOS_INTERNAL_DESCRIPTOR_SOURCE})

target_link_libraries(latios-dev    pokemon-dev)
