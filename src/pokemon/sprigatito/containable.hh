/**
 * @file        pokemon/sprigatito/containable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_CONTAINABLE__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_CONTAINABLE__HH__

#include <pokemon/sprigatito/collectable.hh>

#include <pokemon/sprigatito/reference.hh>

namespace pokemon { namespace sprigatito {
    /**
     * 컨터이너는 아이템을 삽입하고 삭제할 수 있다.
     *
     * promise < future ...
     *
     * @tparam element_type         컨테이너에 저장되는 구성 요소의 타입
     */
    template <typename element_type>
    class containable : public collectable {
    public:     typedef element_type            declaration_type;
    public:     typedef declaration_type *      pointer_type;
    public:     typedef declaration_type &      reference_type;
    public:     typedef declaration_type &&     revalue_reference_type;
    public:     virtual future<uint64> add(const declaration_type & item) = 0;
    public:     virtual future<uint64> add(declaration_type && item) = 0;
    public:     virtual future<uint64> add(const declaration_type & item, uint64 n) = 0;
    public:     virtual future<uint64> add(declaration_type && item, uint64 n) = 0;
    public:     virtual future<uint64> rem(const declaration_type & item) = 0;
    public:     virtual future<uint64> rem(declaration_type item) = 0;
    public:     virtual future<uint64> rem(const reference<declaration_type> & item) = 0;
    public:     virtual future<uint64> rem(const declaration_type & item, uint64 n) = 0;
    public:     virtual future<uint64> rem(declaration_type && item, uint64 n) = 0;
    public:     virtual future<uint64> rem(const reference<declaration_type> & item, uint64 n) = 0;
    public:     containable(void) {}
    public:     ~containable(void) override {}
    public:     containable(const containable<declaration_type> & o) = delete;
    public:     containable(containable<declaration_type> && o) noexcept = delete;
    public:     containable<declaration_type> & operator=(const containable<declaration_type> & o) = delete;
    public:     containable<declaration_type> & operator=(containable<declaration_type> && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_SPRIGATITO_CONTAINABLE__HH__