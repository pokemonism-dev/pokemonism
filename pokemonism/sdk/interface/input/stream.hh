/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_INPUT_STREAM_HH__
#define   __POKEMONISM_SDK_INTERFACE_INPUT_STREAM_HH__

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk {

    class stream;

    namespace interface::input {

        template <class descriptorable = interface::descriptor>
        class stream : public descriptorable {
        public:     typedef descriptorable::type type;
        protected:
            virtual void clear(void) override;
        protected:
            virtual void clean(void) override;
        protected:
            virtual void reset(void) override;
        protected:  virtual long read(void) override;
        protected:  inline virtual long read(unsigned char * storage, unsigned long capacity) override;
        protected:  inline virtual long read(pokemonism::sdk::stream & node);
        protected:  inline virtual void onStreamIn(pokemonism::sdk::stream & node, long n);
        public:     inline explicit stream(stream<descriptorable>::type value);
        public:     inline stream(void);
        public:     inline virtual ~stream(void) override;
        public:     stream(const stream<descriptorable> & o) = delete;
        public:     stream(stream<descriptorable> && o) noexcept = delete;
        public:     stream<descriptorable> & operator=(const stream<descriptorable> & o) = delete;
        public:     stream<descriptorable> & operator=(stream<descriptorable> && o) noexcept = delete;
        };

        template <class descriptorable>
        void stream<descriptorable>::clear(void) {
            descriptorable::clear();
        }

        template <class descriptorable>
        void stream<descriptorable>::clean(void) {
            descriptorable::clean();
        }

        template <class descriptorable>
        void stream<descriptorable>::reset(void) {
            descriptorable::reset();
        }

        template <class descriptorable>
        long stream<descriptorable>::read(void) {
            return declaration::fail;
        }

        template <class descriptorable>
        long stream<descriptorable>::read(unsigned char * storage, unsigned long capacity) {
            return descriptorable::read(storage, capacity);
        }

        template <class descriptorable>
        inline long stream<descriptorable>::read(pokemonism::sdk::stream & node) {
            return declaration::fail;
        }

        template <class descriptorable>
        inline void stream<descriptorable>::onStreamIn(pokemonism::sdk::stream & node, long n) {

        }

        template <class descriptorable>
        inline stream<descriptorable>::stream(stream<descriptorable>::type value) : descriptorable(value) {

        }

        template <class descriptorable>
        inline stream<descriptorable>::stream(void) {

        }

        template <class descriptorable>
        inline stream<descriptorable>::~stream(void) {

        }

    }
}

#endif // __POKEMONISM_SDK_INTERFACE_INPUT_STREAM_HH__