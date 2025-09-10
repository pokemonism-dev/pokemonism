/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_STREAM_OUTPUT_HH__
#define   __POKEMONISM_SDK_STREAM_OUTPUT_HH__

#include <pokemonism/sdk/stream.hh>
#include <pokemonism/sdk/interface/output/stream.hh>

namespace pokemonism::sdk {

    template <class descriptorable>
    class stream::output : public pokemonism::sdk::interface::output::stream<descriptorable> {
    public:     typedef pokemonism::sdk::interface::output::stream<descriptorable>::type type;
    public:     pokemonism::sdk::stream::buffer out;
    protected:  long write(void) override;
    public:     inline explicit output(stream::output<descriptorable>::type value);
    public:     inline output(void);
    public:     inline ~output(void) override;
    public:     output(const stream::output<descriptorable> & o) = delete;
    public:     output(stream::output<descriptorable> && o) noexcept = delete;
    public:     stream::output<descriptorable> & operator=(const stream::output<descriptorable> & o) = delete;
    public:     stream::output<descriptorable> & operator=(stream::output<descriptorable> && o) noexcept = delete;
    };

    template <class descriptorable>
    long stream::output<descriptorable>::write(void) {
        pokemonism::sdk::stream * node = out.untilGet(out.pageGet());

        return node != nullptr ? write(*node) : declaration::success;
    }

    template <class descriptorable>
    inline stream::output<descriptorable>::output(stream::output<descriptorable>::type value) : pokemonism::sdk::interface::output::stream<descriptorable>(value) {

    }

    template <class descriptorable>
    inline stream::output<descriptorable>::output(void) {

    }

    template <class descriptorable>
    inline stream::output<descriptorable>::~output(void) {

    }

}

#endif // __POKEMONISM_SDK_STREAM_OUTPUT_HH__