/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#include "vector.hh"

#ifdef    __EXPOSE_POKEMONISM_MATHEMATICS_LINEAR_ALGEBRA_VECTOR_EXAMPLE
#include <cstdio>

#include <pokemonism/mathematics/geometry.hh>

using namespace pokemonism;
using namespace pokemonism::mathematics;
using namespace pokemonism::mathematics::geometry;
using namespace pokemonism::mathematics::linear::algebra;

int main(int argc, char ** argv) {
    Point<dimension::two> a(-1, 2);
    Point<dimension::two> b(3, 4);

    Vector<dimension::two> first = b - a;

    printf("first: $\\overrightarrow{AB}=(%d, %d)$\n", first[geometry::plane::axis::x], first[geometry::plane::axis::y]);

    // 특별한 콘솔에 이미지를 그리고 싶다.

    Point<dimension::two> c(2, -1);

    Vector<dimension::two> second = c + first;

    printf("second: $\\overrightarrow{AB}=(%d, %d)$\n", second[geometry::plane::axis::x], second[geometry::plane::axis::y]);

    return 0;
}
#endif // __EXPOSE_POKEMONISM_MATHEMATICS_LINEAR_ALGEBRA_VECTOR_EXAMPLE
