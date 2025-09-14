/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 13, 2025
 */

#ifndef   __POKEMONISM_SDK_TYPOGRAPHER_HH__
#define   __POKEMONISM_SDK_TYPOGRAPHER_HH__

namespace pokemonism {
    namespace sdk {

        template <typename elementable>
        struct typographer {
        public:     constexpr static const char *   name = "basic";
        public:     typedef elementable             type;
        public:     typedef void                    primitivable;
        public:     typedef void                    characterable;
        public:     constexpr static unsigned long  unit = sizeof(elementable);
        };

        template <typename elementable>
        struct typographer<elementable *> {
        public:     constexpr static const char *   name = "pointer";
        public:     typedef elementable *           type;
        public:     typedef unsigned char           primitivable;
        public:     typedef void                    characterable;
        public:     constexpr static unsigned long  unit = sizeof(elementable *);
        };
    }

    template <typename elementable> using typographer = pokemonism::sdk::typographer<elementable>;

}

#define describe_typographer(elementType, primitiveType, characterType, size)       \
template <> struct pokemonism::sdk::typographer<elementType> {                      \
public:     constexpr static const char *   name = #elementType;                    \
public:     typedef elementType             type;                                   \
public:     typedef primitiveType           Primitivable;                           \
public:     typedef characterType           characterable;                          \
public:     constexpr static unsigned long  unit = size;                            \
}

describe_typographer(void              , unsigned, void, sizeof(unsigned char)     );

describe_typographer(wchar_t           , unsigned, char, sizeof(wchar_t)           );
describe_typographer(bool              , unsigned, void, sizeof(bool)              );
describe_typographer(float             , unsigned, void, sizeof(float)             );
describe_typographer(double            , unsigned, void, sizeof(double)            );
describe_typographer(long double       , unsigned, void, sizeof(long double)       );
describe_typographer(signed char       , unsigned, char, sizeof(signed char)       );

describe_typographer(char              , unsigned, char, sizeof(char)              );
describe_typographer(unsigned char     , unsigned, char, sizeof(unsigned char)     );
describe_typographer(short             , unsigned, void, sizeof(short)             );
describe_typographer(unsigned short    , unsigned, void, sizeof(unsigned short)    );
describe_typographer(int               , unsigned, void, sizeof(int)               );
describe_typographer(unsigned int      , unsigned, void, sizeof(unsigned int)      );
describe_typographer(long              , unsigned, void, sizeof(long)              );
describe_typographer(unsigned long     , unsigned, void, sizeof(unsigned long)     );
describe_typographer(long long         , unsigned, void, sizeof(long long)         );
describe_typographer(unsigned long long, unsigned, void, sizeof(unsigned long long));

#endif // __POKEMONISM_SDK_TYPOGRAPHER_HH__