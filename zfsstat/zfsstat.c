#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/statzfs.h>
#include <linux/uaccess.h>

// int zfs_statfs(struct kstatzfs *zfs_stat)
// {
// 	zfs_stat->dummy = 0;
// 	return 0;
// }

SYSCALL_DEFINE2(statzfs, void*, data, unsigned int, size)
{
	if (!data)
        return -EINVAL;

    // Check if size is valid
    if (size <= 0)
        return -EINVAL;

    // Access data from userspace
    void *kernel_buffer = kmalloc(size, GFP_KERNEL);
    if (!kernel_buffer)
        return -ENOMEM;

	if (copy_from_user(kernel_buffer, data, size)) {
		kfree(kernel_buffer);
		return -EFAULT;
	}

	// Cast the kernel_buffer to string and print
	char *str = (char *)kernel_buffer;	
	printk("Hello Statzfs %s\n", str);

	// // Access data from kernel space
	// struct kstatzfs *zfs_stat = (struct kstatzfs *)kernel_buffer;
	// zfs_stat->dummy = 0;

	// Copy data to userspace
	// if (copy_to_user(data, kernel_buffer, size)) {
	// 	kfree(kernel_buffer);
	// 	return -EFAULT;
	// }

	kfree(kernel_buffer);
	return 0;
}