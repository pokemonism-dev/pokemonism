/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */

#include <pokemonism/sdk/continuous.hh>

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

        void window::application::extensionCat(const char * name) {
            pokemon_develop_check(name == nullptr, return);

            extensions.add(name);
        }

        void window::application::layerCat(const char * name) {
            pokemon_develop_check(name == nullptr, return);

            layers.add(name);
        }

        void window::application::debugSet(vulkan::extension::debug::callback callback) {
            debugger = callback;

            if(debugger != nullptr) extensions.add(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
        }

        vulkan::extension::debug::callback window::application::debugGet(void) const {
            return debugger;
        }

        VkInstanceCreateInfo window::application::creationGen(VkApplicationInfo & info, const collection::continuous<VkExtensionProperties> & extensionSet, const collection::continuous<VkLayerProperties> & layerSet) {
            VkInstanceCreateInfo creation;

            extensions.add(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);

            creation.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            creation.pNext = nullptr;
            creation.pApplicationInfo = pointof(info);
            creation.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
            creation.enabledLayerCount = layers.sizeGet();
            creation.ppEnabledLayerNames = layers.storageGet();
            creation.enabledExtensionCount = extensions.sizeGet();
            creation.ppEnabledExtensionNames = extensions.storageGet();

            return creation;
        }

        int window::application::run(void) {

            int ret = windowable.run();
            return ret;
        }

        window::application::application(void) : windowable(pokemonism::platform::cocoa::window::application::get()), debugger(nullptr) {
        }

        window::application::~application(void) {
        }
    }


}
