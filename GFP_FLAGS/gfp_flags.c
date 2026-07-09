#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/io.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu");
MODULE_DESCRIPTION("Example of kmalloc with GFP Flags");

static void *ptr;
static int alloc_size = 1024;

static int __init gfp_flags_init(void)
{
    phys_addr_t physical_address;

    pr_info("=== GFP_DMA Allocation ===\n");

    ptr = kmalloc(alloc_size, GFP_DMA);
    if (!ptr) {
        pr_err("GFP_DMA allocation failed\n");
        return -ENOMEM;
    }

    pr_info("Virtual Address : %px\n", ptr);
    physical_address = virt_to_phys(ptr);
    pr_info("Physical Address: %pa\n", &physical_address);
    kfree(ptr);

    pr_info("=== GFP_DMA32 Allocation ===\n");

    ptr = kmalloc(alloc_size, GFP_DMA32);
    if (!ptr) {
        pr_err("GFP_DMA32 allocation failed\n");
        return -ENOMEM;
    }

    pr_info("Virtual Address : %px\n", ptr);
    physical_address = virt_to_phys(ptr);
    pr_info("Physical Address: %pa\n", &physical_address);
    kfree(ptr);

    return 0;   
}

static void __exit gfp_flags_exit(void)
{
    pr_info("Module unloaded\n");
}

module_init(gfp_flags_init);
module_exit(gfp_flags_exit);
