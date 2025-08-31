/**
 * @file
 * @brief
 * @details         이벤트 객체는 이벤트 처리에 필요한 데이터를 관리하여 실제 이벤트를 처리하는
 *                  모듈로 전달하는 객체다.
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_WATTREL_EVENT_HH__
#define   __POKEMONISM_WATTREL_EVENT_HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace wattrel {

        class event {
        public:     event(void) {}
        protected:  virtual ~event(void) {}
        public:     event(const event & o) = delete;
        public:     event(event && o) noexcept = delete;
        public:     event & operator=(const event & o) = delete;
        public:     event & operator=(event && o) noexcept = delete;
        };

    }

    namespace pokemon {
        using event = wattrel::event;
    }
}

#endif // __POKEMONISM_WATTREL_EVENT_HH__