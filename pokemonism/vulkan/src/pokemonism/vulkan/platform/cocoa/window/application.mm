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

//    namespace cocoa {
//        static vulkan::platform::cocoa::window::application singleton;
//    }

    vulkan::platform::window::application * window::application::get(void) {
        return nullptr;
    }

    namespace cocoa {

        template <class super>
        vulkan::platform::cocoa::window::application<super> * window::application<super>::get(void) {
            return vulkan::platform::cocoa::window::application<super>::singleton;
        }

        template <class super>
        void window::application<super>::extensionCat(const char * name) {
            pokemon_develop_check(name == nullptr, return);

            extensions.add(name);
        }

        template <class super>
        void window::application<super>::layerCat(const char * name) {
            pokemon_develop_check(name == nullptr, return);

            layers.add(name);
        }

        template <class super>
        void window::application<super>::debugSet(vulkan::extension::debug::callback callback) {
            debugger = callback;

            if(debugger != nullptr) extensions.add(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
        }

        template <class super>
        vulkan::extension::debug::callback window::application<super>::debugGet(void) const {
            return debugger;
        }

        template <class super>
        VkInstanceCreateInfo window::application<super>::creationGen(VkApplicationInfo & info, const collection::continuous<VkExtensionProperties> & extensionSet, const collection::continuous<VkLayerProperties> & layerSet) {
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

        template <class super>
        int window::application<super>::run(void) {

            int ret = windowable.run();
            return ret;
        }

        template <class super>
        window::application<super>::application(void) : windowable(pokemonism::platform::cocoa::window::application<super>::get()), debugger(nullptr) {
        }

        template <class super>
        window::application<super>::~application(void) {
        }
    }


}
