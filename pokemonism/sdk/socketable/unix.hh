/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 09, 2025
 */

#ifndef   __POKEMONISM_SDK_SOCKETABLE_UNIX_HH__
#define   __POKEMONISM_SDK_SOCKETABLE_UNIX_HH__

#include <sys/socket.h>

#include <pokemonism/sdk/socketable.hh>

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/sdk/socketable.hh>
#include <pokemonism/sdk/descriptorable.hh>

namespace pokemonism::sdk {

    class socketable::unix : public descriptorable::unix<interface::socket> {
    public:     inline int shutdown(int how) override;
    public:     inline unsigned int check(unsigned int state) const override;
    protected:  inline explicit unix(type value);
    public:     inline unix(void);
    public:     inline ~unix(void) override;
    public:     unix(const socketable::unix & o) = delete;
    public:     unix(socketable::unix && o) noexcept = delete;
    public:     socketable::unix & operator=(const socketable::unix & o) = delete;
    public:     socketable::unix & operator=(socketable::unix && o) noexcept = delete;
    };

    inline int socketable::unix::shutdown(int how) {
        if (value > declaration::invalid) {
            if (::shutdown(value, how) != declaration::success) {
                // ### 20250909 | ERROR HANDLING
            }
        }

        return declaration::success;
    }

    inline unsigned int socketable::unix::check(unsigned int state) const {
        return (status & state);
    }

    inline socketable::unix::unix(type value) : descriptorable::unix<interface::socket>(value) {

    }

    inline socketable::unix::unix(void) {

    }

    inline socketable::unix::~unix(void) {

    }

}

#endif // __POKEMONISM_SDK_SOCKETABLE_UNIX_HH__