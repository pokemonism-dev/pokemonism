/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_PROTOCOL_ECHO_HH__
#define   __POKEMONISM_SDK_PROTOCOL_ECHO_HH__

#include <pokemonism/sdk/protocol.hh>

namespace pokemonism::sdk::protocols {

    class echo : public pokemonism::sdk::protocol {
    public:     static echo & protocol;
    protected:  echo(void);
    public:     ~echo(void) override;
    public:     echo(const echo & o) = delete;
    public:     echo(echo && o) noexcept = delete;
    public:     echo & operator=(const echo & o) = delete;
    public:     echo & operator=(echo && o) noexcept = delete;
    };

    // echo::protocol::in(...)
    // echo::protocol::out(...)

}

#endif // __POKEMONISM_SDK_PROTOCOL_ECHO_HH__
