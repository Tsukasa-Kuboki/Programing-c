#include <stdio.h>
#include <stdlib.h>

/* ========= ここだけ変える ========= */
#define N 1000000
#define M 1000000

// 1: 共通要素の個数
// 2: 共通要素をすべて出力（重複なし）
// 3: 共通の最小値（なければ -1）
// 4: 共通の最大値（なければ -1）
// 5: 共通で一番多い値（最頻：min(countA,countB)最大。なければ -1）
#define MODE 1
/* ================================ */

static inline long long read_ll(void){
  int c = getchar_unlocked();
  while (c <= ' ' && c != EOF) c = getchar_unlocked();
  long long x = 0;
  while (c > ' ') { x = x*10 + (c - '0'); c = getchar_unlocked(); }
  return x;
}

/* qsort禁止対策：自作 merge sort（O(n log n)） */
void merge_sort(long long *a, long long *tmp, int l, int r){
  if(r - l <= 1) return;
  int m = (l + r) / 2;
  merge_sort(a, tmp, l, m);
  merge_sort(a, tmp, m, r);

  int i=l, j=m, k=l;
  while(i<m && j<r){
    if(a[i] <= a[j]) tmp[k++] = a[i++];
    else             tmp[k++] = a[j++];
  }
  while(i<m) tmp[k++] = a[i++];
  while(j<r) tmp[k++] = a[j++];
  for(int t=l; t<r; t++) a[t] = tmp[t];
}

int main(void){
  long long *A = (long long*)malloc(sizeof(long long) * N);
  long long *B = (long long*)malloc(sizeof(long long) * M);
  long long *tmpA = (long long*)malloc(sizeof(long long) * N);
  long long *tmpB = (long long*)malloc(sizeof(long long) * M);

  for(int i=0;i<N;i++) A[i] = read_ll();
  for(int i=0;i<M;i++) B[i] = read_ll();

  merge_sort(A, tmpA, 0, N);
  merge_sort(B, tmpB, 0, M);

  int i=0, j=0;

#if MODE == 1
  long long cnt=0;
  while(i<N && j<M){
    if(A[i]==B[j]){ cnt++; i++; j++; }
    else if(A[i]<B[j]) i++;
    else j++;
  }
  printf("%lld\n", cnt);

#elif MODE == 2
  long long last = -(1LL<<60);
  while(i<N && j<M){
    if(A[i]==B[j]){
      if(A[i]!=last){
        printf("%lld\n", A[i]);
        last = A[i];
      }
      i++; j++;
    }else if(A[i]<B[j]) i++;
    else j++;
  }

#elif MODE == 3
  long long ans=-1;
  while(i<N && j<M){
    if(A[i]==B[j]){ ans=A[i]; break; }
    else if(A[i]<B[j]) i++;
    else j++;
  }
  printf("%lld\n", ans);

#elif MODE == 4
  long long ans=-1;
  while(i<N && j<M){
    if(A[i]==B[j]){ ans=A[i]; i++; j++; }
    else if(A[i]<B[j]) i++;
    else j++;
  }
  printf("%lld\n", ans);

#elif MODE == 5
  long long bestVal=-1, bestCnt=0;
  while(i<N && j<M){
    if(A[i]==B[j]){
      long long v=A[i], cA=0, cB=0;
      while(i<N && A[i]==v){ cA++; i++; }
      while(j<M && B[j]==v){ cB++; j++; }
      long long common = (cA<cB)?cA:cB;
      if(common > bestCnt){
        bestCnt = common;
        bestVal = v;
      }
    }else if(A[i]<B[j]) i++;
    else j++;
  }
  printf("%lld\n", bestVal);

#endif

  free(A); free(B); free(tmpA); free(tmpB);
  return 0;
}
