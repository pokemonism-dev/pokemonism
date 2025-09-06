/**
 * @file            pokemonism/sdk/engine.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_SDK_ENGINE_HH__
#define   __POKEMONISM_SDK_ENGINE_HH__

#include <pokemonism.hh>
#include <pokemonism/sdk/command.hh>
#include <pokemonism/sdk/commandable.hh>

namespace pokemonism::sdk {

    class engine {
    protected:  event::queue * queue;
    protected:  struct set {
                    command::event::generator * generator;
                };
    protected:  inline event * add(event * e);
    protected:  inline event * del(event * e);
    public:     friend command::event::generator;
    };

}

#endif // __POKEMONISM_SDK_ENGINE_HH__