/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_CONSOLE_HH__
#define   __POKEMONISM_SDK_CONSOLE_HH__

#include <pokemonism/sdk/stream.hh>
#include <pokemonism/sdk/generic/descriptorable/unix.hh>

namespace pokemonism::sdk {

    class console {
    public:     class input;
    public:     class output;
    public:     static console::input & in;
    public:     static console::output & out;
    public:     console(void) {}
    public:     virtual ~console(void) {}
    public:     console(const console & o) = delete;
    public:     console(console && o) noexcept = delete;
    public:     console & operator=(const console & o) = delete;
    public:     console & operator=(console && o) noexcept = delete;
    };

    class console::input : public generic::descriptor<pokemonism::sdk::stream::input<interface::output::stream<generic::descriptorable::unix<>>>> {
    public:     static console::input & get(void);
    private:    input(void);
    public:     ~input(void) override;
    public:     input(const console::input & o) = delete;
    public:     input(console::input && o) noexcept = delete;
    public:     console::input & operator=(const console::input & o) = delete;
    public:     console::input & operator=(console::input && o) noexcept = delete;
    };

    class console::output : public generic::descriptor<interface::input::stream<pokemonism::sdk::stream::output<generic::descriptorable::unix<>>>> {
    public:     static console::output & get(void);
    public:     virtual long operator()(char c);
    public:     virtual long operator()(const char * s);
    private:    output(void);
    public:     ~output(void) override;
    public:     output(const console::output & o) = delete;
    public:     output(console::output && o) noexcept = delete;
    public:     console::output & operator=(const console::output & o) = delete;
    public:     console::output & operator=(console::output && o) noexcept = delete;
    };

    inline console::input::input(void) : generic::descriptor<pokemonism::sdk::stream::input<interface::output::stream<generic::descriptorable::unix<>>>>(STDIN_FILENO, interface::descriptor::property::console::input) {

    }

    inline console::input::~input(void) {

    }





}

#endif // __POKEMONISM_SDK_CONSOLE_HH__