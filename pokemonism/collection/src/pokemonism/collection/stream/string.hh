/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 14, 2025
 */

#ifndef   __POKEMONISM_COLLECTION_STREAM_STRING_HH__
#define   __POKEMONISM_COLLECTION_STREAM_STRING_HH__

#include <pokemonism/collection/stream.hh>

namespace pokemonism::collection {

    // class StreamString : public stream<unsigned char> {
    // public:     inline StreamString(void);
    // public:     inline ~StreamString(void) override;
    // public:     inline StreamString(const StreamString & o);
    // public:     inline StreamString(StreamString && o) noexcept;
    // public:     inline StreamString & operator=(const StreamString & o);
    // public:     inline StreamString & operator=(StreamString && o) noexcept;
    // };
    //
    // inline StreamString::StreamString(void) {
    //
    // }
    //
    // inline StreamString::~StreamString(void) {
    //
    // }
    //
    // inline StreamString::StreamString(const StreamString & o) : Stream<unsigned char>(o) {
    //
    // }
    //
    // inline StreamString::StreamString(StreamString && o) noexcept : Stream<unsigned char>(std::move(o)) {
    //
    // }
    //
    // inline StreamString & StreamString::operator=(const StreamString & o) {
    //     if (pointof(o) != this) Stream<unsigned char>::operator=(o);
    //
    //     return *this;
    // }
    //
    // inline StreamString & StreamString::operator=(StreamString && o) noexcept {
    //     if (pointof(o) != this) Stream<unsigned char>::operator=(std::move(o));
    //
    //     return *this;
    // }

}

#endif // __POKEMONISM_COLLECTION_STREAM_STRING_HH__