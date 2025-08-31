/* liblxcapi
 *
 * SPDX-License-Identifier: LGPL-2.1+ *
 *
 * This function has been copied from musl.
 */

#include <string.h>

struct mntent {
	char* mnt_fsname;
	char* mnt_dir;
	char* mnt_type;
	char* mnt_opts;
	int mnt_freq;
	int mnt_passno;
};

char *hasmntopt(const struct mntent *mnt, const char *opt)
{
	size_t l = strlen(opt);
	char *p = mnt->mnt_opts;
	for (;;) {
		if (!strncmp(p, opt, l) && (!p[l] || p[l]==',' || p[l]=='='))
			return p;
		p = strchr(p, ',');
		if (!p) return 0;
		p++;
	}
}