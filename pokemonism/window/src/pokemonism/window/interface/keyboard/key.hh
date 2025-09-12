/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_INTERFACE_KEYBOARD_KEY_HH__
#define   __POKEMONISM_WINDOW_INTERFACE_KEYBOARD_KEY_HH__

#include <pokemonism.hh>

namespace pokemonism::window::interface {

    struct KeyboardKey {
    protected:  int key;
    protected:  int scancode;
    protected:  int action;
    protected:  int modifier;
    public:     inline int keyGet(void) const;
    public:     inline int scancodeGet(void) const;
    public:     inline int actionGet(void) const;
    public:     inline int modifierGet(void) const;
    public:     inline KeyboardKey(int key, int scancode, int action, int modifier);
    public:     inline KeyboardKey(void);
    public:     inline ~KeyboardKey(void);
    public:     inline KeyboardKey(const KeyboardKey & o);
    public:     inline KeyboardKey(KeyboardKey && o) noexcept;
    public:     inline KeyboardKey & operator=(const KeyboardKey & o);
    public:     inline KeyboardKey & operator=(KeyboardKey && o) noexcept;
    };

    inline int KeyboardKey::keyGet(void) const {
        return key;
    }

    inline int KeyboardKey::scancodeGet(void) const {
        return scancode;
    }

    inline int KeyboardKey::actionGet(void) const {
        return action;
    }

    inline int KeyboardKey::modifierGet(void) const {
        return modifier;
    }

    inline KeyboardKey::KeyboardKey(int key, int scancode, int action, int modifier) :
    key(key), scancode(scancode), action(action), modifier(modifier) {

    }

    inline KeyboardKey::KeyboardKey(void) :
    key(declaration::none), scancode(declaration::none), action(declaration::none), modifier(declaration::none)  {

    }

    inline KeyboardKey::~KeyboardKey(void) {

    }

    inline KeyboardKey::KeyboardKey(const KeyboardKey & o) :
    key(o.key), scancode(o.scancode), action(o.action), modifier(o.modifier) {

    }

    inline KeyboardKey::KeyboardKey(KeyboardKey && o) noexcept :
    key(o.key), scancode(o.scancode), action(o.action), modifier(o.modifier) {
        o.key = declaration::none;
        o.scancode = declaration::none;
        o.action = declaration::none;
        o.modifier = declaration::none;
    }

    inline KeyboardKey & KeyboardKey::operator=(const KeyboardKey & o) {
        if (pointof(o) != this) {
            key = o.key;
            scancode = o.scancode;
            action = o.action;
            modifier = o.modifier;
        }
        return *this;
    }

    inline KeyboardKey & KeyboardKey::operator=(KeyboardKey && o) noexcept {
        if (pointof(o) != this) {
            key = o.key;
            scancode = o.scancode;
            action = o.action;
            modifier = o.modifier;

            o.key = declaration::none;
            o.scancode = declaration::none;
            o.action = declaration::none;
            o.modifier = declaration::none;
        }
        return *this;
    }

}

#endif // __POKEMONISM_WINDOW_INTERFACE_KEYBOARD_KEY_HH__