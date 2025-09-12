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
    const Point<dimension::two> a(-1, 2);
    const Point<dimension::two> b(3, 4);

    Vector<dimension::two> first = b - a;

    FILE * fp = fopen("test.md", "w+b");

    fprintf(fp, "__예제 1.1.__ $A=(-1, 2)$ 이고 $B=(3, 4)$일 때, $\\overrightarrow{AB}$를 구하고\n\n");

    fprintf(fp, "1. 표준 위치인 벡터로 그려라.\n");
    fprintf(fp, "2. 시점이 $C=(2, -1)$인 벡터로 그려라.\n\n");

    fprintf(fp, "first: $\\overrightarrow{AB}=(%d, %d)$\n\n", first[geometry::plane::axis::x], first[geometry::plane::axis::y]);

    /**
     * 마크다운으로 그리고 싶을까?... 어떻게 해야 하지....
     * 나는 잘 모르겠다. 무엇 하나 다 난관이다.
     * 어떻게 풀까....?
     *
     * 1. 마크다운
     *
     * 쉬운 길이 없구나...
     */

    // 특별한 콘솔에 이미지를 그리고 싶다.

    const Point<dimension::two> c(2, -1);

    Vector<dimension::two> second = c + first;

    fprintf(fp, "second: $\\overrightarrow{AB}=(%d, %d)$\n\n", second[geometry::plane::axis::x], second[geometry::plane::axis::y]);

    fclose(fp);

    return 0;
}
#endif // __EXPOSE_POKEMONISM_MATHEMATICS_LINEAR_ALGEBRA_VECTOR_EXAMPLE
