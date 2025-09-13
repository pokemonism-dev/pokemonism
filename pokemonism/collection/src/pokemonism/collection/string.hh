/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 13, 2025
 */

#ifndef   __POKEMONISM_COLLECTION_STRING_HH__
#define   __POKEMONISM_COLLECTION_STRING_HH__

#include <pokemonism/collection/continuous.hh>

namespace pokemonism::collection {

    class String : public Continuous<char> {
    public:     inline String(void);
    public:     inline ~String(void) override;
    public:     inline String(const String & o);
    public:     inline String(String && o) noexcept;
    public:     inline String & operator=(const String & o);
    public:     inline String & operator=(String && o) noexcept;
    };

    inline String::String(void) {

    }

    inline String::~String(void) {

    }

    inline String::String(const String & o) : Continuous<char>(o) {

    }

    inline String::String(String && o) noexcept : Continuous<char>(std::move(o)) {

    }

    inline String & String::operator=(const String & o) {
        if (pointof(o) != this) Continuous<char>::operator=(o);

        return *this;
    }

    inline String & String::operator=(String && o) noexcept {
        if (pointof(o) != this) Continuous<char>::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_COLLECTION_STRING_HH__