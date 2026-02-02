//共通
#include <stdio.h>
#include <stdlib.h>

static inline long long read_ll(void){
  int c = getchar_unlocked();
  while (c <= ' ' && c != EOF) c = getchar_unlocked();
  long long x = 0;
  while (c > ' ') { x = x*10 + (c - '0'); c = getchar_unlocked(); }
  return x;
}


/*1) 全走査（for 1本）系：攻略コード
1-A) 2018-1：20000個のうち偶数の個数
  */

int main(void){
  int cnt = 0;
  for(int i=0;i<20000;i++){
    long long x = read_ll();
    if(x % 2 == 0) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}


//1-B) 2023-1：最後の値 x と一致する最初の位置
int main(void){
  const int n = 10001;
  long long a[n];
  for(int i=0;i<n;i++) a[i] = read_ll();
  long long x = a[n-1];

  for(int i=0;i<n;i++){
    if(a[i] == x){
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
  
