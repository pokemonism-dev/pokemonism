/**
 * @file        pokemon/latios/internal.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL__HH__

namespace pokemon { namespace latios { namespace internal {

    template <typename first_type, typename second_type>
    inline first_type * eventRel(first_type * x, second_type * y) {
        x->origin = nullptr;
        y->origin = nullptr;
        delete y;
        return x;
    }

//     template <typename event, typename node>
// inline event * eventRel(event * e, node * n) {
//         return nullptr;
//     }

    // template <typename subscription, typename event> class link;
    //
    //
    // class event;
    // class object;
    // class engine;
    // template <typename object, typename subscription> class generator;
    // template <typename object, typename event, typename link> class subscription;

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL__HH__
