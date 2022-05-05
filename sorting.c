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