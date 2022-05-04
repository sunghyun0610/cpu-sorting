# Computer Algorithm -sorting- by 201901671 문성현
### 구성 : 각 정렬 알고리즘들 설명 및 코딩과 정렬 여부에 따른 시간 복잡도 변화.
<br> 1. 버블정렬(bubble sort)
-   첫번째 원소부터 인접한 원소와 비교하며 자리를 바꾸면서 맨 끝부터 정렬하는 방식.
```
//버블정렬 코드!201901671 문성현//
//오름차순//
#include <stdio.h>
#define num 20
int main(){
int arr[num]={0,};
int temp=0;
for(int i=0;i<num;i++){
    scanf("%d",&arr[i]);
}
for(int i = 0 ; i < num ; i ++) {
     for(int j = 0 ; j < num -i -1 ; j ++) {
                if(arr[j]>arr[j+1]) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
         }
    }
}
         
for(int i = 0 ; i < 20 ; i ++) {
     printf("%d ",arr[i]);
    }
    return 0;
}
```
2. 선택정렬(Selection sort)
-   가장 최소값을 찾고 배열의 맨 앞쪽에 위치시키며 정렬.
```
//선택정렬 내림차순//
#include <stdio.h>
#define num 20
int main(){
int number[num]={1,3,5,4,0,};
int temp;
for(int i = 0 ; i < num-1 ; i ++) {
    for(int j = i+1 ; j < num ; j ++) {
        if(number[i] < number[j]) {
            temp = number[j];
            number[j] = number[i];
            number[i] = temp;
       }
    }
}
          
for(int i = 0 ; i <  num ; i ++) {
      printf("[%d]",number[i]);
    }
}
```