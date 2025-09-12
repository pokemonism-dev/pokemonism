/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_INTERFACE_MOUSE_HH__
#define   __POKEMONISM_WINDOW_INTERFACE_MOUSE_HH__

#include <pokemonism/observable.hh>
#include <pokemonism/sdk/linked/list.hh>
#include <pokemonism/window/interface/mouse/pos.hh>

namespace pokemonism::window::interface {

    class MouseOn;

    class Mouse : public Observable<MousePos, MouseOn> {
    protected:  using Collection = pokemonism::sdk::LinkedList<Mouse, MouseOn>;
    protected:  unsigned long size;
    protected:  MouseOn * head;
    protected:  MouseOn * tail;
    protected:  virtual MouseOn * add(MouseOn * observer);
    protected:  virtual MouseOn * del(MouseOn * observer);
    protected:  virtual void clear(void);
    public:     virtual void rawMouseMotionSet(bool enable) = 0;
    public:     virtual bool rawMouseMotionSupportGet(void) const = 0;
    public:     virtual void passthroughSet(bool enable) = 0;
    public:     inline MouseOn * subscribe(MouseOn * observer) override;
    public:     Mouse(void);
    public:     ~Mouse(void) override;
    public:     Mouse(const Mouse & o) = delete;
    public:     Mouse(Mouse && o) noexcept = delete;
    public:     Mouse & operator=(const Mouse & o) = delete;
    public:     Mouse & operator=(Mouse && o) noexcept = delete;
    public:     friend class MouseOn;
    public:     friend Collection;
    };

    inline MouseOn * Mouse::subscribe(MouseOn * observer) {
        return add(observer);
    }

}

#endif // __POKEMONISM_WINDOW_INTERFACE_MOUSE_HH__