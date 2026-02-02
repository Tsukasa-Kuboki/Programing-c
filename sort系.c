
//① 2018-2：101個の整数 → 中央値
//考え方
//101個 → 奇数
//ソート後の中央値 → a[50]（0始まり）
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
  freopen("A.txt","r",stdin);

  long long a[101];
  for(int i = 0; i < 101; i++) a[i] = read_ll();

  qsort(a, 101, sizeof(long long), cmp_ll_asc);

  printf("%lld\n", a[50]);
  return 0;
}

//2018-3：1,000,000個 → 1000番目に大きい
//考え方
//	大きい順で 1000番目
//	昇順ソートなら
// a[n - 1000]



int main(void){
  freopen("A.txt","r",stdin);

  const int n = 1000000;
  long long *a = malloc(sizeof(long long) * n);

  for(int i = 0; i < n; i++) a[i] = read_ll();

  qsort(a, n, sizeof(long long), cmp_ll_asc);

  printf("%lld\n", a[n - 1000]);

  free(a);
  return 0;
}


//② 2018-3：1,000,000個 → 1000番目に大きい

//考え方
//	大きい順で 1000番目
//	昇順ソートなら
// a[n - 1000]

int main(void){
  freopen("A.txt","r",stdin);

  const int n = 1000;
  long long a[n];

  for(int i = 0; i < n; i++) a[i] = read_ll();

  qsort(a, n, sizeof(long long), cmp_ll_asc);

  printf("%lld %lld\n", a[n-1], a[n-100]);
  return 0;
}



//④ 2023-3：100,000個 → 最小・中央値・最大
//考え方
	//•	最小 → a[0]
	//•	中央値 → a[n/2]
	//•	最大 → a[n-1]

int main(void){
  freopen("A.txt","r",stdin);

  const int n = 100000;
  long long *a = malloc(sizeof(long long) * n);

  for(int i = 0; i < n; i++) a[i] = read_ll();

  qsort(a, n, sizeof(long long), cmp_ll_asc);

  printf("%lld %lld %lld\n", a[0], a[n/2], a[n-1]);

  free(a);
  return 0;
}




qsort使えない時


⑥ ここが理解できれば合格ライン
	•	外側の for → 並べる位置
	•	内側の for → 最小を探す
	•	swap → 入れ替え

👉 「小さい順に1個ずつ確定させていく」

⸻

⑦ 注意点（試験で超重要）
	•	❌ 100000 個以上では使わない
	•	⭕ 1000 個以下なら安全
	•	今回（101個）は selection sort が最適



#include <stdio.h>

static inline long long read_ll(void){
  int c = getchar_unlocked();
  while (c <= ' ' && c != EOF) c = getchar_unlocked();
  long long x = 0;
  while (c > ' ') { x = x*10 + (c - '0'); c = getchar_unlocked(); }
  return x;
}

void selection_sort(long long *a, int n){
  for(int i = 0; i < n - 1; i++){
    int min = i;
    for(int j = i + 1; j < n; j++){
      if(a[j] < a[min]){
        min = j;
      }
    }
    long long tmp = a[i];
    a[i] = a[min];
    a[min] = tmp;
  }
}

int main(void){
  freopen("A.txt","r",stdin);

  long long a[101];
  for(int i = 0; i < 101; i++){
    a[i] = read_ll();
  }

  selection_sort(a, 101);

  printf("%lld\n", a[50]);
  return 0;
}
