#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ASIZE 256 /* ASCII字母的种类 */
/*
 * * @brief 预处理，计算每个字母最靠右的位置.
 * *
 * * @param[in] pattern 模式串
 * * @param[out] right 每个字母最靠右的位置
 * * @return 无
 * */
static void pre_right(const char *pattern, int right[]) {
    int i;
    const int m = strlen(pattern);
    for (i = 0; i < ASIZE; ++i) right[i] = -1;
    for (i = 0; i < m; ++i) right[(unsigned char)pattern[i]] = i;
}
static void suffixes(const char *pattern, int suff[]) {
    int f, g, i;
    const int m = strlen(pattern);
    suff[m - 1] = m;
    g = m - 1;
    for (i = m - 2; i >= 0; --i) {
        if (i > g && suff[i + m - 1 - f] < i - g)
            suff[i] = suff[i + m - 1 - f];
        else {
            if (i < g)
                g = i;
            f = i;
            while (g >= 0 && pattern[g] == pattern[g + m - 1 - f])
                --g;
            suff[i] = f - g;
        }
    }
}
/*
 * * @brief 预处理，计算好后缀的后移位置.
 * *
 * * @param[in] pattern 模式串
 * * @param[out] gs 好后缀的后移位置
 * * @return 无
 * */
static void pre_gs(const char pattern[], int gs[]) {
    int i, j;
    const int m = strlen(pattern);
    int *suff = (int*)malloc(sizeof(int) * (m + 1));
    suffixes(pattern, suff);
    for (i = 0; i < m; ++i) gs[i] = m;
    j = 0;
    for (i = m - 1; i >= 0; --i) if (suff[i] == i + 1)
        for (; j < m - 1 - i; ++j) if (gs[j] == m)
            gs[j] = m - 1 - i;
    for (i = 0; i <= m - 2; ++i)
        gs[m - 1 - suff[i]] = m - 1 - i;
    free(suff);
}
/**
 * * @brief Boyer-Moore算法.
 * *
 * * @param[in] text 文本
 * * @param[in] pattern 模式串
 * * @return 成功则返回第一次匹配的位置，失败则返回-1
 * */
int boyer_moore(const char *text, const char *pattern) {
    int i, j;
    int right[ASIZE]; /* bad-character shift */
    const int n = strlen(text);
    const int m = strlen(pattern);
    int *gs = (int*)malloc(sizeof(int) * (m + 1)); /* good-suffix shift */
    /* Preprocessing */
    pre_right(pattern, right);
    pre_gs(pattern, gs);
    /* Searching */
    j = 0;
    while (j <= n - m) {
        for (i = m - 1; i >= 0 && pattern[i] == text[i + j]; --i);
        if (i < 0) { /* 找到一个匹配 */
            /* printf("%d ", j);
             * j += bmGs[0]; */
            free(gs);
            return j;
        } else {
            const int max = gs[i] > right[(unsigned char)text[i + j]] -
                m + 1 + i ? gs[i] : i - right[(unsigned char)text[i + j]];
            j += max;
        }
    }
    free(gs);
    return -1;
}
int main() {
    const char *text="HERE IS A SIMPLE EXAMPLE";
    const char *pattern = "EXAMPLE";
    const int pos = boyer_moore(text, pattern);
    printf("%d\n", pos); /* 17 */
    return 0;
}
