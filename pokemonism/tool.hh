/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_TOOL_HH__
#define   __POKEMONISM_TOOL_HH__

#include <pokemonism.hh>

namespace pokemonism {

    class tool {
    public:     tool(void) {}
    public:     virtual ~tool(void) {}
    public:     tool(const tool & o) = delete;
    public:     tool(tool && o) noexcept = delete;
    public:     tool & operator=(const tool & o) = delete;
    public:     tool & operator=(tool && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_TOOL_HH__