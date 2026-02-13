// https://youtu.be/tC9CBWSzEBk?si=JN2XOgEVf01HkuXq

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#include <algorithm>
bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        // i 문자열이 i+1 문자열에 포함되어 있으면
        // 그 문자열이 위치한 인덱스를 반환
        // 없으면 0을 반환
        if (phone_book[i + 1].find(phone_book[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

#include <unordered_map>
bool solution2(vector<string> phone_book) {
    // 1. HashMap 을 만든다.
    unordered_map<string, int> map;
    for (int i = 0; i < phone_book.size(); i++)
        map[phone_book[i]] = 1;

    // 2. 모든 전화번호의 접두어가 HashMap 에 존재하는지 확인
    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 1; j < phone_book[i].size(); j++)
        {
            string phone_number = phone_book[i].substr(0, j);
            if (map[phone_number])
                return false;
        }
    }
    
    // 3. 여기까지 왔다면 접두어가 없는 것
    return true;
}

int main() {
    ifstream input("CheckPrefixInPhoneBook/input.txt");
    if (!input.is_open()) {
        cerr << "Failed to open input.txt" << endl;
        return 1;
    }

    while (!input.eof()) {
        int n;
        input >> n;
        if (input.fail()) break;

        vector<string> phone_book(n);
        for (int i = 0; i < n; ++i) {
            input >> phone_book[i];
        }

        bool result = solution2(phone_book);
        cout << (result ? "true" : "false") << endl;
    }

    input.close();
    return 0;
}
