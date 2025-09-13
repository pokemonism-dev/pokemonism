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
    public:     Container(const Container & o) = delete;
    public:     Container(Container && o) noexcept = delete;
    public:     Container & operator=(const Container & o) = delete;
    public:     Container & operator=(Container && o) noexcept = delete;
    };

    inline Container::Container(void) {

    }

    inline Container::~Container(void) {

    }

}

#endif // __POKEMONISM_COLLECTION_CONTAINER_HH__