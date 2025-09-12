/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_ON_HH__
#define   __POKEMONISM_ON_HH__

#include <pokemonism/observerable.hh>
#include <pokemonism/sdk/linked/list.hh>
#include <pokemonism/window/interface/keyboard/key.hh>

namespace pokemonism::window::interface {

    class Keyboard;

    class KeyboardOn : public Observerable<KeyboardKey, tag::NondisposableTag> {
    protected:  Keyboard * container;
    protected:  KeyboardOn * prev;
    protected:  KeyboardOn * next;
    protected:  void on(const KeyboardKey & item) override = 0;
    public:     KeyboardOn(void);
    public:     ~KeyboardOn(void) override;
    public:     KeyboardOn(const KeyboardOn & o) = delete;
    public:     KeyboardOn(KeyboardOn && o) noexcept = delete;
    public:     KeyboardOn & operator=(const KeyboardOn & o) = delete;
    public:     KeyboardOn & operator=(KeyboardOn && o) noexcept = delete;
    public:     friend class Keyboard;
    public:     friend class pokemonism::sdk::LinkedList<Keyboard, KeyboardOn>;
    };

}

#endif // __POKEMONISM_ON_HH__