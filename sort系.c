/*
2) ソート系：qsort禁止でもOKな攻略コード（自作マージソート）
2-0) 自作マージソート（long long用）※固定で貼る
*/
void merge_sort(long long *a, long long *tmp, int l, int r){
  if(r - l <= 1) return;
  int m = (l + r) / 2;
  merge_sort(a, tmp, l, m);
  merge_sort(a, tmp, m, r);

  int i=l, j=m, k=l;
  while(i<m && j<r){
    if(a[i] <= a[j]) tmp[k++] = a[i++];
    else            tmp[k++] = a[j++];
  }
  while(i<m) tmp[k++] = a[i++];
  while(j<r) tmp[k++] = a[j++];
  for(int t=l;t<r;t++) a[t] = tmp[t];
}

//2-A) 2018-2：101個の中央値

int main(void){
  const int n = 101;
  long long a[n], tmp[n];
  for(int i=0;i<n;i++) a[i]=read_ll();

  merge_sort(a, tmp, 0, n);

  printf("%lld\n", a[50]);
  return 0;
}

//2-B) 2018-3：100万個 → 1000番目に大きい

int main(void){
  const int n = 1000000;
  long long *a = malloc(sizeof(long long)*n);
  long long *tmp = malloc(sizeof(long long)*n);

  for(int i=0;i<n;i++) a[i]=read_ll();

  merge_sort(a, tmp, 0, n);

  printf("%lld\n", a[n-1000]);

  free(a); free(tmp);
  return 0;
}

//2-C) 2023-2：1000個 → 最大値と100番目に大きい

int main(void){
  const int n = 1000;
  long long a[n], tmp[n];
  for(int i=0;i<n;i++) a[i]=read_ll();

  merge_sort(a, tmp, 0, n);

  printf("%lld %lld\n", a[n-1], a[n-100]);
  return 0;
}


//2-D) 2023-3：100000個 → 最小・中央値・最大

int main(void){
  const int n = 100000;
  long long *a = malloc(sizeof(long long)*n);
  long long *tmp = malloc(sizeof(long long)*n);

  for(int i=0;i<n;i++) a[i]=read_ll();

  merge_sort(a, tmp, 0, n);

  printf("%lld %lld %lld\n", a[0], a[n/2], a[n-1]);

  free(a); free(tmp);
  return 0;
}
