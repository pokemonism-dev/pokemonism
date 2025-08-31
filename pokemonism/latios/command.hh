/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_LATIOS_COMMAND_HH__
#define   __POKEMONISM_LATIOS_COMMAND_HH__

#include <pokemonism.hh>

#include <pokemonism/pokemon/command.hh>

namespace pokemonism {
    namespace latios {

        // class command : public pokemon::command {
        // public:     struct output : public pokemon::command::output {};
        // public:     struct type {
        //             public:     constexpr static int execute    = 0;
        //             };
        // public:     class message : public pokemon::command::message {
        //             public:     const command::output * peak(void) const override = 0;
        //             public:     message(void) {}
        //             public:     ~message(void) override {}
        //             public:     message(const message & o) = delete;
        //             public:     message(message && o) noexcept = delete;
        //             public:     message & operator=(const message & o) = delete;
        //             public:     message & operator=(message && o) noexcept = delete;
        //             };
        // public:     struct envelope : public pokemon::command::envelope {
        //             public:     const command::message * peak(void) const override = 0;
        //             public:     envelope(void) {}
        //             public:     ~envelope(void) override {}
        //             public:     envelope(const envelope & o) = delete;
        //             public:     envelope(envelope && o) noexcept = delete;
        //             public:     envelope & operator=(const envelope & o) = delete;
        //             public:     envelope & operator=(envelope && o) noexcept = delete;
        //             };
        // public:     struct callback : public pokemon::command::callback {
        //             public:     typedef int (*type)(command &, uint32, command::envelope *);
        //             };
        // public:     command::output * operator()(void) override = 0;
        // public:     command(void) {}
        // public:     ~command(void) override {}
        // public:     command(const command & o) = delete;
        // public:     command(command && o) noexcept = delete;
        // public:     command & operator=(const command & o) = delete;
        // public:     command & operator=(command && o) noexcept = delete;
        // };

    }
}

#endif // __POKEMONISM_LATIOS_COMMAND_HH__