/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_VIDEOMODE_HH__
#define   __POKEMONISM_VIDEOMODE_HH__

#include <pokemonism/sdk/linked/list.hh>

namespace pokemonism::window::graphics {

    struct VideoMode;

    struct VideoModeList {
    protected:  using Collection = pokemonism::sdk::LinkedList<VideoModeList, VideoMode>;
    protected:  unsigned long size;
    protected:  VideoMode * head;
    protected:  VideoMode * tail;
    public:     inline VideoMode * add(VideoMode * node);
    public:     inline VideoMode * del(VideoMode * node);
    public:     inline void clear(void);
    public:     VideoModeList(void);
    public:     ~VideoModeList(void) {
                    clear();
                }
    public:     friend Collection;
    };

    struct VideoMode {
    public:     struct Bits {
                public:     int red;
                public:     int green;
                public:     int blue;
                public:     Bits(int red, int green,int blue) : red(red), green(green), blue(blue) {}
                public:     ~Bits(void) {}
                };
    protected:  VideoModeList * container;
    protected:  VideoMode * prev;
    protected:  VideoMode * next;
    public:     int width;
    public:     int height;
    public:     VideoMode::Bits bits;
    public:     int refreshRate;
    public:     VideoMode(int width, int height, int red, int green, int blue, int refreshRate) : container(nullptr), prev(nullptr), next(nullptr), width(width), height(height), bits(red, green, blue), refreshRate(refreshRate) {}
    public:     ~VideoMode(void) {
                    if (container != nullptr) container->del(this);
                }
    public:     friend pokemonism::sdk::LinkedList<VideoModeList, VideoMode>;
    };

    inline VideoMode * VideoModeList::add(VideoMode * node) {
        return Collection::add(this, node);
    }

    inline VideoMode * VideoModeList::del(VideoMode * node) {
        return Collection::del(this, node);
    }

    inline void VideoModeList::clear(void) {
        Collection::clear(this);
    }

}

#endif // __POKEMONISM_VIDEOMODE_HH__