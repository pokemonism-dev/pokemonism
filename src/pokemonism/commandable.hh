/**
 * @file        pokemonism/commandable.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#ifndef   __POKEMONISM_COMMANDABLE__HH__
#define   __POKEMONISM_COMMANDABLE__HH__

#include <pokemonism/primitivable.hh>

namespace pokemonism {
    class commandable {
    public:     virtual primitivable::object * operator()(void) = 0;
    public:     inline commandable(void) {}
    public:     inline virtual ~commandable(void) {}
    public:     commandable(const commandable & o) = delete;
    public:     commandable(commandable && o) noexcept = delete;
    public:     commandable & operator=(const commandable & o) = delete;
    public:     commandable & operator=(commandable && o) noexcept = delete;
    };
}

#endif // __POKEMONISM_COMMANDABLE__HH__