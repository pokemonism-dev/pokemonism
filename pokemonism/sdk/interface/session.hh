/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_SESSION_HH__
#define   __POKEMONISM_SDK_INTERFACE_SESSION_HH__

#include <pokemonism/sdk/linked/list.hh>
#include <pokemonism/sdk/interface/channel.hh>

namespace pokemonism::sdk::interface {

    class server;

    class session : public channel {
    protected:  server * container;
    protected:  session * prev;
    protected:  session * next;
    public:     inline session(void);
    public:     ~session(void) override;
    public:     session(const session & o) = delete;
    public:     session(session && o) noexcept = delete;
    public:     session & operator=(const session & o) = delete;
    public:     session & operator=(session && o) noexcept = delete;
    public:     friend server;
    public:     friend linked::list<server, session>;
    };

    inline session::session(void) : container(nullptr), prev(nullptr), next(nullptr) {

    }



}

#endif // __POKEMONISM_SDK_INTERFACE_SESSION_HH__