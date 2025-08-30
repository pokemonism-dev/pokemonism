/**
 * @file        pokemon/function.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_FUNCTION__HH__
#define   __POKEMONISM_POKEMON_FUNCTION__HH__

namespace pokemon {
    template <typename return_type, typename... argument_type_list>
    class function {
    public:     virtual return_type operator()(argument_type_list...) const = 0;
    public:     function(void) {}
    public:     virtual ~function(void) {}
    public:     function(const function<return_type, argument_type_list...> & o) = delete;
    public:     function(function<return_type, argument_type_list...> && o) noexcept = delete;
    public:     function<return_type, argument_type_list...> & operator=(const function<return_type, argument_type_list...> & o) = delete;
    public:     function<return_type, argument_type_list...> & operator=(function<return_type, argument_type_list...> && o) noexcept = delete;
    };
}

#endif // __POKEMONISM_POKEMON_FUNCTION__HH__