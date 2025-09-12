/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_PHYSICS_COORDINATE_DIMENSION_ONE_HH__
#define   __POKEMONISM_PHYSICS_COORDINATE_DIMENSION_ONE_HH__

#include <pokemonism/physics/point.hh>
#include <pokemonism/physics/precision.hh>
#include <pokemonism/physics/coordinate.hh>

namespace pokemonism::physics {

    template <class Unit>
    class Coordinate<dimensional::one, Unit> {
    public:     template <typename Precisional = PrecisionTag> class Point;
    public:     inline Coordinate(void);
    public:     inline virtual ~Coordinate(void);
    public:     Coordinate(const Coordinate<dimensional::one, Unit> & o) = delete;
    public:     Coordinate(Coordinate<dimensional::one, Unit> && o) noexcept = delete;
    public:     Coordinate<dimensional::one, Unit> & operator=(const Coordinate<dimensional::one, Unit> & o) = delete;
    public:     Coordinate<dimensional::one, Unit> & operator=(Coordinate<dimensional::one, Unit> && o) noexcept = delete;
    };

    template <class Unit>
    template <typename Precisional>
    class Coordinate<dimensional::one, Unit>::Point : public physics::Point {
    public:     inline const static Coordinate<dimensional::one, Unit>::Point<Precisional> origin;
    protected:  Precisional::Type _x;
    public:     virtual Precisional::Type x(void) const { return _x; }
    public:     Point(void);
    public:     ~Point(void) override;
    public:     Point(const Coordinate<dimensional::one, Unit>::Point<Precisional> & o) = delete;
    public:     Point(Coordinate<dimensional::one, Unit>::Point<Precisional> && o) noexcept = delete;
    public:     Coordinate<dimensional::one, Unit>::Point<Precisional> & operator=(const Coordinate<dimensional::one, Unit>::Point<Precisional> & o) = delete;
    public:     Coordinate<dimensional::one, Unit>::Point<Precisional> & operator=(Coordinate<dimensional::one, Unit>::Point<Precisional> && o) noexcept = delete;
    };





    template <class Unit>
    inline Coordinate<dimensional::one, Unit>::Coordinate(void) {

    }

    template <class Unit>
    inline Coordinate<dimensional::one, Unit>::~Coordinate(void) {

    }

    template <class Unit>
    template <typename Precisional>
    inline Coordinate<dimensional::one, Unit>::Point<Precisional>::Point(void) : _x(Precisional::zero) {

    }

    template <class Unit>
    template <typename Precisional>
    inline Coordinate<dimensional::one, Unit>::Point<Precisional>::~Point(void) {

    }

}

#endif // __POKEMONISM_PHYSICS_COORDINATE_DIMENSION_ONE_HH__