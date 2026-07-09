#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sethu");
MODULE_DESCRIPTION("kzalloc Example");

static int *ptr;

static int __init kzalloc_init(void)
{
    int i;

    ptr = kzalloc(10 * sizeof(int), GFP_KERNEL);

    if (!ptr) {
        pr_err("kzalloc failed\n");
        return -ENOMEM;
    }

    pr_info("Memory allocated successfully\n");

    for (i = 0; i < 10; i++)
        pr_info("ptr[%d] = %d\n", i, ptr[i]);

    return 0;
}

static void __exit kzalloc_exit(void)
{
    kfree(ptr);
    pr_info("Memory freed successfully\n");
}

module_init(kzalloc_init);
module_exit(kzalloc_exit);
