cmake_minimum_required(VERSION 3.28.3)

project(pokemonism CXX)
set(CMAKE_CXX_STANDARD 23)

include_directories(include pokemonism)

set(POKEMONISM_HEADER               include/pokemonism.hh)

set(POKEMONISM_SOURCE               pokemonism.cc)

add_subdirectory(pokemonism/pokemon/pidgey)
add_subdirectory(pokemonism/pokemon/meowth)
add_subdirectory(pokemonism/pokemon)
add_subdirectory(pokemonism/pokemon/wooper)
add_subdirectory(pokemonism/pokemon/sprigatito)
add_subdirectory(pokemonism/pokemon/sprigatito/floragato)
add_subdirectory(pokemonism/pokemon/sprigatito/floragato/meowscarada)
add_subdirectory(pokemonism/pokemon/mareep)
add_subdirectory(pokemonism/pokemon/squirtle)
add_subdirectory(pokemonism/pokemon/latios)

add_subdirectory(pokemonism/pokemon/meowth/persian)



#add_subdirectory(src/pokemon)
#add_subdirectory(src/pokemon/sprigatito)
#add_subdirectory(src/pokemon/meowth/persian)

set(POKEMONISM_IMPLEMENT_SOURCE

)

add_executable(pokemonism-cli       ${POKEMONISM_HEADER}
                                    ${POKEMONISM_SOURCE}
                                    ${POKEMONISM_IMPLEMENT_SOURCE})