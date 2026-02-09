#include <iostream>
#include <unordered_set>
using namespace std;

/*문제 분석
- 문제 설명
  - N의 배수 번호를 셈
  - 결론: 이전에 셌던 번호들의 각 자리수에서 0에서 9까지의 모든 숫자를 보는 것은 최소 몇 번 센 시점인지 계산
- 입력 데이터
  - T : 테스트 케이스
  - N : 배수
- 핵심 키워드
  - 각 자리 확인
*/

int solve(int N){
  unordered_set<int> us;
  int count = 0;

  while(us.size() != 10){
    count++;
    int temp = N * count;
    while(temp > 0){
      us.insert(temp % 10);
      temp /= 10;
    }
  }
  
  return N * count;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  for(int t = 1; t <= T; t++){
    int N;
    cin >> N;
    cout << '#' << t << ' ' << solve(N) << '\n';
  }
  return 0;
}