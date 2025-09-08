/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_TYPOGRAPHER_HH__
#define   __POKEMONISM_SDK_TYPOGRAPHER_HH__

#include <pokemonism.hh>

namespace pokemonism::sdk {

    template <typename elementable>
    struct typographer {
    public:     typedef elementable             element;
    public:     typedef void                    primitive;
    public:     typedef void                    character;
    public:     constexpr static unsigned long  unit = sizeof(elementable);
    };

}

#define describe_typographer(element_type, primitive_type, character_type, size)        \
template <> struct pokemonism::sdk::typographer<element_type> {                         \
public:     typedef element_type            element;                                    \
public:     typedef primitive_type          primitive;                                  \
public:     typedef character_type          character;                                  \
public:     constexpr static unsigned long  unit = size;                                \
}

describe_typographer(void              , unsigned char, void, sizeof(unsigned char)     );

describe_typographer(wchar_t           , unsigned char, char, sizeof(wchar_t)           );
describe_typographer(bool              , unsigned char, void, sizeof(bool)              );
describe_typographer(float             , unsigned char, void, sizeof(float)             );
describe_typographer(double            , unsigned char, void, sizeof(double)            );
describe_typographer(long double       , unsigned char, void, sizeof(long double)       );
describe_typographer(signed char       , unsigned char, char, sizeof(signed char)       );

describe_typographer(char              , unsigned char, char, sizeof(char)              );
describe_typographer(unsigned char     , unsigned char, char, sizeof(unsigned char)     );
describe_typographer(short             , unsigned char, void, sizeof(short)             );
describe_typographer(unsigned short    , unsigned char, void, sizeof(unsigned short)    );
describe_typographer(int               , unsigned char, void, sizeof(int)               );
describe_typographer(unsigned int      , unsigned char, void, sizeof(unsigned int)      );
describe_typographer(long              , unsigned char, void, sizeof(long)              );
describe_typographer(unsigned long     , unsigned char, void, sizeof(unsigned long)     );
describe_typographer(long long         , unsigned char, void, sizeof(long long)         );
describe_typographer(unsigned long long, unsigned char, void, sizeof(unsigned long long));

#endif // __POKEMONISM_SDK_TYPOGRAPHER_HH__