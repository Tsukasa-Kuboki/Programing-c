#include <stdio.h>

#define MAXN 50

int n;
int left[MAXN], right[MAXN];
int depth[MAXN];
int isChild[MAXN];

/* ===== DFS（深さ計算） ===== */
void dfs(int v, int d){
  depth[v] = d;
  if(left[v] != -1) dfs(left[v], d+1);
  if(right[v] != -1) dfs(right[v], d+1);
}

/* ===== 巡回 ===== */
// pre-order: 自分 → 左 → 右
void pre(int v){
  printf("%d ", v);
  if(left[v] != -1) pre(left[v]);
  if(right[v] != -1) pre(right[v]);
}

// in-order: 左 → 自分 → 右
void in(int v){
  if(left[v] != -1) in(left[v]);
  printf("%d ", v);
  if(right[v] != -1) in(right[v]);
}

// post-order: 左 → 右 → 自分
void post(int v){
  if(left[v] != -1) post(left[v]);
  if(right[v] != -1) post(right[v]);
  printf("%d ", v);
}

int main(void){
  /* ===== 入力 ===== */
  scanf("%d", &n);
  for(int i=0;i<MAXN;i++){
    left[i] = right[i] = -1;
    isChild[i] = 0;
  }

  for(int i=0;i<n;i++){
    int id, l, r;
    scanf("%d %d %d", &id, &l, &r);
    left[id] = l;
    right[id] = r;
    if(l != -1) isChild[l] = 1;
    if(r != -1) isChild[r] = 1;
  }

  /* ===== root を探す ===== */
  int root = -1;
  for(int i=0;i<n;i++){
    if(!isChild[i]){
      root = i;
      break;
    }
  }

  /* ===== 深さ計算 ===== */
  dfs(root, 0);

  /* ==================================================
     --- ここから問題別（必要なものだけ残す） ---
     ================================================== */

  /* (A) 木の高さ（最大深さ） */
  int height = 0;
  for(int i=0;i<n;i++) if(depth[i] > height) height = depth[i];
  printf("%d\n", height);

  /* (B) 深さが k 以上のノード数（例：k=4） */
  int k = 4;
  int cnt_ge_k = 0;
  for(int i=0;i<n;i++) if(depth[i] >= k) cnt_ge_k++;
  printf("%d\n", cnt_ge_k);

  /* (C) 深さがちょうど k のノード数 */
  int cnt_eq_k = 0;
  for(int i=0;i<n;i++) if(depth[i] == k) cnt_eq_k++;
  printf("%d\n", cnt_eq_k);

  /* (D) 葉ノード数（子を持たない） */
  int leaf = 0;
  for(int i=0;i<n;i++){
    if(left[i]==-1 && right[i]==-1) leaf++;
  }
  printf("%d\n", leaf);

  /* (E) 内部ノード数（子を持つ） */
  int inner = 0;
  for(int i=0;i<n;i++){
    if(left[i]!=-1 || right[i]!=-1) inner++;
  }
  printf("%d\n", inner);

  /* (F) 巡回（必要な1つだけ使う） */
  // pre(root);  printf("\n");
  // in(root);   printf("\n");
  post(root); printf("\n");

  return 0;
}
