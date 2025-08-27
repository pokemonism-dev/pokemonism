/**
 * @file        pokemon/meowth/persian/latios-engine.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#include <pokemon/latios.hh>
#include <pokemon/latios/command.hh>

using namespace pokemon;

namespace pokemon { namespace meowth { namespace persian {

    class command : public latios::command {
    public:     int64 operator()(void) override { return random(); }
    public:     inline command(void) {}
    public:     inline ~command(void) override {}
    public:     command(const command & o) = delete;
    public:     command(command && o) noexcept = delete;
    public:     command & operator=(const command & o) = delete;
    public:     command & operator=(command && o) noexcept = delete;
    };
} } }

using namespace pokemon::meowth::persian;

int main(int argc, char ** argv) {
    srandom(time(nullptr));

    printf("%s\n", latios::engine.tag());

    command o;

    printf("%ld\n", o());

    latios::engine.reg(addressof(o));

    return 0;
}