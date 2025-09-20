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
#include <cstdint>   // 우리 '신세계'의 '국제 표준 단위계'입니다. ㅋㅋㅋ

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
        // ReSharper disable once CppFunctionIsNotImplemented
        template <class T> T&& _return_value_check_impl(int);
        // ReSharper disable once CppFunctionIsNotImplemented
        template <class T> T   _return_value_check_impl(long);
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

    }

    using int8                  = std::int8_t;
    using int16                 = std::int16_t;
    using int32                 = std::int32_t;
    using int64                 = std::int64_t;
    using uint8                 = std::uint8_t;
    using uint16                = std::uint16_t;
    using uint32                = std::uint32_t;
    using uint64                = std::uint64_t;

    /**
     * 잠만보만 사용하는 선언문
     */
    namespace declaration {
        using int8                  = std::int8_t;
        using int16                 = std::int16_t;
        using int32                 = std::int32_t;
        using int64                 = std::int64_t;
        using uint8                 = std::uint8_t;
        using uint16                = std::uint16_t;
        using uint32                = std::uint32_t;
        using uint64                = std::uint64_t;

        constexpr int               success = 0;
        constexpr int               again = 1;
        constexpr int               fail = -1;
        constexpr int               unknown = -2;
        constexpr unsigned int      infinite = 0xFFFFFFFFU;  // '시간'은 다른 값들과 섞이면 안되죠.
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