# Exercise 6-1 Using Arrays to Summarize Survey Result

<img src="https://github.com/channel104257/TaipeiTech-Programming-292362/blob/main/week6/exercise%206-1/original_6-1.jpg"/>
<br/>
題目在此要求使用以下程式庫及定義

```C
#include <stdio.h>
#define RESPONSES_SIZE 40
#define FREQUENCY_SIZE 10

int responses[RESPONSES_SIZE]
int frequency[FREQUENCY_SIZE] 
```
## 說明
### 讀取輸入端資料

```C
for (size_t i = 1; i <= RESPONSES_SIZE; ++i)
    {
        printf("Please Enter The Responses %d (1 ~ 10) : ", i);
        scanf_s("%d", &score);
        .
        .
        .
    }
```
題目首先須讀取40筆輸入資料<br/>
且要求以原圖左下方表示


### 輸入數值確認

```C
if (score < 1 || score > 10)
{
  i = i - 1;
}
```
當取到1~10以外的數字時<br/>
會要求使用者重新輸入且不記錄該筆數據<br/>
便在第一層for中的`i`減一 讓程式不繼續往下跑

### 分數整合統計
```C
if (score >= 1 || score <= 10)
{
  responses[i] = score;

  for (size_t j = 1; j <= FREQUENCY_SIZE; j++)
  {
    if (j == score)
    {
      frequency[j]++;
    }
  }
}
```
輸入到正確的數字之後<br/>
將該成績存入陣列外<br/>
也依據其成績將其分類至相對應位置

> #### 計數迴圈
> ```C
>  for (size_t j = 1; j <= FREQUENCY_SIZE; j++)
>  {
>    if (j == score)
>    {
>      frequency[j]++;
>    }
>  }
> ```
> 這邊使用的陣列格數是 第**1** ~ 第**10** 格<br>
> 當分數等於該格編號時
> 該格數值+1

### 終端機輸出

```C
printf("\nRating   Frequency\n");
for (size_t i = 1; i <= FREQUENCY_SIZE; i++)
{
  printf("%6d%12d\n",i, frequency[i]);
}
```
成功將數值輸出後 便完成本題練習

## 附註
本程式運行時不需使用到原始資料<br>
在完成分類後應釋放記憶體空間<br>
以免造成記憶體占用及效率不佳<br>
