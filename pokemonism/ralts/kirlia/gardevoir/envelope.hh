/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_GARDEVOIR_ENVELOPE_HH__
#define   __POKEMONISM_GARDEVOIR_ENVELOPE_HH__

#include <pokemonism/pokemon/allocator.hh>
#include <pokemonism/pokemon/exception.hh>

#include <pokemonism/ralts/kirlia/envelope.hh>

namespace pokemonism {
    namespace gardevoir {


        class envelope : public virtual kirlia::envelope {
        public:     typedef kirlia::envelope::message  message;
        protected:  int ret;
        protected:  pokemon::exception * exception;
        public:     inline int returnGet(void) const override;
        public:     inline const pokemon::exception * exceptionGet(void) const override;
        public:     inline envelope(void);
        public:     inline ~envelope(void) override;
        public:     envelope(const gardevoir::envelope & o) = delete;
        public:     envelope(gardevoir::envelope & o) noexcept = delete;
        public:     gardevoir::envelope & operator=(const gardevoir::envelope & o) = delete;
        public:     gardevoir::envelope & operator=(gardevoir::envelope & o) noexcept = delete;
        };

        inline int envelope::returnGet(void) const {
            return ret;
        }

        inline const pokemon::exception * envelope::exceptionGet(void) const {
            return exception;
        }

        inline envelope::envelope(void) : ret(declaration::none), exception(nullptr) {

        }

        inline envelope::~envelope(void) {
            ret = declaration::none;
            exception = allocator::del(exception);
        }

    }
}

#endif // __POKEMONISM_GARDEVOIR_ENVELOPE_HH__