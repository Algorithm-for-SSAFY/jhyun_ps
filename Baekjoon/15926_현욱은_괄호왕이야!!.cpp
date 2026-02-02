#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*문제 분석
- 문제 설명
    - 괄호 문자열 : x = (), (x), xy
    - 괄호 문자열에서 일부를 잘라 올바른 괄호 문자열 생성
    - 결과 : 가장 긴 올바른 괄효 문자열 계산
- 입력 데이터
    - n : 문자열의 길이 -> 20만
    - str : 괄호로만 구성된 길이 n짜리 문자열
- 핵심 키워드
    - 시간 제한 : 2초 -> O(2억)
    - ()로 감싸져야 올바른 괄호 문자열 -> stack 사용
*/

int solve(int N, string str){
    stack<int> s;
    s.push(-1);
    
    int result = 0; 
    for(int idx = 0; idx < str.size(); idx++){
        if(str[idx] == '('){
            s.push(idx);
        } else{
            s.pop();
            if(s.empty()){
                s.push(idx);
            }else{
                result = max(result, idx - s.top());
            }
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    string str;
    cin >> N >> str;
    cout << solve(N, str) << '\n';
    return 0;
}