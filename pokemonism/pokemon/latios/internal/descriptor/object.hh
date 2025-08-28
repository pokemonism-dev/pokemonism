/**
* @file        pokemon/latios/descriptor.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_DESCRIPTOR_OBJECT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_DESCRIPTOR_OBJECT__HH__

#include <pokemon/latios/descriptor.hh>

namespace pokemon { namespace latios { namespace internal { namespace descriptor {

    class object : public latios::descriptor {
    protected:  int v;
    protected:  uint32
    public:     int value(void) const;
    public:     uint32 status(void) const override;
    public:     uint32 properties(void) const override;
    public:     pokemon::exception * exception(void) const override;
    public:     uint32 type(void) const override;
    public:     int open(void) override;
    public:     int close(void) override;
    public:     packet & read(packet & o) override;
    public:     string & write(string & o) override;
    public:     object(void);
    public:     ~object(void) override;
    public:     object(const object & o) = delete;
    public:     object(object && o) noexcept = delete;
    public:     object & operator=(const object & o) = delete;
    public:     object & operator=(object && o) noexcept = delete;
    };

    // class descriptor : public virtual latios::descriptor {
    // // protected:  int v;
    // // protected:  uint32 state;
    // // protected:  uint32 property;
    // // protected:  pokemon::exception * exception;
    //
    //
    // public:     inline int value(void) const { return v; }
    // public:     uint32 status(void) const override;
    // public:     uint32 properties(void) const override;
    // public:     pokemon::exception * exception(void) const override;
    // public:     uint32 type(void) const override;
    // public:     int open(void) override;
    // public:     int close(void) override;
    // public:     packet & read(packet & o) override;
    // public:     string & write(string & o) override;
    // public:     explicit descriptor(int v);
    // public:     descriptor(void);
    // public:     ~descriptor(void) override;
    // public:     descriptor(const descriptor & o) = delete;
    // public:     descriptor(descriptor && o) noexcept = delete;
    // public:     descriptor & operator=(const descriptor & o) = delete;
    // public:     descriptor & operator=(descriptor && o) noexcept = delete;
    // };

} } } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_DESCRIPTOR_OBJECT__HH__