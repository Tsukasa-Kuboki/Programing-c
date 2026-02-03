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


#include <stdio.h>

static inline int read_int(void){
  int c = getchar_unlocked();
  while (c <= ' ' && c != EOF) c = getchar_unlocked();
  int x = 0;
  while (c > ' ') { x = x*10 + (c - '0'); c = getchar_unlocked(); }
  return x;
}

//スタックの合計出すみたいな

int main(void){
  const int N = 1000;
  int st[1000];
  int top = 0;

  for(int i=0;i<N;i++){
    int x = read_int();
    if(x > 0){
      st[top++] = x;   // push
    }else{
      top--;           // pop（空でない保証）
    }
  }

  long long sum = 0;
  for(int i=0;i<top;i++) sum += st[i];

  printf("%lld\n", sum);
  return 0;
}
