/* liblxcapi
 *
 * SPDX-License-Identifier: LGPL-2.1+ *
 *
 * This function has been copied from musl.
 */

#ifndef _HASMNTOPT_H
#define _HASMNTOPT_H

#include "../lxc/compiler.h"

__hidden extern char* hasmntopt(const struct mntent* mnt, const char* opt);

#endif