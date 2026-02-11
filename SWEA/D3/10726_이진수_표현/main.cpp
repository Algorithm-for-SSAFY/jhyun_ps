#include<iostream>
#include<string>
using namespace std;

/*문제 분석
- 문제 설명
  - M의 이진수 표현의 마지막 N 비트가 모두 1로 켜져 있는지 아닌지 판별
- 입력 데이터
  - T : 테스트 케이스
  - M : 이진수
  - N : 확인할 비트 수
- 핵심 키워드
  - M을 N번 2로 나누면서 나머지가 1인지 확인
*/

string solve(){
  int N, M;
  cin >> N >> M;

  for(int n = 1; n <= N; n++){
    if(M % 2 == 0){
      return "OFF";
    }
    M /= 2;
  }

  return "ON";
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  for(int tc = 1; tc <= T; tc++){
    cout << '#' << tc << ' ' << solve() << '\n';
  }

  return 0;
}