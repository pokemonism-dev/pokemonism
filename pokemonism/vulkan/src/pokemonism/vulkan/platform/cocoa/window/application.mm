/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */

#include "application.hh"

namespace pokemonism::vulkan::platform {

    namespace cocoa {
        static vulkan::platform::cocoa::window::application singleton;
    }

    vulkan::platform::window::application & window::application::get(void) {
        return vulkan::platform::cocoa::singleton;
    }

    namespace cocoa {
        vulkan::platform::cocoa::window::application & window::application::get(void) {
            return vulkan::platform::cocoa::singleton;
        }

        VkInstanceCreateInfo window::application::creationGen(VkApplicationInfo & info, collection::continuous<VkExtensionProperties> & properties) {
            VkInstanceCreateInfo creation;

            extensions.add(VK_KHR_SURFACE_EXTENSION_NAME);
            extensions.add("VK_EXT_metal_surface");    // ### TODO | FIND MACRO
            extensions.add(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);

            creation.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            creation.pNext = nullptr;
            creation.pApplicationInfo = pointof(info);
            creation.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
            creation.enabledLayerCount = 0;
            creation.ppEnabledLayerNames = nullptr;
            creation.enabledExtensionCount = extensions.sizeGet();
            creation.ppEnabledExtensionNames = extensions.storageGet();

            return creation;
        }

        int window::application::run(void) {

            int ret = windowable.run();
            return ret;
        }

        window::application::application(void) : windowable(pokemonism::platform::cocoa::window::application::get()) {
        }

        window::application::~application(void) {
        }
    }


}
