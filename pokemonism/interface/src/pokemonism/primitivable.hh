/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_PRIMITIVABLE_HH__
#define   __POKEMONISM_PRIMITIVABLE_HH__

namespace pokemonism {

    class primitivable {
    public:     inline primitivable(void);
    public:     inline virtual ~primitivable(void);
    public:     inline primitivable(const primitivable & o);
    public:     inline primitivable(primitivable && o) noexcept;
    public:     inline primitivable & operator=(const primitivable & o);
    public:     inline primitivable & operator=(primitivable && o) noexcept;
    };

    inline primitivable::primitivable(void) {

    }

    inline primitivable::~primitivable(void) {

    }

    inline primitivable::primitivable(const primitivable & o) {

    }

    inline primitivable::primitivable(primitivable && o) noexcept {

    }

    inline primitivable & primitivable::operator=(const primitivable & o) {
        return *this;
    }

    inline primitivable & primitivable::operator=(primitivable && o) noexcept {
        return *this;
    }

}

#endif // __POKEMONISM_PRIMITIVABLE_HH__