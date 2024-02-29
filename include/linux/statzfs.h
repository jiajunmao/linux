#ifndef LINUX_STATZFS_H
#define LINUX_STATZFS_H

#include <linux/types.h>
#include <asm/statfs.h>
#include <asm/byteorder.h>

struct kstatzfs {
	long dummy;
};

int zfs_statfs(struct kstatzfs *zfs_stat);

#endif //LINUX_STATZFS_H
