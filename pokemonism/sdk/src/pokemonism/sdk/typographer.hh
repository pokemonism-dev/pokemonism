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

/**
 * ### TODO: 우리 제미나이와 함께 차후에 구현할 아이템
 * 1. '불변' 법칙 완벽 지원 (const): 지금 constReferenceOf 같은 '땜질' 대신, typographer<const T>에 대한 특수화를 추가해서, 우리 '타입 데이터베이스'가 const 타입을 완벽하게 이해하고 보호하게 만듭니다. '읽기 전용' 객체는 절대 수정할 수 없다는 '불변'의 법칙을 세우는 겁니다.
 * 2. '인쇄기' 매크로 도입: 당신이 좋아했던 그 아이디어죠! describe_integer와 describe_floating 매크로를 만들어서, Typographer의 정의를 더 깔끔하고 우아하게 만듭니다.
 * 3. '탈출구' 제공 (as_integer): 포인터의 '영혼'은 정수가 아니지만, 필요할 땐 '육체'(주소값)를 정수로 꺼내 쓸 수 있도록, typographer<T*>에 as_integer 같은 명시적인 변환 함수를 추가합니다.
 */
namespace pokemonism {
    namespace sdk {

        template <typename elementable>
        struct typographer {
        public:     constexpr static const char *   name = "unknown";                   // 디버깅을 위해서 만들어 놓은 상수
        public:     typedef elementable             type;
        public:     typedef void                    primitivable;                       // 이부분에 concept 커버하면서. 명시적 특수화 시에 사용되어지는 기본 타입도 나오는거지...
        public:     typedef void                    characterable;                      // 이것도 마찬가지고....
        public:     constexpr static bool           integerable = false;                // 기본적으로 모든 타입은 정수가 아닙니다.
        public:     typedef type *                  pointer;
        public:     typedef type &                  reference;
        public:     static type & referenceOf(pointer o){ return *o; }
        public:     static const type & constReferenceOf(const pointer o){ return *o; }
        public:     constexpr static unsigned long align = alignof(elementable);
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
        public:     constexpr static unsigned long align = alignof(elementable *);
        public:     constexpr static unsigned long  unit = sizeof(elementable *);
        };

        template <>
        struct typographer<void> {
        public:     constexpr static const char *   name = "void";
        public:     typedef void                    type;
        public:     typedef void                    primitivable;
        public:     typedef void                    characterable;
        public:     constexpr static bool           integerable = false;
        public:     typedef type *                  pointer;
        public:     typedef unsigned char &         reference;
        public:     static const unsigned char & constReferenceOf(const void * o){ return *(static_cast<const unsigned char *>(o)); }
        public:     static reference referenceOf(pointer o){ return *(static_cast<unsigned char *>(o)); }
        public:     constexpr static unsigned long align = alignof(unsigned char);
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
public:     constexpr static unsigned long align = alignof(elementType);                            \
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
public:     constexpr static unsigned long align = alignof(elementType);                            \
public:     constexpr static unsigned long  unit = size;                                            \
}

#endif // __POKEMONISM_SDK_TYPOGRAPHER_HH__