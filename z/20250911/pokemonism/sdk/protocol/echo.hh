/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_PROTOCOL_ECHO_HH__
#define   __POKEMONISM_PROTOCOL_ECHO_HH__

#include <pokemonism/sdk/protocol.hh>
#include <pokemonism/sdk/generic/serializer.hh>
#include <pokemonism/sdk/generic/deserializer.hh>

namespace pokemonism::protocol {

    class echo : public pokemonism::sdk::protocol {
    public:     static echo & get(void);
    public:     class serializer;
    public:     class deserializer;
    public:     static echo::deserializer & in;
    public:     static echo::serializer & out;
    protected:  echo(void);
    public:     ~echo(void) override;
    public:     echo(const echo & o) = delete;
    public:     echo(echo && o) noexcept = delete;
    public:     echo & operator=(const echo & o) = delete;
    public:     echo & operator=(echo && o) noexcept = delete;
    };

    class echo::serializer : public pokemonism::sdk::generic::serializer<pokemonism::sdk::stream, pokemonism::sdk::stream> {
    public:     static echo::serializer & get(void);
    public:     pokemonism::sdk::stream * serialize(pokemonism::sdk::stream * input, pokemonism::sdk::stream * output = nullptr) override;
    public:     virtual pokemonism::sdk::stream * serialize(const char * format, ...);
    protected:  echo & protocol;
    protected:  explicit serializer(echo & protocol);
    public:     serializer(void) = delete;
    public:     ~serializer(void) override;
    public:     serializer(const echo::serializer & o) = delete;
    public:     serializer(echo::serializer && o) noexcept = delete;
    public:     echo::serializer & operator=(const echo::serializer & o) = delete;
    };

    class echo::deserializer : public pokemonism::sdk::generic::deserializer<pokemonism::sdk::stream, pokemonism::sdk::stream> {
    public:     static echo::deserializer & get(void);
    protected:  pokemonism::sdk::stream * deserialize(pokemonism::sdk::stream * input, pokemonism::sdk::stream * output) override;
    protected:  echo & protocol;
    protected:  explicit deserializer(echo & protocol);
    public:     deserializer(void) = delete;
    public:     ~deserializer(void) override;
    public:     deserializer(const echo::deserializer & o) = delete;
    public:     deserializer(echo::deserializer && o) noexcept = delete;
    public:     echo::deserializer & operator=(const echo::deserializer & o) = delete;
    };

    // echo::in

}

#endif // __POKEMONISM_PROTOCOL_ECHO_HH__
