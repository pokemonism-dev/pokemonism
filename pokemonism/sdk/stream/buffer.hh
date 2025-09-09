/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_STREAM_BUFFER_HH__
#define   __POKEMONISM_SDK_STREAM_BUFFER_HH__

#include <pokemonism/sdk/stream.hh>

namespace pokemonism::sdk {

    class stream::buffer : public synchronizable {
    public:     constexpr static unsigned long defaultPage = 8192;
    public:     typedef stream * (*factory)(stream::buffer *);
    public:     using collection = linked::list<stream::buffer, stream>;
    protected:  unsigned long   size;
    protected:  stream *        head;
    protected:  stream *        tail;
    protected:  unsigned long   page;
    protected:  factory         gen;
    public:     inline unsigned long pageGet(void) const;
    protected:  inline int lock(void) noexcept override { return declaration::fail; }
    protected:  inline int unlock(void) noexcept override { return declaration::fail; }
    protected:  inline int wait(void) noexcept override { return declaration::fail; }
    protected:  inline int wakeup(void) noexcept override { return declaration::fail; }
    protected:  inline int wait(long second, long nano) noexcept override { return declaration::fail; }
    protected:  inline int wakeup(bool all) noexcept override { return declaration::fail; }
    public:     inline virtual stream::buffer * clone(void) const;
    public:     inline virtual stream * frontGet(void);
    public:     virtual stream * untilGet(unsigned long n);
    public:     inline virtual stream * backGet(void);
    public:     stream * streamGet(unsigned long n);
    public:     inline virtual stream * headGet(void) const;
    public:     inline virtual bool empty(void) const;
    public:     inline virtual bool exist(void) const;
    public:     virtual void trash(void);
    public:     virtual void shrink(void);
    public:     virtual void fit(void);
    public:     virtual void clear(void);
    public:     virtual void clean(void);
    public:     virtual void reset(void);
    public:     virtual stream * add(stream * node);
    public:     virtual stream * del(stream * node);
    public:     inline explicit buffer(unsigned long page, stream * (*factory)(stream::buffer *) = stream::factory);
    public:     inline buffer(void);
    public:     inline ~buffer(void) override;
    public:     buffer(const stream::buffer & o) = delete;
    public:     buffer(stream::buffer && o) noexcept = delete;
    public:     stream::buffer & operator=(const stream::buffer & o) = delete;
    public:     stream::buffer & operator=(stream::buffer && o) noexcept = delete;
    public:     friend collection;
    };

    inline unsigned long stream::buffer::pageGet(void) const {
        return page;
    }

    inline stream::buffer * stream::buffer::clone(void) const {
        return new stream::buffer(page, gen);
    }

    inline stream * stream::buffer::frontGet(void) {
        trash();

        return head;
    }

    inline stream * stream::buffer::backGet(void) {
        shrink();

        return tail;
    }

    inline stream * stream::buffer::headGet(void) const {
        return head;
    }

    inline bool stream::buffer::empty(void) const {
        for (const stream * node = head; node != nullptr; node = node->next) {
            if (node->lengthGet() > 0) return false;
        }
        return true;
    }

    inline bool stream::buffer::exist(void) const {
        for (const stream * node = head; node != nullptr; node = node->next) {
            if (node->lengthGet() > 0) return true;
        }
        return false;
    }

    stream::buffer::buffer(void) : size(declaration::zero), head(nullptr), tail(nullptr), page(defaultPage), gen(stream::factory) {

    }

    stream::buffer::buffer(unsigned long page, stream * (*factory)(stream::buffer *)) : size(declaration::zero), head(nullptr), tail(nullptr), page(page == 0 ? defaultPage : page), gen(factory) {

    }

    stream::buffer::~buffer(void) {
        // ReSharper disable once CppVirtualFunctionCallInsideCtor
        clear();

        gen = nullptr;
        page = declaration::zero;
    }




}

#endif // __POKEMONISM_SDK_STREAM_BUFFER_HH__