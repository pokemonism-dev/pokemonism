/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_OUTPUT_STREAM_HH__
#define   __POKEMONISM_SDK_INTERFACE_OUTPUT_STREAM_HH__

#include <pokemonism/sdk/stream.hh>

namespace pokemonism::sdk::interface::output {

    template <class descriptorable>
    class stream : public descriptorable {
    public:     typedef descriptorable::type type;
    protected:  long write(void) override = 0;
    protected:  inline long write(const unsigned char * storage, unsigned long n) override;
    protected:  inline virtual long write(pokemonism::sdk::stream & node);
    protected:  inline virtual void onStreamOut(pokemonism::sdk::stream & node, long n);
    public:     inline explicit stream(output::stream<descriptorable>::type value);
    public:     inline stream(void);
    public:     inline ~stream(void) override;
    public:     stream(const output::stream<descriptorable> & o) = delete;
    public:     stream(output::stream<descriptorable> && o) noexcept = delete;
    public:     output::stream<descriptorable> & operator=(const output::stream<descriptorable> & o) = delete;
    public:     output::stream<descriptorable> & operator=(output::stream<descriptorable> && o) noexcept = delete;
    };

    template <class descriptorable>
    long stream<descriptorable>::write(const unsigned char * storage, unsigned long n) {
        return descriptorable::write(storage, n);
    }

    template <class descriptorable>
    long stream<descriptorable>::write(pokemonism::sdk::stream & node) {
        const long n = write(node.frontGet(), node.lengthGet());

        onStreamOut(node, n);

        if (n > 0) node.pop(n);

        return n;
    }

    template <class descriptorable>
    inline void stream<descriptorable>::onStreamOut(pokemonism::sdk::stream & node, long n) {

    }

    template <class descriptorable>
    inline stream<descriptorable>::stream(stream<descriptorable>::type value) : descriptorable(value) {

    }

    template <class descriptorable>
    inline stream<descriptorable>::stream(void) {

    }

    template <class descriptorable>
    inline stream<descriptorable>::~stream(void) {

    }

}

#endif // __POKEMONISM_SDK_INTERFACE_OUTPUT_STREAM_HH__