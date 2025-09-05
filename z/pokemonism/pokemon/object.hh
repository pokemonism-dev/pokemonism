/**
 * @file        pokemon/object.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 28, 2025
 */

#ifndef   __POKEMONISM_POKEMON_OBJECT__HH__
#define   __POKEMONISM_POKEMON_OBJECT__HH__

#include <synchronizable.hh>

namespace pokemonism {
    namespace pokemon {
        class object : public virtual pokemonism::synchronizable {
        public:     class meta {
                    public:     virtual const object::meta & self(void) const { return *this; }
                    public:     virtual object::meta * clone(void) const { return nullptr; }
                    public:     meta(void) {}
                    public:     virtual ~meta(void) {}
                    public:     meta(const meta & o) = delete;
                    public:     meta(meta && o) noexcept = delete;
                    public:     meta & operator=(const meta & o) = delete;
                    public:     meta & operator=(meta && o) noexcept = delete;
                    };
        protected:  object::meta * meta;
        public:     virtual const object & self(void) const { return *this; }
        public:     virtual object * clone(void) const { return nullptr; }
        public:     int lock(void) override { return pokemonism::fail; }
        public:     int unlock(void) override { return pokemonism::fail; }
        public:     int wait(void) override { return pokemonism::fail; }
        public:     int wait(int64 second, int64 nano) override { return pokemonism::fail; }
        public:     int wakeup(void) override { return pokemonism::fail; }
        public:     int wakeup(bool all) override { return pokemonism::fail; }
        public:     object(void) : meta(nullptr) {}
        public:     ~object(void) override {}
        public:     object(const object & o) = delete;
        public:     object(object && o) noexcept = delete;
        public:     object & operator=(const object & o) = delete;
        public:     object & operator=(object && o) noexcept = delete;
        };
    }

    using object = pokemon::object;
}

#endif // __POKEMONISM_POKEMON_OBJECT__HH__