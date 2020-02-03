#ifndef __STRING_STUFF_H__
#define __STRING_STUFF_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <stdbool.h>

void reverseString(char *begin, char *end);
void removeExtraSpaces(char *s);
void reverseWords(char *s);
int lenOfLongestSubstring(char *s);


#ifdef __cplusplus
}
#endif

#endif
