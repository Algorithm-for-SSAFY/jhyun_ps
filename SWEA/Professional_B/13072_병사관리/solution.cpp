
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
