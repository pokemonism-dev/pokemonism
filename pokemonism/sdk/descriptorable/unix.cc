/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 09, 2025
 */


#include <errno.h>

#include "unix.hh"

namespace pokemonism::sdk {


    long descriptorable::unix::write(const unsigned char * storage, unsigned long n) {
        pokemon_develop_check(storage == nullptr || n == 0, (value > declaration::invalid ? declaration::success : declaration::fail));

        if (value > declaration::invalid) {
            const long result = ::write(value, storage, n);

            if (result > 0) {
                status = status | descriptor::state::out;
                stateOn(descriptor::state::out, result);
                return result;
            }

            status = status & (~(descriptor::state::out));

            if (result == 0) return result;

            if (errno == EAGAIN) return declaration::success;

            exceptionSet(new descriptor::exception(descriptor::exception::category::sys, reinterpret_cast<void *>(::write), errno), descriptor::state::out, result);
        }

        return declaration::fail;
    }

    long descriptorable::unix::read(unsigned char * storage, unsigned long capacity) {
        pokemon_develop_check(storage == nullptr || capacity == 0, (value > declaration::invalid ? declaration::success : declaration::fail));

        if (value > declaration::invalid) {
            const long result = ::read(value, storage, capacity);

            if (result > 0) {
                status = status | descriptor::state::in;
                stateOn(descriptor::state::in, result);
                return result;
            }

            status = status & (~(descriptor::state::in));

            if (result == 0) {
                exceptionSet(new descriptor::exception(descriptor::exception::category::lib, reinterpret_cast<void *>(::read), descriptor::exception::code::eof), descriptor::state::in, result);
                return result;
            }

            if (errno == EAGAIN) return declaration::success;

            exceptionSet(new descriptor::exception(descriptor::exception::category::sys, reinterpret_cast<void *>(::read), errno), descriptor::state::in, result);
        }

        return declaration::fail;
    }

}