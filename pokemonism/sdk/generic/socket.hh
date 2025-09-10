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

namespace pokemonism::sdk::generic {

    template <class socketable = interface::socket>
    class socket : public socketable {
    protected:  typedef socketable::type    type;
    protected:  inline explicit socket(generic::socket<socketable>::type value);
    public:     inline socket(void);
    public:     inline ~socket(void) override;
    public:     socket(const generic::socket<socketable> & o) = delete;
    public:     socket(generic::socket<socketable> && o) noexcept = delete;
    public:     generic::socket<socketable> & operator=(const generic::socket<socketable> & o) = delete;
    public:     generic::socket<socketable> & operator=(generic::socket<socketable> && o) noexcept = delete;
    };

    template <class socketable>
    inline socket<socketable>::socket(generic::socket<socketable>::type value) : socketable(value) {

    }

    template <class socketable>
    inline socket<socketable>::socket(void) {

    }

    template <class socketable>
    inline socket<socketable>::~socket(void) {

    }

}

#endif // __POKEMONISM_SDK_GENERIC_SOCKET_HH__