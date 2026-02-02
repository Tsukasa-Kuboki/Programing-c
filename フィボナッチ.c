#include <stdio.h>

static inline int read_int(void){
  int c = getchar_unlocked();
  while (c <= ' ' && c != EOF) c = getchar_unlocked();
  int x = 0;
  while (c > ' ') { x = x*10 + (c - '0'); c = getchar_unlocked(); }
  return x;
}

long long fib(int n, long long f0, long long f1){
  if(n == 0) return f0;
  if(n == 1) return f1;
  long long a = f0, b = f1;
  for(int i = 2; i <= n; i++){
    long long c = a + b;
    a = b;
    b = c;
  }
  return b;
}

int main(void){
  int n = read_int();

  // ★ここだけ問題に合わせて変える
  long long ans = fib(n, 1, 1);   // 2023
  // long long ans = fib(n, 0, 1); // 2018

  printf("%lld\n", ans);
  return 0;
}
