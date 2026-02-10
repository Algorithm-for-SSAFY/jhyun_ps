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
    - updateTeam
        - mTeam으로 병사들 평판 점수 모두 변경 -> O(mTeam)
            - 만약 10만명의 병사를 모두 수정한다면? 10만번 호출하면 10억 -> 시간 초과
        - score : 1~5, team : 1~5 -> 숫자가 작은 두 값을 활용 => updateTeam 수행 시 scoreUm에 있는 1~5점의 팀 전체를 옮기면 -> O(5)
    - mTeam으로 평판 점수가 가장 높은 병사의 mID 출력 -> O(mTeam)

    - unordered_map<mID, pair<team, score>> idUm = {
        // scoreUm의 2차원 배열의 index 저장
        mID : (mTeam, mScore),
        ...
    }
    - vector<vector<unordered_set>>> scoreUs[score][team] = {
        mID, ...
    }

    - 소속팀 : 1~5, 평판 점수 : 1~5
*/

#define MAX_SOLDIER 100001
#define MAX_NODES 500005

struct Node {
    int id;
    int v;  // 노드 생성 시점의 version
    Node* next;
};

Node nodePool[MAX_NODES];
int nodeCnt;

// 각 팀(1~5)과 점수(1~5)별 연결 리스트 관리
Node* head[6][6];
Node* tail[6][6];

int soldierVersion[MAX_SOLDIER]; // 병사별 최신 버전
int soldierTeam[MAX_SOLDIER];    // 병사별 현재 소속 팀

// 노드 풀에서 새 노드 할당
Node* getNewNode(int id, int v) {
    Node* node = &nodePool[nodeCnt++];
    node->id = id;
    node->v = v;
    node->next = nullptr;
    return node;
}

/*
각 테스트 케이스의 처음에 호출
테스트 케이스의 시작 시 고용된 병사는 없음
*/
void init() {
    nodeCnt = 0;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            head[i][j] = tail[i][j] = nullptr;
        }
    }
    for (int i = 0; i < MAX_SOLDIER; i++) {
        soldierVersion[i] = 0;
        soldierTeam[i] = 0;
    }
}

/*
고유번호가 mID, 소속팀이 mTeam, 평판 점수가 mScore인 병사를 고용
한 테스트 케이스 내에서 동일한 mID를 가진 병사가 여러 번 고용되는 경우는 없음 보장
*/
void hire(int mID, int mTeam, int mScore) {
    Node* newNode = getNewNode(mID, soldierVersion[mID]);
    
    if (head[mTeam][mScore] == nullptr) {
        head[mTeam][mScore] = tail[mTeam][mScore] = newNode;
    } else {
        // 뒤에 붙이는 방식 (tail 업데이트)
        tail[mTeam][mScore]->next = newNode;
        tail[mTeam][mScore] = newNode;
    }
    soldierTeam[mID] = mTeam;
}

/*
고유번호가 mID인 병사를 해고
fire() 함수 호출 시, 고유번호가 mID인 병사가 고용되어 있음이 보장
*/
void fire(int mID) {
    // 실제 삭제 대신 버전만 올려서 기존 노드들을 무효화 (Lazy Deletion)
    soldierVersion[mID]++;
}

/*
고유 번호가 mID인 병사의 평판 점수를 mScore로 변경
고유 번호가 mID인 병사가 고용되어 있음이 보장
*/
void updateSoldier(int mID, int mScore) {
    // 기존 버전 무효화 후 새로 고용하는 것과 같은 로직
    soldierVersion[mID]++;
    hire(mID, soldierTeam[mID], mScore);
}

// src 점수 리스트 전체를 dst 점수 리스트 뒤에 붙임 (O(1))
void moveList(int team, int src, int dst) {
    if (src == dst || head[team][src] == nullptr) return;

    if (head[team][dst] == nullptr) {
        head[team][dst] = head[team][src];
        tail[team][dst] = tail[team][src];
    } else {
        tail[team][dst]->next = head[team][src];
        tail[team][dst] = tail[team][src];
    }
    head[team][src] = tail[team][src] = nullptr;
}

/*
소속팀이 mTeam인 병사들의 평판 점수를 모두 변경
소속팀이 mTeam인 병사가 한 명 이상 고용되어 있음이 보장

# 규칙
1. ‘변경 전 평판 점수 + mChangeScore’가 5보다 클 경우, 평판 점수를 5로 변경한다.
2. ‘변경 전 평판 점수 + mChangeScore’가 1보다 작을 경우, 평판 점수를 1로 변경한다.
3. 그 외의 경우, 평판 점수를 ‘변경 전 평판 점수 + mChangeScore’로 변경한다.
*/
void updateTeam(int mTeam, int mChangeScore) {
    if (mChangeScore == 0) return;

    if (mChangeScore > 0) {
        for (int s = 4; s >= 1; s--) {
            int target = s + mChangeScore;
            if (target > 5) target = 5;
            moveList(mTeam, s, target);
        }
    } else {
        for (int s = 2; s <= 5; s++) {
            int target = s + mChangeScore;
            if (target < 1) target = 1;
            moveList(mTeam, s, target);
        }
    }
}

/*
소속팀이 mTeam인 병사들 중 평판 점수가 가장 높은 병사의 고유 번호 반환
평판 점수가 가장 높은 병사가 여러 명일 경우, 고유번호가 가장 큰 병사의 고유번호 반환
소속팀이 mTeam인 병사가 한 명 이상 고용되어 있음이 보장
# Returns : 평판 점수가 가장 높은 병사의 고유 번호
*/
int bestSoldier(int mTeam) {
    // 점수 5점부터 내려가며 유효한 병사 중 ID가 가장 큰 사람 탐색
    for (int s = 5; s >= 1; s--) {
        Node* curr = head[mTeam][s];
        if (curr == nullptr) continue;

        int maxID = 0;
        while (curr != nullptr) {
            // 병사의 현재 버전과 노드 생성 시점의 버전이 같아야 유효함
            if (curr->v == soldierVersion[curr->id]) {
                if (curr->id > maxID) maxID = curr->id;
            }
            curr = curr->next;
        }

        // 해당 점수대에서 유효한 병사를 한 명이라도 찾았다면 반환
        if (maxID != 0) return maxID;
    }
    return 0;
}
