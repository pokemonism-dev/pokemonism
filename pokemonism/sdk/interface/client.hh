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

#include <pokemonism/sdk/linked/list.hh>
#include <pokemonism/sdk/interface/channel.hh>

namespace pokemonism::sdk::interface {

    class client : public channel {
    public:     class pool : public synchronizable {
                public:     using collection = pokemonism::sdk::linked::list<client::pool, client>;
                protected:  unsigned long size;
                protected:  interface::client * head;
                protected:  interface::client * tail;
                public:     inline client * add(client * node);
                public:     inline client * del(client * node);
                public:     inline pool(void);
                public:     inline ~pool(void) override;
                public:     pool(const client::pool & o) = delete;
                public:     pool(client::pool && o) noexcept = delete;
                public:     client::pool & operator=(const client::pool & o) = delete;
                public:     client::pool & operator=(client::pool && o) noexcept = delete;
                public:     friend collection;
                };
    protected:  client::pool * container;
    protected:  interface::client * prev;
    protected:  interface::client * next;
    public:     inline client(void);
    public:     inline ~client(void) override;
    public:     client(const client & o) = delete;
    public:     client(client && o) noexcept = delete;
    public:     client & operator=(const client & o) = delete;
    public:     client & operator=(client && o) noexcept = delete;
    public:     friend pokemonism::sdk::linked::list<client::pool, client>;
    };

    inline client::client(void) : container(nullptr), prev(nullptr), next(nullptr) {

    }

    inline client::~client(void) {
        if (container) container->del(this);
    }

    // ReSharper disable once CppDFAConstantFunctionResult
    inline client * client::pool::add(client * node) {
        pokemon_develop_check(node == nullptr || node->container != nullptr, return node);

        collection::add(this, node, *this);

        return nullptr;
    }

    inline client * client::pool::del(client * node) {
        pokemon_develop_check(node == nullptr || node->container != this, return node);

        collection::del(this, node, *this);

        return node;
    }

    inline client::pool::pool(void) : size(declaration::zero), head(nullptr), tail(nullptr) {

    }

    inline client::pool::~pool(void) {
        collection::clear(this, *this);
    }

}

#endif // __POKEMONISM_SDK_INTERFACE_CLIENT_HH__
