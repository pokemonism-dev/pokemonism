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

#include <pokemonism/sdk/interface/input.hh>
#include <pokemonism/sdk/interface/output.hh>
#include <pokemonism/sdk/interface/socket.hh>
#include <pokemonism/sdk/generic/descriptor.hh>

namespace pokemonism::sdk::generic {

    // template <class inputable>
    // class socket : public descriptor<inputable> {
    // public:     typedef inputable::type        type;
    // protected:  inline explicit socket(type value);
    // public:     inline socket(void);
    // public:     inline ~socket(void) override;
    // public:     socket(const generic::socket<inputable> & o) = delete;
    // public:     socket(generic::socket<inputable> && o) noexcept = delete;
    // public:     generic::socket<inputable> & operator=(const generic::socket<inputable> & o) = delete;
    // public:     generic::socket<inputable> & operator=(generic::socket<inputable> && o) noexcept = delete;
    // };
    //
    // template <class inputable>
    // inline socket<inputable>::socket(type value) : inputable(value) {
    //
    // }
    //
    // template <class inputable>
    // inline socket<inputable>::socket(void) {
    //
    // }
    //
    // template <class inputable>
    // inline socket<inputable>::~socket(void) {
    // }

    // template <class inputable>
    // class socket : public inputable {
    // public:     typedef inputable::type        type;
    // public:     inline void clear(void) override;
    // public:     inline void clean(void) override;
    // public:     inline void reset(void) override;
    // protected:  inline explicit descriptor(type value);
    // public:     inline descriptor(void);
    // public:     inline ~descriptor(void) override;
    // public:     descriptor(const generic::descriptor<inputable> & o) = delete;
    // public:     descriptor(generic::descriptor<inputable> && o) noexcept = delete;
    // public:     generic::descriptor<inputable> & operator=(const generic::descriptor<inputable> & o) = delete;
    // public:     generic::descriptor<inputable> & operator=(generic::descriptor<inputable> && o) noexcept = delete;
    // };

    // template <class inputable = pokemonism::sdk::interface::input, class outputable = pokemonism::sdk::interface::output>
    // class socket : public interface::socket, public generic::descriptor<inputable, outputable> {
    // public:     socket(void) {}
    // public:     ~socket(void) override {}
    // public:     socket(const generic::socket<inputable, outputable> & o) = delete;
    // public:     socket(generic::socket<inputable, outputable> && o) noexcept = delete;
    // public:     generic::socket<inputable, outputable> & operator=(const generic::socket<inputable, outputable> & o) = delete;
    // public:     generic::socket<inputable, outputable> & operator=(generic::socket<inputable, outputable> && o) noexcept = delete;
    // };
}

#endif // __POKEMONISM_SOCKET_HH__