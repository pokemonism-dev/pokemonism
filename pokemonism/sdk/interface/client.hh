/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_CLIENT_HH__
#define   __POKEMONISM_SDK_INTERFACE_CLIENT_HH__

#include <pokemonism/sdk/interface/channel.hh>

namespace pokemonism::sdk::interface {

    class client : public channel {
    public:     template <class clientable = interface::client> class pool : public synchronizable {
                protected:  unsigned long size;
                protected:  clientable * head;
                protected:  clientable * tail;
                public:     pool(void);
                public:     ~pool(void) override;
                public:     pool(const client::pool<clientable> & o) = delete;
                public:     pool(client::pool<clientable> && o) noexcept = delete;
                public:     client::pool<clientable> & operator=(const client::pool<clientable> & o) = delete;
                public:     client::pool<clientable> & operator=(client::pool<clientable> && o) noexcept = delete;
                };
    public:     client(void) {}
    public:     ~client(void) override {}
    public:     client(const client & o) = delete;
    public:     client(client && o) noexcept = delete;
    public:     client & operator=(const client & o) = delete;
    public:     client & operator=(client && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_CLIENT_HH__
