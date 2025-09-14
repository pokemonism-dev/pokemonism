/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 14, 2025
 */

#ifndef   __POKEMONISM_ABSTRACT_WINDOW_HH__
#define   __POKEMONISM_ABSTRACT_WINDOW_HH__

#include <pokemonism/sdk/linked/list.hh>
#include <pokemonism/platform/window.hh>

namespace pokemonism::abstract {

    class window : public interface::window {
    public:     class application : public interface::window::application {
                protected:  using collection = sdk::linked::list<abstract::window::application, abstract::window>;
                protected:  unsigned long                       size;
                protected:  abstract::window *                  head;
                protected:  abstract::window *                  tail;
                protected:  platform::window::application &     adapter;
                protected:  interface::window * windowGen(const interface::window::config & config) override;
                protected:  abstract::window * add(abstract::window * node);
                protected:  abstract::window * del(abstract::window * node);
                protected:  void clear(void);
                protected:  explicit application(platform::window::application & adapter);
                protected:  application(void) = delete;
                protected:  ~application(void) override;
                protected:  application(const abstract::window::application & o) = delete;
                protected:  application(abstract::window::application && o) noexcept = delete;
                protected:  abstract::window::application & operator=(const abstract::window::application & o) = delete;
                protected:  abstract::window::application & operator=(abstract::window::application && o) noexcept = delete;
                public:     friend collection;
                public:     friend abstract::window;
                };
    protected:  abstract::window::application *     container;
    protected:  abstract::window *                  prev;
    protected:  abstract::window *                  next;
    protected:  platform::window *                  adapter;
    protected:  explicit window(platform::window * adapter);
    protected:  window(void);
    public:     ~window(void) override;
    public:     window(const abstract::window & o) = delete;
    public:     window(abstract::window && o) noexcept = delete;
    public:     abstract::window & operator=(const abstract::window & o) = delete;
    public:     abstract::window & operator=(abstract::window && o) noexcept = delete;
    public:     friend abstract::window::application;
    public:     friend sdk::linked::list<abstract::window::application, abstract::window>;
    };

}

#endif // __POKEMONISM_ABSTRACT_WINDOW_HH__