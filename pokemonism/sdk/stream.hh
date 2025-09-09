/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_STREAM_HH__
#define   __POKEMONISM_SDK_STREAM_HH__

#include <pokemonism/sdk/linked/list.hh>
#include <pokemonism/sdk/collection/stream.hh>
#include <pokemonism/sdk/input.hh>

namespace pokemonism::sdk {

    class stream : public collection::stream<unsigned char> {
    public:     class buffer;
    public:     static stream * factory(stream::buffer * container);
    protected:  stream::buffer *    container;
    protected:  stream *            prev;
    protected:  stream *            next;
    public:     inline unsigned long set(void) override;
    public:     inline unsigned long set(const unsigned char & item, unsigned long n) override;
    public:     inline unsigned long set(const unsigned char * source, unsigned long sourceLen) override;
    public:     inline unsigned long set(const collection::stream<unsigned char> & source) override;
    public:     inline unsigned long set(collection::stream<unsigned char> && source) noexcept override;
    public:     inline virtual unsigned long set(const stream & source);
    public:     virtual unsigned long set(stream && source) noexcept;
    public:     inline unsigned long cat(const unsigned char & item, unsigned long n) override;
    public:     inline unsigned long cat(const unsigned char * source, unsigned long sourceLen) override;
    public:     inline unsigned long cat(const collection::stream<unsigned char> & source) override;
    public:     inline unsigned long cat(collection::stream<unsigned char> && source) override;
    public:     inline virtual unsigned long cat(const stream & source);
    public:     inline virtual unsigned long cat(stream && source);
    public:     unsigned long pageGet(void) const override;
    public:     explicit stream(stream::buffer * container);
    public:     inline stream(unsigned char item, unsigned long n);
    public:     inline stream(const unsigned char * source, unsigned long sourceLen);
    public:     inline stream(void);
    public:     ~stream(void) override;
    public:     inline stream(const stream & o);
    public:     inline stream(stream && o) noexcept;
    public:     inline explicit stream(const collection::stream<unsigned char> & o);
    public:     inline explicit stream(collection::stream<unsigned char> && o) noexcept;
    public:     inline virtual stream & operator=(const stream & o);
    public:     inline virtual stream & operator=(stream && o) noexcept;
    public:     inline stream & operator=(const collection::stream<unsigned char> & o) override;
    public:     inline stream & operator=(collection::stream<unsigned char> && o) noexcept override;
    public:     friend linked::list<stream::buffer, stream>;
    public:     template <class outputable> friend class input::stream;
    };

    inline unsigned long stream::set(void) { return collection::stream<unsigned char>::set(); }

    inline unsigned long stream::set(const unsigned char & item, unsigned long n) { return collection::stream<unsigned char>::set(item, n); }

    inline unsigned long stream::set(const unsigned char * source, unsigned long sourceLen) { return collection::stream<unsigned char>::set(source, sourceLen); }

    inline unsigned long stream::set(const collection::stream<unsigned char> & source) { return collection::stream<unsigned char>::set(source); }

    inline unsigned long stream::set(collection::stream<unsigned char> && source) noexcept { return collection::stream<unsigned char>::set(std::move(source)); }

    inline unsigned long stream::set(const stream & source) { return collection::stream<unsigned char>::set(source); }

    inline unsigned long stream::set(stream && source) noexcept { return collection::stream<unsigned char>::set(std::move(source)); }

    inline unsigned long stream::cat(const unsigned char & item, unsigned long n) { return collection::stream<unsigned char>::cat(item, n); }

    inline unsigned long stream::cat(const unsigned char * source, unsigned long sourceLen) { return collection::stream<unsigned char>::cat(source, sourceLen); }

    inline unsigned long stream::cat(const collection::stream<unsigned char> & source) { return collection::stream<unsigned char>::cat(source); }

    inline unsigned long stream::cat(collection::stream<unsigned char> && source) { return collection::stream<unsigned char>::cat(std::move(source)); }

    inline unsigned long stream::cat(const stream & source) { return collection::stream<unsigned char>::set(source); }

    inline unsigned long stream::cat(stream && source) { return collection::stream<unsigned char>::set(std::move(source)); }

    inline stream::stream(unsigned char item, unsigned long n) : collection::stream<unsigned char>(item, n), container(nullptr), prev(nullptr), next(nullptr) {}

    inline stream::stream(const unsigned char * source, unsigned long sourceLen) : collection::stream<unsigned char>(source, sourceLen), container(nullptr), prev(nullptr), next(nullptr) {}

    inline stream::stream(void) : container(nullptr), prev(nullptr), next(nullptr) {}

    inline stream::stream(const stream & o) : collection::stream<unsigned char>(o), container(nullptr), prev(nullptr), next(nullptr) {}

    inline stream::stream(stream && o) noexcept : collection::stream<unsigned char>(std::move(o)), container(nullptr), prev(nullptr), next(nullptr) {}

    inline stream::stream(const collection::stream<unsigned char> & o) : collection::stream<unsigned char>(o), container(nullptr), prev(nullptr), next(nullptr) {}

    inline stream::stream(collection::stream<unsigned char> && o) noexcept : collection::stream<unsigned char>(std::move(o)), container(nullptr), prev(nullptr), next(nullptr) {}

    inline stream & stream::operator=(const stream & o) {
        collection::stream<unsigned char>::operator=(o);
        return *this;
    }

    inline stream & stream::operator=(stream && o) noexcept {
        collection::stream<unsigned char>::operator=(std::move(o));
        return *this;
    }

    inline stream & stream::operator=(const collection::stream<unsigned char> & o) {
        collection::stream<unsigned char>::operator=(o);
        return *this;
    }

    inline stream & stream::operator=(collection::stream<unsigned char> && o) noexcept {
        collection::stream<unsigned char>::operator=(std::move(o));
        return *this;
    }

}

#include <pokemonism/sdk/stream/buffer.hh>

#endif // __POKEMONISM_SDK_STREAM_HH__