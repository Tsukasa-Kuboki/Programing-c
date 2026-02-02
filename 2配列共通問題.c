//✅ 2023-6：共通要素の個数（A,B 各10^6）
/*
やること（そのまま）
	1.	Aを読む
	2.	Bを読む
	3.	AとBをソート
	4.	two pointersで一致数を数える
	5.	出力
*/

#include <stdio.h>
#include <stdlib.h>

static inline long long read_ll(void){
  int c = getchar_unlocked();
  while (c <= ' ' && c != EOF) c = getchar_unlocked();
  long long x = 0;
  while (c > ' ') { x = x*10 + (c - '0'); c = getchar_unlocked(); }
  return x;
}

int cmp_ll_asc(const void* p, const void* q){
  long long a = *(const long long*)p;
  long long b = *(const long long*)q;
  if(a < b) return -1;
  if(a > b) return 1;
  return 0;
}

int main(void){
  freopen("F.txt","r",stdin);   // ★ファイル名を合わせる

  const int n = 1000000;
  long long *A = (long long*)malloc(sizeof(long long)*n);
  long long *B = (long long*)malloc(sizeof(long long)*n);

  for(int i=0;i<n;i++) A[i] = read_ll();
  for(int i=0;i<n;i++) B[i] = read_ll();

  qsort(A, n, sizeof(long long), cmp_ll_asc);
  qsort(B, n, sizeof(long long), cmp_ll_asc);

  long long cnt = 0;
  int i=0, j=0;
  while(i<n && j<n){
    if(A[i] == B[j]){
      cnt++;
      i++; j++;
    }else if(A[i] < B[j]){
      i++;
    }else{
      j++;
    }
  }

  printf("%lld\n", cnt);

  free(A);
  free(B);
  return 0;
}




//両方に含まれる最大の数は

#include <stdio.h>
#include <stdlib.h>

static inline long long read_ll(void){
  int c = getchar_unlocked();
  while (c <= ' ' && c != EOF) c = getchar_unlocked();
  long long x = 0;
  while (c > ' ') { x = x*10 + (c - '0'); c = getchar_unlocked(); }
  return x;
}

int cmp_ll_asc(const void* p, const void* q){
  long long a = *(const long long*)p;
  long long b = *(const long long*)q;
  if(a < b) return -1;
  if(a > b) return 1;
  return 0;
}

int main(void){
  freopen("D.txt","r",stdin);   // ★ファイル名を合わせる

  const int n = 1000000;        // ★問題の個数に合わせる（2018-4の指定個数）
  long long *A = (long long*)malloc(sizeof(long long)*n);
  long long *B = (long long*)malloc(sizeof(long long)*n);

  for(int i=0;i<n;i++) A[i] = read_ll();
  for(int i=0;i<n;i++) B[i] = read_ll();

  qsort(A, n, sizeof(long long), cmp_ll_asc);
  qsort(B, n, sizeof(long long), cmp_ll_asc);

  long long ans = -1;
  int i=0, j=0;
  while(i<n && j<n){
    if(A[i] == B[j]){
      ans = A[i];   // 一致した値（昇順なので更新すると大きくなっていく）
      i++; j++;
    }else if(A[i] < B[j]){
      i++;
    }else{
      j++;
    }
  }

  printf("%lld\n", ans);

  free(A);
  free(B);
  return 0;
}



//共通要素をすべ出力する場合
if(A[i]==B[j]){
  printf("%lld\n", A[i]);  // 共通要素を1行ずつ出す
  i++; j++;
}



//再品を出す場合
long long bestVal = 0;
long long bestCnt = 0;

int i=0, j=0;
while(i<n && j<m){
  if(A[i]==B[j]){
    long long v = A[i];
    long long cA=0, cB=0;
    while(i<n && A[i]==v){ cA++; i++; }
    while(j<m && B[j]==v){ cB++; j++; }
    long long common = (cA < cB) ? cA : cB;
    if(common > bestCnt){
      bestCnt = common;
      bestVal = v;
    }
  }else if(A[i] < B[j]){
    i++;
  }else{
    j++;
  }
}

if(bestCnt==0) printf("-1\n");     // 共通が無い場合
else printf("%lld\n", bestVal);    // 最頻の共通値



//③ “共通の一番小さい数字” を出したい

long long ans = -1;

int i=0, j=0;
while(i<n && j<m){
  if(A[i]==B[j]){
    ans = A[i];
    break;            // ←最初に見つけた一致が最小
  }else if(A[i] < B[j]){
    i++;
  }else{
    j++;
  }
}

printf("%lld\n", ans);



//共通の一番大きい数字
int i=n-1, j=m-1;
long long ans = -1;
while(i>=0 && j>=0){
  if(A[i]==B[j]){ ans=A[i]; break; }
  else if(A[i] > B[j]) i--;
  else j--;
}
printf("%lld\n", ans);




//共通にしたやつ


#include <stdio.h>
#include <stdlib.h>

/* ========= 設定ここだけ変える ========= */

// 入力ファイル名
#define INPUT_FILE "A.txt"

// 配列サイズ（問題文に合わせる）
#define N 1000000
#define M 1000000

// 目的別モード（↓から1つ選ぶ）
// 1: 共通要素の個数
// 2: 共通要素をすべて出力（重複なし）
// 3: 共通の最小値
// 4: 共通の最大値
// 5: 共通で一番多い値（最頻値）
#define MODE 1

/* ===================================== */

static inline long long read_ll(void){
  int c = getchar_unlocked();
  while (c <= ' ' && c != EOF) c = getchar_unlocked();
  long long x = 0;
  while (c > ' ') {
    x = x * 10 + (c - '0');
    c = getchar_unlocked();
  }
  return x;
}

int cmp_ll_asc(const void* p, const void* q){
  long long a = *(const long long*)p;
  long long b = *(const long long*)q;
  if(a < b) return -1;
  if(a > b) return 1;
  return 0;
}

int main(void){
  freopen(INPUT_FILE, "r", stdin);

  long long *A = malloc(sizeof(long long) * N);
  long long *B = malloc(sizeof(long long) * M);

  for(int i=0;i<N;i++) A[i] = read_ll();
  for(int i=0;i<M;i++) B[i] = read_ll();

  qsort(A, N, sizeof(long long), cmp_ll_asc);
  qsort(B, M, sizeof(long long), cmp_ll_asc);

  int i=0, j=0;

#if MODE == 1
  /* 共通要素の個数 */
  long long cnt = 0;
  while(i<N && j<M){
    if(A[i]==B[j]){
      cnt++; i++; j++;
    }else if(A[i] < B[j]){
      i++;
    }else{
      j++;
    }
  }
  printf("%lld\n", cnt);

#elif MODE == 2
  /* 共通要素をすべて出力（重複なし） */
  long long last = -(1LL<<60);
  while(i<N && j<M){
    if(A[i]==B[j]){
      if(A[i] != last){
        printf("%lld\n", A[i]);
        last = A[i];
      }
      i++; j++;
    }else if(A[i] < B[j]){
      i++;
    }else{
      j++;
    }
  }

#elif MODE == 3
  /* 共通の最小値 */
  long long ans = -1;
  while(i<N && j<M){
    if(A[i]==B[j]){
      ans = A[i];
      break;
    }else if(A[i] < B[j]){
      i++;
    }else{
      j++;
    }
  }
  printf("%lld\n", ans);

#elif MODE == 4
  /* 共通の最大値 */
  long long ans = -1;
  while(i<N && j<M){
    if(A[i]==B[j]){
      ans = A[i];
      i++; j++;
    }else if(A[i] < B[j]){
      i++;
    }else{
      j++;
    }
  }
  printf("%lld\n", ans);

#elif MODE == 5
  /* 共通で一番多い値（最頻） */
  long long bestVal = -1;
  long long bestCnt = 0;

  while(i<N && j<M){
    if(A[i]==B[j]){
      long long v = A[i];
      long long cA = 0, cB = 0;
      while(i<N && A[i]==v){ cA++; i++; }
      while(j<M && B[j]==v){ cB++; j++; }
      long long common = (cA < cB) ? cA : cB;
      if(common > bestCnt){
        bestCnt = common;
        bestVal = v;
      }
    }else if(A[i] < B[j]){
      i++;
    }else{
      j++;
    }
  }

  if(bestCnt == 0) printf("-1\n");
  else printf("%lld\n", bestVal);

#endif

  free(A);
  free(B);
  return 0;
}
