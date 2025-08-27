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
    template <typename original>
    struct typographer {
    public:     typedef original                            original_type;
    public:     typedef char                                characterized_type;
    public:     typedef void                                primitived_type;
    public:     typedef original_type                       memorized_type;
    public:     typedef void                                numberized_type;
    public:     constexpr static declaration::type::size    width = sizeof(original_type);
    public:     constexpr static const char *               name = nullptr;
    };
}

#define pokemon_typographer_declare(original, character, primitive, allocation, number, unit)     \
template <> struct ::pokemon::typographer<original> {                                                       \
public:     typedef original                original_type;                                                  \
public:     typedef character               characterized_type;                                             \
public:     typedef primitive               primitived_type;                                                \
public:     typedef allocation              memorized_type;                                                 \
public:     typedef number                  numberized_type;                                                \
public:     constexpr static int            width = unit;                                                   \
public:     constexpr static const char *   name = #original;                                               \
};

/**                       | ORIGINAL          | CHARACTER | PRIMITIVE         | ALLOCATION   | NUMBER            | WIDTH                     | */
pokemon_typographer_declare(void              , void      , void              , unsigned char, void              , sizeof(unsigned char)     );
pokemon_typographer_declare(bool              , void      , bool              , unsigned char, void              , sizeof(bool)              );
pokemon_typographer_declare(wchar_t           , char      , wchar_t           , unsigned char, wchar_t           , sizeof(wchar_t)           );
pokemon_typographer_declare(signed char       , void      , signed char       , unsigned char, signed char       , sizeof(signed char)       );
pokemon_typographer_declare(float             , void      , float             , unsigned char, float             , sizeof(float)             );
pokemon_typographer_declare(double            , void      , double            , unsigned char, double            , sizeof(double)            );
pokemon_typographer_declare(long double       , void      , long double       , unsigned char, long double       , sizeof(long double)       );
pokemon_typographer_declare(char              , char      , char              , unsigned char, char              , sizeof(char)              );
pokemon_typographer_declare(unsigned char     , void      , unsigned char     , unsigned char, unsigned char     , sizeof(unsigned char)     );
pokemon_typographer_declare(short             , void      , short             , unsigned char, short             , sizeof(short)             );
pokemon_typographer_declare(unsigned short    , void      , unsigned short    , unsigned char, unsigned short    , sizeof(unsigned short)    );
pokemon_typographer_declare(int               , void      , int               , unsigned char, int               , sizeof(int)               );
pokemon_typographer_declare(unsigned int      , void      , unsigned int      , unsigned char, unsigned int      , sizeof(unsigned int)      );
pokemon_typographer_declare(long              , void      , long              , unsigned char, long              , sizeof(long)              );
pokemon_typographer_declare(unsigned long     , void      , unsigned long     , unsigned char, unsigned long     , sizeof(unsigned long)     );
pokemon_typographer_declare(long long         , void      , long long         , unsigned char, long long         , sizeof(long long)         );
pokemon_typographer_declare(unsigned long long, void      , unsigned long long, unsigned char, unsigned long long, sizeof(unsigned long long));

#endif // __POKEMONISM_POKEMON_TYPOGRAPHER__HH__