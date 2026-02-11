#include<iostream>
#include<list>
using namespace std;

/*문제 분석
- 문제 설명
  - N개의 10억 이하 자연수로 이뤄진 수열
  - M번의 편집 후 완성
    - I x y: x번 인덱스 앞에 y추가
    - D x: x번 인덱스 제거 
    - C x y : x번 인덱스를 y로 변경
  - 결론 : 완성된 수열에서 인덱스 L의 데이터 출력
    - L이 없으면 -1 출력
- 입력 데이터
  - T : 테스트 케이스
  - N : 수열의 길이
  - M : 편집 횟수
  - L : 출력할 인덱스 번호
- 핵심 키워드
*/

int solve(){
  // 데이터 입력
  int N, M, L;
  cin >> N >> M >> L;

  list<int> cryptogram;
  for(int n = 0; n < N; n++){
    int temp;
    cin >> temp;
    cryptogram.push_back(temp);
  }

  // 명령어 수행
  for(int m = 0; m < M; m++){
    char command;
    cin >> command;
    if(command == 'I'){
      int x, y;
      cin >> x >> y;
      cryptogram.insert(next(cryptogram.begin(), x), y);
    } else if(command == 'D'){
        int x;
        cin >> x;
        if (x < cryptogram.size()) {
          cryptogram.erase(next(cryptogram.begin(), x));
        }
    } else{
        int x, y;
        cin >> x >> y;
        if (x < cryptogram.size()){
          *next(cryptogram.begin(), x) = y;
        }
    }
  }

  if (L >= cryptogram.size()) return -1;
    
  auto it = cryptogram.begin();
  advance(it, L);
  return *it;
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