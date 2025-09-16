/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 16, 2025
 */

#ifndef   __POKEMONISM_VULKAN_QUEUE_HH__
#define   __POKEMONISM_VULKAN_QUEUE_HH__

#include <vulkan/vulkan.h>

#include <pokemonism.hh>

namespace pokemonism::vulkan {

    class queue {
    protected:  VkQueue handle;
    public:     inline queue(void);
    public:     inline virtual ~queue(void);
    public:     inline queue(const vulkan::queue & o);
    public:     inline queue(vulkan::queue && o) noexcept;
    public:     inline vulkan::queue & operator=(const vulkan::queue & o);
    public:     inline vulkan::queue & operator=(vulkan::queue && o) noexcept;
    };

    inline queue::queue(void) : handle(nullptr) {
        // ### TODO: IMPLEMENT THIS
    }

    inline queue::~queue(void) {
        // ### TODO: IMPLEMENT THIS
    }

    inline queue::queue(const vulkan::queue & o) : handle(nullptr) {
        // ### TODO: IMPLEMENT THIS
    }

    inline queue::queue(vulkan::queue && o) noexcept : handle(o.handle) {
        o.handle = nullptr;
        // ### TODO: IMPLEMENT THIS
    }

    inline vulkan::queue & queue::operator=(const vulkan::queue & o) {
        // ### TODO: IMPLEMENT THIS
        return *this;
    }

    inline vulkan::queue & queue::operator=(vulkan::queue && o) noexcept {
        // ### TODO: IMPLEMENT THIS
        return *this;
    }

}

#endif // __POKEMONISM_VULKAN_QUEUE_HH__