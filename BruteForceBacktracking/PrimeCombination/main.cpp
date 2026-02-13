#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

#include <set>
set<int> numberSet;

// comb: 현재까지 만들어진 조합
// others: 현재까지 사용하지 않은 스트링
void recursive(string comb, string others)
{
    cout << "comb: " << comb << endl;
    cout << "others: " << others << endl;

    // 1. 현 조합을 numberSet 에 추가한다.
    if (comb != "")
        numberSet.insert(stoi(comb));

    // 2. 현 조합 + others[i] concat 후 새 새로운 조합을 만들어본다.
    for (int i = 0; i < others.size(); i++)
    {
        cout << "i: " << i
            << ", others[i]: " << others[i]
            << ", others.substr(0, i): " << others.substr(0, i)
            << ", others.substr(i + 1): " << others.substr(i + 1) 
            << endl;
        recursive(comb + others[i], others.substr(0, i) + others.substr(i + 1));
    }
}

#include <cmath>
bool isPrime(int num) {
    // 1. 0과 1은 소수가 아니다
    if (num == 0 || num == 1)
        return false;

    // 2. 에라토스테네스의 체
    int lim = sqrt(num);
    for (int i = 2; i <= lim; i++)
        if (num % i == 0)
            return false;
    
    return true;
}

int solution(const string numbers) {
    // 1. 모든 숫자 조합을 만든다.
    recursive("", numbers);

    // 2. 소수의 개수를 센다.
    int answer = 0;
    for (int number : numberSet)
        if (isPrime(number))
            answer++;

    // 3. 소수의 개수를 반환한다.
    return answer;
}

int main() {
    ifstream fin("PrimeCombination/input.txt");
    ofstream fout("PrimeCombination/result.txt");

    string line;
    while (getline(fin, line)) {
        int answer = solution(line);
        fout << answer << '\n';
    }

    // 정답 확인
    ifstream fresult("result.txt");
    ifstream fanswer("output.txt");
    string rline, aline;
    int lineNum = 1;
    bool correct = true;

    while (getline(fresult, rline) && getline(fanswer, aline)) {
        if (rline != aline) {
            cout << "Wrong answer at line " << lineNum << ": got " << rline << ", expected " << aline << endl;
            correct = false;
        }
        ++lineNum;
    }

    if (correct) {
        cout << "All test cases passed!" << endl;
    }

    return 0;
}
