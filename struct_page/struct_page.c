#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <linux/mm_types.h>

MODULE_LICENSE("GPL");

static int __init page_init(void)
{
    pr_info("PAGE_SIZE = %lu bytes\n", PAGE_SIZE);
    pr_info("sizeof(struct page) = %lu bytes\n",
            sizeof(struct page));

    return 0;
}

static void __exit page_exit(void)
{
}

module_init(page_init);
module_exit(page_exit);
