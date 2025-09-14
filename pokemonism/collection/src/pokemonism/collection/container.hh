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

    class container : public containable {
    public:     inline container(void);
    public:     inline ~container(void) override;
    public:     inline container(const container & o);
    public:     inline container(container && o) noexcept;
    public:     inline container & operator=(const container & o);
    public:     inline container & operator=(container && o) noexcept;
    };

    inline container::container(void) {

    }

    inline container::~container(void) {

    }

    inline container::container(const container & o) {

    }

    inline container::container(container && o) noexcept {

    }

    inline container & container::operator=(const container & o) {
        return *this;
    }

    inline container & container::operator=(container && o) noexcept {
        return *this;
    }

}

#endif // __POKEMONISM_COLLECTION_CONTAINER_HH__