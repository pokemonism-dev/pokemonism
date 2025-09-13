/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_COLLECTION_CONTAINER_HH__
#define   __POKEMONISM_COLLECTION_CONTAINER_HH__

#include <pokemonism/containable.hh>

namespace pokemonism::collection {

    class Container : public Containable {
    public:     inline Container(void);
    public:     inline ~Container(void) override;
    public:     inline Container(const Container & o);
    public:     inline Container(Container && o) noexcept;
    public:     inline Container & operator=(const Container & o);
    public:     inline Container & operator=(Container && o) noexcept;
    };

    inline Container::Container(void) {

    }

    inline Container::~Container(void) {

    }

    inline Container::Container(const Container & o) {

    }

    inline Container::Container(Container && o) noexcept {

    }

    inline Container & Container::operator=(const Container & o) {
        return *this;
    }

    inline Container & Container::operator=(Container && o) noexcept {
        return *this;
    }

}

#endif // __POKEMONISM_COLLECTION_CONTAINER_HH__