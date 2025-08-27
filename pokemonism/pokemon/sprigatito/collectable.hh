/**
 * @file        pokemon/sprigatito/collectable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 *
 * 아이템을 찾아서 삭제하는 로직은 operator== 이 구현되어 있지 않으면 동작하지 않는다.
 * 그렇기 때문에 deletable 클래스로 옮긴다. deletable 클래스는 scannable 에서 상속하였다.
 */

#ifndef   __POKEMONISM_POKEMON_COLLECTABLE__HH__
#define   __POKEMONISM_POKEMON_COLLECTABLE__HH__

#include <pokemon/sprigatito/iterable.hh>

namespace pokemon { namespace sprigatito {

    template <typename element_type>
    class collectable : public virtual iterable<element_type> {
    public:     typedef element_type        element;
    public:     constexpr static uint64     max = 0xFFFFFFFFFFFFFFFELU;
    public:     constexpr static uint64     invalid = 0xFFFFFFFFFFFFFFFFLU;
    public:     virtual uint64 size(void) const = 0;
    public:     virtual uint64 length(void) const = 0;
    public:     virtual bool empty(void) const = 0;
    public:     virtual bool add(const element & item) = 0;
    public:     virtual bool add(element && item) = 0;
    public:     virtual uint64 add(const element & item, uint64 n) = 0;
    public:     virtual uint64 add(element && item, uint64 n) = 0;
    public:     virtual uint64 add(const element * source, uint64 n) = 0;
    public:     virtual void clear(void) = 0;
    public:     virtual void clean(void) = 0;
    public:     virtual void reset(void) = 0;
    public:     collectable(void) {}
    public:     ~collectable(void) override {}
    public:     collectable(const collectable & o) = delete;
    public:     collectable(collectable && o) noexcept = delete;
    public:     collectable & operator=(const collectable & o) = delete;
    public:     collectable & operator=(collectable && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_COLLECTABLE__HH__