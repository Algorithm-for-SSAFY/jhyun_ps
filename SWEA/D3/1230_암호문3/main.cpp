#include<iostream>
#include<list>
using namespace std;

/*문제 분석
- 문제 설명
  - 0 ~ 999,999 사이의 수로 표현되는 암호문 N개
  - 암호문 뭉치를 명령어로 수정
    - I(삽입) x, y, s: 앞에서부터 x번째 암호문 바로 다음 y개의 암호문 삽입
    - D(삭제) x, y : 앞에서부터 x번째 암호문 바로 다음 y 개의 암호문 삭제
    - A(추가) y, s : 암호문 맨 뒤에 y개의 암호문 추가
- 입력 데이터
  - T : 테스트 케이스
  - N : 원본 암호문 뭉치 속 암호문의 개수 (2000 ~ 4000)
  - M : 명령어 개수 (250 ~ 400)
  - command : 명령어
- 핵심 키워드
  - 제약 시간 : 0.06초(60ms)
  - 연결 리스트로 관리: vector -> list
*/

void print(list<int>& cryptogram){
  for(int i = 0; i < 10; i++){
    cout << cryptogram.front() << ' ';
    cryptogram.pop_front();
  }
  cout << '\n';
}

void solve(){
  // 데이터 입력
  int N, M;
  cin >> N;

  list<int> cryptogram;
  for(int n = 0; n < N; n++){
    int temp;
    cin >> temp;
    cryptogram.push_back(temp);
  }

  // 명령어 수행
  cin >> M;
  for(int m = 0; m < M; m++){
    char command;
    cin >> command;
    if(command == 'I'){
      int x, y;
      cin >> x >> y;
      for(int i = 0; i < y; i++){
        int s;
        cin >> s;
        cryptogram.insert(next(cryptogram.begin(), x + i), s);
      }
    } else if(command == 'D'){
        int x, y;
        cin >> x >> y;
        for(int i = 0; i < y; i++){
          cryptogram.erase(next(cryptogram.begin(), x));
        }
    } else{
      int y;
      cin >> y;
      for(int i = 0; i < y; i++){
        int s;
        cin >> s;
        cryptogram.push_back(s);
      }
    }
  }

  print(cryptogram);
}


int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T = 10;
  for(int tc = 1; tc <= T; tc++){
    cout << '#' << tc << ' ';
    solve();
  }

  return 0;
}