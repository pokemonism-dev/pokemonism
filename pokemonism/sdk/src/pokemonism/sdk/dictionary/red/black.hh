/**
 * @file
 * @brief
 * @details
 * ### TODO: 이름 공간 오염 (Namespace Pollution)
 * 헤더 파일의 전역 스코프에서 `using namespace`를 사용하는 것은 매우 위험한 관행입니다.
 * 이름 충돌(name collision)을 일으켜 예측할 수 없는 버그를 유발할 수 있습니다.
 * 이 `using` 구문은 클래스 내부나 `.cc` 파일로 옮겨야 합니다.
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 19, 2025
 */

#ifndef   __POKEMONISM_BLACK_HH__
#define   __POKEMONISM_BLACK_HH__

#include <pokemonism/sdk/dictionary/binary/search.hh>

namespace pokemonism::sdk::dictionary::red {

    // 'using namespace'를 헤더의 전역 스코프에 두는 것은 위험하므로,
    // 클래스 내부나 cpp 파일로 옮기는 것이 좋습니다. 여기서는 명시적으로 전체 이름을 사용합니다.
    template <typename collection, typename item, class comparator>
    class black : public pokemonism::sdk::dictionary::binary::search<collection, item, comparator> {

    };

}

#endif // __POKEMONISM_BLACK_HH__