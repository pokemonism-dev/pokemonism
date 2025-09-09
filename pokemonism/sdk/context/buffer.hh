/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 09, 2025
 */

#ifndef   __POKEMONISM_SDK_CONTEXT_BUFFER_HH__
#define   __POKEMONISM_SDK_CONTEXT_BUFFER_HH__

#include <pokemonism/sdk/context.hh>

namespace pokemonism::sdk {

    class context::buffer : public stream::buffer {
    public:     inline context * gen(void) override;
    public:     inline explicit buffer(unsigned long page);
    public:     inline buffer(void);
    public:     inline ~buffer(void) override;
    public:     buffer(const context::buffer & o) = delete;
    public:     buffer(context::buffer && o) noexcept = delete;
    public:     context::buffer & operator=(const context::buffer & o) = delete;
    public:     context::buffer & operator=(context::buffer && o) noexcept = delete;
    };

    context * context::buffer::gen(void) {
        return new context(this);
    }

    context::buffer::buffer(unsigned long page) : stream::buffer(page) {

    }

    context::buffer::buffer(void) {

    }

    context::buffer::~buffer(void) {

    }

}

#endif // __POKEMONISM_SDK_CONTEXT_BUFFER_HH__