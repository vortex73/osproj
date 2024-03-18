#include "linux/kern_levels.h"
#include "linux/printk.h"
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched/signal.h>

static int __init process_tree_init(void) {
    struct task_struct *task;
    struct task_struct *child;
    struct list_head *list;

    printk(KERN_INFO "Initializing Process Tree Module\n");

    for_each_process(task) {
        printk(KERN_INFO "Parent Process: %s [%d]\n", task->comm, task->pid);

        list_for_each(list, &task->children) {
            child = list_entry(list, struct task_struct, sibling);
            printk(KERN_INFO " |");
            printk(KERN_INFO " - Child Process: %s [%d]\n", child->comm, child->pid);
        }
    }

    return 0;
}

static void __exit process_tree_exit(void) {
    printk(KERN_INFO "Exiting Process Tree Module\n");
}

module_init(process_tree_init);
module_exit(process_tree_exit);


