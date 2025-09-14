/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_WINDOW_HH__
#define   __POKEMONISM_WINDOW_WINDOW_HH__

namespace pokemonism::window {

    class window {
    public:     struct rectangle;
    public:     virtual int create(void) = 0;
    public:     virtual int destroy(void) = 0;
    protected:  inline window(void);
    protected:  inline virtual ~window(void);
    public:     inline window(const window & o);
    public:     inline window(window && o) noexcept;
    public:     inline window & operator=(const window & o);
    public:     inline window & operator=(window && o) noexcept;
    };

    inline window::window(void) {

    }

    inline window::~window(void) {

    }

    inline window::window(const window & o) {

    }

    inline window::window(window && o) noexcept {

    }

    inline window & window::operator=(const window & o) {
        return *this;
    }

    inline window & window::operator=(window && o) noexcept {
        return *this;
    }

}

#endif // __POKEMONISM_WINDOW_WINDOW_HH__