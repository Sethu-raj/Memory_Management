#include <linux/module.h>
#include <linux/kernel.h>

static int __init page_init(void)
{
    pr_info("PAGE_SIZE = %lu bytes\n", PAGE_SIZE);
    return 0;
}

static void __exit page_exit(void)
{
}

module_init(page_init);
module_exit(page_exit);

MODULE_LICENSE("GPL");
