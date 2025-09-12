/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_PHYSICS_DIMENSIONAL_HH__
#define   __POKEMONISM_PHYSICS_DIMENSIONAL_HH__

#include <pokemonism/physics.hh>

namespace pokemonism::physics {

    struct DimensionTag : public physics::Tag {};

    namespace dimensional {
        struct one : public DimensionTag {};
        struct two : public DimensionTag {};
        struct three : public DimensionTag {};
    }

}

#endif // __POKEMONISM_PHYSICS_DIMENSIONAL_HH__