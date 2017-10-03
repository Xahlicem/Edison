#include <linux/init.h>
#include <linux/module.h>

static int hello_init(void) {
	printk(KERN_ALERT "TEST: Hello World!");
	return 0;
}

static void hello_exit(void) {
	printk(KERN_ALERT "TEST: Goodbye");
}

module_init(hello_init);
module_exit(hello_exit);
