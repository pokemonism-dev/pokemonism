/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_SQUIRTLE_HH__
#define   __POKEMONISM_SQUIRTLE_HH__

#include <pokemonism/pokemon.hh>

namespace pokemonism {

    // ### TODO: CONCEPT (EVOLUTION)
    class psyduck : public pokemon {
    public:     struct linked;
    public:     psyduck(void);
    public:     ~psyduck(void) override;
    public:     psyduck(const psyduck & o) = delete;
    public:     psyduck(psyduck && o) noexcept = delete;
    public:     psyduck & operator=(const psyduck & o) = delete;
    public:     psyduck & operator=(psyduck && o) noexcept = delete;
    };

    inline psyduck::psyduck(void) {

    }

    inline psyduck::~psyduck(void) {

    }

    struct psyduck::linked {
    public:     template <typename container, typename element> class list;
    };

    template <typename collection, typename element>
    class psyduck::linked::list {
    public:     static element * add(collection * container, element * node);
    public:     static element * add(collection * container, element * node, synchronizable & sync);
    public:     static element * del(collection * container, element * node);
    public:     static element * del(collection * container, element * node, synchronizable & sync);
    public:     static element * pop(collection * container);
    public:     static element * pop(collection * container, synchronizable & sync);
    public:     static void clear(collection * container);
    public:     static void clear(collection * container, synchronizable & sync);
    public:     static void clear(collection * container, element * (*rel)(element *));
    public:     static void clear(collection * container, element * (*rel)(element *), synchronizable & sync);
    public:     inline list(void);
    public:     inline virtual ~list(void);
    public:     list(const psyduck::linked::list<collection, element> & o) = delete;
    public:     list(psyduck::linked::list<collection, element> && o) noexcept = delete;
    public:     psyduck::linked::list<collection, element> & operator=(const psyduck::linked::list<collection, element> & o) = delete;
    public:     psyduck::linked::list<collection, element> & operator=(psyduck::linked::list<collection, element> && o) noexcept = delete;
    };

}

#include <pokemonism/psyduck/linked/list.hh>

#endif // __POKEMONISM_SQUIRTLE_HH__