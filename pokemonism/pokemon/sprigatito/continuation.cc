/**
 * @file        pokemon/sprigatito/continuation.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#include "continuation.hh"

namespace pokemon { namespace sprigatito { namespace diagnostic {
    using namespace sprigatito;

    class example {
    public:     virtual ~example() {}
    };

    void continuationCheck(void) {
        continuation<char> o1;
        continuation<long> o2;
        continuation<example> o3;
    }

} } }
