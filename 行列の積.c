#include <stdio.h>
#include <limits.h>

int main(void){
  int n;
  scanf("%d",&n);

  int p[n+1];
  for(int i=0;i<n;i++){
    int r,c;
    scanf("%d %d",&r,&c);
    if(i==0) p[0]=r;
    p[i+1]=c;
  }

  long long dp[n+1][n+1];
  for(int i=1;i<=n;i++) dp[i][i]=0;

  for(int len=2; len<=n; len++){
    for(int i=1; i+len-1<=n; i++){
      int j = i+len-1;
      dp[i][j] = LLONG_MAX;
      for(int k=i; k<j; k++){
        long long cost =
          dp[i][k] + dp[k+1][j]
          + (long long)p[i-1]*p[k]*p[j];
        if(cost < dp[i][j]) dp[i][j] = cost;
      }
    }
  }

  printf("%lld\n", dp[1][n]);
  return 0;
}
