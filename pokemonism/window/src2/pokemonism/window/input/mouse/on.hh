/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_INPUT_MOUSE_ON_HH__
#define   __POKEMONISM_WINDOW_INPUT_MOUSE_ON_HH__

#include <pokemonism/observerable.hh>
#include <pokemonism/sdk/linked/list.hh>
#include <pokemonism/window/src/pokemonism/window.old/input/mouse/pos.hh>

namespace pokemonism::window::input {

    class Mouse;

    class MouseOn : public Observerable<MousePos, tag::NondisposableTag> {
    protected:  Mouse * container;
    protected:  MouseOn * prev;
    protected:  MouseOn * next;
    protected:  void on(const MousePos & item) override = 0;
    public:     MouseOn(void);
    public:     ~MouseOn(void) override;
    public:     MouseOn(const MouseOn & o) = delete;
    public:     MouseOn(MouseOn && o) noexcept = delete;
    public:     MouseOn & operator=(const MouseOn & o) = delete;
    public:     MouseOn & operator=(MouseOn && o) noexcept = delete;
    public:     friend class Mouse;
    public:     friend class pokemonism::sdk::LinkedList<Mouse, MouseOn>;
    };

}

#endif // __POKEMONISM_WINDOW_INPUT_MOUSE_ON_HH__