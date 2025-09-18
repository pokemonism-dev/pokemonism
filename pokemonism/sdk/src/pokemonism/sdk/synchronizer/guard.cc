/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 18, 2025
 */


#include "guard.hh"

namespace pokemonism {
}

#ifdef    __EXPORT_POKEMONISM_SDK_SYNCHRONIZER_GUARD
#include <cstdio>

using namespace pokemonism;
using namespace pokemonism::sdk;

template <class super> void test(typename synchronizer<super>::guard sync) {
    sync.lock();
    sync.unlock();
}

int main(void) {
    printf("hello\n");

    synchronizer<virtualable> o;

    test<virtualable>(synchronizer<virtualable>::guard(o));

    test<virtualable>(o);


    return 0;
}

#endif // __EXPORT_POKEMONISM_SDK_SYNCHRONIZER_GUARD
