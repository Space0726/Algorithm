# Queue
### 1차 배열 큐
- front = rear = -1에서 시작
- empty: front == rear
- enQueue: ++rear
- deQueue: ++front
- 길이가 제한되어있어 인덱스 끝에 도착 시 더이상 사용 불가

### 원형 큐
- 길이 제한 없이 사용 가능
- 모듈러 연산을 이용하여 인덱스를 순환하여 사용
- front = rear = 0에서 시작
- empty: front = rear
- full: rear + 1 = front
    - (rear + 1) mod n = front
- enQueue: rear = (rear + 1) mod n
- deQueue: front = (front + 1) mod n

### 연결 큐
- Linked List 사용
- front = rear = null인 상태에서 시작
- empty: front = rear = null
- enQueue
    - 초기화 후 첫 연산: front = rear = 입력된 데이터 가리킴
    - 이후 연산: rear = 입력된 데이터 가리킴
    - 맨 마지막 원소가 새로운 원소를 가리키게 한 후, rear가 가리켜야 탐색 가능
- deQueue
    1. old 변수에 삭제할 노드를 가리키게 하고 front 재설정
    2. 삭제 후 공백 큐가 되는 경우 rear도 null로 설정
    3. old가 가리키는 노드를 삭제하고 free
