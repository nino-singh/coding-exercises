#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverseString(char *begin, char *end);
void removeExtraSpaces(char *s);
void reverseWords(char *s);

int main(void) {
  char str[] = "this is a simple string";
  char str2[] = "this  is not  a  simple string ";
  char str3[] = " this  one is the  worst string   ";

  printf("Input: --%s--\n", str3);
  reverseWords(str3);
  printf("Reverse Words: --%s--\n", str3);

  return 0;
}

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
