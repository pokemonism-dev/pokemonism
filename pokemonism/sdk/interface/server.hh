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

#include <pokemonism/sdk/linked/list.hh>
#include <pokemonism/sdk/interface/communicator.hh>

namespace pokemonism::sdk::interface {

    class session;

    class server : public communicator {
    public:     using collection = linked::list<server, session>;
    protected:  unsigned long size;
    protected:  session * head;
    protected:  session * tail;
    public:     virtual session * accept(void) = 0;
    protected:  virtual session * gen(void) = 0;
    public:     virtual session * add(session * node);
    public:     virtual session * del(session * node);
    public:     inline server(void);
    public:     ~server(void) override;
    public:     server(const server & o) = delete;
    public:     server(server && o) noexcept = delete;
    public:     server & operator=(const server & o) = delete;
    public:     server & operator=(server && o) noexcept = delete;
    public:     friend session;
    public:     friend collection;
    };

    inline server::server(void) : size(declaration::zero), head(nullptr), tail(nullptr) {

    }

}

#endif // __POKEMONISM_SDK_INTERFACE_SERVER_HH__
