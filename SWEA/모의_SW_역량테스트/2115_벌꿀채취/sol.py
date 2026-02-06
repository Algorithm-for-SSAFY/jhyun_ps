import sys
sys.stdin = open('input.txt')
 
'''문제 분석
- 문제 설명
    - N*N 개의 벌통
    - 각 칸에는 꿀의 양을 나타내는 꿀의 양이 존재
    - 채취 방법
        - 두 명의 일꾼이 채취
        - 꿀을 채취할 수 있는 벌통의 수 M이 주어짐
        - 각각의 일꾼은 가로로 연속되도록 M개의 벌통 선택
        - 두 명의 일꾼이 선택한 벌통은 겹치면 안됨
        - 두 명의 일꾼은 선택한 벌통에서 꿀을 채취해 용기에 담음
        - 두 일꾼이 채취할 수 있는 꿀의 최대 양은 C
        - 각 용기에 있는 꿀의 양의 제곱만큼 수익 발생
    - 결론 : 두 일꾼이 꿀을 채취하여 얻을 수 있는 수익의 합이 최대가 되는 경우 찾기
        - 그때 최대 수익 출력
- 입력 데이터
    - T : 테스트 케이스
    - N : 벌통의 크기 ( 3 <= N <= 10 )
    - M : 선택할 수 있는 벌통의 개수 ( 1 <= M <= 5 )
    - C : 각 일꾼이 채취 가능한 꿀의 최대 양 ( 10 <= C <= 30 )
    - honey : N*N 개의 벌통에서 채취할 수 있는 꿀의 양 ( 1 <= honey[i][j] <= 9 )
- 핵심 키워드
    - 시간 제한 : 50문제 6초 -> 문제당 0.12초 -> O(240만)
    - 한 칸에서 일부만 채취 불가능
    - 수익 : 각 용기에 있는 꿀의 제곱만큼 수익
    - C : 한 일꾼이 채취 가능한 꿀의 최대 양
    - 문제 정리: 각 일꾼은 연속된 가로 M개 선택 -> 모든 칸을 합쳐서 C만큼 채취 가능 -> 두 일꾼이 선택한 칸의 제곱만큼 수익 -> 수익이 최대화 하는 경우 탐색
    - 아이디어 : DFS + 메모이제이션(시작 위치에 합 저장)
        1. N*N 꿀벌통에서 채취할 수 있는 모든 경우 계산
            -> 각 위치에서 dp? (M^2) -> (NM)^2
            -> 또는 dfs로 하나씩 넣어보면서 더 넣을 수 있으면 넣는 방식
            - 각 시작 위치에서 얻을 수 있는 수익 저장
        2. 4중 반복문 수행하면서 가능한 조합 탐색
            - 내부 반복문은 외부 반복문의 끝나는 지점부터 탐색
            - 수행 중 최대값 갱신
'''
 
 
# 현재 위치에서 채취 가능한 최대 꿀의 양 - dfs 방법
def dfs(y, x, max_profit, cur_profit, harvested, idx):
    # 기저 조건: 모든 꿀을 담은 경우 or C를 넘은 경우
    if idx == M:
        return
 
    # 현재를 선택하지 않는 경우
    dfs(y, x, max_profit, cur_profit, harvested, idx + 1)
 
    # 현재를 선택하는 경우
    harvested += honey[y][x + idx]
    if harvested <= C:
        cur_profit += honey[y][x + idx] ** 2
        max_profit[0] = max(max_profit[0], cur_profit)
        dfs(y, x, max_profit, cur_profit, harvested, idx + 1)
 
 
# 꿀벌통의 각 위치에서 채취할 수 있는 모든 경우 계산하는 함수
def cal_honey():
    harvested_honey = [[0] * N for _ in range(N)]
 
    # 각 위치에서 꿀 채취
    for y in range(N):
        for x in range(N - M + 1):
            max_profit = [0]
            dfs(y, x, max_profit, 0, 0, 0)
            harvested_honey[y][x] = max_profit[0]
    return harvested_honey
 
 
# 채취 가능한 조합의 최대 수익을 계산하는 함수
def cal_profit(harvested_honey):
    max_profit = 0
    for y1 in range(N):
        for x1 in range(N - M + 1):
            for y2 in range(y1, N):
                start_x2 = x1 + M if y1 == y2 else 0
                for x2 in range(start_x2, N - M + 1):
                    max_profit = max(max_profit, harvested_honey[y1][x1] + harvested_honey[y2][x2])
    return max_profit
 
 
if __name__ == '__main__':
    T = int(input())
    for tc in range(1, T + 1):
        N, M, C = map(int, input().split())
        honey = [list(map(int, input().split())) for _ in range(N)]
        print(f'#{tc} {cal_profit(cal_honey())}')