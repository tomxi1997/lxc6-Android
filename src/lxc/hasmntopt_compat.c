// src/lxc/hasmntopt.c
#include <string.h>
#include <mntent.h>

// 手动实现 hasmntopt 函数（适配 Android musl libc）
// 功能：检查挂载项（mnt）是否包含指定选项（opt），返回选项起始地址或 NULL
char *hasmntopt(const struct mntent *mnt, const char *opt) {
    char *opt_ptr;
    char *tmp_opt;
    char *save_ptr;
    char opts_copy[1024];  // 存储挂载选项副本（避免修改原数据）

    // 1. 检查输入合法性
    if (!mnt || !mnt->mnt_opts || !opt) {
        return NULL;
    }

    // 2. 复制挂载选项字符串（strtok 会修改原字符串，需用副本）
    strncpy(opts_copy, mnt->mnt_opts, sizeof(opts_copy) - 1);
    opts_copy[sizeof(opts_copy) - 1] = '\0';  // 确保字符串终止

    // 3. 按逗号分割选项（挂载选项格式："rw,relatime,create=dir"）
    tmp_opt = strtok_r(opts_copy, ",", &save_ptr);
    while (tmp_opt != NULL) {
        // 4. 去除选项前后空格（如 " create=dir " → "create=dir"）
        opt_ptr = tmp_opt;
        while (*opt_ptr == ' ') opt_ptr++;  // 跳过前导空格
        char *end_ptr = opt_ptr + strlen(opt_ptr) - 1;
        while (end_ptr > opt_ptr && *end_ptr == ' ') end_ptr--;  // 跳过尾随空格
        *(end_ptr + 1) = '\0';  // 截断空格后的字符

        // 5. 匹配目标选项（支持精确匹配，如 "optional" 或 "create=dir"）
        if (strcmp(opt_ptr, opt) == 0) {
            // 计算原字符串中该选项的起始地址（返回原 mnt->mnt_opts 的指针）
            return mnt->mnt_opts + (opt_ptr - opts_copy);
        }

        // 6. 处理下一个选项
        tmp_opt = strtok_r(NULL, ",", &save_ptr);
    }

    // 7. 未找到目标选项
    return NULL;
}
