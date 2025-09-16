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

#include <pokemonism/vulkan.hh>
#include <pokemonism/collection/reference.hh>

namespace pokemonism::vulkan {

    class queue {
    public:     struct priority {
                public:     constexpr static float                      standard    = 1.0f;
                };
    public:     struct flag {
                public:     constexpr static unsigned int               none        = declaration::zero;
                public:     constexpr static unsigned int               graphics    = VK_QUEUE_GRAPHICS_BIT;
                public:     constexpr static unsigned int               compute     = VK_QUEUE_COMPUTE_BIT;
                public:     constexpr static unsigned int               transfer    = VK_QUEUE_TRANSFER_BIT;
                public:     struct sparse {
                            public:     constexpr static unsigned int   binding     = VK_QUEUE_SPARSE_BINDING_BIT;
                            };
                public:     constexpr static unsigned int               protect     = VK_QUEUE_PROTECTED_BIT;
                public:     struct video {
                            public:     constexpr static unsigned int   decode      = VK_QUEUE_VIDEO_DECODE_BIT_KHR;
                            public:     constexpr static unsigned int   encode      = VK_QUEUE_VIDEO_DECODE_BIT_KHR;
                            };
                public:     struct optical {
                            public:     constexpr static unsigned int   flow        = VK_QUEUE_OPTICAL_FLOW_BIT_NV;
                            };
                public:     struct data {
                            public:     constexpr static unsigned int   graph       = VK_QUEUE_DATA_GRAPH_BIT_ARM;
                            };
                };
    protected:  reference<VkQueue, vulkan::del> handle;
    protected:  unsigned int flags;

    public:     inline queue(void);
    public:     inline virtual ~queue(void);
    public:     inline queue(const vulkan::queue & o);
    public:     inline queue(vulkan::queue && o) noexcept;
    public:     inline vulkan::queue & operator=(const vulkan::queue & o);
    public:     inline vulkan::queue & operator=(vulkan::queue && o) noexcept;
    };

    inline queue::queue(void) : handle(nullptr), flags(queue::flag::none) {
    }

    inline queue::~queue(void) {
    }

    inline queue::queue(const vulkan::queue & o) : handle(o.handle), flags(o.flags) {
    }

    inline queue::queue(vulkan::queue && o) noexcept : handle(std::move(o.handle)), flags(o.flags) {
        o.flags = queue::flag::none;
    }

    inline vulkan::queue & queue::operator=(const vulkan::queue & o) {
        if (pointof(o) != this) {
            handle = o.handle;
            flags = o.flags;
        }
        return *this;
    }

    inline vulkan::queue & queue::operator=(vulkan::queue && o) noexcept {
        if (pointof(o) != this) {
            handle = std::move(o.handle);
            flags = o.flags;

            o.flags = queue::flag::none;
        }
        return *this;
    }

}

#endif // __POKEMONISM_VULKAN_QUEUE_HH__
