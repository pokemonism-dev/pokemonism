/**
 * @file        pokemonism/sprigatito/tuple/pair.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_SPRIGATITO_TUPLE_PAIR__HH__
#define   __POKEMONISM_SPRIGATITO_TUPLE_PAIR__HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace sprigatito {
        namespace tuple {
            // template <class first_type, class second_type>
            // struct pair {
            // public:     struct type {
            //             public:     typedef first_type      first;
            //             public:     typedef second_type     second;
            //             };
            // public:     typedef pair<typename type::first, typename type::second>       collection;
            // public:     type::first first;
            // public:     type::second second;
            // public:     pair(const type::first & first, const type::second & second) : first(first), second(second) {}
            // public:     pair(void) : first(), second() {}
            // public:     ~pair(void) {}
            // public:     pair(const pair<first_type, second_type> & o) : first(o.first), second(o.second) {}
            // public:     pair(pair<first_type, second_type> & o) noexcept : first(std::move(o.first)), second(std::move(o.second)) {}
            // public:     pair<first_type, second_type> & operator=(const pair<first_type, second_type> & o) {
            //                 if (pointof(o) != this) {
            //                     first = o.first;
            //                     second = o.second;
            //                 }
            //                 return *this;
            //             }
            // public:     pair<first_type, second_type> & operator=(pair<first_type, second_type> & o) noexcept {
            //                 if (pointof(o) != this) {
            //                     first = std::move(o.first);
            //                     second = std::move(o.second);
            //                 }
            //                 return *this;
            //             }
            // };
        }
    }
}

#endif // __POKEMONISM_SPRIGATITO_TUPLE_PAIR__HH__