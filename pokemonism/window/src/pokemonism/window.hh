/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 14, 2025
 */

#ifndef   __POKEMONISM_WINDOW_HH__
#define   __POKEMONISM_WINDOW_HH__

#include <pokemonism/applicationable.hh>

#include <pokemonism/sdk/linked/list.hh>

namespace pokemonism {

    class window {
    public:     struct config;
    public:     class application;
    public:     inline window(void);
    public:     inline virtual ~window(void);
    public:     inline window(const window & o) = delete;
    public:     inline window(window && o) noexcept = delete;
    public:     inline window & operator=(const window & o) = delete;
    public:     inline window & operator=(window && o) noexcept = delete;
    };

    namespace platform {
        class window;
    }

    namespace abstract {
        class window : public pokemonism::window {
        public:     class application;
        protected:  abstract::window::application *     container;
        protected:  abstract::window *                  prev;
        protected:  abstract::window *                  next;
        public:     platform::window *                  adapter;
        public:     inline explicit window(platform::window * adapter);
        public:     window(void) = delete;
        public:     ~window(void) override;
        public:     window(const abstract::window & o) = delete;
        public:     window(abstract::window && o) noexcept = delete;
        public:     abstract::window & operator=(const abstract::window & o) = delete;
        public:     abstract::window & operator=(abstract::window && o) noexcept = delete;
        public:     friend sdk::linked::list<abstract::window::application, abstract::window>;
        };
    }


    namespace platform {
        class window : public pokemonism::window {
        public:     class application;
        public:     inline window(void);
        public:     inline ~window(void) override;
        public:     window(const platform::window & o) = delete;
        public:     window(platform::window && o) noexcept = delete;
        public:     platform::window & operator=(const platform::window & o) = delete;
        public:     platform::window & operator=(platform::window && o) noexcept = delete;
        };

        class platform::window::application : public applicationable {
        public:     static platform::window::application & get(void);
        public:     virtual platform::window * windowGen(const window::config & config) = 0;
        public:     inline application(void);
        public:     inline ~application(void) override;
        public:     application(const platform::window::application & o) = delete;
        public:     application(platform::window::application && o) noexcept = delete;
        public:     platform::window::application & operator=(const platform::window::application & o) = delete;
        public:     platform::window::application & operator=(platform::window::application && o) noexcept = delete;
        public:     friend abstract::window::application;
        };
    }

    namespace abstract {
        class abstract::window::application : public applicationable {
        protected:  using collection = sdk::linked::list<abstract::window::application, abstract::window>;
        protected:  platform::window::application &     adapter;
        protected:  unsigned long                       size;
        protected:  abstract::window *                  head;
        protected:  abstract::window *                  tail;
        protected:  virtual pokemonism::window * windowGen(const window::config & config);
        protected:  abstract::window * del(abstract::window * node);
        protected:  inline int run(void) override;
        protected:  application(void);
        protected:  ~application(void) override;
        public:     application(const abstract::window::application & o) = delete;
        public:     application(abstract::window::application && o) noexcept = delete;
        public:     abstract::window::application & operator=(const abstract::window::application & o) = delete;
        public:     abstract::window::application & operator=(abstract::window::application && o) noexcept = delete;
        public:     friend collection;
        public:     friend abstract::window;
        };
    }

    class window::application : public abstract::window::application {
    public:     inline application(void);
    public:     inline ~application(void) override;
    public:     inline application(const window::application & o);
    public:     inline application(window::application && o) noexcept;
    public:     inline window::application & operator=(const window::application & o);
    public:     inline window::application & operator=(window::application && o) noexcept;
    };

    inline window::window(void) {

    }

    inline window::~window(void) {

    }

}

// ReSharper disable CppUnusedIncludeDirective
#include <pokemonism/window/application.hh>
#include <pokemonism/abstract/window/application.hh>
#include <pokemonism/platform/window/application.hh>
// ReSharper restore CppUnusedIncludeDirective

#endif // __POKEMONISM_WINDOW_HH__
