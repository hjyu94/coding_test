#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
using namespace std;

#include <algorithm>

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    // 1. sort
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    // 2.
    int i = 0;
    for (; i < completion.size(); i++)
        if (participant[i] != completion[i])
            break;

    // 3.
    return participant[i];
}

#include <unordered_map>
string solution2(vector<string> participant, vector<string> completion) {
    string answer = "";

    // 1. create hash map
    unordered_map<string, int> map;
    for (auto player : participant)
    {
        if (map.end() == map.find(player))
            map.insert(make_pair(player, 1));
        else
            map[player]++;
    }

    // 2. delete each player from hash map
    for (auto player : completion)
        map[player]--;

    // 3. find player with value 0 in hash map
    for (auto player : participant)
    {
        if (map[player] > 0)
        {
            answer = player;
            break;
        }
    }

    return answer;
}

int main_participants() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int T; fin >> T;

    for (int t = 1; t <= T; t++) {
        int n;
        fin >> n;
        vector<string> participant(n);
        for (int i = 0; i < n; i++) fin >> participant[i];

        int m;
        fin >> m;
        vector<string> completion(m);
        for (int i = 0; i < m; i++) fin >> completion[i];

        string expected;
        fin >> expected;

        {
            string answer = solution(participant, completion);
            if (answer == expected) {
                fout << "Test case #" << t << ": Passed\n";
                cout << "Test case #" << t << ": Passed\n";
            }
            else {
                fout << "Test case #" << t << ": Failed (Expected: " << expected << ", Got: " << answer << ")\n";
                cout << "Test case #" << t << ": Failed (Expected: " << expected << ", Got: " << answer << ")\n";
            }
        }

        {
            string answer = solution2(participant, completion);
            if (answer == expected) {
                fout << "Test case #" << t << ": Passed\n";
                cout << "Test case #" << t << ": Passed\n";
            }
            else {
                fout << "Test case #" << t << ": Failed (Expected: " << expected << ", Got: " << answer << ")\n";
                cout << "Test case #" << t << ": Failed (Expected: " << expected << ", Got: " << answer << ")\n";
            }
        }
    }

    fin.close();
    fout.close();

    return 0;
}
