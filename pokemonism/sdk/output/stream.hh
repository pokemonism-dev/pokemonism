/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_OUTPUT_STREAM_HH__
#define   __POKEMONISM_SDK_OUTPUT_STREAM_HH__

#include <pokemonism/sdk/stream.hh>
#include <pokemonism/sdk/output.hh>
#include <pokemonism/sdk/interface/output.hh>

namespace pokemonism::sdk {

    template <class descriptorable>
    class output::stream : public descriptorable {
    public:     typedef descriptorable::type type;
    protected:  pokemonism::sdk::stream::buffer * out;
    protected:  inline long write(void) override;
    protected:  inline long write(const unsigned char * storage, unsigned long n) override;
    protected:  inline virtual long write(pokemonism::sdk::stream * node);
    public:     inline void clear(void) override;
    public:     inline void clean(void) override;
    public:     inline void reset(void) override;
    protected:  inline virtual void onStreamOut(pokemonism::sdk::stream * node);
    protected:  inline explicit stream(type value);
    protected:  inline explicit stream(pokemonism::sdk::stream::buffer * out);
    protected:  inline stream(type value, pokemonism::sdk::stream::buffer * out);
    public:     inline stream(void);
    public:     inline ~stream(void) override;
    public:     stream(const pokemonism::sdk::output::stream<descriptorable> & o) = delete;
    public:     stream(pokemonism::sdk::output::stream<descriptorable> && o) noexcept = delete;
    public:     pokemonism::sdk::output::stream<descriptorable> & operator=(const pokemonism::sdk::output::stream<descriptorable> & o) = delete;
    public:     pokemonism::sdk::output::stream<descriptorable> & operator=(pokemonism::sdk::output::stream<descriptorable> && o) noexcept = delete;
    };

    template <class descriptorable>
    long output::stream<descriptorable>::write(void) {
        long total = 0;
        pokemonism::sdk::stream * node = nullptr;
        while ((node = out->untilGet(out->pageGet())) != nullptr) {
            const long n = write(node);

            if (n > 0) {
                total = total + n;

                if (node->lengthGet() == 0) {
                    out->del(node);
                    onStreamOut(node);
                    delete node;
                }

                continue;
            }

            if (n < 0) {
                return n;
            }

            break;
        }

        return total;
    }

    template <class descriptorable>
    inline long output::stream<descriptorable>::write(const unsigned char * storage, unsigned long n) {
        return descriptorable::write(storage, n);
    }

    template <class descriptorable>
    inline long output::stream<descriptorable>::write(pokemonism::sdk::stream * node) {
        pokemon_develop_check(node == nullptr || node->lengthGet() == 0, return declaration::zero);

        const long n = write(node->frontGet(), node->lengthGet());

        if (n > 0) node->pop(n);

        return n;
    }

    template <class descriptorable>
    inline void output::stream<descriptorable>::clear(void) {
        out->clear();
    }

    template <class descriptorable>
    inline void output::stream<descriptorable>::clean(void) {
        out->clean();
    }

    template <class descriptorable>
    inline void output::stream<descriptorable>::reset(void) {
        out->reset();
    }

    template<class descriptorable>
    inline void output::stream<descriptorable>::onStreamOut(pokemonism::sdk::stream * node) {

    }

    template<class descriptorable>
    inline output::stream<descriptorable>::stream(type value) : interface::output<descriptorable>(value), out(new pokemonism::sdk::stream::buffer()) {

    }

    template<class descriptorable>
    inline output::stream<descriptorable>::stream(pokemonism::sdk::stream::buffer * out) : out(out) {
        pokemon_develop_check(out == nullptr, return);
    }

    template<class descriptorable>
    inline output::stream<descriptorable>::stream(type value, pokemonism::sdk::stream::buffer * out) : interface::output<descriptorable>(value), out(out) {
        pokemon_develop_check(out == nullptr, return);
    }

    template<class descriptorable>
    inline output::stream<descriptorable>::stream() : out(new pokemonism::sdk::stream::buffer()) {

    }

    template<class descriptorable>
    inline output::stream<descriptorable>::~stream() {
        out = allocator::del(out);
    }


}

#endif // __POKEMONISM_SDK_OUTPUT_STREAM_HH__