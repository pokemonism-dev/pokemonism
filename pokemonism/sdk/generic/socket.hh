/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_GENERIC_SOCKET_HH__
#define   __POKEMONISM_SDK_GENERIC_SOCKET_HH__

#include <pokemonism/sdk/interface/socket.hh>
#include <pokemonism/sdk/generic/descriptor.hh>

namespace pokemonism::sdk::generic {

    template <class socketable = interface::socket>
    class socket : public generic::descriptor<socketable> {
    protected:  typedef socketable::type    type;
    protected:  inline int link(void) override;
    public:     inline socket(void);
    public:     inline ~socket(void) override;
    public:     socket(const generic::socket<socketable> & o) = delete;
    public:     socket(generic::socket<socketable> && o) noexcept = delete;
    public:     generic::socket<socketable> & operator=(const generic::socket<socketable> & o) = delete;
    public:     generic::socket<socketable> & operator=(generic::socket<socketable> && o) noexcept = delete;
    };

    template <class socketable>
    inline int socket<socketable>::link(void) {
        // this->value = linker::open<method, category>(this->value);



        if (this->stateChk(interface::descriptor::state::open)) {
            unsigned int state = interface::socket::state::link::begin | interface::socket::state::link::end;
            if (this->readable()) state = state | interface::socket::state::link::in;
            if (this->writeable()) state = state | interface::socket::state::link::out;
            this->stateSet(state);
            return declaration::success;
        }
        return declaration::fail;
    }

    template <class socketable>
    inline socket<socketable>::socket(void) {

    }

    template <class socketable>
    inline socket<socketable>::~socket(void) {
    }

}

#endif // __POKEMONISM_SDK_GENERIC_SOCKET_HH__