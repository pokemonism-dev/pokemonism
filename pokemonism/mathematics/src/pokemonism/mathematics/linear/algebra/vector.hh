/**
 * @file
 * @brief
 * @details         길이, 넓이, 부피, 질량, 온도와 같이 측정 가능한 양들은 각각츼 크기를 명시함으로써 완전히 나타낼 수 있다. 반면에 속도, 힘,
 *                  가속도와 같은 양들을 나타내기 위해서는 크기와 방ㅎ샹이 모두 필요하다. 이러한 양들을 벡터라고 한다.
 *
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 12, 2025
 */

#ifndef   __POKEMONISM_MATHEMATICS_LINEAR_ALGEBRA_VECTOR_HH__
#define   __POKEMONISM_MATHEMATICS_LINEAR_ALGEBRA_VECTOR_HH__

#include <cstring>

#include <pokemonism/mathematics/scalar.hh>

namespace pokemonism::mathematics::linear::algebra {

    template <int dimension, class Precisional = ScalarTag>
    class Vector {
    public:     constexpr static unsigned long size = sizeof(Precisional::Type) * dimension;
    public:     static const Vector<dimension, Precisional> zero;
    protected:  Precisional::Type v[dimension];
    public:     inline Vector(void);
    public:     inline ~Vector(void);
    public:     inline Vector(const Vector<dimension, Precisional> & o);
    public:     inline Vector(Vector<dimension, Precisional> && o) noexcept;
    public:     inline Vector<dimension, Precisional> & operator=(const Vector<dimension, Precisional> & o);
    public:     inline Vector<dimension, Precisional> & operator=(Vector<dimension, Precisional> && o) noexcept;
    public:     inline Vector<dimension, Precisional> & operator+=(const Vector<dimension, Precisional> & o);
    public:     inline Vector<dimension, Precisional> & operator-=(Vector<dimension, Precisional> && o) noexcept;
    public:     friend inline Vector<dimension, Precisional> operator+(const Vector<dimension, Precisional> & o);
    public:     friend inline Vector<dimension, Precisional> operator+(const Vector<dimension, Precisional> & left, const Vector<dimension, Precisional> & right);
    public:     friend inline Vector<dimension, Precisional> operator-(const Vector<dimension, Precisional> & o);
    public:     friend inline Vector<dimension, Precisional> operator-(const Vector<dimension, Precisional> & left, const Vector<dimension, Precisional> & right);
    public:     template <typename Primitivable> friend inline Vector<dimension, Precisional> operator*(Primitivable left, const Vector<dimension, Precisional> & right);
    public:     template <typename Primitivable> friend inline Vector<dimension, Precisional> operator*(const Vector<dimension, Precisional> & left, Primitivable right);
    public:     template <typename Primitivable> friend inline Vector<dimension, Precisional> operator/(Primitivable left, const Vector<dimension, Precisional> & right);
    public:     template <typename Primitivable> friend inline Vector<dimension, Precisional> operator/(const Vector<dimension, Precisional> & left, Primitivable right);
    };

    template <int dimension, class Precisional>
    inline Vector<dimension, Precisional>::Vector(void) {
    }

    template <int dimension, class Precisional>
    inline Vector<dimension, Precisional>::~Vector(void) {

    }

    template <int dimension, class Precisional>
    inline Vector<dimension, Precisional>::Vector(const Vector<dimension, Precisional> & o) {
        ::memcpy(v, o.v, size);
    }

    template <int dimension, class Precisional>
    inline Vector<dimension, Precisional>::Vector(Vector<dimension, Precisional> && o) noexcept {
        ::memcpy(v, o.v, size);
    }

    template <int dimension, class Precisional>
    inline Vector<dimension, Precisional> & Vector<dimension, Precisional>::operator=(const Vector<dimension, Precisional> & o) {
        if (pointof(o) != this) ::memcpy(v, o.v, size);
        return *this;
    }

    template <int dimension, class Precisional>
    inline Vector<dimension, Precisional> & Vector<dimension, Precisional>::operator=(Vector<dimension, Precisional> && o) noexcept {
        if (pointof(o) != this) ::memcpy(v, o.v, size);
        return *this;
    }

    template <int dimension, class Precisional>
    inline Vector<dimension, Precisional> & Vector<dimension, Precisional>::operator+=(const Vector<dimension, Precisional> & o) {
        if (pointof(o) != this) {
            for (int i = 0; i < dimension; i = i + 1) v[i] = v[i] + o.v[i];
        }
        return *this;
    }

    template <int dimension, class Precisional>
    inline Vector<dimension, Precisional> & Vector<dimension, Precisional>::operator-=(Vector<dimension, Precisional> && o) noexcept {
        if (pointof(o) != this) {
            for (int i = 0; i < dimension; i = i + 1) v[i] = v[i] - o.v[i];
        }
        return *this;
    }

    template <int dimension, class Precisional>
    inline Vector<dimension, Precisional> operator+(const Vector<dimension, Precisional> & o) {
        return Vector<dimension, Precisional>(o);
    }

    template <int dimension, class Precisional>
    inline Vector<dimension, Precisional> operator+(const Vector<dimension, Precisional> & left, const Vector<dimension, Precisional> & right) {
        Vector<dimension, Precisional> x(left);

        // ### 20250912 | SUPPORT SIMD, CUDA
        for (int i = 0; i < dimension; i = i + 1) x.v[i] = x.v[i] + right.v[i];

        return x;
    }

    template <int dimension, class Precisional, typename Primitivable>
    inline Vector<dimension, Precisional> operator*(Primitivable left, const Vector<dimension, Precisional> & right) {
        Vector<dimension, Precisional> x;

        // ### 20250912 | SUPPORT SIMD, CUDA
        for (int i = 0; i < dimension; i = i + 1) x.v[i] = left * right.v[i];

        return x;
    }

    template <int dimension, class Precisional, typename Primitivable>
    inline Vector<dimension, Precisional> operator*(const Vector<dimension, Precisional> & left, Primitivable right) {
        Vector<dimension, Precisional> x;

        // ### 20250912 | SUPPORT SIMD, CUDA
        for (int i = 0; i < dimension; i = i + 1) x.v[i] = right * left.v[i];

        return x;
    }

    template <int dimension, class Precisional>
    inline Vector<dimension, Precisional> operator-(const Vector<dimension, Precisional> & o) {
        Vector<dimension, Precisional> x;

        // ### 20250912 | SUPPORT SIMD, CUDA
        for (int i = 0; i < dimension; i = i + 1) x.v[i] = -1 * o.v[i];

        return x;
    }

    template <int dimension, class Precisional>
    inline Vector<dimension, Precisional> operator-(const Vector<dimension, Precisional> & left, const Vector<dimension, Precisional> & right) {
        Vector<dimension, Precisional> x(left);

        // ### 20250912 | SUPPORT SIMD, CUDA
        for (int i = 0; i < dimension; i = i + 1) x.v[i] = x.v[i] - right.v[i];

        return x;
    }

    template <int dimension, class Precisional, typename Primitivable>
    inline Vector<dimension, Precisional> operator/(Primitivable left, const Vector<dimension, Precisional> & right) {
        Vector<dimension, Precisional> x;

        // ### 20250912 | SUPPORT SIMD, CUDA
        for (int i = 0; i < dimension; i = i + 1) x.v[i] = left / right.v[i];

        return x;
    }

    template <int dimension, class Precisional, typename Primitivable>
    inline Vector<dimension, Precisional> operator/(const Vector<dimension, Precisional> & left, Primitivable right) {
        Vector<dimension, Precisional> x;

        // ### 20250912 | SUPPORT SIMD, CUDA
        for (int i = 0; i < dimension; i = i + 1) x.v[i] = right / left.v[i];

        return x;
    }

}

#endif // __POKEMONISM_MATHEMATICS_LINEAR_ALGEBRA_VECTOR_HH__