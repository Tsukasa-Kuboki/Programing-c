#include <stdio.h>

int main(void){
  long long st[200000];
  int top = 0;

  int x;
  while(scanf("%d",&x)!=EOF){
    if(x==0){
      if(top>0) top--;
    }else{
      st[top++] = x;
    }
  }

  long long sum = 0;
  for(int i=0;i<top;i++) sum += st[i];

  printf("%lld\n", sum);
  return 0;
}
