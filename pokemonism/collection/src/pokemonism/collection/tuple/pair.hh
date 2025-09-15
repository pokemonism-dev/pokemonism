/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 15, 2025
 */

#ifndef   __POKEMONISM_COLLECTION_TUPLE_PAIR_HH__
#define   __POKEMONISM_COLLECTION_TUPLE_PAIR_HH__

#include <pokemonism.hh>

namespace pokemonism::collection::tuple {

    template <typename one, typename two>
    class pair {
    public:     one first;
    public:     two second;
    public:     inline pair(void);
    public:     inline ~pair(void);
    public:     inline pair(const pokemonism::collection::tuple::pair<one, two> & o);
    public:     inline pair(pokemonism::collection::tuple::pair<one, two> && o) noexcept;
    public:     inline pokemonism::collection::tuple::pair<one, two> & operator=(const pokemonism::collection::tuple::pair<one, two> & o);
    public:     inline pokemonism::collection::tuple::pair<one, two> & operator=(pokemonism::collection::tuple::pair<one, two> && o) noexcept;
    };

    template <typename one, typename two>
    inline pair<one, two>::pair(void) {

    }

    template <typename one, typename two>
    inline pair<one, two>::~pair(void) {

    }

    template <typename one, typename two>
    inline pair<one, two>::pair(const pokemonism::collection::tuple::pair<one, two> & o) : first(o.first), second(o.second) {

    }

    template <typename one, typename two>
    inline pair<one, two>::pair(pokemonism::collection::tuple::pair<one, two> && o) noexcept : first(std::move(o.first)), second(std::move(o.second)) {

    }

    template <typename one, typename two>
    inline pokemonism::collection::tuple::pair<one, two> & pair<one, two>::operator=(const pokemonism::collection::tuple::pair<one, two> & o) {
        if (pointof(o) != this) {
            first = o.first;
            second = o.second;
        }

        return o;
    }

    template <typename one, typename two>
    inline pokemonism::collection::tuple::pair<one, two> & pair<one, two>::operator=(pokemonism::collection::tuple::pair<one, two> && o) noexcept {
        if (pointof(o) != this) {
            first = std::move(o.first);
            second = std::move(o.second);
        }

        return o;
    }

}

#endif // __POKEMONISM_COLLECTION_TUPLE_PAIR_HH__