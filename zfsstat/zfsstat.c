#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/statzfs.h>

int zfs_statfs(struct kstatzfs *zfs_stat)
{
	zfs_stat->dummy = 0;
	return 0;
}

SYSCALL_DEFINE1(statzfs, const struct kstatzfs __user *, buf)
{
	struct kstatzfs stat_zfs;
	return zfs_statfs(&stat_zfs);
}