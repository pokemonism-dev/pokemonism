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
#include <pokemonism/sdk/interface/descriptor.hh>
#include <pokemonism/sdk/interface/input/stream.hh>
#include <pokemonism/sdk/interface/output/stream.hh>

namespace pokemonism::sdk {

    class protocol;

    class stream : public collection::stream<unsigned char> {
    public:     class buffer;
    public:     struct state {
                public:     constexpr static unsigned int none = (0x00000000U <<  0U);
                public:     struct prepare {
                            public:     constexpr static unsigned int begin = (0x00000001U <<  0U);
                            public:     constexpr static unsigned int end   = (0x00000001U <<  7U);
                            };
                public:     struct process {
                            public:     constexpr static unsigned int begin = (0x00000001U <<  8U);
                            public:     constexpr static unsigned int end   = (0x00000001U << 15U);
                            };
                public:     struct package {
                            public:     constexpr static unsigned int begin = (0x00000001U << 16U);
                            public:     constexpr static unsigned int end   = (0x00000001U << 23U);
                            };
                public:     struct publish {
                            public:     constexpr static unsigned int begin = (0x00000001U << 24U);
                            public:     constexpr static unsigned int move  = (0x00000001U << 29U);
                            public:     constexpr static unsigned int end   = (0x00000001U << 30U);
                            public:     constexpr static unsigned int rel   = (0x00000001U << 31U);
                            };
                };
    public:     template <class descriptorable = pokemonism::sdk::interface::descriptor> class input;
    public:     template <class descriptorable = pokemonism::sdk::interface::descriptor> class output;
    protected:  stream::buffer *    container;
    protected:  stream *            prev;
    protected:  stream *            next;
    protected:  unsigned int        status;
    public:     virtual void unlink(void);
    public:     virtual void stateSet(unsigned int v);
    public:     inline virtual void onState(unsigned int previous, unsigned int state);
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
    public:     inline stream(const char * format, va_list ap);
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
    public:     friend protocol;
    public:     friend linked::list<stream::buffer, stream>;
    public:     template <class descriptorable> friend class pokemonism::sdk::interface::input::stream;
    };

    class stream::buffer : public synchronizable {
    public:     constexpr static unsigned long defaultPage = 8192;
    public:     using collection = linked::list<stream::buffer, stream>;
    protected:  unsigned long   size;
    protected:  stream *        head;
    protected:  stream *        tail;
    protected:  unsigned long   page;
    protected:  stream *        prepare;
    protected:  stream *        process;
    protected:  stream *        publish;
    public:     inline unsigned long pageGet(void) const;
    protected:  inline int lock(void) noexcept override { return declaration::fail; }
    protected:  inline int unlock(void) noexcept override { return declaration::fail; }
    protected:  inline int wait(void) noexcept override { return declaration::fail; }
    protected:  inline int wakeup(void) noexcept override { return declaration::fail; }
    protected:  inline int wait(long second, long nano) noexcept override { return declaration::fail; }
    protected:  inline int wakeup(bool all) noexcept override { return declaration::fail; }
    public:     inline virtual stream::buffer * clone(void) const;
    public:     inline virtual stream * frontGet(void);
    public:     inline virtual stream * streamGet(unsigned long n);
    public:     inline virtual stream * headGet(void) const;
    public:     inline virtual stream * prepareGet(void);
    public:     inline virtual stream * processGet(void);
    public:     inline virtual stream * publishGet(void);
    public:     virtual void trash(void);
    public:     inline virtual void shrink(void);
    public:     inline virtual void fit(void);
    public:     virtual void clear(void);
    public:     virtual void clean(void);
    public:     virtual void reset(void);
    public:     virtual stream * add(stream * node);
    public:     virtual stream * del(stream * node);
    public:     virtual stream * gen(void);
    public:     inline explicit buffer(unsigned long page);
    public:     inline buffer(void);
    public:     inline ~buffer(void) override;
    public:     buffer(const stream::buffer & o) = delete;
    public:     buffer(stream::buffer && o) noexcept = delete;
    public:     stream::buffer & operator=(const stream::buffer & o) = delete;
    public:     stream::buffer & operator=(stream::buffer && o) noexcept = delete;
    public:     friend collection;
    };

    template <class descriptorable>
    class stream::input : public pokemonism::sdk::interface::input::stream<descriptorable> {
    public:     typedef pokemonism::sdk::interface::input::stream<descriptorable>::type type;
    protected:  pokemonism::sdk::stream::buffer * in;
    protected:  void clear(void) override;
    protected:  void clean(void) override;
    protected:  void reset(void) override;
    protected:  long read(unsigned char * storage, unsigned long capacity) override;
    protected:  long read(void) override;
    protected:  long read(pokemonism::sdk::stream & node) override;
    public:     inline bool readable(void) const override;
    public:     inline explicit input(unsigned int properties);
    public:     inline input(stream::input<descriptorable>::type value, unsigned int properties);
    public:     inline input(void);
    public:     inline ~input(void) override;
    public:     input(const stream::input<descriptorable> & o) = delete;
    public:     input(stream::input<descriptorable> && o) noexcept = delete;
    public:     stream::input<descriptorable> & operator=(const stream::input<descriptorable> & o) = delete;
    public:     stream::input<descriptorable> & operator=(stream::input<descriptorable> && o) noexcept = delete;
    };

    template <class descriptorable>
    class stream::output : public pokemonism::sdk::interface::output::stream<descriptorable> {
    public:     typedef pokemonism::sdk::interface::output::stream<descriptorable>::type type;
    protected:  pokemonism::sdk::stream::buffer * out;
    protected:  void clear(void) override;
    protected:  void clean(void) override;
    protected:  void reset(void) override;
    protected:  long write(const unsigned char * storage, unsigned long n) override;
    protected:  long write(void) override;
    protected:  long write(pokemonism::sdk::stream & node) override;
    public:     inline bool writeable(void) const override;
    public:     inline explicit output(unsigned int properties);
    public:     inline output(stream::output<descriptorable>::type value, unsigned int properties);
    public:     inline output(void);
    public:     inline ~output(void) override;
    public:     output(const stream::output<descriptorable> & o) = delete;
    public:     output(stream::output<descriptorable> && o) noexcept = delete;
    public:     stream::output<descriptorable> & operator=(const stream::output<descriptorable> & o) = delete;
    public:     stream::output<descriptorable> & operator=(stream::output<descriptorable> && o) noexcept = delete;
    };

    inline void stream::onState(unsigned int previous, unsigned int state) {

    }

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

    inline stream::stream(const char * format, va_list ap) : container(nullptr), prev(nullptr), next(nullptr), status(stream::state::prepare::begin) {
        capacity = size = vasprintf(reinterpret_cast<char **>(pointof(storage)), format, ap);
    }

    inline stream::stream(unsigned char item, unsigned long n) : collection::stream<unsigned char>(item, n), container(nullptr), prev(nullptr), next(nullptr), status(stream::state::prepare::begin) {}

    inline stream::stream(const unsigned char * source, unsigned long sourceLen) : collection::stream<unsigned char>(source, sourceLen), container(nullptr), prev(nullptr), next(nullptr), status(stream::state::prepare::begin) {}

    inline stream::stream(void) : container(nullptr), prev(nullptr), next(nullptr), status(stream::state::prepare::begin) {}

    inline stream::stream(const stream & o) : collection::stream<unsigned char>(o), container(nullptr), prev(nullptr), next(nullptr), status(o.status) {}

    inline stream::stream(stream && o) noexcept : collection::stream<unsigned char>(std::move(o)), container(nullptr), prev(nullptr), next(nullptr), status(o.status) {
        o.status = o.status | stream::state::publish::move;
    }

    inline stream::stream(const collection::stream<unsigned char> & o) : collection::stream<unsigned char>(o), container(nullptr), prev(nullptr), next(nullptr), status(stream::state::prepare::begin) {}

    inline stream::stream(collection::stream<unsigned char> && o) noexcept : collection::stream<unsigned char>(std::move(o)), container(nullptr), prev(nullptr), next(nullptr), status(stream::state::prepare::begin) {}

    inline stream & stream::operator=(const stream & o) {
        if (pointof(o) != this) {
            collection::stream<unsigned char>::operator=(o);

            status = o.status;
        }
        return *this;
    }

    inline stream & stream::operator=(stream && o) noexcept {
        if (pointof(o) != this) {
            collection::stream<unsigned char>::operator=(std::move(o));

            status = o.status;

            o.status = (o.status | stream::state::publish::move);
        }
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

    inline unsigned long stream::buffer::pageGet(void) const {
        return page;
    }

    inline stream::buffer * stream::buffer::clone(void) const {
        return new stream::buffer(page);
    }

    inline stream * stream::buffer::frontGet(void) {
        while (process != nullptr && process->status & stream::state::process::end && process->next != nullptr) process = process->next;

        return (process != nullptr && process->status & stream::state::process::begin) ? process : nullptr;
    }

    inline stream * stream::buffer::streamGet(unsigned long n) {
        while (prepare != nullptr && prepare->status & stream::state::prepare::end) prepare = prepare->next;

        if (prepare == nullptr) prepare = gen();

        prepare->grow(n);

        return prepare;
    }

    inline stream * stream::buffer::headGet(void) const {
        return head;
    }

    inline stream * stream::buffer::prepareGet(void) {
        while (prepare != nullptr && prepare->status & stream::state::prepare::end) prepare = prepare->next;

        return prepare;
    }

    inline stream * stream::buffer::processGet(void) {
        return frontGet();
    }

    inline stream * stream::buffer::publishGet(void) {
        while (publish != nullptr && publish->status & stream::state::publish::end && publish->next != nullptr) publish = publish->next;

        return (publish != nullptr && publish->status & stream::state::publish::begin) ? publish : nullptr;
    }

    inline void stream::buffer::shrink(void) {

    }

    inline void stream::buffer::fit(void) {
        trash();
        shrink();
    }

    stream::buffer::buffer(void) : size(declaration::zero), head(nullptr), tail(nullptr), page(defaultPage), prepare(nullptr), process(nullptr), publish(nullptr) {

    }

    stream::buffer::buffer(unsigned long page) : size(declaration::zero), head(nullptr), tail(nullptr), page(page == 0 ? defaultPage : page), prepare(nullptr), process(nullptr), publish(nullptr) {

    }

    stream::buffer::~buffer(void) {
        // ReSharper disable once CppVirtualFunctionCallInsideCtor
        clear();

        page = declaration::zero;
    }

    template <class descriptorable>
    void stream::input<descriptorable>::clear(void) {
        in->clear();
        descriptorable::clear();
    }

    template <class descriptorable>
    void stream::input<descriptorable>::clean(void) {
        in->clean();
        descriptorable::clean();
    }

    template <class descriptorable>
    void stream::input<descriptorable>::reset(void) {
        in->reset();
        descriptorable::reset();
    }

    template <class descriptorable>
    long stream::input<descriptorable>::read(unsigned char * storage, unsigned long capacity) {
        return descriptorable::read(storage, capacity);
    }

    template <class descriptorable>
    long stream::input<descriptorable>::read(void) {
        long total = 0;

        while (pokemonism::sdk::stream * node = in->streamGet(in->pageGet())) {
            const long n = read(*node);

            if (n > 0) {
                total = total + n;

                if (node->remainGet() > 0) return total;

                continue;
            }

            if (n < 0) return n;
        }

        return total;
    }

    template <class descriptorable>
    long stream::input<descriptorable>::read(pokemonism::sdk::stream & node) {
        const long n = read(node.storage + node.size, node.remainGet());

        this->onStreamIn(node, n);

        if (n > 0) node.size = node.size + n;

        return n;
    }

    template <class descriptorable>
    inline bool stream::input<descriptorable>::readable(void) const {
        return true;
    }

    template <class descriptorable>
    inline stream::input<descriptorable>::input(void) : in(new stream::buffer()) {

    }

    template <class descriptorable>
    inline stream::input<descriptorable>::input(unsigned int properties) : pokemonism::sdk::interface::input::stream<descriptorable>(properties), in(new stream::buffer()) {

    }

    template <class descriptorable>
    inline stream::input<descriptorable>::input(stream::input<descriptorable>::type value, unsigned int properties) : pokemonism::sdk::interface::input::stream<descriptorable>(value, properties), in(new stream::buffer()) {
        if (this->value > declaration::invalid) this->status = this->status | pokemonism::sdk::interface::input::stream<descriptorable>::state::in;
    }

    template <class descriptorable>
    inline stream::input<descriptorable>::~input(void) {
        in = allocator::del(in);
    }

    template <class descriptorable>
    void stream::output<descriptorable>::clear(void) {
        out->clear();
        descriptorable::clear();
    }

    template <class descriptorable>
    void stream::output<descriptorable>::clean(void) {
        out->clean();
        descriptorable::clean();
    }

    template <class descriptorable>
    void stream::output<descriptorable>::reset(void) {
        out->reset();
        descriptorable::reset();
    }

    template <class descriptorable>
    long stream::output<descriptorable>::write(const unsigned char * storage, unsigned long n) {
        return descriptorable::write(storage, n);
    }

    template <class descriptorable>
    long stream::output<descriptorable>::write(void) {
        long total = 0;
        while (pokemonism::sdk::stream * node = out->frontGet()) {
            if (node->lengthGet() > 0) {
                const long n = write(*node);

                if (n > 0) {
                    total = total + n;

                    continue;
                }

                if (n < 0) return n;
            }
            break;
        }

        return total;
    }

    template <class descriptorable>
    long stream::output<descriptorable>::write(pokemonism::sdk::stream & node) {
        const long n = write(node.frontGet(), node.lengthGet());

        this->onStreamOut(node, n);

        if (n > 0) node.pop(n);

        return n;
    }

    template <class descriptorable>
    inline bool stream::output<descriptorable>::writeable(void) const {
        return true;
    }

    template <class descriptorable>
    inline stream::output<descriptorable>::output(unsigned int properties) : pokemonism::sdk::interface::output::stream<descriptorable>(properties), out(new stream::buffer()) {
    }

    template <class descriptorable>
    inline stream::output<descriptorable>::output(stream::output<descriptorable>::type value, unsigned int properties) : pokemonism::sdk::interface::output::stream<descriptorable>(value, properties), out(new stream::buffer()) {
        if (this->value > declaration::invalid) this->status = this->status | pokemonism::sdk::interface::output::stream<descriptorable>::state::out;
    }

    template <class descriptorable>
    inline stream::output<descriptorable>::output(void) : out(new stream::buffer()) {

    }

    template <class descriptorable>
    inline stream::output<descriptorable>::~output(void) {
        out = allocator::del(out);
    }

}

#endif // __POKEMONISM_SDK_STREAM_HH__