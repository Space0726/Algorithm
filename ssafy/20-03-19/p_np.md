# P-NP
### Intractability
- 다루기 힘든 정도
- 다차시간(n^k 형태) 알고리즘을 찾을 수 없는 문제
### 문제의 분류
1. 다차시간 알고리즘을 찾은 문제
    - P
    - 정렬 문제, 탐색 문제 등
2. 다루기 힘들다고 증명된 문제
    - P(hard)
    - 비다항식 크기(nonpolynomial)의 결과를 요구하는 비현실적인 문제
        - 모든 해밀토니안 회로 구하기 문제
    - 결정 불가능(Undecidable)한 문제
        - ex) 정지 문제
    - 요구가 현실적이나, 다차시간에 풀 수 없다고 증명된 문제
    - 별로 없음
3. 다루기 힘들다고 증명되지 않았고, 다차시간 알고리즘도 찾지 못한 문제
    - NP
    - 많은 문제들이 여기에 속함
        - knapsack, TSP, m-coloring, hamiltonian circuit 등
### 최적화 문제 / 결정 문제
- 최적화 문제(optimization problem)
    - ex) 경로는 무엇인가?
- 결정 문제(decision problem)
    - 대답이 yes or no
    - ex) 경로가 존재하는가?
- 최적화 문제를 풀면 결정 문제는 자동으로 풀리므로, P-NP에서는 결정 문제로도 충분
### P(Polynomial)
- DTM(Deterministic Turing Machine)에서 polynomial 사이즈의 답이 있는 문제
- 다차시간 알고리즘이 존재하는 모든 결정 문제
### NP(Nondeterministic Polynomial)
- NDTM에서 돌아가는 polynomial 사이즈의 답이 있는 문제
- 다차시간 비결정적 알고리즘으로 해결할 수 있는 모든 결정 문제
    - 검증 단계가 다차시간 알고리즘인 비결정적 알고리즘
- 결정 문제 자체를 해결할 수 있는 다항시간 알고리즘이 존재해야 함을 의미하진 않음
- 어떤 결정 문제를 풀 수 있는
    1. 다항식 시간 알고리즘을 찾을 수 없고
    2. 다항식 시간 비결정적 알고리즘을 찾으면 NP문제에 속함
### 결정적 알고리즘
- 결과가 유일하게 정의된 연산만을 써서 만들어진 알고리즘
### 비결정적 알고리즘
- 연산 결과가 상황에 따라 달라질 수 있는 연산을 써서 만들어진 알고리즘
- 추측단계(결정적), 검증(비결정적)단계
### NP-Complete
- NP에 있는 모든 문제 A에 대해 A는 B문제로 다항시간 내에 변환 가능
- 이렇게 서로 얽혀 있어 NP-Complete 문제 중 하나만 풀어도 다른 문제들이 해결됨
- 여러 분야에 걸쳐 많은 문제가 있음
### NP-Hard
- 모든 NP 문제가 문제 A로 다항 시간에 변환이 가능하다면 문제 A는 NP-Hard
    - A가 결정 문제이면 NP-Complete
        - NP문제와 NP-Hard의 교집합
    - A가 결정문제이건 아니건 NP-Hard(더 넓음)