#include <stdio.h>

#define MAXN 200
#define MAXE 10000

int n, m;
int to[MAXE], nxt[MAXE], head[MAXN], ecnt;
int dist[MAXN];
int q[MAXN];

void add_edge(int u, int v){
  to[ecnt] = v;
  nxt[ecnt] = head[u];
  head[u] = ecnt++;
}

int main(void){
  scanf("%d %d", &n, &m);
  for(int i=1;i<=n;i++) head[i] = -1;

  for(int i=0;i<m;i++){
    int u,v;
    scanf("%d %d", &u, &v);
    add_edge(u, v);
  }

  /* ===== BFS ===== */
  for(int i=1;i<=n;i++) dist[i] = -1;

  int l=0, r=0;
  q[r++] = 1;
  dist[1] = 0;

  while(l < r){
    int v = q[l++];
    for(int e=head[v]; e!=-1; e=nxt[e]){
      int u = to[e];
      if(dist[u] == -1){
        dist[u] = dist[v] + 1;
        q[r++] = u;
      }
    }
  }

  /* ===== ここから問題別 ===== */

  return 0;
}


//到達できる頂点数
int cnt = 0;
for(int i=1;i<=n;i++){
  if(dist[i] != -1) cnt++;
}
printf("%d\n", cnt);


//1 → 86 の最短距離（辺数）
printf("%d\n", dist[86]);

//到達できない頂点数
int cnt = 0;
for(int i=1;i<=n;i++){
  if(dist[i] == -1) cnt++;
}
printf("%d\n", cnt);
