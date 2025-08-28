/**
 * @file        pokemon/meowth/virtual-return.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#include <pokemon/meowth.hh>

#include <pokemon/primitivable.hh>

#include <variant>

namespace pokemon { namespace meowth {
    class returnObject : public primitivable::object {
    public:     virtual int hello(void) { return 0; }
    public:     returnObject(void) {}
    public:     ~returnObject(void) override {}
    };

    class virtualReturnInterface {
    public:     virtual primitivable::object * operator()(void) = 0;
    public:     virtualReturnInterface(void) {}
    public:     virtual ~virtualReturnInterface() {}
    };

    class virtualReturnPrimitive : public virtualReturnInterface {
    public:     primitivable::object * operator()(void) override { return primitivable::object::gen(1004); }
    public:     virtualReturnPrimitive(void) {}
    public:     ~virtualReturnPrimitive() override {}
    };

    class virtualReturnObject : public virtualReturnInterface {
    public:     returnObject * operator()(void) override { return new returnObject(); }
    public:     virtualReturnObject(void) {}
    public:     ~virtualReturnObject() override {}
    };

    // primitivable::object

    class primitive : public primitivable::object {

    };

    class object : public primitivable::object {

    };
} }

using namespace pokemon;
using namespace pokemon::meowth;

int main(int argc, char ** argv) {

    printf("sizeof(variant<char, int, short, long, double>) => %ld\n", sizeof(std::variant<char, int, short, long, double>));

    {
        virtualReturnPrimitive o;

        primitivable::object * ret = o();

        printf("%d\n", primitivable::object::to::int32(ret));
    }

    {
        virtualReturnObject o;

        returnObject * ret = o();

        printf("%p\n", ret);

        delete ret;
    }



    return 0;
}