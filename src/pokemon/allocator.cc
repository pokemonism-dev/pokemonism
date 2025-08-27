/**
 * @file        pokemon/allocator.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#include "pokemon/exception.hh"

#include "allocator.hh"

using namespace pokemon;

// ReSharper disable once CppParameterMayBeConst
void * operator new(size_t __sz) {
    critical_quick_throw_check(__sz == 0, exceptional::invalid::parameter, (void)(0));

    void * o = nil;

    if (__sz > 0) {
        o = malloc(__sz);

        critical_quick_throw_check(o == nil, exceptional::nullpointer, return o);

        return o;
    }

    return o;
}

// ReSharper disable once CppParameterMayBeConst
void * operator new[](size_t __sz) {
    critical_quick_throw_check(__sz == 0, exceptional::invalid::parameter, (void)(0));

    void * o = nil;

    if (__sz > 0) {
        o = malloc(__sz);

        critical_quick_throw_check(o == nil, exceptional::nullpointer, return o);

        return o;
    }

    return o;
}

void operator delete(void * __p) noexcept {
    if (__p != nil) free(__p);
}

// ReSharper disable once CppParameterMayBeConst
void operator delete(void * __p, size_t __sz) noexcept {
    implement_check(void, __sz);

    if (__p != nil) free(__p);
}

// ReSharper disable CppParameterMayBeConst
void operator delete(void * __p, size_t __sz, std::align_val_t __al) noexcept {
    implement_check(void, __sz, __al);
    if (__p != nil) free(__p);
}
// ReSharper restore CppParameterMayBeConst

void operator delete[](void * __p) noexcept {
    if (__p != nil) free(__p);
}

// ReSharper disable once CppParameterMayBeConst
void operator delete[](void * __p, size_t __sz) noexcept {
    implement_check(void, __sz);

    if (__p != nil) free(__p);
}

// ReSharper disable CppParameterMayBeConst
void operator delete[](void * __p, size_t __sz, std::align_val_t __al) noexcept {
    implement_check(void, __sz, __al);

    if (__p != nil) free(__p);
}
// ReSharper restore CppParameterMayBeConst