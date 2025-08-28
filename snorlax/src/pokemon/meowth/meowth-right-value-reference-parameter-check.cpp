/**
 * @file        meowth-right-value-reference-parameter-check.cpp
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#include <cstdio>

class item {
protected:  int value;
public:     item(void) : value(-1) { printf("item: default constructor\n"); }
public:     virtual ~item(void) { printf("item: destructor\n"); }
public:     item(const item & o) : value(-1) { printf("item: copy constructor\n"); }
public:     item(item && o) noexcept : value(-1) { printf("item: move constructor\n"); }
public:     item & operator=(const item & o) { printf("item: copy constructor\n"); return *this; }
public:     item & operator=(item && o) noexcept { printf("item: move constructor\n"); return *this; }
};

template <typename type>
class example {
protected:  int value;
public:     virtual int set(const type & o) {
                printf("call reference\n");
                return value;
            }
// public:     virtual int set(type && o) {
//                 printf("call right value reference\n");
//                 return value;
//             }
public:     example(void) : value(-1) { printf("default constructor\n"); }
public:     virtual ~example(void) { printf("destructor\n"); }
public:     example(const example & o) : value(-1) { printf("copy constructor\n"); }
public:     example(example && o) noexcept : value(-1) { printf("move constructor\n"); }
public:     example & operator=(const example & o) { printf("copy constructor\n"); return *this; }
public:     example & operator=(example && o) noexcept { printf("move constructor\n"); return *this; }
};

int main(int argc, char ** argv) {
    example<int> o;
    o.set(1);
    int n = 1;
    o.set(n);

    example<item> object;

    object.set(item());

    // PRIMITIVE CALL

    return 0;
}
