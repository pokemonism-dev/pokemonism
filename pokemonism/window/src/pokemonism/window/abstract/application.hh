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

#include <pokemonism/window/applicationable.hh>
#include <pokemonism/window/platform/application.hh>

namespace pokemonism::window {

        class AbstractWindow;

        class AbstractWindowApplication : public WindowApplicationable {
        protected:  unsigned long               size;
        protected:  AbstractWindow *            head;
        protected:  AbstractWindow *            tail;
        protected:  PlatformWindowApplication & adapter;
        public:     inline const char * platformNameGet(void) const noexcept override { return adapter.platformNameGet();  }
        public:     Window * gen(const WindowConfig & config) override;
        protected:  inline int run(void) override { return adapter.run(); }
        public:     AbstractWindowApplication(void);
        public:     ~AbstractWindowApplication(void) override;
        public:     AbstractWindowApplication(const AbstractWindowApplication & o) = delete;
        public:     AbstractWindowApplication(AbstractWindowApplication && o) noexcept = delete;
        public:     AbstractWindowApplication & operator=(const AbstractWindowApplication & o) = delete;
        public:     AbstractWindowApplication & operator=(AbstractWindowApplication && o) noexcept = delete;
        };

}

#endif // __POKEMONISM_WINDOW_ABSTRACT_APPLICATION_HH__