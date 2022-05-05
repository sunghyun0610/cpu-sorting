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

## 1. 배열이 정렬되어있지 않았을 때 각 정렬 알고리즘들의 시간값 그래프(데이터 개수:2^5~2^20)

<br>![logo](https://github.com/sunghyun0610/cpu-sorting/blob/main/random%EC%A0%95%EB%A0%AC.png)

## 2.배열이 역(reverse)정렬되어있을때 각 정렬 알고리즘들의 시간값 그래프(데이터 개수:2^5~2^20)
![logo](https://github.com/sunghyun0610/cpu-sorting/blob/main/reverse%EC%A0%95%EB%A0%AC.png)
## 3.배열이 정렬되어있을때 각 정렬 알고리즘들의 시간값 그래프(데이터:2^5~2^20)
![logo](https://github.com/sunghyun0610/cpu-sorting/blob/main/sorted%EC%A0%95%EB%A0%AC.png)
<br> run-time-over값은 그래포 모양관계로 임의로 큰숫자를 부여했다.