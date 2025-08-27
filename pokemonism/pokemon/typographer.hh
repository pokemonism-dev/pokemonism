/**
 * @file        pokemon/typographer.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#ifndef   __POKEMONISM_POKEMON_TYPOGRAPHER__HH__
#define   __POKEMONISM_POKEMON_TYPOGRAPHER__HH__

#include <pokemonism.hh>

namespace pokemon {
    template <typename type>
    struct typographer {
    public:     typedef type                                original;
    public:     typedef void                                character;
    public:     typedef void                                primitive;
    public:     typedef type                                memorial;
    public:     typedef void                                number;
    public:     constexpr static declaration::type::size    width = sizeof(original);
    public:     constexpr static const char *               name = nullptr;
    };
}

#define pokemon_typographer_declare(original_type, character_type, primitive_type, memorial_type, number_type, unit)    \
template <> struct ::pokemon::typographer<original_type> {                                                              \
public:     typedef original_type           original;                                                                   \
public:     typedef character_type          character;                                                                  \
public:     typedef primitive_type          primitive;                                                                  \
public:     typedef memorial_type           memorial;                                                                   \
public:     typedef number_type             number;                                                                     \
public:     constexpr static int            width = unit;                                                               \
public:     constexpr static const char *   name = #original_type;                                                      \
};

/**                       | ORIGINAL          | CHARACTER | PRIMITIVE    | ALLOCATION   | NUMBER     | WIDTH                     | */
pokemon_typographer_declare(void              , void      , void         , unsigned char, void       , sizeof(unsigned char)     );
pokemon_typographer_declare(bool              , void      , unsigned char, unsigned char, void       , sizeof(bool)              );
pokemon_typographer_declare(wchar_t           , char      , unsigned char, unsigned char, long long  , sizeof(wchar_t)           );
pokemon_typographer_declare(signed char       , void      , unsigned char, unsigned char, long long  , sizeof(signed char)       );
pokemon_typographer_declare(float             , void      , unsigned char, unsigned char, long double, sizeof(float)             );
pokemon_typographer_declare(double            , void      , unsigned char, unsigned char, long double, sizeof(double)            );
pokemon_typographer_declare(long double       , void      , unsigned char, unsigned char, long double, sizeof(long double)       );
pokemon_typographer_declare(char              , char      , unsigned char, unsigned char, long long  , sizeof(char)              );
pokemon_typographer_declare(unsigned char     , void      , unsigned char, unsigned char, long long  , sizeof(unsigned char)     );
pokemon_typographer_declare(short             , void      , unsigned char, unsigned char, long long  , sizeof(short)             );
pokemon_typographer_declare(unsigned short    , void      , unsigned char, unsigned char, long long  , sizeof(unsigned short)    );
pokemon_typographer_declare(int               , void      , unsigned char, unsigned char, long long  , sizeof(int)               );
pokemon_typographer_declare(unsigned int      , void      , unsigned char, unsigned char, long long  , sizeof(unsigned int)      );
pokemon_typographer_declare(long              , void      , unsigned char, unsigned char, long long  , sizeof(long)              );
pokemon_typographer_declare(unsigned long     , void      , unsigned char, unsigned char, long long  , sizeof(unsigned long)     );
pokemon_typographer_declare(long long         , void      , unsigned char, unsigned char, long long  , sizeof(long long)         );
pokemon_typographer_declare(unsigned long long, void      , unsigned char, unsigned char, long long  , sizeof(unsigned long long));

#endif // __POKEMONISM_POKEMON_TYPOGRAPHER__HH__
