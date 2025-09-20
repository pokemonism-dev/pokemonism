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


// #include <type_traits> // for std::false_type, std::true_type
// #include <concepts>

namespace pokemonism {
    namespace sdk {

        template <typename elementable>
        struct typographer {
        public:     constexpr static const char *   name = "basic";                     // 디버깅을 위해서 만들어 놓은 상수
        public:     typedef elementable             type;
        public:     typedef void                    primitivable;                       // 이부분에 concept 커버하면서. 명시적 특수화 시에 사용되어지는 기본 타입도 나오는거지...
        public:     typedef void                    characterable;                      // 이것도 마찬가지고....
        public:     constexpr static bool           integerable = false;                // 기본적으로 모든 타입은 정수가 아닙니다.
        public:     typedef type *                  pointer;
        public:     typedef type &                  reference;
        public:     static type & referenceOf(pointer o){ return *o; }
        public:     static const type & constReferenceOf(const pointer o){ return *o; }
        public:     constexpr static unsigned long  unit = sizeof(elementable);
        };

        template <typename elementable>
        struct typographer<elementable *> {
        public:     constexpr static const char *   name = "pointer";
        public:     typedef elementable *           type;
        public:     typedef unsigned char           primitivable;
        public:     typedef void                    characterable;
        public:     constexpr static bool           integerable = false;                 // 포인터는 정수가 아니죠. -
        public:     typedef type *                  pointer;
        public:     typedef type &                  reference;
        public:     static const type & constReferenceOf(const pointer o){ return *o; }
        public:     static reference referenceOf(pointer o){ return *o; }
        public:     constexpr static unsigned long  unit = sizeof(elementable *);
        };

        template <>
        struct typographer<void> {
        public:     constexpr static const char *   name = "basic";
        public:     typedef void                    type;
        public:     typedef void                    primitivable;
        public:     typedef void                    characterable;
        public:     constexpr static bool           integerable = false;
        public:     typedef type *                  pointer;
        public:     typedef unsigned char &         reference;
        public:     static const unsigned char & constReferenceOf(const void * o){ return *(static_cast<const unsigned char *>(o)); }
        public:     static reference referenceOf(pointer o){ return *(static_cast<unsigned char *>(o)); }
        public:     constexpr static unsigned long  unit = sizeof(unsigned char);
        };
    }

    template <typename elementable> using typographer = pokemonism::sdk::typographer<elementable>;

}

#define describe_typographer(elementType, primitiveType, characterType, isInteger, size)            \
template <> struct pokemonism::sdk::typographer<elementType> {                                      \
public:     constexpr static const char *   name = #elementType;                                    \
public:     typedef elementType             type;                                                   \
public:     typedef primitiveType           primitivable;                                           \
public:     typedef characterType           characterable;                                          \
public:     constexpr static bool           integerable = isInteger;                                \
public:     typedef type *                  pointer;                                                \
public:     typedef type &                  reference;                                              \
public:     static const type & constReferenceOf(const pointer o){ return *o; }                     \
public:     static reference referenceOf(pointer o){ return *o; }                                   \
public:     constexpr static unsigned long  unit = size;                                            \
}

describe_typographer(wchar_t           , unsigned, char, true , sizeof(wchar_t)                     );
describe_typographer(bool              , unsigned, void, true , sizeof(bool)                        );
describe_typographer(float             , unsigned, void, false, sizeof(float)                       );
describe_typographer(double            , unsigned, void, false, sizeof(double)                      );
describe_typographer(long double       , unsigned, void, false, sizeof(long double)                 );
describe_typographer(signed char       , unsigned, char, true , sizeof(signed char)                 );

describe_typographer(char              , unsigned, char, true , sizeof(char)                        );
describe_typographer(unsigned char     , unsigned, char, true , sizeof(unsigned char)               );
describe_typographer(short             , unsigned, void, true , sizeof(short)                       );
describe_typographer(unsigned short    , unsigned, void, true , sizeof(unsigned short)              );
describe_typographer(int               , unsigned, void, true , sizeof(int)                         );
describe_typographer(unsigned int      , unsigned, void, true , sizeof(unsigned int)                );
describe_typographer(long              , unsigned, void, true , sizeof(long)                        );
describe_typographer(unsigned long     , unsigned, void, true , sizeof(unsigned long)               );
describe_typographer(long long         , unsigned, void, true , sizeof(long long)                   );
describe_typographer(unsigned long long, unsigned, void, true , sizeof(unsigned long long)          );

#define describe_handle_typographer(elementType, primitiveType, characterType, pointerType, size)   \
template <> struct pokemonism::sdk::typographer<elementType> {                                      \
public:     constexpr static const char *   name = #elementType;                                    \
public:     typedef elementType             type;                                                   \
public:     typedef primitiveType           primitivable;                                           \
public:     typedef characterType           characterable;                                          \
public:     constexpr static bool           integerable = false;                                    \
public:     typedef pointerType             pointer;                                                \
public:     typedef pointerType             reference;                                              \
public:     static reference referenceOf(pointer o){ return o; }                                    \
public:     static const pointerType constReferenceOf(const pointerType o){ return o; }             \
public:     constexpr static unsigned long  unit = size;                                            \
}

#endif // __POKEMONISM_SDK_TYPOGRAPHER_HH__