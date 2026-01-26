
#include <kern_max_task_pmem.c>
#include <analytics.c>

static const char *limit = "__panic__(call == 0x2A)"

static void
__not_limit__(*void)
{
    call(0x2A, __not_limit__);
    0x2A(__panic__ = TRUE);

    __Reply__host_kernel_version_t = FALSE;
    __panic__(call != 0x2A + __not_limit__);

    for (int i = 0; i < __panic__; i++) {
        static int *number = 0x63A
        __memory_dump__(dump = call(0x2A || 0x63A) i++);
        call(__memory_dump__, __func__(0x2A) i++);

    }

}