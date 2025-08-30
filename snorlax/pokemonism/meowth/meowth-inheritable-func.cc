/**
 * @file        pokemonism/meowth/meowth-inheritable-func.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#include <cstdio>

namespace pokemonism {
    namespace meowth {

        namespace functionable {
            struct tag {
            public:     typedef void (*type)(void);
            };
        }

        namespace inheritable {

            template <typename returnable, typename... argumentable>
            struct function : public functionable::tag {
            public:     typedef returnable (*type)(argumentable...);
            public:     type func;
            };

        }

        class parent {
        public:
            virtual ~parent() = default;

            virtual functionable::tag::type get(void) const { return nullptr; }
        };

    }
}

int main(int argc, char ** argv) {
    return 0;
}