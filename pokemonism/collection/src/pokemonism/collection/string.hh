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

#include <cstring>

#include <pokemonism/collection/continuous.hh>

namespace pokemonism {
    namespace collection {
        class String : public Continuous<char> {
        public:     inline virtual void set(char c);
        public:     inline void set(const char & item, unsigned long n) override;
        public:     inline void set(const char * source, unsigned long sourceLen) override;
        public:     inline virtual void set(const char * source);
        public:     inline virtual void cat(char c);
        public:     inline void cat(const char & item, unsigned long n) override;
        public:     inline void cat(const char * source, unsigned long sourceLen) override;
        public:     inline virtual void cat(const char * source);
        public:     inline String & operator=(const char * s);
        public:     inline String & operator=(char c);
        public:     inline String & operator+=(const char * s);
        public:     inline String & operator+=(char c);
        public:     inline String(void);
        public:     inline ~String(void) override;
        public:     inline String(const String & o);
        public:     inline String(String && o) noexcept;
        public:     inline String & operator=(const String & o);
        public:     inline String & operator=(String && o) noexcept;
        };

        inline void String::set(char c) {
            Continuous<char>::set(c, 1);
        }

        inline void String::set(const char & item, unsigned long n) {
            Continuous<char>::set(item, n);
        }

        inline void String::set(const char * source, unsigned long sourceLen) {
            Continuous<char>::set(source, sourceLen);
        }

        inline void String::set(const char * source) {
            Continuous<char>::set(source, source != nullptr ? ::strlen(source) : declaration::zero);
        }

        inline void String::cat(char c) {
            Continuous<char>::cat(c, 1);
        }

        inline void String::cat(const char & item, unsigned long n) {
            Continuous<char>::cat(item, n);
        }

        inline void String::cat(const char * source, unsigned long sourceLen) {
            Continuous<char>::cat(source, sourceLen);
        }

        inline void String::cat(const char * source) {
            Continuous<char>::cat(source, source != nullptr ? ::strlen(source) : declaration::zero);
        }

        inline String & String::operator=(const char * s) {
            if (s != nullptr) set(s, ::strlen(s));

            return *this;
        }

        inline String & String::operator=(char c) {
            set(c, 1);

            return *this;
        }

        inline String & String::operator+=(const char * s) {
            cat(s, s != nullptr ? ::strlen(s) : declaration::zero);
            return *this;
        }

        inline String & String::operator+=(char c) {
            cat(c, 1);

            return *this;
        }

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

    using String = pokemonism::collection::String;

}

#endif // __POKEMONISM_COLLECTION_STRING_HH__