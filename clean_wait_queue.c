#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/wait.h>
extern wait_queue_head_t project2_queue_1, project2_queue_2, project2_queue_3;

asmlinkage int sys_clean_wait_queue(int x)
{
    switch (x)
    {
    case 1:
        printk("dequeue in queue1\n");
        wake_up_all(&project2_queue_1);

        return 1;
        break;
    case 2:
        printk("dequeue in queue2\n");
        wake_up_all(&project2_queue_2);

        return 1; //
        break;
    case 3:
        printk("dequeue in queue3\n");
        wake_up_all(&project2_queue_3);

        return 1;
        break;
    default:
        return 0;
        break;
    }
}
