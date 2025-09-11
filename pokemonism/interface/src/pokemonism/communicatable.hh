/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_COMMUNICATABLE_HH__
#define   __POKEMONISM_COMMUNICATABLE_HH__

#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class Super = Virtualable>
    class Communicatable : public Super {
    public:     virtual int open(void) = 0;
    public:     virtual long read(void) = 0;
    public:     virtual long write(void) = 0;
    public:     virtual int close(void) = 0;
    public:     inline Communicatable(void);
    public:     inline ~Communicatable(void) override;
    public:     Communicatable(const Communicatable<Super> & o) = delete;
    public:     Communicatable(Communicatable<Super> && o) noexcept = delete;
    public:     Communicatable<Super> & operator=(const Communicatable<Super> & o) = delete;
    public:     Communicatable<Super> & operator=(Communicatable<Super> && o) noexcept = delete;
    };

    template <class Super>
    inline Communicatable<Super>::Communicatable(void) {

    }

    template <class Super>
    inline Communicatable<Super>::~Communicatable(void) {

    }

}

#endif // __POKEMONISM_COMMUNICATABLE_HH__