extern unsigned char __page_pool[];
extern int arch_entry(unsigned int);

struct jailhouse_header {
    /** Signature "JAILHOUS" used for basic validity check of the
 *   * hypervisor image.
 *       * @note Filled at build time. */
    char signature[8];
    /** Size of hypervisor core.
 *   * It starts with the hypervisor's header and ends after its bss
 *       * section. Rounded up to page boundary.
 *           * @note Filled at build time. */
    unsigned long core_size;
    /** Size of the per-CPU data structure.
 *   * @note Filled at build time. */
    unsigned long percpu_size;
    /** Entry point (arch_entry()).
 *   * @note Filled at build time. */
    int (*entry)(unsigned int);
    /** Offset of the console page inside the hypervisor memory
 *   * @note Filled at build time. */
    unsigned long console_page;
    /** Pointer to the first struct gcov_info
 *   * @note Filled at build time */
    void *gcov_info_head;

    /** Configured maximum logical CPU ID + 1.
 *   * @note Filled by Linux loader driver before entry. */
    unsigned int max_cpus;
    /** Number of online CPUs that will call the entry function.
 *   * @note Filled by Linux loader driver before entry. */
    unsigned int online_cpus;
    /** Virtual base address of the debug console device (if used).
 *   * @note Filled by Linux loader driver on ARM and x86 before entry.
 *       *       Filled by arch_entry on ARM64. */
    void *debug_console_base;

    /** Physical address of Linux's hyp-stubs.
 *   * @note Filled by Linux loader driver before entry. */
    unsigned long long arm_linux_hyp_vectors;
    /** Denotes hyp-stub ABI for arm and arm64:
 *   * @note Filled by Linux loader driver before entry. */
    unsigned int arm_linux_hyp_abi;
};

#define JAILHOUSE_SIGNATURE "JAILHOUS"
#define JAILHOUSE_BASE      (0xfffffffff0000000)
#define PERCPU_SIZE (0x6000)
/** Hypervisor description header. */
struct jailhouse_header __attribute__((section(".header")))
hypervisor_header = {
    .signature = JAILHOUSE_SIGNATURE,
    .core_size = (unsigned long)__page_pool - JAILHOUSE_BASE,
    .percpu_size = PERCPU_SIZE,
    .entry = arch_entry - JAILHOUSE_BASE,
    .console_page = 0,
};
