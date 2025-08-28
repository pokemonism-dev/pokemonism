/**
 * @file        pokemon/future.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#ifndef   __POKEMONISM_POKEMON_FUTURE__HH__
#define   __POKEMONISM_POKEMON_FUTURE__HH__

#include <pokemonism.hh>

#include <pokemon/exception.hh>
#include <pokemon/typographer.hh>

namespace pokemon {
    template <typename element>
    struct future final {
    public:     typedef element         declaration_type;
    public:     enum state {
                    running,
                    success,
                    fail,
                    reject,
                    uninitialized
                };
    public:     class original {
                private:    static const original failure;
                public:     constexpr static const future<declaration_type>::original & fail = failure;
                public:     virtual inline bool cancel(bool interrupt) const { return false; }
                public:     virtual inline bool done(void) const { return true; }
                public:     virtual inline bool cancelled(void) const { return false; }
                public:     virtual inline bool rejected(void) const { return true; }
                public:     virtual inline declaration_type get(void) const { fatal_quick_throw(exceptional::rejected::operation); }
                public:     virtual inline declaration_type get(int64 second, int64 nano) { fatal_quick_throw(exceptional::rejected::operation); }
                public:     virtual inline enum future<declaration_type>::state state(void) const { return state::fail; }
                public:     virtual inline void observe(const declaration::type::function<void (declaration_type &&)> & on, const declaration::type::function<void (exception &&)> & exception) {
                                if (exception) exception(exceptional::rejected::operation("failure operation", __FILE__, __LINE__, __func__));
                            }
                protected:  virtual inline void rel(void) {}
                public:     original(void) {}
                public:     virtual ~original(void) {}
                public:     original(const original & o) = delete;
                public:     original(original && o) noexcept = delete;
                public:     original & operator=(const original & o) = delete;
                public:     original & operator=(original && o) noexcept = delete;
                };
    public:     class response;
    protected:  const future<declaration_type>::original & origin;  // 래퍼런스면,... 기본 original 타입이면, ...
    public:     inline bool cancel(bool interrupt) const { return origin.cancel(interrupt); }
    public:     inline bool done(void) const { return origin.done(); }
    public:     inline bool cancelled(void) const { return origin.cancelled(); }
    public:     inline bool rejected(void) const { return origin.rejected(); }
    public:     inline declaration_type get(void) const { return origin.get(); }
    public:     inline declaration_type get(int64 second, int64 nano) const { return origin.get(second, nano); }
    public:     inline future<declaration_type>::state state(void) const { return origin.state(); }
    public:     inline void observe(const declaration::type::function<void (declaration_type &&)> & on, const declaration::type::function<void (exception &&)> & exception) {
                    origin.observe(on, exception);
                }
    public:     inline explicit future(const future<declaration_type>::original & origin) : origin(origin) {}
    public:     inline explicit future(future<declaration_type>::original && origin) : origin(std::move(origin)) {}
    public:     inline ~future(void) {}
    public:     inline future(const future<declaration_type> & o) : origin(o.origin) {}
    public:     inline future(future<declaration_type> && o) noexcept : origin(std::move(o.origin)) {}
    public:     inline future<declaration_type> & operator=(const future<declaration_type> & o) {
                    if (pointof(o) != this) origin = o.origin;
                    return *this;
                }
    public:     inline future<declaration_type> & operator=(future<declaration_type> && o) noexcept {
                    if (pointof(o) != this) origin = o.origin;
                    return *this;
                }
    public:     inline future<declaration_type> & operator=(const future<declaration_type>::original & o) {
                    origin = o;
                    return *this;
                }
    public:     inline future<declaration_type> & operator=(future<declaration_type>::original && o) noexcept {
                    origin = o;
                    return *this;
                }
    public:     future(void) = delete;
    };

    template <typename declaration_type>
    class future<declaration_type>::response : public future<declaration_type>::original {
    private:    declaration_type result;
    public:     inline bool cancel(bool interrupt) const override { return false; }
    public:     inline bool done(void) const override { return true; }
    public:     inline bool cancelled(void) const override { return false; }
    public:     inline bool rejected(void) const override { return false; }
    public:     inline declaration_type get(void) const override { return result; }
    public:     inline declaration_type get(int64 second, int64 nano) override { return result; }
    public:     inline enum future<declaration_type>::state state(void) const override { return state::success; }
    public:     inline void observe(const declaration::type::function<void (declaration_type &&)> & on, const declaration::type::function<void (exception &&)> & exception) override { on(std::move(result)); }
    public:     response(void) {
        printf("new\n");
    };
    public:     explicit response(const declaration_type & result) : result(result) {
        printf("new\n");
    }
    public:     explicit response(declaration_type && result) : result(result) {
        printf("new\n");
    }
    public:     ~response(void) override {
                    printf("destroy\n");
                }
    public:     response(const response & o) : result(o.result) {
        printf("new\n");
    }
    public:     response(response && o) noexcept : result(o.result) {
        printf("new\n");
    }
    public:     response & operator=(const response & o) {
                    if (pointof(o) != this) o.result = result;
                    return *this;
                }
    public:     response & operator=(response && o) noexcept {
                    if (pointof(o) != this) o.result = result;
                    return *this;
                }
    };
    template <typename declaration_type> const future<declaration_type>::original future<declaration_type>::original::failure;



}

#endif // __POKEMONISM_POKEMON_FUTURE__HH__