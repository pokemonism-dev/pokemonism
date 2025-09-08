cmake_minimum_required(VERSION 3.28.3)

project(pokemonism LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(POKEMONISM_SDK_HEADER                   log.hh
                                            sync.hh
                                            event.hh
                                            event/link.hh
                                            event/queue.hh
                                            event/envelope.hh
                                            event/generator.hh
                                            event/subscription.hh
                                            event/internal/subscription.hh
                                            protocol.hh
                                            protocol/transmission.hh
                                            protocol/transmission/control.hh
                                            protocol/transmission/control/socket.hh
                                            command.hh
                                            command/event.hh
                                            command/event/link.hh
                                            command/event/envelope.hh
                                            command/event/generator.hh
                                            command/event/processor.hh
                                            command/event/subscription.hh
                                            command/event/internal/subscription.hh
                                            exception.hh
                                            generic/envelope.hh
                                            generic/command.hh
                                            generic/functional/command.hh
                                            templateable/engine.hh
                                            templateable/command.hh
                                            templateable/command/subscription.hh
                                            templateable/command/event/generator.hh
                                            lambdable/command.hh
                                            lambdable/pure/command.hh
                                            allocator.hh
                                            subscription.hh
                                            callable.hh
                                            runnable.hh
                                            cloneable.hh
                                            envelopeable.hh
                                            callbackable.hh
                                            primitivable.hh
                                            functionable.hh
                                            synchronizable.hh
                                            linked/list.hh
                                            engine.hh
                                            functional/command.hh)

set(POKEMONISM_SDK_SOURCE                   log.cc
                                            sync.cc
                                            event.cc
                                            event/link.cc
                                            event/queue.cc
                                            event/envelope.cc
                                            event/generator.cc
                                            event/subscription.cc
                                            event/internal/subscription.cc
                                            protocol.cc
                                            protocol/transmission.cc
                                            protocol/transmission/control.cc
                                            protocol/transmission/control/socket.cc
                                            command.cc
                                            command/event.cc
                                            command/event/link.cc
                                            command/event/envelope.cc
                                            command/event/generator.cc
                                            command/event/processor.cc
                                            command/event/subscription.cc
                                            command/event/internal/subscription.cc
                                            exception.cc
                                            generic/envelope.cc
                                            generic/command.cc
                                            generic/functional/command.cc
                                            templateable/engine.cc
                                            templateable/command.cc
                                            templateable/command/subscription.cc
                                            templateable/command/event/generator.cc
                                            lambdable/command.cc
                                            lambdable/pure/command.cc
                                            allocator.cc
                                            subscription.cc
                                            callable.cc
                                            runnable.cc
                                            cloneable.cc
                                            envelopeable.cc
                                            callbackable.cc
                                            primitivable.cc
                                            functionable.cc
                                            synchronizable.cc
                                            linked/list.cc
                                            engine.cc
                                            functional/command.cc)

add_library(pokemonism-sdk                  ${POKEMONISM_SDK_HEADER}
                                            ${POKEMONISM_SDK_SOURCE})
