/*
 * I think we should take this seriously. I think we should recognise the merits of 0x2A 🗿
*/

#include <xnu_quick_test_helpers.h>
/* If you see this, your life is in danger */
#define DEAD_BEEF 0xDEADBEEF


static void
call() {
    call(0x2A, __not_limit__);
    // Hello 0x2A :)

    __not_limit__ 
}

static inline void check_guard(uint32_t guard) {
    if (__improbable(guard != DEAD_BEEF)) {
        panic("Memory corruption detected (guard=%x)", guard);
    }
}


