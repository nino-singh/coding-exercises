#include "StringStuff.h"

void reverseWords(char *s)
{
  //Remove extra white spaces
  removeExtraSpaces(s);

  //Reverse characters in entire string
  char *pBegin = s;
  char *pEnd = s+strlen(s) - 1;
  reverseString(pBegin, pEnd);

  //Reverse characters of each word
  pBegin = s;
  pEnd = pBegin;

  while(pEnd != NULL) {
     if(*pEnd == '\0') {
       reverseString(pBegin, pEnd-1);
       return;
     } else if(*pEnd == ' ') {
       reverseString(pBegin, pEnd-1);
       pBegin = pEnd + 1;
     }
     pEnd++;
  }
}

void removeExtraSpaces(char *s) {

  //Keep track of next free spot in the result array
  int k = 0;
  //Keep track, if curr character is a space
  bool isSpace = false;

  for(int i= 0; i < strlen(s); i++) {

  //Iterate through any leading spaces first
    while(k == 0 && i<strlen(s) && s[i] == ' ') {
      i++;
    }

    if(s[i] == ' ') {
      if(!isSpace) {
        s[k++] = s[i];
        isSpace = true;
      }
    } else {
      s[k++] = s[i];
      isSpace = false;
    }
  }
  s[k] = '\0';
}

void reverseString(char *begin, char *end)
{
   while(begin < end) {
     //Swap each character
     *begin = *begin + *end;
     *end = *begin - *end;
     *begin = *begin - *end;

     //increment pointers
     begin++;
     end--;
   }
}

int lenOfLongestSubstring(char *s)
{
  char occurrences[256] = {0};

  //Length tracking unique substring
  int currLen = 0;

  //Track length of longest substring
  int maxLen = 0;

  //Loop through characters of string s,
  for(int i = 0; i< strlen(s); i++) {

    //Check to see if curr char is in occurrences, and if this is
    //first unique character, record the index as beginning of longest substring
    if(occurrences[s[i]] == 0) {
      currLen++;
      //Put curr char into occurrences
      occurrences[s[i]]++;
    } else {

      if(currLen >= maxLen) {
        maxLen = currLen;
      }
      currLen = 0;
      memset(occurrences, 0, 256);
    }
  }

  return maxLen;
}
