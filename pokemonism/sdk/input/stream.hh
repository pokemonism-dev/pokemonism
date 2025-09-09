/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INPUT_STREAM_HH__
#define   __POKEMONISM_SDK_INPUT_STREAM_HH__

#include <pokemonism/sdk/input.hh>
#include <pokemonism/sdk/stream.hh>
#include <pokemonism/sdk/interface/input.hh>

namespace pokemonism::sdk {

    template <class outputable>
    class input::stream : public outputable {
    public:     typedef outputable::type type;
    protected:  pokemonism::sdk::stream::buffer * in;
    protected:  inline long read(void) override;
    protected:  inline long read(unsigned char * storage, unsigned long capacity) override;
    protected:  inline virtual long read(pokemonism::sdk::stream * node);
    protected:  inline void clear(void) override;
    protected:  inline void clean(void) override;
    protected:  inline void reset(void) override;
    protected:  inline virtual void onStreamIn(pokemonism::sdk::stream * node);
    protected:  inline explicit stream(type value);
    protected:  inline explicit stream(pokemonism::sdk::stream::buffer * in);
    protected:  inline stream(type value, pokemonism::sdk::stream::buffer * in);
    public:     inline stream(void);
    public:     inline ~stream(void) override;
    public:     stream(const pokemonism::sdk::input::stream<outputable> & o) = delete;
    public:     stream(pokemonism::sdk::input::stream<outputable> && o) noexcept = delete;
    public:     pokemonism::sdk::input::stream<outputable> & operator=(const pokemonism::sdk::input::stream<outputable> & o) = delete;
    public:     pokemonism::sdk::input::stream<outputable> & operator=(pokemonism::sdk::input::stream<outputable> && o) noexcept = delete;
    };

    template <class outputable>
    long input::stream<outputable>::read(void) {
        long total = 0;
        pokemonism::sdk::stream * node = nullptr;
        while ((node = in->streamGet(in->pageGet())) != nullptr) {
            const long n = read(node);

            if (n > 0) {
                total = total + n;

                onStreamIn(node);
                continue;
            }

            if (n < 0) {
                return n;
            }

            break;
        }

        return total;
    }

    template <class outputable>
    inline long input::stream<outputable>::read(unsigned char * storage, unsigned long capacity) {
        return outputable::read(storage, capacity);
    }

    template <class outputable>
    inline long input::stream<outputable>::read(pokemonism::sdk::stream * node) {
        pokemon_develop_check(node == nullptr || node->remainGet() == 0, return declaration::zero);

        const long n = read(node->storage + node->size, node->remainGet());

        if (n > 0) node->size = node->size + n;

        return n;
    }

    template <class outputable>
    inline void input::stream<outputable>::clear(void) {
        in->clear();
        outputable::clear();
    }

    template <class outputable>
    inline void input::stream<outputable>::clean(void) {
        in->clean();
        outputable::clean();
    }

    template <class outputable>
    inline void input::stream<outputable>::reset(void) {
        in->reset();
        outputable::reset();
    }

    template <class outputable>
    inline void input::stream<outputable>::onStreamIn(pokemonism::sdk::stream * node) {

    }

    template <class outputable>
    inline input::stream<outputable>::stream(type value) : outputable(value), in(new pokemonism::sdk::stream::buffer()) {

    }

    template <class outputable>
    inline input::stream<outputable>::stream(pokemonism::sdk::stream::buffer * in) : in(in) {
        pokemon_develop_check(in == nullptr, return);
    }

    template <class outputable>
    inline input::stream<outputable>::stream(type value, pokemonism::sdk::stream::buffer * in) : outputable(value), in(in) {
        pokemon_develop_check(in == nullptr, return);
    }

    template <class outputable>
    inline input::stream<outputable>::stream(void) : in(new pokemonism::sdk::stream::buffer()) {

    }

    template <class outputable>
    inline input::stream<outputable>::~stream(void) {
        in = allocator::del(in);
    }

}

#endif // __POKEMONISM_SDK_INPUT_STREAM_HH__