#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*문제 분석
- 문제 설명
  - 도시를 연결하는 도로는 일방 통행
  - 도시 X를 선택해서 만남
    - 왕복 시간 : X를 갔다가 다시 자신이 살고 있는 도시로 이동하는 시간을 합친 것
    - 모두가 도로를 이용하여 갈 수 있는 도시만 선택
    - 모두의 왕복시간 들 중 최대가 최소가 되는 도시 X 선택
    - 모두가 이동할 수 있는 도시가 최소 하나 이상 존재
- 입력 데이터
  - N : 도시의 개수
  - M : 도로의 개수
  - roads : A -> B 이동 시간
  - K : 총 인원
  - Cs : 모든 인원이 살고 있는 도시 정보
- 핵심 키워드
  - 모든 도시에 대한 왕복 정보 -> 플로이드 워셜
*/

const int INF = 1000000; 
const int ROUND_INF = 2000000;

void floyd_warshall(int N, vector<vector<int>>& roads){
  for(int i = 1; i <= N; i++) roads[i][i] = 0;

  for(int k = 1; k <= N; k++){
    for(int start = 1; start <= N; start++){
      for(int end = 1; end <= N; end++){
        if(roads[start][k] < INF && roads[k][end] < INF){
          roads[start][end] = min(roads[start][end], roads[start][k] + roads[k][end]);
        }
      }
    }
  }
}

void print(vector<vector<int>>& roads){
  for(vector<int> road : roads){
    for(int i : road){
      cout << i << ' ';
    }
    cout << '\n';
  }
}

void cal_times(int N, int K, vector<int>& Cs, vector<vector<int>>& roads, vector<vector<int>>& round_trip_times){
  for(int k = 0; k < K; k++){
    int start = Cs[k];
    for(int x = 1; x <= N; x++){
      if(roads[start][x] < INF && roads[x][start] < INF){
        round_trip_times[k][x] = roads[start][x] + roads[x][start]; 
      }
    }
  }
}

vector<int> cal_min_of_max_times(int N, int K, vector<vector<int>>& round_trip_times){
  vector<int> result;
  vector<int> max_times(N + 1, 0);
  int min_of_max_times = ROUND_INF;

  for (int x = 1; x <= N; x++) {
    int current_max = 0;
    bool possible = true;

    for (int k = 0; k < K; k++) {
      if (round_trip_times[k][x] >= ROUND_INF) {
        possible = false;
        break;
      }
      current_max = max(current_max, round_trip_times[k][x]);
    }

    if (possible) {
      max_times[x] = current_max;
      min_of_max_times = min(min_of_max_times, current_max);
    } else {
      max_times[x] = ROUND_INF;
    }
  }

  for (int x = 1; x <= N; x++) {
    if (max_times[x] == min_of_max_times && min_of_max_times != ROUND_INF) {
      result.push_back(x);
    }
  }
  return result;
}

vector<int> solve(int N, int M, vector<vector<int>>& roads, int K, vector<int>& Cs){
  // 모든 거리 계산
  floyd_warshall(N, roads);

  // 각 Cs의 X의 왕복 시간 계산
  vector<vector<int>> round_trip_times(K, vector<int>(N + 1, ROUND_INF));
  cal_times(N, K, Cs, roads, round_trip_times);

  // 각 X의 최댓값들 추출 -> 최댓값 중 최솟값인 도시의 index반환
  return cal_min_of_max_times(N, K, round_trip_times);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  vector<vector<int>> roads(N + 1, vector<int>(N + 1, INF));
  for(int m = 0; m < M; m++){
    int A, B, T;
    cin >> A >> B >> T;
    roads[A][B] = T;
  }

  int K;
  cin >> K;
  vector<int> Cs(K, 0);
  for(int k = 0; k < K; k++){
    cin >> Cs[k];
  }

  for(int city : solve(N, M, roads, K, Cs)){
    cout << city << ' ';
  }
  cout << '\n';
  return 0;
} 