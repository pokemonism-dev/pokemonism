/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_ABSTRACT_APPLICATION_HH__
#define   __POKEMONISM_WINDOW_ABSTRACT_APPLICATION_HH__

#include <pokemonism/window/src/pokemonism/window.old/applicationable.hh>
#include <pokemonism/window/src/pokemonism/window.old/platform/application.hh>

#include <pokemonism/sdk/linked/list.hh>

namespace pokemonism::window {

    namespace abstract {
        // class window {
        // public:     class applica
        // };
    }

        class AbstractWindow;

        class AbstractWindowApplication : public WindowApplicationable {
        protected:  using Collection = pokemonism::sdk::LinkedList<AbstractWindowApplication, AbstractWindow>;
        protected:  unsigned long               size;
        protected:  AbstractWindow *            head;
        protected:  AbstractWindow *            tail;
        protected:  PlatformWindowApplication & adapter;
        public:     inline const char * platformNameGet(void) const noexcept override { return adapter.platformNameGet();  }
        protected:  inline int run(void) override { return adapter.run(); }
        public:     Window * windowGen(const WindowConfig & config) override;
        protected:  virtual AbstractWindow * add(AbstractWindow * node);
        protected:  virtual AbstractWindow * del(AbstractWindow * node);
        protected:  virtual void clear(void);
        public:     AbstractWindowApplication(void);
        public:     ~AbstractWindowApplication(void) override;
        public:     AbstractWindowApplication(const AbstractWindowApplication & o) = delete;
        public:     AbstractWindowApplication(AbstractWindowApplication && o) noexcept = delete;
        public:     AbstractWindowApplication & operator=(const AbstractWindowApplication & o) = delete;
        public:     AbstractWindowApplication & operator=(AbstractWindowApplication && o) noexcept = delete;
        public:     friend Collection;
        public:     friend AbstractWindow;
        };

}

#endif // __POKEMONISM_WINDOW_ABSTRACT_APPLICATION_HH__