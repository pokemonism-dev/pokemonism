/**
 * @file        pokemon/latios/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_EVENT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_EVENT__HH__

#include <pokemonism.hh>

#include <pokemon/allocator.hh>
#include <pokemon/exception.hh>

namespace pokemon { namespace latios {

    class event {
    /** STATIC MEMBER */
    public:     constexpr static int    success = declaration::success;
    public:     constexpr static int    fail = declaration::fail;
    public:     constexpr static int    retry = declaration::retry;
    /** MEMBER VARIABLE */
    protected:  uint32                  no;
    protected:  pokemon::exception *    exception;
    /** MEMBER METHOD */
    public:     virtual inline uint32 type(void) const { return no; }
    public:     virtual inline const pokemon::exception * e(void) const { return exception; }
    /** CUSTOM CONSTRUCTOR */
    protected:  inline explicit event(const uint32 type) : no(type), exception(nullptr) {}
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    public:     inline event(void) = delete;
    protected:  inline virtual ~event(void) { exception = allocator::del(exception); }
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_LATIOS_EVENT__HH__