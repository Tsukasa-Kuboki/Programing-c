/*
最大ヒープ（最後に1個残す）

問題の流れ
	1.	最大ヒープを作る
	2.	最大値 a, b を pop
	3.	(a+b)%10^9 を push
	4.	1個になるまで繰り返す
*/

#include <stdio.h>
#define MOD 1000000000LL

long long h[200000];
int sz = 0;

void push(long long x){
  int i = ++sz;
  while(i>1 && h[i/2] < x){
    h[i] = h[i/2];
    i /= 2;
  }
  h[i] = x;
}

long long pop(){
  long long ret = h[1];
  long long x = h[sz--];
  int i=1;
  while(i*2 <= sz){
    int c = i*2;
    if(c+1<=sz && h[c+1] > h[c]) c++;
    if(h[c] <= x) break;
    h[i] = h[c];
    i = c;
  }
  h[i] = x;
  return ret;
}

int main(void){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    long long x;
    scanf("%lld",&x);
    push(x);
  }

  while(sz > 1){
    long long a = pop();
    long long b = pop();
    push((a+b)%MOD);
  }

  printf("%lld\n", h[1]);
  return 0;
}

/*
最小ヒープ（popした値の合計）
*/
long long h[200000];
int sz = 0;

void push(long long x){
  int i = ++sz;
  while(i>1 && h[i/2] > x){
    h[i] = h[i/2];
    i /= 2;
  }
  h[i] = x;
}

long long pop(){
  long long ret = h[1];
  long long x = h[sz--];
  int i=1;
  while(i*2 <= sz){
    int c = i*2;
    if(c+1<=sz && h[c+1] < h[c]) c++;
    if(h[c] >= x) break;
    h[i] = h[c];
    i = c;
  }
  h[i] = x;
  return ret;
}
