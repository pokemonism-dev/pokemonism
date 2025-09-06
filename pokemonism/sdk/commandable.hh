/**
 * @file            pokemonism/sdk/commandable.hh
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 4, 2025
 *
 * C++ 의 공변환 상속의 제약으로 포인터에 대한 리턴을 지원해애만
 * 상속하여 리턴 값을 변화시킬 수 있다.
 */

#ifndef   __POKEMONISM_SDK_COMMANDABLE_HH__
#define   __POKEMONISM_SDK_COMMANDABLE_HH__

#include <pokemonism/sdk/callable.hh>

namespace pokemonism::sdk {

    class commandable : public callable<primitivable> {
    public:     typedef primitivable    output;
    public:     output * operator()(void) override = 0;
    public:     commandable(void) {}
    public:     ~commandable(void) override {}
    public:     commandable(const commandable & o) = delete;
    public:     commandable(commandable && o) noexcept = delete;
    public:     commandable & operator=(const commandable & o) = delete;
    public:     commandable & operator=(commandable && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_COMMANDABLE_HH__