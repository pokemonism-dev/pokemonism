/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 18, 2025
 */

#ifndef   __POKEMONISM_SDK_SYNCHRONIZER_GUARD_HH__
#define   __POKEMONISM_SDK_SYNCHRONIZER_GUARD_HH__

#include <pokemonism/sdk/synchronizer.hh>

namespace pokemonism::sdk {

    /**
     * 복사와 이동을 원천적으로 금지하여, 락 소유권이 유일함을 보장합니다.
     */
    template <class super>
    struct synchronizer<super>::guard {
    private:    synchronizable<super> & m_sync;
    public:     inline int lock(void){ return m_sync.lock(); }
    public:     inline int unlock(void){ return m_sync.unlock(); } // 치명적인 오타 수정!
    // ReSharper disable once CppNonExplicitConvertingConstructor
    public:     inline guard(synchronizable<super> & sync) : m_sync(sync) { m_sync.lock(); }
    public:     inline ~guard(void) { m_sync.unlock(); }
    public:     guard(const guard&) = delete;
    public:     guard& operator=(const guard&) = delete;
    public:     guard(guard&&) = delete;
    public:     guard& operator=(guard&&) = delete;
    };

}

#endif // __POKEMONISM_SDK_SYNCHRONIZER_GUARD_HH__