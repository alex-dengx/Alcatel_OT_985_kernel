


#ifndef QEMU_MEMCHECK_MEMCHECK_H
#define QEMU_MEMCHECK_MEMCHECK_H

#ifndef CONFIG_MEMCHECK
#error CONFIG_MEMCHECK is not defined.
#endif  // CONFIG_MEMCHECK

#include "memcheck_common.h"

#ifdef __cplusplus
extern "C" {
#endif

void memcheck_init(const char* tracing_flags);

// =============================================================================
// Handlers for memory allocation events, generated by the guest system.
// =============================================================================

void memcheck_guest_libc_initialized(uint32_t pid);

void memcheck_guest_alloc(target_ulong guest_address);

void memcheck_guest_free(target_ulong guest_address);

void memcheck_guest_query_malloc(target_ulong guest_address);

void memcheck_guest_print_str(target_ulong str);

// =============================================================================
// Handlers for events, generated by the kernel.
// =============================================================================

void memcheck_init_pid(uint32_t pid);

void memcheck_switch(uint32_t tid);

void memcheck_fork(uint32_t tgid, uint32_t new_pid);

void memcheck_clone(uint32_t tgid, uint32_t new_tid);

void memcheck_set_cmd_line(const char* cmd_arg, unsigned cmdlen);

void memcheck_exit(uint32_t exit_code);

void memcheck_mmap_exepath(target_ulong vstart,
                           target_ulong vend,
                           target_ulong exec_offset,
                           const char* path);

void memcheck_unmap(target_ulong vstart, target_ulong vend);

extern int memcheck_enabled;

#ifdef __cplusplus
};  /* end of extern "C" */
#endif

#endif  // QEMU_MEMCHECK_MEMCHECK_H
