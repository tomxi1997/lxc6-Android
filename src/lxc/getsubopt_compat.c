#include <string.h>
#include <stdlib.h>

/* Android Bionic兼容实现：POSIX标准getsubopt函数 */
int getsubopt(char **optionp, const char *const *tokens, char **valuep) {
    char *option = *optionp;
    char *equal = strchr(option, '=');
    char *colon = strchr(option, ':');
    size_t token_len;
    int i;

    /* 提取当前子选项（到'='或':'为止） */
    if (equal) {
        token_len = equal - option;
        *valuep = equal + 1;
        if (colon) {
            *colon = '\0'; /* 截断后续子选项 */
            *optionp = colon + 1;
        } else {
            *optionp = *valuep + strlen(*valuep);
        }
    } else {
        *valuep = NULL;
        if (colon) {
            token_len = colon - option;
            *colon = '\0';
            *optionp = colon + 1;
        } else {
            token_len = strlen(option);
            *optionp = option + token_len;
        }
    }

    /* 匹配tokens中的子选项 */
    for (i = 0; tokens[i] != NULL; i++) {
        if (strlen(tokens[i]) == token_len && strncmp(option, tokens[i], token_len) == 0) {
            return i;
        }
    }

    /* 未匹配到的子选项，返回-1 */
    return -1;
}
