#include <stdio.h>
#include <limits.h>

#define MAXN 200
#define MAXE 10000
#define INF  (1LL<<60)

int n, m;
int to[MAXE], w[MAXE], nxt[MAXE], head[MAXN], ecnt;
long long dist[MAXN];
int used[MAXN];

void add_edge(int u, int v, int c){
  to[ecnt] = v;
  w[ecnt]  = c;
  nxt[ecnt]= head[u];
  head[u]  = ecnt++;
}

int main(void){
  scanf("%d %d", &n, &m);
  for(int i=1;i<=n;i++) head[i] = -1;

  for(int i=0;i<m;i++){
    int u,v,c;
    scanf("%d %d %d", &u, &v, &c);
    add_edge(u, v, c);
  }

  /* ===== Dijkstra ===== */
  for(int i=1;i<=n;i++){
    dist[i] = INF;
    used[i] = 0;
  }
  dist[1] = 0;

  for(int iter=0; iter<n; iter++){
    int v = -1;
    for(int i=1;i<=n;i++){
      if(!used[i] && (v==-1 || dist[i] < dist[v])){
        v = i;
      }
    }

    used[v] = 1;

    for(int e=head[v]; e!=-1; e=nxt[e]){
      int u = to[e];
      if(dist[u] > dist[v] + w[e]){
        dist[u] = dist[v] + w[e];
      }
    }
  }

  /* ===== ここから問題別 ===== */

  return 0;
}

//「1から最短距離が最大になる頂点」
long long ans = 0;
for(int i=1;i<=n;i++){
  if(dist[i] > ans) ans = dist[i];
}
printf("%lld\n", ans);

