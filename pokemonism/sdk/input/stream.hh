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

    class input::stream : public interface::input {
    // public:     pokemonism::sdk::stream storage;
    public:     void clear(void) override;
    public:     void clean(void) override;
    public:     void reset(void) override;
    public:     stream(void);
    public:     ~stream(void) override;
    public:     stream(const pokemonism::sdk::input::stream & o) = delete;
    public:     stream(pokemonism::sdk::input::stream && o) noexcept = delete;
    public:     pokemonism::sdk::input::stream & operator=(const pokemonism::sdk::input::stream & o) = delete;
    public:     pokemonism::sdk::input::stream & operator=(pokemonism::sdk::input::stream && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INPUT_STREAM_HH__