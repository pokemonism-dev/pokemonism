/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_APPLICATION_HH__
#define   __POKEMONISM_APPLICATION_HH__

#include <pokemonism/window/applicationable.hh>
#include <pokemonism/window/interface/application.hh>


namespace pokemonism::window {

    class PlatformWindowApplication : public WindowApplicationable {
    public:     static PlatformWindowApplication & get(void);
    public:     PlatformWindowApplication(void);
    public:     ~PlatformWindowApplication(void) override;
    public:     PlatformWindowApplication(const PlatformWindowApplication & o) = delete;
    public:     PlatformWindowApplication(PlatformWindowApplication && o) noexcept = delete;
    public:     PlatformWindowApplication & operator=(const PlatformWindowApplication & o) = delete;
    public:     PlatformWindowApplication & operator=(PlatformWindowApplication && o) noexcept = delete;
    };

    inline PlatformWindowApplication::PlatformWindowApplication(void) {

    }

    inline PlatformWindowApplication::~PlatformWindowApplication(void) {

    }


}

#endif // __POKEMONISM_APPLICATION_HH__