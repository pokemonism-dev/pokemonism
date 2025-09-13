/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_WINDOWABLE_HH__
#define   __POKEMONISM_WINDOW_WINDOWABLE_HH__

#include <pokemonism.hh>

namespace pokemonism::window {

    class Windowable {
    public:     inline Windowable(void);
    public:     inline virtual ~Windowable(void);
    public:     Windowable(const Windowable & o) = delete;
    public:     Windowable(Windowable && o) noexcept = delete;
    public:     Windowable & operator=(const Windowable & o) = delete;
    public:     Windowable & operator=(Windowable && o) noexcept = delete;
    };

    inline Windowable::Windowable(void) {

    }

    inline Windowable::~Windowable(void) {

    }


}

#endif // __POKEMONISM_WINDOW_WINDOWABLE_HH__