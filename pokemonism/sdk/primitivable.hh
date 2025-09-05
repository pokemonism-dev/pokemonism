/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_SDK_PRIMITIVABLE_HH__
#define   __POKEMONISM_SDK_PRIMITIVABLE_HH__

#include <pokemonism/sdk/exception.hh>

namespace pokemonism::sdk {

    struct primitivable {
    public:     template <typename convertable> static primitivable * from(convertable v);
    public:     template <typename convertable> static convertable to(primitivable * o);
    public:     primitivable(void) {}
    public:     ~primitivable(void) {}
    public:     primitivable(const primitivable & o) = delete;
    public:     primitivable(primitivable && o) noexcept = delete;
    public:     primitivable & operator=(const primitivable & o) = delete;
    public:     primitivable & operator=(primitivable && o) noexcept = delete;
    };

    template <typename convertable> inline primitivable * primitivable::from(convertable v) {
        throw exception();
    }

    template <> inline primitivable * primitivable::from<char>(char v) { return reinterpret_cast<primitivable *>(v); }
    template <> inline primitivable * primitivable::from<short>(short v) { return reinterpret_cast<primitivable *>(v); }
    template <> inline primitivable * primitivable::from<int>(int v) { return reinterpret_cast<primitivable *>(v); }
    template <> inline primitivable * primitivable::from<long>(long v) { return reinterpret_cast<primitivable *>(v); }
    template <> inline primitivable * primitivable::from<unsigned char>(unsigned char v) { return reinterpret_cast<primitivable *>(v); }
    template <> inline primitivable * primitivable::from<unsigned short>(unsigned short v) { return reinterpret_cast<primitivable *>(v); }
    template <> inline primitivable * primitivable::from<unsigned int>(unsigned int v) { return reinterpret_cast<primitivable *>(v); }
    template <> inline primitivable * primitivable::from<unsigned long>(unsigned long v) { return reinterpret_cast<primitivable *>(v); }

    template <typename convertable> inline convertable primitivable::to(primitivable * o) {
        throw exception();
    }

    template <> inline char primitivable::to<char>(primitivable * o) { return static_cast<char>(reinterpret_cast<unsigned long>(o)); }
    template <> inline short primitivable::to<short>(primitivable * o) { return static_cast<short>(reinterpret_cast<unsigned long>(o)); }
    template <> inline int primitivable::to<int>(primitivable * o) { return static_cast<int>(reinterpret_cast<unsigned long>(o)); }
    template <> inline long primitivable::to<long>(primitivable * o) { return static_cast<long>(reinterpret_cast<unsigned long>(o)); }
    template <> inline unsigned char primitivable::to<unsigned char>(primitivable * o) { return static_cast<unsigned char>(reinterpret_cast<unsigned long>(o)); }
    template <> inline unsigned short primitivable::to<unsigned short>(primitivable * o) { return static_cast<unsigned short>(reinterpret_cast<unsigned long>(o)); }
    template <> inline unsigned int primitivable::to<unsigned int>(primitivable * o) { return static_cast<unsigned int>(reinterpret_cast<unsigned long>(o)); }
    template <> inline unsigned long primitivable::to<unsigned long>(primitivable * o) { return reinterpret_cast<unsigned long>(o); }

}

#endif // __POKEMONISM_SDK_PRIMITIVABLE_HH__