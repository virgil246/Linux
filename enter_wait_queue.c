#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/wait.h>
wait_queue_head_t project2_queue_1, project2_queue_2, project2_queue_3;
DECLARE_WAIT_QUEUE_HEAD(project2_queue_1);
DECLARE_WAIT_QUEUE_HEAD(project2_queue_2);
DECLARE_WAIT_QUEUE_HEAD(project2_queue_3);

asmlinkage int sys_enter_wait_queue(int x)
{
    switch (x)
    {
    case 1:
        printk("enqueue in queue1 %p \n", &project2_queue_1);
        interruptible_sleep_on(&project2_queue_1);

        return 1;
        break;
    case 2:
        printk("enqueue in queue2 %p \n", &project2_queue_2);
        interruptible_sleep_on(&project2_queue_2);

        return 1; //
        break;
    case 3:
        printk("enqueue in queue3 %p \n", &project2_queue_3);
        interruptible_sleep_on(&project2_queue_3);

        return 1;
        break;
    default:
        printk("Failed\n");
        break;
    }
}
