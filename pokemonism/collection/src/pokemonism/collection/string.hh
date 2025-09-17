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
        class string : public continuous<char> {
        public:     inline virtual const char * stringGet(void) const;
        public:     inline virtual void set(char c);
        public:     inline void set(const char & item, unsigned long n) override;
        public:     inline void set(const char * source, unsigned long sourceLen) override;
        public:     inline virtual void set(const char * source);
        public:     inline virtual void cat(char c);
        public:     inline void cat(const char & item, unsigned long n) override;
        public:     inline void cat(const char * source, unsigned long sourceLen) override;
        public:     inline virtual void cat(const char * source);
        public:     inline string & operator=(const char * s);
        public:     inline string & operator=(char c);
        public:     inline string & operator+=(const char * s);
        public:     inline string & operator+=(char c);
        public:     inline explicit string(const char * s);
        public:     inline string(void);
        public:     inline ~string(void) override;
        public:     inline string(const string & o);
        public:     inline string(string && o) noexcept;
        public:     inline string & operator=(const string & o);
        public:     inline string & operator=(string && o) noexcept;
        };

        inline const char * string::stringGet(void) const {
            return size > 0 ? storage : nullptr;
        }

        inline void string::set(char c) {
            continuous<char>::set(c, 1);
        }

        inline void string::set(const char & item, unsigned long n) {
            continuous<char>::set(item, n);
        }

        inline void string::set(const char * source, unsigned long sourceLen) {
            continuous<char>::set(source, sourceLen);
        }

        inline void string::set(const char * source) {
            continuous<char>::set(source, source != nullptr ? ::strlen(source) : declaration::zero);
        }

        inline void string::cat(char c) {
            continuous<char>::cat(c, 1);
        }

        inline void string::cat(const char & item, unsigned long n) {
            continuous<char>::cat(item, n);
        }

        inline void string::cat(const char * source, unsigned long sourceLen) {
            continuous<char>::cat(source, sourceLen);
        }

        inline void string::cat(const char * source) {
            continuous<char>::cat(source, source != nullptr ? ::strlen(source) : declaration::zero);
        }

        inline string & string::operator=(const char * s) {
            if (s != nullptr) set(s, ::strlen(s));

            return *this;
        }

        inline string & string::operator=(char c) {
            set(c, 1);

            return *this;
        }

        inline string & string::operator+=(const char * s) {
            cat(s, s != nullptr ? ::strlen(s) : declaration::zero);
            return *this;
        }

        inline string & string::operator+=(char c) {
            cat(c, 1);

            return *this;
        }

        inline string::string(const char * s) :
            continuous<char>(s, s != nullptr ? ::strlen(s) : declaration::zero) {

        }

        inline string::string(void) {

        }

        inline string::~string(void) {

        }

        inline string::string(const string & o) : continuous<char>(o) {

        }

        inline string::string(string && o) noexcept : continuous<char>(std::move(o)) {

        }

        inline string & string::operator=(const string & o) {
            if (pointof(o) != this) continuous<char>::operator=(o);

            return *this;
        }

        inline string & string::operator=(string && o) noexcept {
            if (pointof(o) != this) continuous<char>::operator=(std::move(o));

            return *this;
        }

    }

    using string = pokemonism::collection::string;

}

#endif // __POKEMONISM_COLLECTION_STRING_HH__