/**
 * @file            pokemonism/sdk/synchronizable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_SDK_SYNCHRONIZABLE_HH__
#define   __POKEMONISM_SDK_SYNCHRONIZABLE_HH__

namespace pokemonism::sdk {

    class synchronizable {
    public:     virtual int lock(void) noexcept = 0;
    public:     virtual int unlock(void) noexcept = 0;
    public:     virtual int wait(void) noexcept = 0;
    public:     virtual int wakeup(void) noexcept = 0;
    public:     virtual int wait(long second, long nano) noexcept = 0;
    public:     virtual int wakeup(bool all) noexcept = 0;
    public:     synchronizable(void) {}
    public:     virtual ~synchronizable(void) {}
    public:     synchronizable(const synchronizable & o) = delete;
    public:     synchronizable(synchronizable && o) noexcept = delete;
    public:     synchronizable & operator=(const synchronizable & o) = delete;
    public:     synchronizable & operator=(synchronizable && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_SYNCHRONIZABLE_HH__