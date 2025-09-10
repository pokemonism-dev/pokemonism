/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 09, 2025
 */

#ifndef   __POKEMONISM_SDK_CONTEXT_HH__
#define   __POKEMONISM_SDK_CONTEXT_HH__

#include <pokemonism/sdk/stream.hh>
#include <pokemonism/sdk/collection/continuous.hh>

namespace pokemonism::sdk {

    class context : public stream {
    public:     struct state : public stream::state {
                public:     struct prepare : public stream::state::prepare {
                            public:     constexpr static unsigned int begin = stream::state::prepare::begin;    // (0x00000001U <<  0U)
                            public:     constexpr static unsigned int end   = stream::state::prepare::end;      // (0x00000001U <<  8U);
                            };
                public:     struct process : public stream::state::process {
                            public:     constexpr static unsigned int begin = stream::state::process::begin;    // (0x00000001U <<  8U);
                            public:     constexpr static unsigned int end   = stream::state::process::end;      // (0x00000001U << 16U);
                            };
                public:     struct package : public stream::state::package {
                            public:     constexpr static unsigned int begin = stream::state::package::begin;    // (0x00000001U << 16U);
                            public:     constexpr static unsigned int end   = stream::state::package::end;      // (0x00000001U << 23U);
                            };
                public:     struct publish : public stream::state::publish {
                            public:     constexpr static unsigned int begin = stream::state::publish::begin;    // (0x00000001U << 24U);
                            public:     constexpr static unsigned int move  = stream::state::publish::move;     // (0x00000001U << 29U);
                            public:     constexpr static unsigned int end   = stream::state::publish::end;      // (0x00000001U << 30U);
                            public:     constexpr static unsigned int rel   = stream::state::publish::rel;      // (0x00000001U << 31U);
                            };
                };
    public:     struct property {
                public:     struct type {
                            public:     constexpr static unsigned int none     = 0;
                            public:     constexpr static unsigned int request  = 1;
                            public:     constexpr static unsigned int response = 2;
                            };

                };
    public:     class buffer;
    protected:  unsigned int                        properties;
    protected:  context *                           parent;
    protected:  collection::continuous<context *>   children;
    public:     explicit context(context::buffer * container);
    public:     context(unsigned char item, unsigned long n);
    public:     context(const unsigned char * source, unsigned long sourceLen);
    public:     context(void);
    public:     ~context(void) override;
    public:     context(const context & o);
    public:     context(context && o) noexcept;
    public:     context & operator=(const context & o);
    public:     context & operator=(context && o) noexcept;
    public:     explicit context(const stream & o);
    public:     explicit context(stream && o) noexcept;
    public:     context & operator=(const stream & o) override;
    public:     context & operator=(stream && o) noexcept override;
    public:     explicit context(const collection::stream<unsigned char> & o);
    public:     explicit context(collection::stream<unsigned char> && o) noexcept;
    public:     context & operator=(const collection::stream<unsigned char> & o) override;
    public:     context & operator=(collection::stream<unsigned char> && o) noexcept override;
    };

}

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/sdk/context/buffer.hh>

#endif // __POKEMONISM_SDK_CONTEXT_HH__