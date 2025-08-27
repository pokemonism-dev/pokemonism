/**
 * @file        pokemon/promise.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#ifndef   __POKEMONISM_POKEMON_PROMISE__HH__
#define   __POKEMONISM_POKEMON_PROMISE__HH__

#include <pokemon/future.hh>

namespace pokemon {
    // template <typename return_type, typename first_type, typename... argument_type_list>
    // struct promise {
    // public:     typedef declaration::type::function<void (throwable &&)>                                catcher;
    // public:     typedef declaration::type::function<return_type (first_type, argument_type_list...)>    callback;
    // public:     class original : public future<first_type>::original {
    //             private:    static const original failure;
    //             public:     constexpr static const original & fail = failure;
    //             protected:  virtual void replay(void) { develop_quick_throw(rejected::operation::exception, (void)(0)); }
    //             public:     virtual void set(const callback & on, const catcher & exception) { exception(rejected::operation::exception("failure operation", __FILE__, __LINE__, __func__)); }
    //             public:     original(const callback & on, const catcher & exception) { exception(rejected::operation::exception("failure operation", __FILE__, __LINE__, __func__)); }
    //             public:     original(void) {}
    //             public:     virtual ~original(void) {}
    //             public:     original(const original & o) = delete;
    //             public:     original(original && o) noexcept = delete;
    //             public:     original & operator=(const original & o) = delete;
    //             public:     original & operator=(original && o) noexcept = delete;
    //             public:     friend class promise;
    //             };
    // protected:  const original & origin;
    // public:     inline void set(const callback & on, const catcher & exception) { origin.set(on, exception); }
    // public:     inline explicit promise(const original & origin) : origin(origin) {
    //                 if (origin.done()) origin.replay();
    //             }
    // public:     inline promise(const promise & o) : origin(o.origin) {
    //                 if (origin.done()) origin.replay();
    //             }
    // public:     inline promise(promise && o) noexcept : origin(std::move(o.origin)) {
    //                 if (origin.done()) origin.replay();
    //             }
    // public:     inline promise & operator=(const promise & o) {
    //                 if (pointof(o) != this) origin = o.origin;
    //                 return *this;
    //             }
    // public:     inline promise & operator=(promise && o) noexcept {
    //                 if (pointof(o) != this) origin = std::move(o.origin);
    //                 return *this;
    //             }
    // public:     promise(void) = delete;
    // };
    //
    // template <typename return_type, typename first_type, typename... argument_type_list>
    // const promise<return_type, first_type, argument_type_list...>::original failure;
}

#endif // __POKEMONISM_POKEMON_PROMISE__HH__