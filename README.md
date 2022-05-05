# Computer Algorithm -sorting- by 201901671 문성현
### 수업시간에 배우고 코딩해본 정렬 알고리즘들을 간단히 보고 넘어가겠다.
<br> 1. 버블정렬(bubble sort)
-   첫번째 원소부터 인접한 원소와 비교하며 자리를 바꾸면서 맨 끝부터 정렬하는 방식.
<br>시간복잡도:O(n^2)

<br>2. 선택정렬(Selection sort)
-   가장 작은 요소부터 선택해 알맞은 위치로 옮겨서 순서대로 정렬하는 방식.
<br>시간복잡도:O(n^2)

<br> 3.삽입정렬(insertion sort)
-   선택한 요소를 그보다 더 앞쪽의 알맞은 위치에 '삽입'하는 작업을 반복하여 정렬하는 방식.
<br>시간복잡도:O(n^2)

<br> 4. 셸 정렬(shell sort)
-   먼저 정렬한 배열의 요소를 그룹으로 나누고 각 그룹별로 삽입 정렬을 수행하고, 그 그룹을 합치면서 정렬을 반복하여 요소의 이동 횟수를 줄이는 방식
<br>시간복잡도:O(n^1.5)

<br>5. 퀵 정렬(quick sort)
- 기준점(pivot)을 정하여, 왼쪽으로는 기준점보다 낮은값/오른쪽으로는 기준점보다 높은값으로 정렬한다.그리고 낮은값(왼쪽)/높은값(오른쪽)에서 똑같은 작업을 수행한다.
<br>시간복잡도:O(nlog2n)~O(n^2)

<br>6. 힙 정렬(Heap sort)
-   힙에서 가장 큰 값인 루트를 꺼내는 작업을 반복하고 그 값을 늘어 놓으면서 정렬하는 방식
<br>시간복잡도:O(nlogn)

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 32
//32~2^20까지 데이터 개수 조절//

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) //정렬에 필요한 swap함수 선언
int original[MAX_SIZE];                                 //랜덤함수로 만든 데이터를 저장할 원본 배열
int list[MAX_SIZE];                                     //각 정렬 알고리즘에서 사용할 데이터 배열
int n;                                                  //데이터의 개수를 받는 전역변수 설정
clock_t start, finish, used_time = 0;
//실행 시간 측정을 위한 변수

//버블 정렬
void bubble_sort(int list[], int n)
{
    int i, j, tmp;
    printf("버블 정렬 중... ");
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
            if (list[j] > list[j + 1])
                SWAP(list[j], list[j + 1], tmp);
    }
}

//선택 정렬
void selection_sort(int list[], int n)
{
    int i, j, least, tmp;

    printf("선택 정렬 중... ");
    for (i = 0; i < n - 1; i++)
    {
        least = i;
        for (j = i + 1; j < n; j++)
            if (list[j] < list[least])
                least = j;
        SWAP(list[i], list[least], tmp);
    }
}

//삽입 정렬
void insertion_sort(int list[], int n)
{
    int i, j, key;
    printf("삽입 정렬 중... ");
    for (i = 1; i < n; i++)
    {
        key = list[i];
        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j];
        list[j + 1] = key;
    }
}
void inc_insertion_sort(int list[], int first, int last, int gap)
{
    int i, j, key;
    for (i = first + gap; i <= last; i = i + gap)
    {
        key = list[i];
        for (j = i - gap; j >= first && key < list[j]; j = j - gap)
            list[j + gap] = list[j];
        list[j + gap] = key;
    }
}

//셸 정렬
void shell_sort(int list[], int n)
{
    int i, gap;
    printf("쉘 정렬 중... ");
    for (gap = n / 2; gap > 0; gap = gap / 2)
    {
        if ((gap % 2) == 0)
            gap++;
        for (i = 0; i < gap; i++)
            inc_insertion_sort(list, i, n - 1, gap);
    }
}

void Heap_Sort(int[], int);
void Build_Max_Heap(int[], int);
void Max_Heapify(int[], int, int);

void Heap_Sort(int list[], int n)
{

    int *temp;
    int i;
    printf("힙 정렬 중... ");
    Build_Max_Heap(list, n); // 먼저 힙을 만든다.
    for (i = n - 1; i >= 0; i--)
    {
        SWAP(list[0], list[i], temp); // 부모노드와 마지막 노드와 SWAP
        n--;                          // 부모노드를 삭제.
        Max_Heapify(list, 0, n);      // 힙 유지 실시.
    }
}

// 힙 정렬
void Build_Max_Heap(int list[], int length)
{

    int parent_position;

    for (parent_position = length / 2 - 1; parent_position >= 0; parent_position--)
    {
        Max_Heapify(list, parent_position, length); 
    }
}


void Max_Heapify(int list[], int parent_position, int heap_size)
{

    int *temp;
    int left, right, largest;

    left = 2 * parent_position + 1;
    right = 2 * parent_position + 2;

    if ((left < heap_size) && (list[left] > list[parent_position])) 
        largest = left;
    else
        largest = parent_position;

    if ((right < heap_size) && (list[right] > list[largest])) 
        largest = right;

    if (largest != parent_position)
    {
        SWAP(list[parent_position], list[largest], temp); 
        Max_Heapify(list, largest, heap_size);           
    }
}

//원본 배열을 복사하는 함수
void CopyArr(void)
{
    int i;
    for (i = 0; i < n; i++)
        list[i] = original[i];
}

//실행 시간을 측정 및 출력하는 함수
void CalcTime(void)
{
    used_time = finish - start;
    printf("완료!\n소요 시간 : %f sec\n\n", (float)used_time / CLOCKS_PER_SEC);
}

void main()
{
    int i;

    n = MAX_SIZE;
    for (i = 0; i < n; i++)
        original[i] = rand();

    printf("데이터의 개수 : %d\n\n", n);

    CopyArr();
    start = clock();
    selection_sort(list, n);
    finish = clock();
    CalcTime();

    CopyArr();
    start = clock();
    insertion_sort(list, n);
    finish = clock();
    CalcTime();

    CopyArr();
    start = clock();
    bubble_sort(list, n);
    finish = clock();
    CalcTime();

    CopyArr();
    start = clock();
    shell_sort(list, n);
    finish = clock();
    CalcTime();

    CopyArr();
    start = clock();
    printf("퀵 정렬 중... ");
    quick_sort(list, 0, n);
    finish = clock();
    CalcTime();


    CopyArr();
    start = clock();
    Heap_Sort(list, n);
    finish = clock();
    CalcTime();

}
```
랜덤정렬인경우를 코드로 나타내었다.
reverse와 이미 정렬이 된경우는 위코드에 reverse해주거나 정렬만 시켜놓으면 되므로 생략하겠다.

## 1. 배열이 정렬되어있지 않았을 때 각 정렬 알고리즘들의 시간값 그래프(데이터 개수:2^5~2^20)

<br/>

 ![logo](https://github.com/sunghyun0610/cpu-sorting/blob/main/random%EC%A0%95%EB%A0%AC.png)

## 2.배열이 역(reverse)정렬되어있을때 각 정렬 알고리즘들의 시간값 그래프(데이터 개수:2^5~2^20)
<br/>

 ![logo](https://github.com/sunghyun0610/cpu-sorting/blob/main/reverse%EC%A0%95%EB%A0%AC.png)

## 3.배열이 정렬되어있을때 각 정렬 알고리즘들의 시간값 그래프(데이터:2^5~2^20)
<br/> 

![logo](https://github.com/sunghyun0610/cpu-sorting/blob/main/sorted%EC%A0%95%EB%A0%AC.png)
<br> run-time-over값은 그래포 모양관계로 임의로 큰숫자를 부여했다.
<br>이상.