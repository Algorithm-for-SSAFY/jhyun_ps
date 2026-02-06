#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*문제 분석
- 문제 설명
  - 직사각형 보드에 빨간 구슬과 파란 구슬 1개씩 존재
    - 보드는 N*N, 바깥 행과 열은 모두 막혀 있음
  - 중력을 이용해 굴려야만 함
    - 왼/오/위/아래 방향으로 기울이기 가능
  - 빨/파 구슬은 동일 칸에 존재 X
    - 빨/파 구슬은 각 1칸씩 차지
  - 빨/파 구슬이 동시에 구멍에 빠져도 실패
  - 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지
  - 결론: 파란 구슬을 빼지 않고, 빨간 구슬을 구멍을 통해 빼내는 게임 -> 최소 몇 번 기울여야 빨간 구슬이 탈출 가능한지 구하기
- 입력 데이터
  - N : 보드의 세로 길이 ( 3 <= N <= 10 )
  - M : 보드의 가로 길이 ( 3 <= M <= 10 )
  - board : 보드 정보
    - . : 빈 칸
    - # : 벽 -> 입력되는 모든 보드의 가장자리에는 모두 # 존재
    - O : 구멍
    - R : 빨간 구슬
    - B : 파란 구슬
- 핵심 키워드
*/

int solve(int N, int M, const vector<string>& board){
  return 0;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vector<string> board(N);
  for(int n = 0; n < N; n++){
    cin >> board[n];
  }
  cout << solve(N, M, board) << '\n';
}