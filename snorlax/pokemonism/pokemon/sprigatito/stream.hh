/**
 * @file        pokemon/sprigatito/stream.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_STREAM__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_STREAM__HH__

#include <pokemon/memorizer.hh>
#include <pokemon/typographer.hh>
#include <pokemon/sprigatito/streamable.hh>
#include <pokemon/sprigatito/continuation.hh>

namespace pokemon { namespace sprigatito {

    template <typename element_type, typename primitive_tag = typographer<element_type>::primitive, typename character_tag = typographer<element_type>::character, uint64 unit = typographer<element_type>::width>
    class stream : public continuation<element_type, primitive_tag, character_tag, unit>, public virtual streamable<element_type> {
    public:     typedef element_type        element;
    public:     typedef primitive_tag       primitive;
    public:     typedef character_tag       character;
    public:     constexpr static uint64     width = unit;
    public:     using                       memorizer = continuation<element_type, primitive_tag, character_tag, unit>::memorizer;
    protected:  uint64                      pos;
    /** streamable<element> */
    public:     inline uint64 position(void) const override;
    public:     stream(void);
    public:     ~stream(void) override;
    public:     stream(const stream<element, primitive, character, unit> & o);
    public:     stream(stream<element, primitive, character, unit> && o) noexcept;
    public:     stream<element, primitive, character, unit> & operator=(const stream<element, primitive, character, unit> & o);
    public:     stream<element, primitive, character, unit> & operator=(stream<element, primitive, character, unit> && o) noexcept;
    };

    template <typename element, typename primitive, typename character, uint64 unit>
    stream<element, primitive, character, unit>::stream() : continuation<element, primitive, character, unit>(), pos(0) {

    }

    template <typename element, typename primitive, typename character, uint64 unit>
    stream<element, primitive, character, unit>::~stream(void) {
        pos = 0;
    }

    template <typename element, typename primitive, typename character, uint64 unit>
    stream<element, primitive, character, unit>::stream(const stream<element, primitive, character, unit> & o) : continuation<element, primitive, character, unit>(), pos(0) {
        this->storage = memorizer::gen(this->capa = o.capa);
        this->pos = o.pos;
        if (o.length() > 0) memorizer::set(this->storage + this->pos, o.storage + o.pos, o.length());
        this->len = o.len;
    }

    template <typename element, typename primitive, typename character, uint64 unit>
    stream<element, primitive, character, unit>::stream(stream<element, primitive, character, unit> && o) noexcept : continuation<element, primitive, character, unit>(std::move(o)), pos(o.pos) {
        o.pos = 0;
    }

    template <typename element, typename primitive, typename character, uint64 unit>
    stream<element, primitive, character, unit> & stream<element, primitive, character, unit>::operator=(const stream<element, primitive, character, unit> & o) {
        if (pointof(o) != this) {
            this->clean();

            this->pos = o.pos;
            if (this->capa < o.capa) this->storage = memorizer::reset(this->storage, this->capa = o.capa);
            if (o.length() > 0) memorizer::set(this->storage + this->pos, o.storage + o.pos, o.length());
            this->len = o.len;
        }
        return *this;
    }

    template <typename element, typename primitive, typename character, uint64 unit>
    stream<element, primitive, character, unit> & stream<element, primitive, character, unit>::operator=(stream<element, primitive, character, unit> && o) noexcept {
        if (pointof(o) != this) {
            this->clear();
            this->pos = o.pos;
            this->capa = o.capa;
            this->len = o.len;
            this->storage = o.storage;

            o.pos = 0;
            o.capa = 0;
            o.len = 0;
            o.storage = nullptr;
        }
        return *this;
    }

    /** streamable<element> */
    template <typename element, typename primitive, typename character, uint64 unit>
    uint64 stream<element, primitive, character, unit>::position(void) const {
        return pos;
    }

} }

#include <pokemon/sprigatito/stream.template.unsigned.char.hh>

#endif // __POKEMONISM_POKEMON_SPRIGATITO_STREAM__HH__
