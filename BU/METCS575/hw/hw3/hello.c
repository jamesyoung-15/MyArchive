/*
 * File: hello.c
 * Purpose : To demonstrate a simple kernel module.
 */


#include <linux/module.h> /* for all kernel modules */
#include <linux/kernel.h> /* for KERN_INFO */

int init_module ( void ) /* module entry point */
{
    printk(KERN_INFO "Hello , James Young!\n" );
    return 0;
}

void cleanup_module ( void ) /* module exit point */
{
    printk(KERN_INFO "Goodbye , James Young!\n" );
    return;
}

MODULE_LICENSE ("GPL");
MODULE_DESCRIPTION ("My first cool kernel module ");
MODULE_AUTHOR ("James Young");
