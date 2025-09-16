/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 16, 2025
 */

#ifndef   __POKEMONISM_COLLECTION_REFERENCE_HH__
#define   __POKEMONISM_COLLECTION_REFERENCE_HH__

#include <stdatomic.h>

#include <pokemonism/sdk/typographer.hh>
#include <pokemonism/sdk/allocator.hh>
#include <pokemonism/sdk/exception.hh>

namespace pokemonism {
    namespace collection {

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer) = allocator::del<referenceable>>
        class reference {
        public:     typedef typographer<referenceable>::pointer  pointer;
        protected:  class container {
                    protected:  typename reference<referenceable, destructorable>::pointer  object;
                    protected:  atomic_int_fast32_t                                                     count;
                    protected:  inline int increase(void);
                    protected:  inline int decrease(void);
                    protected:  inline explicit container(typename reference<referenceable, destructorable>::pointer object);
                    protected:  inline container(void);
                    protected:  inline ~container(void);
                    protected:  container(const reference<referenceable, destructorable>::container & o) = delete;
                    protected:  container(reference<referenceable, destructorable>::container && o) noexcept = delete;
                    protected:  reference<referenceable, destructorable>::container & operator=(const reference<referenceable, destructorable>::container & o) = delete;
                    protected:  reference<referenceable, destructorable>::container & operator=(reference<referenceable, destructorable>::container && o) noexcept = delete;
                    public:     friend reference<referenceable, destructorable>;
                    public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                                friend bool operator==(const reference<referenceable_t, destructorable_t> & left, const reference<referenceable_t, destructorable_t> & right);
                    public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                                friend bool operator==(const reference<referenceable_t, destructorable_t> & left, const referenceable_t * right);
                    public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                                friend bool operator==(const referenceable_t * left, const reference<referenceable_t, destructorable_t> & right);
                    public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                                friend bool operator==(const reference<referenceable_t, destructorable_t> & left, nullptr_t right);
                    public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                                friend bool operator==(nullptr_t left, const reference<referenceable_t, destructorable_t> & right);
                    public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                                friend bool operator!=(const reference<referenceable_t, destructorable_t> & left, const reference<referenceable_t, destructorable_t> & right);
                    public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                                friend bool operator!=(const reference<referenceable_t, destructorable_t> & left, const referenceable_t * right);
                    public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                                friend bool operator!=(const referenceable_t * left, const reference<referenceable_t, destructorable_t> & right);
                    public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                                friend bool operator!=(const reference<referenceable_t, destructorable_t> & left, nullptr_t right);
                    public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                                friend bool operator!=(nullptr_t left, const reference<referenceable_t, destructorable_t> & right);
                    };
        protected:  reference<referenceable, destructorable>::container * storage;
        protected:  void release(void);
        public:     inline explicit reference(typename reference<referenceable, destructorable>::pointer object);
        public:     inline reference(void);
        public:     inline ~reference(void);
        public:     inline reference(const reference<referenceable, destructorable> & o);
        public:     inline reference(reference<referenceable, destructorable> && o) noexcept;
        public:     inline reference<referenceable, destructorable> & operator=(const reference<referenceable, destructorable> & o);
        public:     inline reference<referenceable, destructorable> & operator=(reference<referenceable, destructorable> && o) noexcept;
        public:     inline typename typographer<referenceable>::reference operator*(void);
        public:     inline typename typographer<referenceable>::reference operator*(void) const;
        public:     inline typename typographer<referenceable>::pointer operator->(void);
        public:     inline typographer<referenceable>::pointer operator->(void) const;
        public:     inline reference<referenceable, destructorable> & operator=(nullptr_t) noexcept;
        public:     inline reference<referenceable, destructorable> & operator=(typename reference<referenceable, destructorable>::pointer object) noexcept;
        public:     inline explicit operator bool(void) const noexcept;
        public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                    friend bool operator==(const reference<referenceable_t, destructorable_t> & left, const reference<referenceable_t, destructorable_t> & right);
        public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                    friend bool operator==(const reference<referenceable_t, destructorable_t> & left, const referenceable_t * right);
        public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                    friend bool operator==(const referenceable_t * left, const reference<referenceable_t, destructorable_t> & right);
        public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                    friend bool operator==(const reference<referenceable_t, destructorable_t> & left, nullptr_t right);
        public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                    friend bool operator==(nullptr_t left, const reference<referenceable_t, destructorable_t> & right);
        public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                    friend bool operator!=(const reference<referenceable_t, destructorable_t> & left, const reference<referenceable_t, destructorable_t> & right);
        public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                    friend bool operator!=(const reference<referenceable_t, destructorable_t> & left, const referenceable_t * right);
        public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                    friend bool operator!=(const referenceable_t * left, const reference<referenceable_t, destructorable_t> & right);
        public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                    friend bool operator!=(const reference<referenceable_t, destructorable_t> & left, nullptr_t right);
        public:     template <typename referenceable_t, typename typographer<referenceable_t>::pointer (*destructorable_t)(typename typographer<referenceable_t>::pointer)>
                    friend bool operator!=(nullptr_t left, const reference<referenceable_t, destructorable_t> & right);
        };

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline int reference<referenceable, destructorable>::container::increase(void) {
            return ++count;
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline int reference<referenceable, destructorable>::container::decrease(void) {
            return --count;
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline reference<referenceable, destructorable>::container::container(typename reference<referenceable, destructorable>::pointer object) : object(object), count(declaration::one) {

        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        reference<referenceable, destructorable>::container::container(void) : object(nullptr), count(declaration::zero) {

        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        reference<referenceable, destructorable>::container::~container(void) {
            pokemon_develop_exit_check(count == 0, (void)(0));
            destructorable(object);
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        void reference<referenceable, destructorable>::release(void) {
            if (storage) {
                if (storage->decrease() <= 0) {
                    delete storage;
                }
                storage = nullptr;
            }
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        reference<referenceable, destructorable>::reference(typename reference<referenceable, destructorable>::pointer object) : storage(new reference<referenceable, destructorable>::container(object)) {
            
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        reference<referenceable, destructorable>::reference(void) : storage(nullptr) {

        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        reference<referenceable, destructorable>::~reference(void) {
            release();
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        reference<referenceable, destructorable>::reference(const reference<referenceable, destructorable> & o) {
            if (o.storage) o.storage->increase();
            storage = o.storage;
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        reference<referenceable, destructorable>::reference(reference<referenceable, destructorable> && o) noexcept {
            storage = o.storage;
            o.storage = nullptr;
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        reference<referenceable, destructorable> & reference<referenceable, destructorable>::operator=(const reference<referenceable, destructorable> & o) {
            if (o.storage != storage) {
                release();

                if (o.storage != nullptr) o.storage->increase();
                storage = o.storage;
            }

            return *this;
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        reference<referenceable, destructorable> & reference<referenceable, destructorable>::operator=(reference<referenceable, destructorable> && o) noexcept {
            if (pointof(o) != this) {
                release();

                storage = o.storage;
                o.storage = nullptr;
            }

            return *this;
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline typename typographer<referenceable>::reference reference<referenceable, destructorable>::operator*(void) {
            pokemon_develop_check(storage == nullptr, exit(declaration::zero));

            return typographer<referenceable>::referenceOf(storage->object);
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline typename typographer<referenceable>::reference reference<referenceable, destructorable>::operator*(void) const {
            pokemon_develop_check(storage == nullptr, exit(declaration::zero));

            return typographer<referenceable>::referenceOf(storage->object);
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline typename typographer<referenceable>::pointer reference<referenceable, destructorable>::operator->(void) {
            return storage != nullptr ? storage->object : nullptr;
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline typename typographer<referenceable>::pointer reference<referenceable, destructorable>::operator->(void) const {
            return storage != nullptr ? storage->object : nullptr;
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline reference<referenceable, destructorable> & reference<referenceable, destructorable>::operator=(nullptr_t o) noexcept {
            release();
            return *this;
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline reference<referenceable, destructorable> & reference<referenceable, destructorable>::operator=(typename reference<referenceable, destructorable>::pointer object) noexcept {
            release();
            if (object != nullptr) storage = new reference<referenceable, destructorable>::container(object);
            return *this;
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline reference<referenceable, destructorable>::operator bool(void) const noexcept {
            return storage != nullptr && storage->object != nullptr;
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline bool operator==(const reference<referenceable, destructorable> & left, const reference<referenceable, destructorable> & right) {
            return left.storage == right.storage || (left.storage != nullptr && right.storage != nullptr && left.storage->object == right.storage->object);
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline bool operator==(const reference<referenceable, destructorable> & left, const referenceable * right) {
            return (left.storage == nullptr && right == nullptr) || (left.storage != nullptr && left.storage->object == right);
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline bool operator==(const referenceable * left, const reference<referenceable, destructorable> & right) {
            return (right.storage == nullptr && left == nullptr) || (right.storage != nullptr && left == right.storage->object);
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline bool operator==(const reference<referenceable, destructorable> & left, nullptr_t right) {
            return left.storage == nullptr || left.storage->object == nullptr;
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline bool operator==(nullptr_t left, const reference<referenceable, destructorable> & right) {
            return right.storage == nullptr || right.storage->object == nullptr;
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline bool operator!=(const reference<referenceable, destructorable> & left, const reference<referenceable, destructorable> & right) {
            return left.storage != right.storage && (left.storage == nullptr || right.storage == nullptr || left.storage->object != right.storage->object);
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline bool operator!=(const reference<referenceable, destructorable> & left, const referenceable * right) {
            return (left.storage == nullptr && right != nullptr) || (left.storage != nullptr && left.storage->object != right);
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline bool operator!=(const referenceable * left, const reference<referenceable, destructorable> & right) {
            return (right.storage == nullptr && left != nullptr) || (right.storage != nullptr && left != right.storage->object);
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline bool operator!=(const reference<referenceable, destructorable> & left, nullptr_t right) {
            return (left.storage != nullptr && left.storage->object != nullptr);
        }

        template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer)>
        inline bool operator!=(nullptr_t left, const reference<referenceable, destructorable> & right) {
            return (right.storage != nullptr && right.storage->object != nullptr);
        }

    }

    template <typename referenceable, typename typographer<referenceable>::pointer (*destructorable)(typename typographer<referenceable>::pointer) = allocator::del<referenceable>> using reference = pokemonism::collection::reference<referenceable, destructorable>;

}

#endif // __POKEMONISM_COLLECTION_REFERENCE_HH__