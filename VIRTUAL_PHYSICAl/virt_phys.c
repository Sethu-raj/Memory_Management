#include <linux/kernel.h>
#include <linux/module.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");

static int __init virt_phys_init(void)
{
    int i = 10;
    void *virtual_address = (void *)&i;
    phys_addr_t physical_address = virt_to_phys(virtual_address);

    pr_info("Virtual Address of i is %p\n", virtual_address);
    pr_info("Virtual Address of i is %px\n", virtual_address);
    pr_info("Physical Address of i is %pa\n", &physical_address);
    pr_info("Virtual Address of i is %px\n",
            phys_to_virt(physical_address));

    return 0;
}

static void __exit virt_phys_exit(void)
{
    pr_info("virt_phys module removed\n");
}

module_init(virt_phys_init);
module_exit(virt_phys_exit);
