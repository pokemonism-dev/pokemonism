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

    class output::stream : public interface::output {
    // protected:  pokemonism::sdk::stream
    public:     stream(void);
    public:     ~stream(void) override;
    public:     stream(const pokemonism::sdk::output::stream & o) = delete;
    public:     stream(pokemonism::sdk::output::stream && o) noexcept = delete;
    public:     pokemonism::sdk::output::stream & operator=(const pokemonism::sdk::output::stream & o) = delete;
    public:     pokemonism::sdk::output::stream & operator=(pokemonism::sdk::output::stream && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_OUTPUT_STREAM_HH__