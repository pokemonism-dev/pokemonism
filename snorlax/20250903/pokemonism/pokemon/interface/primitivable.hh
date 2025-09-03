/**
 * @file        pokemonism/pokemon/interface/primitivable.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_INTERFACE_PRIMITIVABLE__HH__
#define   __POKEMONISM_POKEMON_INTERFACE_PRIMITIVABLE__HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace pokemon {

        class primitivable {
        public:     struct object {
                    public:     class to {
                                public:     inline static int8     integer8(const object * o) { return static_cast<pokemonism::int8>(reinterpret_cast<pokemonism::uint64>(o)); }
                                public:     inline static int16    integer16(const object * o) { return static_cast<pokemonism::int16>(reinterpret_cast<pokemonism::uint64>(o)); }
                                public:     inline static int32    integer32(const object * o) { return static_cast<pokemonism::int32>(reinterpret_cast<pokemonism::uint64>(o)); }
                                public:     inline static int64    integer64(const object * o) { return static_cast<pokemonism::int64>(reinterpret_cast<pokemonism::uint64>(o)); }
                                public:     inline static uint8    uinteger8(const object * o) { return static_cast<pokemonism::uint8>(reinterpret_cast<pokemonism::uint64>(o)); }
                                public:     inline static uint16  uinteger16(const object * o) { return static_cast<pokemonism::uint16>(reinterpret_cast<pokemonism::uint64>(o)); }
                                public:     inline static uint32  uinteger32(const object * o) { return static_cast<pokemonism::uint32>(reinterpret_cast<pokemonism::uint64>(o)); }
                                public:     inline static uint64  uinteger64(const object * o) { return reinterpret_cast<pokemonism::uint64>(o); }
                                public:     inline to(void) {}
                                public:     inline virtual ~to(void) {}
                                public:     to(const to & o) = delete;
                                public:     to(to && o) noexcept = delete;
                                public:     to & operator=(const to & o) = delete;
                                public:     to & operator=(to && o) noexcept = delete;
                                };
                    public:     inline static object * gen(const   int8 v) { return reinterpret_cast<object *>(v); }
                    public:     inline static object * gen(const  int16 v) { return reinterpret_cast<object *>(v); }
                    public:     inline static object * gen(const  int32 v) { return reinterpret_cast<object *>(v); }
                    public:     inline static object * gen(const  int64 v) { return reinterpret_cast<object *>(v); }
                    public:     inline static object * gen(const  uint8 v) { return reinterpret_cast<object *>(v); }
                    public:     inline static object * gen(const uint16 v) { return reinterpret_cast<object *>(v); }
                    public:     inline static object * gen(const uint32 v) { return reinterpret_cast<object *>(v); }
                    public:     inline static object * gen(const uint64 v) { return reinterpret_cast<object *>(v); }
                    protected:  inline object(void) {}
                    protected:  inline virtual ~object(void) {}
                    public:     object(const object & o) = delete;
                    public:     object(object && o) noexcept = delete;
                    public:     object & operator=(const object & o) = delete;
                    public:     object & operator=(object && o) noexcept = delete;
                    };
        public:     inline primitivable(void) {}
        public:     inline virtual ~primitivable(void) {}
        public:     primitivable(primitivable & o) = delete;
        public:     primitivable(primitivable && o) noexcept = delete;
        public:     primitivable & operator=(primitivable & o) = delete;
        public:     primitivable & operator=(primitivable && o) noexcept = delete;
        };
    }

    using primitivable = pokemon::primitivable;
}

#endif // __POKEMONISM_POKEMON_INTERFACE_PRIMITIVABLE__HH__