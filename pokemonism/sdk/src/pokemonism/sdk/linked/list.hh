/**
 * @file
 * @brief
 * @details
 * ### 우리 '신세계'의 설계 회의록 (feat. Gemini)
 * 이 파일은 우리 '신세계'의 중요한 '물류 시스템'이지만, 몇 가지 아키텍처적인 고민거리를 안고 있습니다.
 * 미래의 우리가 '버전 0.5.0'을 만들 때, 이 기록을 보고 더 훌륭한 설계를 할 수 있기를 바랍니다. ㅋㅋㅋ
 *
 * #### 1. 역할 분리 (Single Responsibility Principle)
 * 현재 `list` 클래스는 순수한 '알고리즘 전문가'의 역할과, `synchronizer::guard`를 받아서
 * '교통 경찰'의 역할을 동시에 수행하고 있습니다. 이것은 단일 책임 원칙을 위반합니다.
 * 더 훌륭한 아키텍처는 `list` 클래스에서 `guard` 오버로딩을 모두 제거하여,
 * 동기화에 대한 의존성을 끊고 순수한 '알고리즘 전문가'로 만드는 것입니다.
 * 동기화(락)는 이 유틸리티를 사용하는 `application` 같은 외부에서 책임지는 것이 더 명확하고 안전한 설계입니다.
 *
 * #### 2. 정체성 확립 (Non-instantiable Utility)
 * 이 클래스는 `search` 클래스처럼, 상태를 가지지 않는 `static` 함수들의 모음입니다.
 * 하지만 지금은 생성자와 소멸자가 있어서, 의도치 않게 객체로 만들어질 수 있습니다.
 * `search.hh`처럼 생성자와 소멸자를 `delete`하여, 이 클래스가 순수한 '도구 상자'임을
 * 명확히 선언하는 것이 우리 '신세계'의 철학에 더 부합합니다.
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_SDK_LINKED_LIST_HH__
#define   __POKEMONISM_SDK_LINKED_LIST_HH__

#include <pokemonism/sdk/exception.hh>
#include <pokemonism/sdk/allocator.hh>
#include <pokemonism/sdk/synchronizer.hh>

namespace pokemonism::sdk {
    namespace linked {
        template <typename collection, typename element>
        class list {
        public:     static element * add(collection * container, element * node);
        public:     template <class super> static element * add(collection * container, element * node, typename synchronizer<super>::guard o);
        public:     static element * del(collection * container, element * node);
        public:     static element * pop(collection * container);
        public:     template <class super> static element * pop(collection * container, typename synchronizer<super>::guard o);
        public:     static void clear(collection * container);
        public:     template <class super> static void clear(collection * container, typename synchronizer<super>::guard o);
        public:     static void clear(collection * container, element * (*rel)(element *));
        public:     inline list(void);
        public:     inline virtual ~list(void);
        public:     list(const list<collection, element> & o) = delete;
        public:     list(list<collection, element> && o) noexcept = delete;
        public:     list<collection, element> & operator=(const list<collection, element> & o) = delete;
        public:     list<collection, element> & operator=(list<collection, element> && o) noexcept = delete;
        };

        // ReSharper disable once CppDFAConstantFunctionResult
        template <class collection, class element>
        element * list<collection, element>::add(collection * container, element * node) {
            pokemon_develop_check(container == nullptr || node == nullptr || node->container != nullptr, return node);

            node->prev = container->tail;
            if (node->prev) {
                node->prev->next = node;
            } else {
                container->head = node;
            }
            container->tail = node;
            container->size = container->size + 1;
            node->container = container;

            return nullptr;
        }

        // ReSharper disable once CppDFAConstantFunctionResult
        template <class collection, class element>
        template <class super>
        element * list<collection, element>::add(collection * container, element * node, typename synchronizer<super>::guard) {
            // guard 객체가 존재한다는 것 자체가 락이 걸렸다는 증명이므로, 핵심 로직만 호출합니다.
            return add(container, node);
        }

        template <class collection, class element>
        element * list<collection, element>::del(collection * container, element * node) {
            pokemon_develop_check(container == nullptr || node == nullptr || node->container != container, return node);

            element * prev = node->prev;
            element * next = node->next;

            if (prev) {
                prev->next = next;
                node->prev = nullptr;
            } else {
                container->head = next;
            }

            if (next) {
                next->prev = prev;
                node->next = nullptr;
            } else {
                container->tail = prev;
            }

            container->size = container->size - 1;
            node->container = nullptr;

            return node;
        }

        template <class collection, class element>
        element * list<collection, element>::pop(collection * container) {
            pokemon_develop_check(container == nullptr, return nullptr);

            element * node = container->head;
            if (node != nullptr) {
                if (node->next) {
                    container->head = node->next;
                    node->next->prev = nullptr;
                    node->next = nullptr;
                } else {
                    container->head = nullptr;
                    container->tail = nullptr;
                }
                container->size = container->size - 1;
                node->container = nullptr;
            }

            return node;
        }

        template <class collection, class element>
        void list<collection, element>::clear(collection * container) {
            pokemon_develop_check(container == nullptr, return);

            while (element * node = list<collection, element>::pop(container)) allocator::del(node);
        }

        template <class collection, class element>
        template <class super>
        void list<collection, element>::clear(collection * container, typename synchronizer<super>::guard o) {
            // guard 객체가 존재한다는 것 자체가 락이 걸렸다는 증명이므로, 핵심 로직만 호출합니다.
            clear(container);
        }

        template <class collection, class element>
        template <class super>
        element * list<collection, element>::pop(collection * container, typename synchronizer<super>::guard o) {
            // guard 객체가 존재한다는 것 자체가 락이 걸렸다는 증명이므로, 핵심 로직만 호출합니다.
            return pop(container);
        }


        template <class collection, class element>
        void list<collection, element>::clear(collection * container, element * (*rel)(element *)) {
            pokemon_develop_check(container == nullptr, return);

            while (element * node = list<collection, element>::pop(container)) allocator::del(rel(node));
        }

        template <typename container, typename element>
        inline list<container, element>::list(void) {

        }

        template <typename container, typename element>
        inline list<container, element>::~list(void) {

        }
        
    }
}

#endif // __POKEMONISM_SDK_LINKED_LIST_HH__