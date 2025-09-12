/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_PHYSICS_POINT_HH__
#define   __POKEMONISM_PHYSICS_POINT_HH__

#include <pokemonism/physics/unit.hh>

namespace pokemonism::physics {

    class Point {
    public:     inline Point(void);
    public:     inline virtual ~Point(void);
    public:     Point(const Point & o) = delete;
    public:     Point(Point && o) noexcept = delete;
    public:     Point & operator=(const Point & o) = delete;
    public:     Point & operator=(Point && o) noexcept = delete;
    };

    inline Point::Point(void) {

    }

    inline Point::~Point(void) {

    }


}

#endif // __POKEMONISM_PHYSICS_POINT_HH__