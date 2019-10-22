#include <stdlib.h>

int lengh(char* str){
  int count = 0;
  while(str[count]!='\0'){
    count++;
  }
  return count;
}
