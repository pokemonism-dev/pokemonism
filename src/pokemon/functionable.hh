/**
 * @file        pokemon/functionable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#ifndef   __POKEMONISM_POKEMON_FUNCTIONABLE__HH__
#define   __POKEMONISM_POKEMON_FUNCTIONABLE__HH__

#include <pokemonism.hh>

namespace pokemon {
    template <typename return_type, typename... argument_type_list>
    class functionable {
    public:     virtual return_type operator()(argument_type_list... args) const = 0;
    public:     functionable(void) {}
    public:     virtual ~functionable(void) {}
    public:     functionable(const functionable<return_type, argument_type_list...> & o) = delete;
    public:     functionable(functionable<return_type, argument_type_list...> && o) noexcept = delete;
    public:     functionable<return_type, argument_type_list...> & operator=(const functionable<return_type, argument_type_list...> & o) = delete;
    public:     functionable<return_type, argument_type_list...> & operator=(functionable<return_type, argument_type_list...> && o) noexcept = delete;
    };

    struct functionable_tag {};

    struct functionable_tag_const : public functionable_tag {};
}

#endif // __POKEMONISM_POKEMON_FUNCTIONABLE__HH__