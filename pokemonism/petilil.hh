/**
 * @file            pokemonism/petilil.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_PETILIL_HH__
#define   __POKEMONISM_PETILIL_HH__

#include <pokemonism.hh>

namespace pokemonism {
    /**
     *
     * petilil::evolve
     *
     * petilil::evolve
     * petilil * o = petilil::evolve<stone::sun>();
     * o->run()
     * stone::sun
     *
     * @tparam evolvable
     */
    class petilil {
    public:     template <typename item = void> static petilil * evolve(void);
    public:     virtual int run(void);
    public:     petilil(void) {}
    public:     virtual ~petilil(void) {}
    public:     petilil(const petilil & o) = delete;
    public:     petilil(petilil && o) noexcept = delete;
    public:     petilil & operator=(const petilil & o) = delete;
    public:     petilil & operator=(petilil && o) noexcept = delete;
    };

    template <itemname item>
    petilil * petilil::evolve(void) {
        return nullptr;
    }
}

#endif // __POKEMONISM_PETILIL_HH__