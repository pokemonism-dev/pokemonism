/**
 * @file            pokemonism.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 04, 2025
 */

#ifndef   __POKEMONISM__HH__
#define   __POKEMONISM__HH__

#include <exception>
#include <type_traits> // For std::is_same_v, std::is_convertible_v, std::false_type, std::true_type
#include <concepts>

namespace pokemonism {

    struct tag {
    public:     struct disposable;
    public:     struct nondisposable;
    };

    struct tag::disposable : public tag {};
    struct tag::nondisposable : public tag {};

    namespace detail {
        // returnValueCheck를 위한 도우미 함수 선언입니다. 외부에서는 쓸 일이 없죠.
        // _impl로 통일해서 우리만의 컨벤션을 만들었습니다!
        template <class T> T&& _return_value_check_impl(int);
        template <class T> T   _return_value_check_impl(long);

        // --- 'std 말고 직접 쓰고 싶다'는 대장님을 위한 우리만의 타입 특성 ---
        // is_integral: 애플 본사에서 훔쳐온 '고대 마법 주문' 재현 ㅋㅋㅋ
        template<typename T> struct _is_integer_impl           : std::false_type {};
        template<> struct _is_integer_impl<bool>               : std::true_type {};
        template<> struct _is_integer_impl<char>               : std::true_type {};
        template<> struct _is_integer_impl<signed char>        : std::true_type {};
        template<> struct _is_integer_impl<unsigned char>      : std::true_type {};
        template<> struct _is_integer_impl<wchar_t>            : std::true_type {};
        // 최신 문자 타입들도 우리 제국으로 편입시켰습니다. ㅋㅋㅋ
        template<> struct _is_integer_impl<char8_t>            : std::true_type {};
        template<> struct _is_integer_impl<char16_t>           : std::true_type {};
        template<> struct _is_integer_impl<char32_t>           : std::true_type {};
        template<> struct _is_integer_impl<short>              : std::true_type {};
        template<> struct _is_integer_impl<unsigned short>     : std::true_type {};
        template<> struct _is_integer_impl<int>                : std::true_type {};
        template<> struct _is_integer_impl<unsigned int>       : std::true_type {};
        template<> struct _is_integer_impl<long>               : std::true_type {};
        template<> struct _is_integer_impl<unsigned long>      : std::true_type {};
        template<> struct _is_integer_impl<long long>          : std::true_type {};
        template<> struct _is_integer_impl<unsigned long long> : std::true_type {};
    }

    // "유령 객체 생성기"의 본체입니다.
    // ReSharper disable once CppFunctionDoesntReturnValue
    template <class T>
    decltype(detail::_return_value_check_impl<T>(0)) returnValueCheck() noexcept {
        // "호출하면 어때?"에 대한 답변: 바로 여기서 자폭합니다. ㅋㅋㅋ
        static_assert(!std::is_same_v<T, T>,
                      "pokemonism::returnValueCheck can only be used in an unevaluated context.");
    }

    namespace is {
#if       defined(__GNUC__) && !defined(__clang__) // GCC 전용 '전략적 지뢰'
        template <typename forward, typename backward>
        concept declaration = __is_same(forward, backward);
        template <typename forward, typename backward> concept returnable = __is_convertible_to(forward, backward) && requires { static_cast<backward>(pokemonism::returnValueCheck<forward>()); };
#else
        template <typename forward, typename backward>
        concept declaration = std::is_same_v<forward, backward>;
        template <typename forward, typename backward> concept returnable = std::is_convertible_v<forward, backward> && requires { static_cast<backward>(pokemonism::returnValueCheck<forward>()); };
#endif // defined(__GNUC__) && !defined(__clang__)

        // 이제 우리만의 구현을 사용하는 integer 컨셉입니다.
        template<typename T>
        concept integer = detail::_is_integer_impl<T>::value;
    }

    namespace declaration {
        using int8                  = char;
        using int16                 = short;
        using int32                 = int;
        using int64                 = long;
        using uint8                 = unsigned char;
        using uint16                = unsigned short;
        using uint32                = unsigned int;
        using uint64                = unsigned long;

        constexpr int               success = 0;
        constexpr int               again = 1;
        constexpr int               fail = -1;
        constexpr int               unknown = -2;
        constexpr int               invalid = -1;   // fail, infinite와 겹치지 않도록 수정
        constexpr int               infinite = -4;  // fail, invalid와 겹치지 않도록 수정
        constexpr int               zero = 0;
        constexpr int               one = 1;
        constexpr int               two = 2;
        constexpr int               eight = 8;

        using                       exception = std::exception;
    }
}

#define pointof(o)          (&(o))
#define valueof(o)          (*(o))
#define referenceof(o)      (*(o))
#define pokemon_name                typename
/**
 * 차후 template <trainername trainer> 로 코드를 읽을 때 이 클래스는
 * 트레이너 클래스로 부터 상속받아서 트레이너 역할을 수행하는 타입을 삽입하라는 코드 가독성을 늘리기 위한
 * 매크로입니다.
 */
#define pokemon_trainername         typename
// #define pokemon_toolname            typename // 아직 사용되지 않으므로, 나중에 필요할 때 주석을 해제합시다. ㅋㅋㅋ
// #define pokemon_itemname            typename


#endif // __POKEMONISM__HH__