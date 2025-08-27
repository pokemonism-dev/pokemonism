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
// #include <pokemon/latios/internal.hh>
// #include <pokemon/latios/internal.temp/queue.hh>

using namespace pokemon;

namespace pokemon { namespace meowth { namespace persian {
    /**
     * 사용자에게 중간 단계 ...
     */
    class command : public latios::command {
    public:     primitivable::object * operator()(void) override { return primitivable::object::gen(1004); }
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

    // latios::internal::queue queue;
    //
    // printf("%s\n", latios::engine.tag());

    command o;

    printf("%ld\n", primitivable::object::to::int64(o()));

    // latios::engine.reg(addressof(o));

    // latios::engine::run

    return 0;
}