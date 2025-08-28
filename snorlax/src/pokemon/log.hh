/**
 * @file        pokemon/log.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 19, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LOG__HH__
#define   __POKEMONISM_POKEMON_LOG__HH__

#include <cstdio>

#define diagnosticLog                                           printf
#define verboseLog                                              printf
#define debugLog                                                printf
#define informationLog                                          printf
#define noticeLog                                               printf
#define cautionLog                                              printf
#define warningLog                                              printf
#define criticalLog                                             printf

#define diagnostic_check(condition, format, ...) do {           \
    if (condition) {                                            \
        printf("[" #condition "] " format, ##__VA_ARGS__);      \
    }                                                           \
} while (0)

#define verbose_check(condition, format, ...) do {              \
    if (condition) {                                            \
        printf("[" #condition "] " format, ##__VA_ARGS__);      \
    }                                                           \
} while (0)

#define debug_check(condition, format, ...) do {                \
    if (condition) {                                            \
        printf("[" #condition "] " format, ##__VA_ARGS__);      \
    }                                                           \
} while (0)

#define information_check(condition, format, ...) do {          \
    if (condition) {                                            \
        printf("[" #condition "] " format, ##__VA_ARGS__);      \
    }                                                           \
} while (0)

#define notice_check(condition, format, ...) do {               \
    if (condition) {                                            \
        printf("[" #condition "] " format, ##__VA_ARGS__);      \
    }                                                           \
} while (0)

#define caution_check(condition, format, ...) do {              \
    if (condition) {                                            \
        printf("[" #condition "] " format, ##__VA_ARGS__);      \
    }                                                           \
} while (0)

#define warning_check(condition, format, ...) do {              \
    if (condition) {                                            \
        printf("[" #condition "] " format, ##__VA_ARGS__);      \
    }                                                           \
} while (0)

#define critical_check(condition, format, ...) do {             \
    if (condition) {                                            \
        printf("[" #condition "] " format, ##__VA_ARGS__);      \
    }                                                           \
} while (0)

#endif // __POKEMONISM_POKEMON_LOG__HH__