#include <stdio.h>
#include <stdlib.h>

static inline int read_token(char *s){
  return scanf("%s", s) != EOF;
}

int main(void){
  long long st[100000];
  int top = 0;

  char tok[20];
  while(read_token(tok)){
    if(tok[0]=='+' || tok[0]=='-' || tok[0]=='*' || tok[0]=='/'){
      long long b = st[--top];
      long long a = st[--top];
      if(tok[0]=='+') st[top++] = a + b;
      if(tok[0]=='-') st[top++] = a - b;
      if(tok[0]=='*') st[top++] = a * b;
      if(tok[0]=='/') st[top++] = a / b;
    }else{
      st[top++] = atoll(tok);
    }
  }

  printf("%lld\n", st[0]);
  return 0;
}
