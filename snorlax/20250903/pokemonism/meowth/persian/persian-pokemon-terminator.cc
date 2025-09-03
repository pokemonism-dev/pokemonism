#include <cstdio>
namespace pokemonism::pokemon::interface {
    template <int max, typename... argumentable> struct terminatable { typedef void (*type)(argumentable...); type func[max]; type basic; };
    template <typename... argumentable> struct terminator { typedef void (*type)(argumentable...); type terminate; explicit terminator(type terminate) : terminate(terminate) {} };
    template <int max, typename... argumentable> inline terminator<argumentable...> operator-(terminatable<max, argumentable...> & o, long n) {
        if (n < max) {
            typename terminatable<max, argumentable...>::type f = o.func[n];
            if (f != nullptr) return terminator<argumentable...>(f);
        }
        return terminator<argumentable...>(o.basic);
    }
}
namespace pokemonism::pokemon {
    class pidgey {
    public:     pidgey(void) {}
    public:     virtual ~pidgey(void) { printf("meow meow..., gougou is terminated. I'll be back. 🤦👋🤪\n"); }
    };
}
static void terminator_1(pokemonism::pokemon::pidgey * o) { delete o; }
static void terminator_800(pokemonism::pokemon::pidgey * o) { delete o; }
static pokemonism::pokemon::interface::terminatable<1000, pokemonism::pokemon::pidgey *> T;
using namespace pokemonism;
int main(int argc, char ** argv) {
    T.func[800] = terminator_800;
    T.basic = terminator_1;
    pokemon::pidgey * pidgey1 = new pokemon::pidgey();
    (T-800).terminate(pidgey1);
    return 0;
}