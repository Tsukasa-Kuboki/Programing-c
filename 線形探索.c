#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline long long read_ll(void){                           //例：2018-1（偶数の個数）の完成形
  int c = getchar_unlocked();
  while (c <= ' ' && c != EOF) c = getchar_unlocked();
  long long x = 0;
  while (c > ' ') { x = x*10 + (c - '0'); c = getchar_unlocked(); }
  return x;
}

int main(void){
  freopen("A.txt","r",stdin);   // ★ここだけファイル名を合わせる

  int cnt = 0;
  for(int i=0;i<20000;i++){
    long long x = read_ll();
    if(x % 2 == 0) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}


//問題	整数が 配列として順番に並んでいる
//最後の要素を x とする
//	配列の先頭から見ていって
//   x と同じ値が最初に出てくる位置（インデックス）を出力

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline long long read_ll(void){
  int c = getchar_unlocked();
  while (c <= ' ' && c != EOF) c = getchar_unlocked();
  long long x = 0;
  while (c > ' ') { x = x*10 + (c - '0'); c = getchar_unlocked(); }
  return x;
}

int main(void){
  freopen("A.txt","r",stdin);

  long long a[10001];

  for(int i = 0; i < 10001; i++){
    a[i] = read_ll();
  }

  long long x = a[10000];

  for(int i = 0; i < 10001; i++){
    if(a[i] == x){
      printf("%d\n", i);
      break;
    }
  }

  return 0;
}
