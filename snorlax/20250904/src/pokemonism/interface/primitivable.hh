/**
 * @file            pokemonism/interface/primitivable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_INTERFACE_PRIMITIVABLE_HH__
#define   __POKEMONISM_INTERFACE_PRIMITIVABLE_HH__

#include <pokemonism.hh>

#include <pokemonism/exception.hh>

namespace pokemonism {
    namespace interface {

        struct primitivable {
        public:     template <typename type> static type to(primitivable * o) { pokemon_critical_check(o != nullptr && dynamic_cast<type *>(o) == nullptr, return o); }
        public:     primitivable(void) {}
        protected:  ~primitivable(void) {}
        public:     primitivable(const primitivable & o) = delete;
        public:     primitivable(primitivable && o) noexcept = delete;
        public:     primitivable & operator=(const primitivable & o) = delete;
        public:     primitivable & operator=(primitivable && o) noexcept = delete;
        };


        template <> inline int8   primitivable::to<int8>(primitivable * o)   { return static_cast<int8>(reinterpret_cast<uint64>(o)); }
        template <> inline int16  primitivable::to<int16>(primitivable * o)  { return static_cast<int16>(reinterpret_cast<uint64>(o)); }
        template <> inline int32  primitivable::to<int32>(primitivable * o)  { return static_cast<int32>(reinterpret_cast<uint64>(o)); }
        template <> inline int64  primitivable::to<int64>(primitivable * o)  { return static_cast<int64>(reinterpret_cast<uint64>(o)); }
        template <> inline uint8  primitivable::to<uint8>(primitivable * o)  { return static_cast<uint8>(reinterpret_cast<uint64>(o)); }
        template <> inline uint16 primitivable::to<uint16>(primitivable * o) { return static_cast<uint16>(reinterpret_cast<uint64>(o)); }
        template <> inline uint32 primitivable::to<uint32>(primitivable * o) { return static_cast<uint32>(reinterpret_cast<uint64>(o)); }
        template <> inline uint64 primitivable::to<uint64>(primitivable * o) { return reinterpret_cast<uint64>(o); }
    }

    using primitivable = interface::primitivable;

}

#endif // __POKEMONISM_INTERFACE_PRIMITIVABLE_HH__