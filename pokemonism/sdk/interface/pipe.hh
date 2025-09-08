/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_PIPE_HH__
#define   __POKEMONISM_SDK_INTERFACE_PIPE_HH__

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk::interface {

    class pipe : public interface::descriptor {
    public:     pipe(void) {}
    public:     ~pipe(void) override {}
    public:     pipe(const interface::pipe & o) = delete;
    public:     pipe(interface::pipe && o) noexcept = delete;
    public:     interface::pipe & operator=(const interface::pipe & o) = delete;
    public:     interface::pipe & operator=(interface::pipe && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_PIPE_HH__