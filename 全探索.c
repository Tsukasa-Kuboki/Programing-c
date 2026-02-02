/*
9枚の硬貨（各1枚）
合計が 430円以上になる最小額
考え方
	•	全組み合わせを試す
	•	合計 ≥ 430 の中で 最小を取る
*/

#include <stdio.h>

int main(void){
  int a[9];

  // 9枚の硬貨を読む
  for(int i=0;i<9;i++){
    scanf("%d", &a[i]);
  }

  int ans = 1000000000; // 十分大きな初期値

  // 全パターン（0 ～ 2^9 - 1）
  for(int mask = 0; mask < (1<<9); mask++){
    int sum = 0;

    // 各ビットを見る
    for(int i = 0; i < 9; i++){
      if(mask & (1<<i)){
        sum += a[i];
      }
    }

    // 条件チェック
    if(sum >= 430 && sum < ans){
      ans = sum;
    }
  }

  printf("%d\n", ans);
  return 0;
}
/*
問題

12枚の硬貨
ちょうど500円になる組み合わせ数

考え方
	•	全探索
	•	sum == 500 の数を数える
*/

#include <stdio.h>

int main(void){
  int a[12];

  // 12枚の硬貨を読む
  for(int i = 0; i < 12; i++){
    scanf("%d", &a[i]);
  }

  int cnt = 0;

  // 全パターン：0 ～ (2^12 - 1)
  for(int mask = 0; mask < (1<<12); mask++){
    int sum = 0;

    for(int i = 0; i < 12; i++){
      if(mask & (1<<i)){
        sum += a[i];
      }
    }

    if(sum == 500){
      cnt++;
    }
  }

  printf("%d\n", cnt);
  return 0;
}
