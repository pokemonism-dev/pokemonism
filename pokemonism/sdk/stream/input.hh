/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_STREAM_INPUT_HH__
#define   __POKEMONISM_SDK_STREAM_INPUT_HH__

#include <pokemonism/sdk/stream.hh>
#include <pokemonism/sdk/interface/input/stream.hh>

namespace pokemonism::sdk {

    template <class descriptorable>
    class stream::input : public pokemonism::sdk::interface::input::stream<descriptorable> {
    public:     typedef pokemonism::sdk::interface::input::stream<descriptorable>::type type;
    public:     pokemonism::sdk::stream::buffer in;
    protected:  long read(void) override;
    public:     inline explicit input(stream::input<descriptorable>::type value);
    public:     inline input(void);
    public:     inline ~input(void) override;
    public:     input(const stream::input<descriptorable> & o) = delete;
    public:     input(stream::input<descriptorable> && o) noexcept = delete;
    public:     stream::input<descriptorable> & operator=(const stream::input<descriptorable> & o) = delete;
    public:     stream::input<descriptorable> & operator=(stream::input<descriptorable> && o) noexcept = delete;
    };

    template <class descriptorable>
    long stream::input<descriptorable>::read(void) {
        pokemonism::sdk::stream * node = in.streamGet(in.pageGet());

        pokemon_develop_check(node == nullptr, return declaration::success);

        return read(*node);
    }

    template <class descriptorable>
    inline stream::input<descriptorable>::input(stream::input<descriptorable>::type value) : pokemonism::sdk::interface::input::stream<descriptorable>(value) {

    }

    template <class descriptorable>
    inline stream::input<descriptorable>::input(void) {

    }

    template <class descriptorable>
    inline stream::input<descriptorable>::~input(void) {

    }

}

#endif // __POKEMONISM_SDK_STREAM_INPUT_HH__