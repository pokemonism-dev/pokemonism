/**
 * @file        pokemonism/mareep.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 */

#ifndef   __POKEMONISM_MAREEP__HH__
#define   __POKEMONISM_MAREEP__HH__

#include <pokemonism/mareep/observer.hh>
#include <pokemonism/mareep/observable.hh>
#include <pokemonism/mareep/subscription.hh>

namespace pokemonism {
    namespace mareep {

    }

    using subscription = mareep::subscription;
    template <class element> using observer = mareep::observer<element>;
    template <class element> using observable = mareep::observable<element>;
}



#endif // __POKEMONISM_MAREEP__HH__