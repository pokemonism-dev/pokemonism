/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_GENERIC_SOCKET_HH__
#define   __POKEMONISM_SDK_GENERIC_SOCKET_HH__

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/sdk/socketable.hh>
#include <pokemonism/sdk/interface/socket.hh>

namespace pokemonism::sdk::generic {

    template <class inputable>
    class socket : public inputable {
    public:     typedef inputable::type     type;
    protected:  inline explicit socket(type value);
    public:     inline socket(void);
    public:     inline ~socket(void) override;
    public:     socket(const generic::socket<inputable> & o) = delete;
    public:     socket(generic::socket<inputable> && o) noexcept = delete;
    public:     generic::socket<inputable> & operator=(const generic::socket<inputable> & o) = delete;
    public:     generic::socket<inputable> & operator=(generic::socket<inputable> && o) noexcept = delete;
    };

    template <class inputable>
    inline socket<inputable>::socket(type value) : inputable(value) {

    }

    template <class inputable>
    inline socket<inputable>::socket(void) {

    }

    template <class inputable>
    inline socket<inputable>::~socket(void) {
    }

}

#endif // __POKEMONISM_SOCKET_HH__