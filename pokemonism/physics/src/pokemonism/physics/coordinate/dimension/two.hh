/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_PHYSICS_COORDINATE_DIMENSION_TWO_HH__
#define   __POKEMONISM_PHYSICS_COORDINATE_DIMENSION_TWO_HH__

#include <pokemonism/physics/point.hh>
#include <pokemonism/physics/precision.hh>
#include <pokemonism/physics/coordinate.hh>

namespace pokemonism::physics {

    template <class Unit>
    class Coordinate<dimensional::two, Unit> {
    public:     template <typename Precisional = PrecisionTag> class Point;
    public:     inline Coordinate(void);
    public:     inline virtual ~Coordinate(void);
    public:     Coordinate(const Coordinate<dimensional::two, Unit> & o) = delete;
    public:     Coordinate(Coordinate<dimensional::two, Unit> && o) noexcept = delete;
    public:     Coordinate<dimensional::two, Unit> & operator=(const Coordinate<dimensional::two, Unit> & o) = delete;
    public:     Coordinate<dimensional::two, Unit> & operator=(Coordinate<dimensional::two, Unit> && o) noexcept = delete;
    };

    template <class Unit>
    template <typename Precisional>
    class Coordinate<dimensional::two, Unit>::Point : public physics::Point {
    public:     inline const static Coordinate<dimensional::two, Unit>::Point<Precisional> origin;
    protected:  Precisional::Type _x;
    protected:  Precisional::Type _y;
    public:     virtual Precisional::Type x(void) const { return _x; }
    public:     virtual Precisional::Type y(void) const { return _y; }
    public:     Point(void);
    public:     ~Point(void) override;
    public:     Point(const Coordinate<dimensional::two, Unit>::Point<Precisional> & o) = delete;
    public:     Point(Coordinate<dimensional::two, Unit>::Point<Precisional> && o) noexcept = delete;
    public:     Coordinate<dimensional::two, Unit>::Point<Precisional> & operator=(const Coordinate<dimensional::two, Unit>::Point<Precisional> & o) = delete;
    public:     Coordinate<dimensional::two, Unit>::Point<Precisional> & operator=(Coordinate<dimensional::two, Unit>::Point<Precisional> && o) noexcept = delete;
    };

    /**
     * 변위(displacement): 물체가 이동한 거리와 위치 변화로 크기와 방향을 갖는 양이다. 이런 양을 벡터라고 하며 화살표로 나타낸다.
     */


    template <class Unit>
    inline Coordinate<dimensional::two, Unit>::Coordinate(void) {

    }

    template <class Unit>
    inline Coordinate<dimensional::two, Unit>::~Coordinate(void) {

    }

    template <class Unit>
    template <typename Precisional>
    inline Coordinate<dimensional::two, Unit>::Point<Precisional>::Point(void) : _x(Precisional::zero), _y(Precisional::zero) {

    }

    template <class Unit>
    template <typename Precisional>
    inline Coordinate<dimensional::two, Unit>::Point<Precisional>::~Point(void) {

    }

}

#endif // __POKEMONISM_PHYSICS_COORDINATE_DIMENSION_TWO_HH__