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

#ifndef   __POKEMONISM_MATHEMATICS_LINEAR_ALGEBRA_VECTOR_DIMENSION_TWO_HH__
#define   __POKEMONISM_MATHEMATICS_LINEAR_ALGEBRA_VECTOR_DIMENSION_TWO_HH__


#include <pokemonism/mathematics/geometry.hh>
#include <pokemonism/mathematics/linear/algebra/vector.hh>

namespace pokemonism::mathematics::linear::algebra {

    template <class Precisional>
    class Vector<geometry::dimension::two, Precisional> {
    public:     constexpr static unsigned long size = sizeof(typename Precisional::Type) * geometry::dimension::two;
    public:     static const Vector<geometry::dimension::two, Precisional> zero;
    protected:  Precisional::Type v[geometry::dimension::two];
    public:     inline Precisional::Type & at(unsigned int index);
    public:     inline const Precisional::Type & at(unsigned int index) const;
    public:     inline Vector(Precisional::Type x, Precisional::Type y);
    public:     inline Vector(void);
    public:     inline ~Vector(void);
    public:     inline Vector(const Vector<geometry::dimension::two, Precisional> & o);
    public:     inline Vector(Vector<geometry::dimension::two, Precisional> && o) noexcept;
    public:     inline Vector<geometry::dimension::two, Precisional> & operator=(const Vector<geometry::dimension::two, Precisional> & o);
    public:     inline Vector<geometry::dimension::two, Precisional> & operator=(Vector<geometry::dimension::two, Precisional> && o) noexcept;
    public:     inline Precisional::Type & operator[](unsigned int index);
    public:     inline const Precisional::Type & operator[](unsigned int index) const;
    public:     inline Vector<geometry::dimension::two, Precisional> & operator+=(const Vector<geometry::dimension::two, Precisional> & o);
    public:     inline Vector<geometry::dimension::two, Precisional> & operator-=(Vector<geometry::dimension::two, Precisional> && o) noexcept;
    public:     friend inline Vector<geometry::dimension::two, Precisional> operator+(const Vector<geometry::dimension::two, Precisional> & o) {
                    return Vector<geometry::dimension::two, Precisional>(o);
                }
    public:     friend inline Vector<geometry::dimension::two, Precisional> operator+(const Vector<geometry::dimension::two, Precisional> & left, const Vector<geometry::dimension::two, Precisional> & right) {
                    Vector<geometry::dimension::two, Precisional> x;
                    for (int i = 0; i < geometry::dimension::two; i = i + 1) x[i] = left[i] + right[i];
                    return x;
                }
    public:     friend inline Vector<geometry::dimension::two, Precisional> operator-(const Vector<geometry::dimension::two, Precisional> & o) {
                    Vector<geometry::dimension::two, Precisional> x;

                    // ### 20250912 | SUPPORT SIMD, CUDA
                    for (int i = 0; i < geometry::dimension::two; i = i + 1) x = -1 * o[i];

                    return x;
                }
    public:     friend inline Vector<geometry::dimension::two, Precisional> operator-(const Vector<geometry::dimension::two, Precisional> & left, const Vector<geometry::dimension::two, Precisional> & right) {
                    Vector<geometry::dimension::two, Precisional> x;

                    // ### 20250912 | SUPPORT SIMD, CUDA
                    for (int i = 0; i < geometry::dimension::two; i = i + 1) {
                        x[i] = left[i] - right[i];
                    }

                    return x;
                }
    public:     template <typename Primitivable> friend inline Vector<geometry::dimension::two, Precisional> operator*(Primitivable left, const Vector<geometry::dimension::two, Precisional> & right) {
                    Vector<geometry::dimension::two, Precisional> x;

                    // ### 20250912 | SUPPORT SIMD, CUDA
                    for (int i = 0; i < geometry::dimension::two; i = i + 1) x[i] = left * right[i];

                    return x;
                }
    public:     template <typename Primitivable> friend inline Vector<geometry::dimension::two, Precisional> operator*(const Vector<geometry::dimension::two, Precisional> & left, Primitivable right) {
                    Vector<geometry::dimension::two, Precisional> x;

                    // ### 20250912 | SUPPORT SIMD, CUDA
                    for (int i = 0; i < geometry::dimension::two; i = i + 1) x[i] = left[i] * right;

                    return x;
                }
    public:     template <typename Primitivable> friend inline Vector<geometry::dimension::two, Precisional> operator/(Primitivable left, const Vector<geometry::dimension::two, Precisional> & right) {
                    Vector<geometry::dimension::two, Precisional> x;

                    // ### 20250912 | SUPPORT SIMD, CUDA
                    for (int i = 0; i < geometry::dimension::two; i = i + 1) x[i] = left / right[i];

                    return x;
                }
    public:     template <typename Primitivable> friend inline Vector<geometry::dimension::two, Precisional> operator/(const Vector<geometry::dimension::two, Precisional> & left, Primitivable right) {
                    Vector<geometry::dimension::two, Precisional> x;

                    // ### 20250912 | SUPPORT SIMD, CUDA
                    for (int i = 0; i < geometry::dimension::two; i = i + 1) x[i] = left[i] / right;

                    return x;
                }
    };

    template <class Precisional>
    inline Precisional::Type & Vector<geometry::dimension::two, Precisional>::at(unsigned int index) {
        if (geometry::dimension::two <= index) throw Exception();

        return v[index];
    }

    template <class Precisional>
    inline const Precisional::Type & Vector<geometry::dimension::two, Precisional>::at(unsigned int index) const {
        if (geometry::dimension::two <= index) throw Exception();

        return v[index];
    }

    template <class Precisional>
    inline Vector<geometry::dimension::two, Precisional>::Vector(typename Precisional::Type x, typename Precisional::Type y) {
        v[geometry::plane::axis::x] = x;
        v[geometry::plane::axis::y] = y;
    }

    template <class Precisional>
    inline Vector<geometry::dimension::two, Precisional>::Vector(void) {
    }

    template <class Precisional>
    inline Vector<geometry::dimension::two, Precisional>::~Vector(void) {

    }

    template <class Precisional>
    inline Vector<geometry::dimension::two, Precisional>::Vector(const Vector<geometry::dimension::two, Precisional> & o) {
        ::memcpy(v, o.v, size);
    }

    template <class Precisional>
    inline Vector<geometry::dimension::two, Precisional>::Vector(Vector<geometry::dimension::two, Precisional> && o) noexcept {
        ::memcpy(v, o.v, size);
    }

    template <class Precisional>
    inline Vector<geometry::dimension::two, Precisional> & Vector<geometry::dimension::two, Precisional>::operator=(const Vector<geometry::dimension::two, Precisional> & o) {
        if (pointof(o) != this) ::memcpy(v, o.v, size);
        return *this;
    }

    template <class Precisional>
    inline Vector<geometry::dimension::two, Precisional> & Vector<geometry::dimension::two, Precisional>::operator=(Vector<geometry::dimension::two, Precisional> && o) noexcept {
        if (pointof(o) != this) ::memcpy(v, o.v, size);
        return *this;
    }

    template <class Precisional>
    inline Precisional::Type & Vector<geometry::dimension::two, Precisional>::operator[](unsigned int index) {
        if (geometry::dimension::two <= index) throw Exception();

        return v[index];
    }

    template <class Precisional>
    inline const Precisional::Type & Vector<geometry::dimension::two, Precisional>::operator[](unsigned int index) const {
        if (geometry::dimension::two <= index) throw Exception();

        return v[index];
    }


    template <class Precisional>
    inline Vector<geometry::dimension::two, Precisional> & Vector<geometry::dimension::two, Precisional>::operator+=(const Vector<geometry::dimension::two, Precisional> & o) {
        if (pointof(o) != this) {
            for (int i = 0; i < geometry::dimension::two; i = i + 1) v[i] = v[i] + o.v[i];
        }
        return *this;
    }

    template <class Precisional>
    inline Vector<geometry::dimension::two, Precisional> & Vector<geometry::dimension::two, Precisional>::operator-=(Vector<geometry::dimension::two, Precisional> && o) noexcept {
        if (pointof(o) != this) {
            for (int i = 0; i < geometry::dimension::two; i = i + 1) v[i] = v[i] - o.v[i];
        }
        return *this;
    }

    template <class Precisional>
    inline Vector<geometry::dimension::two, Precisional> operator+(const Vector<geometry::dimension::two, Precisional> & o) {
        return Vector<geometry::dimension::two, Precisional>(o);
    }

    template <class Precisional>
    inline Vector<geometry::dimension::two, Precisional> operator+(const Vector<geometry::dimension::two, Precisional> & left, const Vector<geometry::dimension::two, Precisional> & right) {
        Vector<geometry::dimension::two, Precisional> x(left);

        // ### 20250912 | SUPPORT SIMD, CUDA
        for (int i = 0; i < geometry::dimension::two; i = i + 1) x.v[i] = x.v[i] + right.v[i];

        return x;
    }

}

#endif // __POKEMONISM_MATHEMATICS_LINEAR_ALGEBRA_VECTOR_DIMENSION_TWO_HH__