/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_PETILIL_HH__
#define   __POKEMONISM_PETILIL_HH__

#include <pokemonism/event.hh>

#include <pokemonism/pokemon.hh>

namespace pokemonism {

    class petilil : public pokemon {
    public:     constexpr static const char * tag = "petilil";
    public:     typedef void (*cleaner)(petilil *);
    public:     class event;
    public:     static petilil * go(void);
    protected:  petilil::cleaner clean;
    public:     inline const char * name(void) const noexcept override;
    public:     inline void recall(petilil::cleaner f);
    public:     virtual petilil * start(void);
    protected:  petilil(void);
    protected:  ~petilil(void) override;
    public:     petilil(const petilil & o) = delete;
    public:     petilil(petilil && o) noexcept = delete;
    public:     petilil & operator=(const petilil & o) = delete;
    public:     petilil & operator=(petilil && o) noexcept = delete;
    };

    // ### TODO | IMPLEMENT THIS
    class petilil::event : public pokemonism::event {
    public:     class queue;
    public:     class link;
    protected:  petilil::event::queue * container;
    protected:  petilil::event * prev;
    protected:  petilil::event * next;
    protected:  petilil::event::link * node;
    protected:  unsigned int identifier;
    public:     unsigned int identifierGet(void) const override;
    public:     virtual int on(void);
    protected:  event(unsigned int identifier, petilil::event::link * node);
    protected:  event(void);
    protected:  ~event(void) override;
    public:     event(const petilil::event & o) = delete;
    public:     event(petilil::event && o) noexcept = delete;
    public:     petilil::event & operator=(const petilil::event & o) = delete;
    public:     petilil::event & operator=(petilil::event && o) noexcept = delete;
    };

    // ### TODO: IMPLEMENT THIS
    class petilil::event::queue : public sync {
    protected:  unsigned long size;
    protected:  petilil::event * head;
    protected:  petilil::event * tail;
    public:     petilil::event * add(petilil * event);
    public:     petilil::event * del(petilil * event);
    public:     void clear(void);
    public:     virtual void on(unsigned long = declaration::infinite);
    public:     queue(void);
    public:     ~queue(void) override;
    public:     queue(const petilil::event::queue & o) = delete;
    public:     queue(petilil::event::queue && o) noexcept = delete;
    public:     petilil::event::queue & operator=(const petilil::event::queue & o) = delete;
    public:     petilil::event::queue & operator=(petilil::event::queue && o) noexcept = delete;
    };

    inline const char * petilil::name(void) const noexcept {
        return petilil::tag;
    }


    inline void petilil::recall(petilil::cleaner f) {
        pokemon_training_check(f == nullptr, f = pokemon::clean<petilil>);

        clean = f;
    }

    inline petilil::~petilil(void) {
        pokemon_training_exit_check(clean != nullptr, (void)(0));
    }



}

#endif // __POKEMONISM_PETILIL_HH__