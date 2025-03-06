#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

constexpr int N = 110;

struct Team {
    bool summit;
    int id;
    int score;
    int problem;
    int error[10] = {0};

    bool operator<(const Team &oth) const {
        if (problem != oth.problem) {
            return problem > oth.problem;
        } else if (score != oth.score) {
            return score < oth.score;
        } else {
            return id < oth.id;
        }
    }
};

void solve() {
    string buffer;

    Team teams[N];
    for (int i = 0; i < N; i++) {
        teams[i].summit = false;
        teams[i].id = i;
        teams[i].score = 0;
        teams[i].problem = 0;
        memset(teams[i].error, 0, sizeof teams[i].error);
    }

    while (getline(cin, buffer)) {
        if (buffer.size() == 0) {
            break;
        }

        stringstream ss(buffer);
        int id, prob, t;
        char status;
        ss >> id >> prob >> t >> status;
        teams[id].summit = true;

        if (teams[id].error[prob] == -1) continue;
        if (status == 'I') {
            teams[id].error[prob]++;
        } else if (status == 'C') {
            teams[id].score += t + teams[id].error[prob] * 20;
            teams[id].problem++;
            teams[id].error[prob] = -1;
        }
    }

    sort(teams, teams + N);
    for (int i = 0; i < N; i++) {
        if (teams[i].summit) {
            cout << teams[i].id << " " << teams[i].problem << " " << teams[i].score << "\n";
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T;
    cin >> T;
    cin.ignore();
    
    string trash;
    getline(cin, trash);

    bool first = true;

    while (T--) {
        if (!first) cout << "\n";
        solve();
        first = false;
    }

    return 0;
}