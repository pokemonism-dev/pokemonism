/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_SERVER_HH__
#define   __POKEMONISM_SDK_INTERFACE_SERVER_HH__

#include <pokemonism/sdk/interface/communicator.hh>

namespace pokemonism::sdk::interface {

    class session;

    class server : public communicator {
    protected:  virtual session * gen(void) = 0;
    public:     server(void) {}
    public:     ~server(void) override {}
    public:     server(const server & o) = delete;
    public:     server(server && o) noexcept = delete;
    public:     server & operator=(const server & o) = delete;
    public:     server & operator=(server && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_SERVER_HH__
