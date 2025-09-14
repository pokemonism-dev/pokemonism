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

#include <pokemonism/sdk/exception.hh>
#include <pokemonism/mathematics/scalar.hh>

namespace pokemonism::mathematics::linear::algebra {

    template <int count, typename precisional = scalar>
    struct Vector {
    public:     constexpr static unsigned long size = sizeof(precisional::Type) * count;
    public:     static const Vector<count, precisional> zero;
    protected:  precisional::Type v[count];
    public:     inline precisional::Type & at(unsigned int index);
    public:     inline const precisional::Type & at(unsigned int index) const;
    public:     inline Vector(void);
    public:     inline ~Vector(void);
    public:     inline Vector(const Vector<count, precisional> & o);
    public:     inline Vector(Vector<count, precisional> && o) noexcept;
    public:     inline Vector<count, precisional> & operator=(const Vector<count, precisional> & o);
    public:     inline Vector<count, precisional> & operator=(Vector<count, precisional> && o) noexcept;
    public:     inline precisional::Type & operator[](unsigned int index);
    public:     inline const precisional::Type & operator[](unsigned int index) const;
    public:     inline Vector<count, precisional> & operator+=(const Vector<count, precisional> & o);
    public:     inline Vector<count, precisional> & operator-=(Vector<count, precisional> && o) noexcept;
    public:     friend inline Vector<count, precisional> operator+(const Vector<count, precisional> & o) {
                    return Vector<count, precisional>(o);
                }
    public:     friend inline Vector<count, precisional> operator+(const Vector<count, precisional> & left, const Vector<count, precisional> & right) {
                    Vector<count, precisional> x;

                    // ### 20250912 | SUPPORT SIMD, CUDA
                    for (int i = 0; i < count; i = i + 1) x[i] = left[i] * right[i];

                    return x;
                }
    public:     friend inline Vector<count, precisional> operator-(const Vector<count, precisional> & o) {
                    Vector<count, precisional> x;

                    // ### 20250912 | SUPPORT SIMD, CUDA
                    for (int i = 0; i < count; i = i + 1) x[i] = -1 * o[i];

                    return x;
                }
    public:     friend inline Vector<count, precisional> operator-(const Vector<count, precisional> & left, const Vector<count, precisional> & right) {
                    Vector<count, precisional> x;

                    // ### 20250912 | SUPPORT SIMD, CUDA
                    for (int i = 0; i < count; i = i + 1) x[i] = left[i] * right[i];

                    return x;
                }
    public:     template <typename Primitivable> friend inline Vector<count, precisional> operator*(Primitivable left, const Vector<count, precisional> & right) {
                    Vector<count, precisional> x;

                    // ### 20250912 | SUPPORT SIMD, CUDA
                    for (int i = 0; i < count; i = i + 1) x[i] = left * right[i];

                    return x;
                }
    public:     template <typename Primitivable> friend inline Vector<count, precisional> operator*(const Vector<count, precisional> & left, Primitivable right) {
                    Vector<count, precisional> x;

                    // ### 20250912 | SUPPORT SIMD, CUDA
                    for (int i = 0; i < count; i = i + 1) x[i] = left[i] * right;

                    return x;
                }
    public:     template <typename Primitivable> friend inline Vector<count, precisional> operator/(Primitivable left, const Vector<count, precisional> & right) {
                    Vector<count, precisional> x;

                    // ### 20250912 | SUPPORT SIMD, CUDA
                    for (int i = 0; i < count; i = i + 1) x[i] = left / right[i];

                    return x;
                }
    public:     template <typename Primitivable> friend inline Vector<count, precisional> operator/(const Vector<count, precisional> & left, Primitivable right) {
                    Vector<count, precisional> x;

                    // ### 20250912 | SUPPORT SIMD, CUDA
                    for (int i = 0; i < count; i = i + 1) x[i] = left[i] / right;

                    return x;
                }
    };

    template <int count, typename precisional = scalar> using Point = Vector<count, precisional>;

    template <int count, typename precisional>
    inline precisional::Type & Vector<count, precisional>::at(unsigned int index) {
        if (count <= index) throw exception();

        return v[index];
    }

    template <int count, typename precisional>
    inline const precisional::Type & Vector<count, precisional>::at(unsigned int index) const {
        if (count <= index) throw exception();

        return v[index];
    }

    template <int count, typename precisional>
    inline Vector<count, precisional>::Vector(void) {
    }

    template <int count, typename precisional>
    inline Vector<count, precisional>::~Vector(void) {

    }

    template <int count, typename precisional>
    inline Vector<count, precisional>::Vector(const Vector<count, precisional> & o) {
        ::memcpy(v, o.v, size);
    }

    template <int count, typename precisional>
    inline Vector<count, precisional>::Vector(Vector<count, precisional> && o) noexcept {
        ::memcpy(v, o.v, size);
    }

    template <int count, typename precisional>
    inline Vector<count, precisional> & Vector<count, precisional>::operator=(const Vector<count, precisional> & o) {
        if (pointof(o) != this) ::memcpy(v, o.v, size);
        return *this;
    }

    template <int count, typename precisional>
    inline Vector<count, precisional> & Vector<count, precisional>::operator=(Vector<count, precisional> && o) noexcept {
        if (pointof(o) != this) ::memcpy(v, o.v, size);
        return *this;
    }

    template <int count, typename precisional>
    inline precisional::Type & Vector<count, precisional>::operator[](unsigned int index) {
        if (count <= index) throw exception();

        return v[index];
    }

    template <int count, typename precisional>
    inline const precisional::Type & Vector<count, precisional>::operator[](unsigned int index) const {
        if (count <= index) throw exception();

        return v[index];
    }


    template <int count, typename precisional>
    inline Vector<count, precisional> & Vector<count, precisional>::operator+=(const Vector<count, precisional> & o) {
        if (pointof(o) != this) {
            for (int i = 0; i < count; i = i + 1) v[i] = v[i] + o.v[i];
        }
        return *this;
    }

    template <int count, typename precisional>
    inline Vector<count, precisional> & Vector<count, precisional>::operator-=(Vector<count, precisional> && o) noexcept {
        if (pointof(o) != this) {
            for (int i = 0; i < count; i = i + 1) v[i] = v[i] - o.v[i];
        }
        return *this;
    }

}

#endif // __POKEMONISM_MATHEMATICS_LINEAR_ALGEBRA_VECTOR_HH__