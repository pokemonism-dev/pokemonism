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


#include <concepts>

namespace pokemonism {
    namespace sdk {

        template <typename elementable>
        struct typographer {
        public:     constexpr static const char *   name = "basic";                     /** 디버깅을 위해서 만들어 놓은 상수 */
        public:     typedef elementable             type;
        public:     typedef void                    primitivable;                       // 이부분에 concept 커버하면서. 명시적 특수화 시에 사용되어지는 기본 타입도 나오는거지...
        public:     typedef void                    characterable;                      // 이것도 마찬가지고....
        public:     typedef type *                  pointer;
        public:     typedef type &                  reference;
        // 'const' 갑옷을 입히기 위한 오버로딩입니다! '읽기 전용' 참조를 위한 규칙이죠.
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
        public:     typedef type *                  pointer;
        public:     typedef unsigned char &         reference;
        public:     static const unsigned char & constReferenceOf(const void * o){ return *(static_cast<const unsigned char *>(o)); }
        public:     static reference referenceOf(pointer o){ return *(static_cast<unsigned char *>(o)); }
        public:     constexpr static unsigned long  unit = sizeof(unsigned char);
        };
    }

    template <typename elementable> using typographer = pokemonism::sdk::typographer<elementable>;

}

#define describe_typographer(elementType, primitiveType, characterType, size)       \
template <> struct pokemonism::sdk::typographer<elementType> {                      \
public:     constexpr static const char *   name = #elementType;                    \
public:     typedef elementType             type;                                   \
public:     typedef primitiveType           primitivable;                           \
public:     typedef characterType           characterable;                          \
public:     typedef type *                  pointer;                                \
public:     typedef type &                  reference;                              \
public:     static const type & constReferenceOf(const pointer o){ return *o; }         \
public:     static reference referenceOf(pointer o){ return *o; }                   \
public:     constexpr static unsigned long  unit = size;                            \
}

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

#define describe_handle_typographer(elementType, primitiveType, characterType, pointerType, size)   \
template <> struct pokemonism::sdk::typographer<elementType> {                                      \
public:     constexpr static const char *   name = #elementType;                                    \
public:     typedef elementType             type;                                                   \
public:     typedef primitiveType           primitivable;                                           \
public:     typedef characterType           characterable;                                          \
public:     typedef pointerType             pointer;                                                \
public:     typedef pointerType             reference;                                              \
public:     static reference referenceOf(pointer o){ return o; }                                    \
public:     static const pointerType constReferenceOf(const pointerType o){ return o; }                 \
public:     constexpr static unsigned long  unit = size;                                            \
}

#endif // __POKEMONISM_SDK_TYPOGRAPHER_HH__