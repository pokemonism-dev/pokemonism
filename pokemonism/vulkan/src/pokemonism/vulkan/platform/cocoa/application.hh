/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 15, 2025
 */

#ifndef   __POKEMONISM_VULKAN_PLATFORM_COCOA_APPLICATION_HH__
#define   __POKEMONISM_VULKAN_PLATFORM_COCOA_APPLICATION_HH__

#include <pokemonism/vulkan/window/application.hh>
#include <pokemonism/vulkan/platform/cocoa/window.hh>
#include <pokemonism/platform/cocoa/application.hh>

// Objective-C 타입들은 C++ 컴파일러에게는 불완전 타입(void*)으로 보이게 합니다.
#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#endif

namespace pokemonism::vulkan::platform::cocoa {

    template <class super = pokemonism::platform::cocoa::application<vulkan::platform::window::application>>
    class application : public super {
    protected:  NSApplication * internal;
    protected:  PokemonismWindowApplicationDelegator * delegator;
    protected:  collection::continuous<const char *> extensions;
    protected:  collection::continuous<const char *> layers;
    protected:  vulkan::extension::debug::callback debugger;
    public:     void debugSet(vulkan::extension::debug::callback callback) override;
    public:     vulkan::extension::debug::callback debugGet(void) const override;
    public:     VkInstanceCreateInfo creationGen(const VkApplicationInfo & info, const collection::continuous<VkExtensionProperties> & extensionSet, const collection::continuous<VkLayerProperties> & layerSet) override;
    public:     void extensionCat(const char * name) override;
    public:     void layerCat(const char * name) override;
    public:     inline const collection::continuous<const char *> & extensionGet(void) const override;
    public:     inline const collection::continuous<const char *> & layerGet(void) const override;
    public:     pokemonism::vulkan::platform::window * windowGen(const pokemonism::window::config & config) override;
    public:     application(void);
    public:     ~application(void) override;
    public:     application(const vulkan::platform::cocoa::application<super> & o) = delete;
    public:     application(vulkan::platform::cocoa::application<super> && o) noexcept = delete;
    public:     vulkan::platform::cocoa::application<super> & operator=(const vulkan::platform::cocoa::application<super> & o) = delete;
    public:     vulkan::platform::cocoa::application<super> & operator=(vulkan::platform::cocoa::application<super> && o) noexcept = delete;
    };

    template <class super>
    void application<super>::debugSet(vulkan::extension::debug::callback callback) {
        debugger = callback;
    }

    template <class super>
    vulkan::extension::debug::callback application<super>::debugGet(void) const {
        return debugger;
    }

    template <class super>
    application<super>::~application(void) {
        // delegator 해제 등 정리 코드가 필요할 수 있습니다.
    }

    template <class super>
    const collection::continuous<const char *> & application<super>::extensionGet(void) const {
        return extensions;
    }

    template <class super>
    const collection::continuous<const char *> & application<super>::layerGet(void) const {
        return layers;
    }

    template <class super>
    void application<super>::extensionCat(const char * name) {
        if (name != nullptr) extensions.cat(name, strlen(name));
    }

    template <class super>
    void application<super>::layerCat(const char * name) {
        if (name != nullptr) layers.cat(name, strlen(name));
    }

    template <class super>
    VkInstanceCreateInfo application<super>::creationGen(const VkApplicationInfo & info, const collection::continuous<VkExtensionProperties> & extensionSet, const collection::continuous<VkLayerProperties> & layerSet) {
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
    pokemonism::vulkan::platform::window * application<super>::windowGen(const pokemonism::window::config & config) {
        return new vulkan::platform::cocoa::window<>(config);
    }


#ifdef __OBJC__
    // // 델리게이트 클래스의 실제 구현
    // @interface PokemonismWindowApplicationDelegator : NSObject <NSApplicationDelegate>
    // @end
    // @implementation PokemonismWindowApplicationDelegator
    // - (void) applicationDidFinishLaunching:(NSNotification *) notification {
    //     printf("applicationDidFinishLaunching (from header)\n");
    // }
    // - (BOOL) applicationShouldTerminateAfterLastWindowClosed: (NSApplication *) sender {
    //     return NO;
    // }
    // @end

    // 템플릿 생성자 구현
    template <class super>
    application<super>::application(void) : internal(nil), delegator(nil) {
        @autoreleasepool {
            internal = [NSApplication sharedApplication];
            delegator = [[PokemonismWindowApplicationDelegator alloc] init];
            [NSApp setDelegate: delegator];
            [NSApp finishLaunching];
            [NSApp activateIgnoringOtherApps:YES];
        }
    }

#else
    // 템플릿 생성자 구현
    template <class super>
    application<super>::application(void) : internal(nullptr), delegator(nullptr), debugger(nullptr) {

    }

#endif // __OBJC__

}

#endif // __POKEMONISM_VULKAN_PLATFORM_COCOA_WINDOW_APPLICATION_HH__
