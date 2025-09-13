/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_INPUT_KEYBOARD_HH__
#define   __POKEMONISM_WINDOW_INPUT_KEYBOARD_HH__

#include <pokemonism/observable.hh>
#include <pokemonism/sdk/linked/list.hh>
#include <pokemonism/window/input/keyboard/key.hh>

namespace pokemonism::window::input {

    class KeyboardOn;

    class Keyboard : public Observable<KeyboardKey, KeyboardOn> {
    protected:  using Collection = pokemonism::sdk::LinkedList<Keyboard, KeyboardOn>;
    protected:  unsigned long size;
    protected:  KeyboardOn * head;
    protected:  KeyboardOn * tail;
    protected:  virtual KeyboardOn * add(KeyboardOn * observer);
    protected:  virtual KeyboardOn * del(KeyboardOn * observer);
    protected:  virtual void clear(void);
    public:     inline KeyboardOn * subscribe(KeyboardOn * o) override;
    public:     Keyboard(void);
    public:     ~Keyboard(void) override;
    public:     Keyboard(const Keyboard & o) = delete;
    public:     Keyboard(Keyboard && o) noexcept = delete;
    public:     Keyboard & operator=(const Keyboard & o) = delete;
    public:     Keyboard & operator=(Keyboard && o) noexcept = delete;
    public:     friend class KeyboardOn;
    public:     friend Collection;
    };

    inline KeyboardOn * Keyboard::subscribe(KeyboardOn * o) {
        return add(o);
    }

}

#endif // __POKEMONISM_WINDOW_INPUT_KEYBOARD_HH__