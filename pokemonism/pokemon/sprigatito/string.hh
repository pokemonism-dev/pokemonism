/**
 * @file        pokemon/sprigatito/string.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_STRING__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_STRING__HH__

#include <pokemon/sprigatito/continuation.hh>

namespace pokemon { namespace sprigatito {

    // ReSharper disable once CppClassCanBeFinal
    class string : public continuation<char> {
    /** string */
    public:     inline void set(const element & item, uint64 n) override;
    public:     inline void set(element && item, uint64 n) override;
    public:     inline void set(const element * source, uint64 n) override;
    public:     inline void set(const continuation<char> & o) override;
    public:     inline void set(continuation<char> && o) override;
    public:     virtual inline void set(const string & o);
    public:     virtual inline void set(const string & source, uint64 sourcePos, uint64 sourceLen);
    public:     virtual inline void set(string && o);
    public:     virtual inline void set(const char * s);
    public:     inline void cat(const element & item, uint64 n) override;
    public:     inline void cat(element && item, uint64 n) override;
    public:     inline void cat(const element * source, uint64 n) override;
    public:     inline void cat(const continuation<char> & o) override;
    public:     inline void cat(continuation<char> && o) override;
    public:     virtual inline void cat(const string & o);
    public:     virtual inline void cat(const string & source, uint64 sourcePos, uint64 sourceLen);
    public:     virtual inline void cat(string && o);
    public:     virtual inline void cat(const char * s);
    public:     inline void put(uint64 offset, const element & item, uint64 n) override;
    public:     inline void put(uint64 offset, element && item, uint64 n) override;
    public:     inline void put(uint64 offset, const element * source, uint64 n) override;
    public:     inline void put(uint64 offset, const continuation<char> & o) override;
    public:     inline void put(uint64 offset, continuation<char> && o) override;
    public:     virtual inline void put(uint64 offset, const string & o);
    public:     virtual inline void put(uint64 offset, const string & source, uint64 sourcePos, uint64 sourceLen);
    public:     virtual inline void put(uint64 offset, string && o);
    public:     virtual inline void put(uint64 offset, const char * s);
    public:     inline void mod(uint64 offset, uint64 length, const element & item, uint64 n) override;
    public:     inline void mod(uint64 offset, uint64 length, element && item, uint64 n) override;
    public:     inline void mod(uint64 offset, uint64 length, const element * source, uint64 n) override;
    public:     inline virtual void mod(uint64 offset, uint64 length, const continuation<char> & o) override;
    public:     inline virtual void mod(uint64 offset, uint64 length, continuation<char> && o) override;
    public:     virtual inline void mod(uint64 offset, uint64 length, const string & o);
    public:     virtual inline void mod(uint64 offset, uint64 length, const string & source, uint64 sourcePos, uint64 sourceLen);
    public:     virtual inline void mod(uint64 offset, uint64 length, string && o);
    public:     virtual inline void mod(uint64 offset, uint64 length, const char * s);
    public:     virtual inline string & operator+=(const string & o);
    public:     virtual inline string & operator+=(string && o);
    public:     virtual inline string & operator+=(const continuation<char> & o) override;
    public:     virtual inline string & operator+=(continuation<char> && o) override;
    public:     virtual inline string & operator+=(const char * s);
    public:     virtual inline string & operator+=(char && c)  override;
    public:     virtual inline string & operator+=(const char & c)  override;
    public:     inline explicit string(const char * s);
    public:     inline string(const char * s, uint64 n);
    public:     inline string(const string & o, uint64 offset);
    public:     inline string(const string & o, uint64 offset, uint64 length);
    public:     inline string(uint64 n, char c);
    public:     inline string(void);
    public:     inline ~string(void) override;
    public:     inline string(const string & o);
    public:     inline string(string && o) noexcept;
    public:     inline string & operator=(const string & o);
    public:     inline string & operator=(string && o) noexcept;
    public:     inline string & operator=(const char * s);
    public:     inline string & operator=(char c);
    /** std::iostream */
    public:     inline friend std::ostream & operator<<(std::ostream & stream, const string & o);
    /** operator */
    public:     inline friend string operator+(const string & left, const string & right);
    public:     inline friend string operator+(const string & left, const char *   right);
    public:     inline friend string operator+(const char *   left, const string & right);
    public:     inline friend string operator+(const string & left, char           right);
    public:     inline friend string operator+(char           left, const string & right);
    };

    string::string(void) {

    }

    string::~string(void) {

    }

    string::string(const string & o) : continuation<char>(o) {

    }

    string::string(string && o) noexcept : continuation<char>(std::move(o)) {

    }

    string & string::operator=(const string & o) {
        if (pointof(o) != this) continuation<char>::operator=(o);
        return *this;
    }

    string & string::operator=(string && o) noexcept {
        if (pointof(o) != this) continuation<char>::operator=(std::move(o));
        return *this;
    }

    string::string(const char * s) : continuation<char>(s, strlen(s)) {

    }

    string::string(const char * s, const uint64 n) : continuation<char>(s, n) {

    }

    string::string(const string & o, const uint64 offset) : continuation<char>(offset < o.len ? o.storage + offset : nullptr, offset < o.len ? o.len - offset : 0) {

    }

    string::string(const uint64 n, const char c) : continuation<char>(c, n) {

    }

    string::string(const string & o, const uint64 offset, uint64 const length) : continuation<char>(offset < o.len ? o.storage + offset : nullptr, offset < o.len ? (o.len - offset < length ? o.len - offset : length) : 0) {

    }

    string & string::operator=(const char * s) {
        if (s != nullptr) {
            len = strlen(s);
            if (const uint64 capacity = capacityCal(len); capacity != capa) storage = memorizer::reset(storage, capa = capacity);
            if (len > 0) {
                memorizer::set(storage, s, len);
                storage[len] = 0;
            }
        }
        return *this;
    }

    string & string::operator=(const char c) {
        len = 1;
        if (const uint64 capacity = capacityCal(len); capacity != capa) storage = memorizer::reset(storage, capa = capacity);
        memorizer::set(storage, c, len);
        storage[len] = 0;
        return *this;
    }

    /** string */
    void string::set(const element & item, const uint64 n) { continuation::set(item, n); }
    void string::set(element && item, const uint64 n) { continuation::set(std::move(item), n); }
    void string::set(const element * source, const uint64 n) { continuation::set(source, n); }
    void string::set(const continuation<char> & o) { continuation::set(o); }
    void string::set(continuation<char> && o) { continuation::set(std::move(o)); }
    void string::set(const string & o) { continuation::set(o); }
    void string::set(const string & source, const uint64 sourcePos, const uint64 sourceLen) {
        critical_quick_throw_check(source.len < sourcePos, exceptional::overflow::index, return);
        set(source.storage + sourcePos, sourceLen);
    }
    void string::set(string && o) { continuation::set(std::move(o)); }
    void string::set(const char * s) { continuation::set(s, s != nullptr ? strlen(s) : 0); }

    void string::cat(const element & item, const uint64 n) { continuation::cat(item, n); }
    void string::cat(element && item, const uint64 n) { continuation::cat(std::move(item), n); }
    void string::cat(const element * source, const uint64 n) { continuation::cat(source, n); }
    void string::cat(const continuation<char> & o) { continuation::cat(o); }
    void string::cat(continuation<char> && o) { continuation::cat(std::move(o)); }
    void string::cat(const string & o) { continuation::cat(o); }
    void string::cat(const string & source, const uint64 sourcePos, const uint64 sourceLen) {
        critical_quick_throw_check(source.len < sourcePos, exceptional::overflow::index, return);
        cat(source.storage + sourcePos, sourceLen);
    }
    void string::cat(string && o) { continuation::cat(std::move(o)); }
    void string::cat(const char * s) { continuation::cat(s, s != nullptr ? strlen(s) : 0); }

    void string::put(const uint64 offset, const element & item, const uint64 n) { continuation::put(offset, item, n); }
    void string::put(const uint64 offset, element && item, const uint64 n) { continuation::put(offset, std::move(item), n); }
    void string::put(const uint64 offset, const element * source, const uint64 n) { continuation::put(offset, source, n); }
    void string::put(const uint64 offset, const continuation<char> & o) { continuation::put(offset, o); }
    void string::put(const uint64 offset, continuation<char> && o) { continuation::put(offset, std::move(o)); }
    void string::put(const uint64 offset, const string & o) { continuation::put(offset, o); }
    void string::put(const uint64 offset, const string & source, const uint64 sourcePos, const uint64 sourceLen) {
        critical_quick_throw_check(source.len < sourcePos, exceptional::overflow::index, return);
        put(offset, source.storage + sourcePos, sourceLen);
    }
    void string::put(const uint64 offset, string && o) { continuation::put(offset, std::move(o)); }
    void string::put(const uint64 offset, const char * s) { continuation::put(offset, s, s != nullptr ? strlen(s) : 0); }

    void string::mod(const uint64 offset, const uint64 length, const element & item, const uint64 n) { continuation::mod(offset, length, item, n); }
    void string::mod(const uint64 offset, const uint64 length, element && item, const uint64 n) { continuation::mod(offset, length, std::move(item), n); }
    void string::mod(const uint64 offset, const uint64 length, const element * source, const uint64 n) { continuation::mod(offset, length, source, n); }
    void string::mod(const uint64 offset, const uint64 length, const continuation<char> & o) { continuation::mod(offset, length, o); }
    void string::mod(const uint64 offset, const uint64 length, continuation<char> && o) { continuation::mod(offset, length, std::move(o)); }
    void string::mod(const uint64 offset, const uint64 length, const string & o) { continuation::mod(offset, length, o); }
    void string::mod(const uint64 offset, const uint64 length, const string & source, const uint64 sourcePos, const uint64 sourceLen) {
        critical_quick_throw_check(source.len < sourcePos, exceptional::overflow::index, return);
        mod(offset, length, source.storage + sourcePos, sourceLen);
    }
    void string::mod(const uint64 offset, const uint64 length, string && o) { continuation::mod(offset, length, std::move(o)); }
    void string::mod(const uint64 offset, const uint64 length, const char * s) { continuation::mod(offset, length, s, s != nullptr ? strlen(s) : 0); }

    string & string::operator+=(const string & o) {
        cat(o);
        return *this;
    }

    string & string::operator+=(string && o) {
        cat(std::move(o));
        return *this;
    }

    string & string::operator+=(const continuation<char> & o) {
        cat(o);
        return *this;
    }

    string & string::operator+=(continuation<char> && o) {
        cat(std::move(o));
        return *this;
    }

    string & string::operator+=(const char * s) {
        cat(s);
        return *this;
    }

    string & string::operator+=(const char & c) {
        cat(c, 1);
        return *this;
    }

    string & string::operator+=(char && c) {
        cat(c, 1);
        return *this;
    }

    /** std::iostream */
    std::ostream & operator<<(std::ostream & stream, const string & o) {
        return operator<<(stream, static_cast<const continuation<char> &>(o));
    }

    /** operator */
    string operator+(const string & left, const string & right) {
        string o = left;
        if (right.len > 0) o.cat(right);
        return o;
    }
    string operator+(const string & left, const char *   right) {
        string o = left;
        if (const uint64 len = strlen(right); len > 0) o.cat(right, len);
        return o;
    }

    string operator+(const char *   left, const string & right) {
        string o(left);
        o.cat(right);
        return o;
    }

    string operator+(const string & left, const char     right) {
        string o = left;
        o.cat(right, 1);
        return o;
    }

    string operator+(const char     left, const string & right) {
        string o(1, left);
        if (right.len > 0) o.cat(right.storage, right.len);
        return o;
    }

} }

#endif // __POKEMONISM_POKEMON_SPRIGATITO_STRING__HH__