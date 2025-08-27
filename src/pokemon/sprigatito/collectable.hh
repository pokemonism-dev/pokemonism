/**
 * @file        pokemon/sprigatito/collectable.hh
 * @brief
 * @details     `virtual collectable & clear(void)` clear 함수의 리턴타입을 `collectable &` 로 정의한 이유는
 *              차후에 레디스 같은 자료 구조 서버를 만들려고 할 때, 클라이언트 자료구조에서 상속 받아서
 *              구현 시에 리턴 값으로 Future<Collectable &> 를 통해서 결과를 가지고 올 수 있도록 하려고 한다.
 *              그러면 비동기적으로 그 결과를 받을 수 있을 것 같다.
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 *
 */


#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_COLLECTABLE__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_COLLECTABLE__HH__

#include <pokemonism.hh>

#include <pokemon/future.hh>
#include <pokemon/object.hh>

namespace pokemon { namespace sprigatito {

    class collectable : public virtual object {
    protected:  uint64 size;
        // result, primitive 를 리턴할 수 있다. 이미 정의된 것을 리턴하면 된다.
    public:     virtual future<uint64> clear(void) = 0;
    public:     virtual future<uint64> clean(void) = 0;
    public:     virtual inline future<uint64> reset(void) { return future<uint64>(future<uint64>::response(0)); };
    public:     virtual inline future<uint64> total(void) const { return future<uint64>(future<uint64>::response(size)); }
    public:     collectable(void) : size(0) {}
    public:     virtual ~collectable(void) {}
    public:     collectable(const collectable & o) = delete;
    public:     collectable(collectable && o) noexcept = delete;
    public:     collectable & operator=(const collectable & o) = delete;
    public:     collectable & operator=(collectable && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_SPRIGATITO_COLLECTABLE__HH__