#include <unordered_map>
using namespace std;

/*문제 분석
- 문제 설명
    - 병사들을 관리하는 프로그램
    - 병사 : 고유번호, 소속팀, 평판 점수
    - 기능
        - 병사 고용
        - 병사 해고
        - 병사의 평판 점수 변경
        - 특정 팀에 속한 병사들의 평판 점수를 일괄 변경
        - 특정 팀 안에서 가장 평판 점수가 높은 병사를 검색
- 입력 데이터
    - T : 테스트 케이스
- 데이터
    - mID : 고유 번호 (1~10만)
    - mTeam : 소속팀 (1~5)
    - mScore : 평판 점수 (1~5)
    - mChangeScore : 평판 점수의 변화량 (-4 ≤ mChangeScore ≤ 4)
- 함수 호출
    - init : 최초 1회
    - hire : 10만 이하 -> O(N^2) = 10,000,000,000 => 시간 초과
    - fire : 10만 이하
    - updateSoldier : 10만 이하
    - updateTeam : 10만 이하
    - bestSoldier : 100이하
- 핵심 키워드
    - 시간 제한 : 25개 테스트 케이스 3초 -> 문제당 0.12초 = O(1200만)
        - 각 함수는 최대 O(NlogN)으로 구현해야 함
    - 메모리 제한 : 힙/정적 메모리 : 256MB, 스택 메몰 : 1MB
- 아이디어
    - mID로 병사를 고용, 해고, 평판 점수 변경 -> mID를 빠르게 탐색 필요 -> unordered_map
    - updateTeam : mTeam으로 병사들 평판 점수 모두 변경 -> O(mTeam)
        - 만약 10만명의 병사를 모두 수정한다면? 10만번 호출하면 10억 -> 시간 초과
    - mTeam으로 평판 점수가 가장 높은 병사의 mID 출력 -> O(mTeam)

    - unordered_map = {
        mID : (mTeam, mScore),
        ...
    }
    - unordered_map = {
        mTeam : [mID, mID, ...],
        ...
    }

    - 소속팀 : 1~5, 평판 점수 : 1~5
*/

/*
각 테스트 케이스의 처음에 호출
테스트 케이스의 시작 시 고용된 병사는 없음
*/
void init()
{
}

/*
고유번호가 mID, 소속팀이 mTeam, 평판 점수가 mScore인 병사를 고용
한 테스트 케이스 내에서 동일한 mID를 가진 병사가 여러 번 고용되는 경우는 없음 보장
*/
void hire(int mID, int mTeam, int mScore)
{
}

/*
고유번호가 mID인 병사를 해고
fire() 함수 호출 시, 고유번호가 mID인 병사가 고용되어 있음이 보장
*/
void fire(int mID)
{
}

/*
고유 번호가 mID인 병사의 평판 점수를 mScore로 변경
고유 번호가 mID인 병사가 고용되어 있음이 보장
*/
void updateSoldier(int mID, int mScore)
{
}

/*
소속팀이 mTeam인 병사들의 평판 점수를 모두 변경
소속팀이 mTeam인 병사가 한 명 이상 고용되어 있음이 보장

# 규칙
1. ‘변경 전 평판 점수 + mChangeScore’가 5보다 클 경우, 평판 점수를 5로 변경한다.
2. ‘변경 전 평판 점수 + mChangeScore’가 1보다 작을 경우, 평판 점수를 1로 변경한다.
3. 그 외의 경우, 평판 점수를 ‘변경 전 평판 점수 + mChangeScore’로 변경한다.
*/
void updateTeam(int mTeam, int mChangeScore)
{
}

/*
소속팀이 mTeam인 병사들 중 평판 점수가 가장 높은 병사의 고유 번호 반환
평판 점수가 가장 높은 병사가 여러 명일 경우, 고유번호가 가장 큰 병사의 고유번호 반환
소속팀이 mTeam인 병사가 한 명 이상 고용되어 있음이 보장
# Returns : 평판 점수가 가장 높은 병사의 고유 번호
*/
int bestSoldier(int mTeam)
{
    return 0;
}
