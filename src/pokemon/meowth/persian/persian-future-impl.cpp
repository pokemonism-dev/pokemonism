/**
 * @file        pokemon/future.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#include <pokemonism.hh>

#include <pokemon/exception.hh>
#include <pokemon/typographer.hh>
#include <pokemon/reference.hh>

using namespace pokemon;

namespace pokemonImpl {

    namespace futurable {
        namespace mask {
            enum type {
                none = 0,
                wrap = 1,
                object = 2
            };
        }

        //
        // typedef enum mask mask;

        template <typename element>
        struct wrap final {
        public:     typedef element         declaration_type;
        public:     typedef declaration::type::function<void (declaration_type &)>              observer_type;
        public:     typedef declaration::type::function<void (throwable &&)>                    exception_catcher_type;
        public:     struct immutable {
                        typedef declaration::type::function<void (const declaration_type &)>    observer_type;
                    };
        public:     inline futurable::mask::type state(void) const;
        public:     inline declaration_type & get(void);
        public:     inline const declaration_type & get(void) const;
        public:     inline void observe(const observer_type & observer, const exception_catcher_type & catcher);
        public:     inline void observe(const immutable::observer_type & observer, const exception_catcher_type & catcher);
        };

        template <typename element>
        class object {
        public:     typedef element         declaration_type;
        public:     typedef declaration::type::function<void (declaration_type &)>              observer_type;
        public:     typedef declaration::type::function<void (throwable &&)>                    exception_catcher_type;
        public:     struct immutable {
                        typedef declaration::type::function<void (const declaration_type &)>    observer_type;
                    };
        public:     virtual inline bool cancel(void);
        public:     inline futurable::mask::type state(void) const;
        public:     inline declaration_type & get(void);
        public:     inline const declaration_type & get(void) const;
        public:     inline void observe(const observer_type & observer, const exception_catcher_type & catcher);
        public:     inline void observe(const immutable::observer_type & observer, const exception_catcher_type & catcher);

        };

        template <typename element>
        union variety {
        public:     typedef element                                 declaration_type;
        public:     futurable::wrap<declaration_type>               wrap;
                    reference<futurable::object<declaration_type>>  reference;
                    declaration_type                                value;
        public:     inline variety(void) : value() {}
        };
    }

    template <typename element>
    struct future final {
    public:     typedef element                                                             declaration_type;
    public:     typedef declaration::type::function<void (declaration_type &)>              observer_type;
    public:     typedef declaration::type::function<void (throwable &&)>                    exception_catcher_type;
    public:     struct immutable {
                    typedef declaration::type::function<void (const declaration_type &)>    observer_type;
                };
    public:     enum state {
                    none = 0,
                    observable = 1,
                    complete = 2,
                    exceptional = 3
                };
    public:     union variable {
                public:     int                                                 value;
                            futurable::wrap<declaration_type>                   wrap;
                            ::reference<futurable::object<declaration_type>>    reference;
                public:     explicit variable(const declaration_type & v) : value(v) {}
                public:     explicit variable(declaration_type && v) noexcept : value(std::move(v)) {}
                public:     variable() : value(0) {}
                public:     explicit variable(const futurable::wrap<declaration_type> & o) : wrap(o) {}
                public:     explicit variable(futurable::wrap<declaration_type> && o) noexcept : wrap(std::move(o)) {}
                public:     explicit variable(const ::reference<futurable::object<declaration_type>> & o) : reference(o) {}
                public:     explicit variable(::reference<futurable::object<declaration_type>> && o) noexcept : reference(std::move(o)) {}
                public:     variable & operator=(const futurable::wrap<declaration_type> & o) {
                                wrap = o;
                                return *this;
                            }
                public:     variable & operator=(futurable::wrap<declaration_type> && o) noexcept {
                                wrap = std::move(o);
                                return this;
                            }
                public:     variable & operator=(const ::reference<futurable::object<declaration_type>> & o) {
                                reference = o;
                                return *this;
                            }
                public:     variable & operator=(::reference<futurable::object<declaration_type>> && o) noexcept {
                                reference = o;
                                return *this;
                            }
                public:     variable & operator=(const declaration_type & v) {
                                value = v;
                                return *this;
                            }
                public:     variable & operator=(declaration_type && v) noexcept {
                                value = std::move(v);
                                return *this;
                            }
                public:     ~variable() {}
                };
    private:    uint64 mask;
    private:    variable variable;
    public:     inline bool cancel(void) const {
                    if (mask == futurable::mask::object && variable.reference != nil) return variable.reference.cancel();
                    return false;
                }
    public:     inline state state(void) const {
                    if (mask == futurable::mask::object) {
                        if (variable.reference == nil) return exceptional;
                        return variable.reference.state();
                    }
                    if (mask == futurable::mask::wrap) return variable.wrap.state();
                    return none;
                }
    public:     inline declaration_type & get(void) {
                    if (mask == futurable::mask::object) return variable.reference.get();
                    if (mask == futurable::mask::wrap) return variable.wrap.get();

                    critical_quick_throw(exceptional::uninitialized::object, exit(0));
                }
    public:     inline const declaration_type & get(void) const {
                    if (mask == futurable::mask::object) return variable.reference.get();
                    if (mask == futurable::mask::wrap) return variable.wrap.get();

                    critical_quick_throw(exceptional::uninitialized::object, exit(0));
                }
    public:     inline void observe(const observer_type & observer, const exception_catcher_type & catcher) {
                    if (mask == futurable::mask::object) return variable.reference.observe(observer, catcher);
                    if (mask == futurable::mask::wrap) return variable.wrap.observe(observer, catcher);

                    catcher(exceptional::uninitialized::object());
                }
    public:     inline void observe(const immutable::observer_type & observer, const exception_catcher_type & catcher) {
                    if (mask == futurable::mask::object) return variable.reference.observe(observer, catcher);
                    if (mask == futurable::mask::wrap) return variable.wrap.observe(observer, catcher);

                    catcher(exceptional::failure::operation());
                }
    public:     inline future(void) : mask(none), variable() {}
    public:     inline explicit future(const futurable::wrap<declaration_type> & wrap) : mask(futurable::mask::wrap), variable(wrap) {}
    public:     inline explicit future(futurable::wrap<declaration_type> && wrap) : mask(futurable::mask::wrap), variable(std::move(wrap)) {}
    public:     inline explicit future(const reference<futurable::object<declaration_type>> & reference) : mask(futurable::mask::object), variable(reference) {}
    public:     inline explicit future(reference<futurable::object<declaration_type>> && reference) : mask(futurable::mask::object), variable(std::move(reference)) {}
    public:     inline ~future(void) {}
    public:     inline future(const future<declaration_type> & o) : mask(o.mask), variable() {
                    if (mask == futurable::mask::object) {
                        variable.reference = o.variable.reference;
                    } else if (mask == futurable::mask::wrap) {
                        variable.wrap = o.variable.wrap;
                    }
                }
    public:     inline future(future<declaration_type> && o) noexcept : mask(o.mask), variable() {
                    if (mask == futurable::mask::object) {
                        variable.reference = std::move(o.variable.reference);
                    } else if (mask == futurable::mask::wrap) {
                        variable.wrap = std::move(o.variable.wrap);
                    }
                }
    public:     inline future<declaration_type> & operator=(const future<declaration_type> & o) {
                    if (&o != this) {
                        if (mask == futurable::mask::object) {
                            variable.reference = o.variable.reference;
                        } else if (mask == futurable::mask::wrap) {
                            variable.wrap = o.variable.wrap;
                        } else {
                            variable.value = o.variable.value;
                        }
                    }
                    return *this;
                }
    public:     inline future<declaration_type> & operator=(future<declaration_type> && o) noexcept {
                    if (&o != this) {
                        if (mask == futurable::mask::object) {
                            variable.reference = std::move(o.variable.reference);
                        } else if (mask == futurable::mask::wrap) {
                            variable.wrap = std::move(o.variable.wrap);
                        } else {
                            variable.value = std::move(o.variable.value);
                        }
                    }
                    return *this;
                }
    };
}

using namespace pokemonImpl;

int main(int argc, char ** argv) {
    {
        printf("sizeof() => %ld\n", sizeof(reference<int>));
        printf("sizeof(future<int>) => %ld\n", sizeof(future<int>));
        future<int> o;
    }
    // future<int> o;
}