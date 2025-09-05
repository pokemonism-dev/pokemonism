/**
 * @file            pokemonism/supporter/lana.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 5, 2025
 */

#ifndef   __POKEMONISM_SUPPORTER_LANA_HH__
#define   __POKEMONISM_SUPPORTER_LANA_HH__

#include <pokemonism/pokemon.hh>

namespace pokemonism {

    class lana : public pokemon::trainer {
    protected:  static lana & singleton;
    public:     static lana & one(void);
    public:     static const char * name(void) { return singleton.name_(); }
    public:     const char * name_(void) const noexcept override { return "lana"; }
    protected:  lana(void);
    protected:  ~lana(void) override;
    public:     lana(const lana & o) = delete;
    public:     lana(lana && o) noexcept = delete;
    public:     lana & operator=(const lana & o) = delete;
    public:     lana & operator=(lana && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SUPPORTER_LANA_HH__