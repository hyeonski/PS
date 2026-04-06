#include <iostream>
#include <set>
#include <map>
using namespace std;

set<int> lamps;
multiset<int> gaps;
map<int, int> lamp_num_to_pos;

int last_m = 0;
int n = 0, m = 0;

void add_gap(int a, int b) {
    gaps.insert(b - a);
}

void erase_gap(int a, int b) {
    multiset<int>::iterator it = gaps.find(b - a);
    if (it != gaps.end()) {
        gaps.erase(it);
    }
}

void add_lamp() {
    if (lamps.size() < 2) return;

    int max_len = -1;
    set<int>::iterator max_left = lamps.begin();

    set<int>::iterator it = lamps.begin();
    set<int>::iterator next_it = it;
    ++next_it;

    while (next_it != lamps.end()) {
        int len = *next_it - *it;
        if (len > max_len) {
            max_len = len;
            max_left = it;
        }
        ++it;
        ++next_it;
    }

    int left = *max_left;
    set<int>::iterator right_it = max_left;
    ++right_it;
    int right = *right_it;

    int new_pos = (left + right + 1) / 2; // ceil((left + right) / 2.0)

    erase_gap(left, right);

    lamps.insert(new_pos);
    ++last_m;
    lamp_num_to_pos[last_m] = new_pos;

    add_gap(left, new_pos);
    add_gap(new_pos, right);

    ++m;
}

void delete_lamp(int target) {
    if (lamp_num_to_pos.find(target) == lamp_num_to_pos.end()) return;

    int target_pos = lamp_num_to_pos[target];
    set<int>::iterator it = lamps.find(target_pos);

    if (it == lamps.end()) return;

    set<int>::iterator prev_it = it;
    set<int>::iterator next_it = it;
    bool has_prev = false;
    bool has_next = false;

    if (it != lamps.begin()) {
        --prev_it;
        has_prev = true;
    }

    ++next_it;
    if (next_it != lamps.end()) {
        has_next = true;
    }

    if (has_prev) {
        erase_gap(*prev_it, target_pos);
    }
    if (has_next) {
        erase_gap(target_pos, *next_it);
    }
    if (has_prev && has_next) {
        add_gap(*prev_it, *next_it);
    }

    lamps.erase(it);
    lamp_num_to_pos.erase(target);

    --m;
}

int get_r() {
    if (m == 0) return 0;

    int left_edge = (*lamps.begin() - 1) * 2;
    int right_edge = (n - *lamps.rbegin()) * 2;

    int max_len = 0;
    if (!gaps.empty()) {
        max_len = *gaps.rbegin();
    }

    int answer = left_edge;
    if (answer < right_edge) answer = right_edge;
    if (answer < max_len) answer = max_len;

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        int command;
        cin >> command;

        if (command == 100) {
            cin >> n >> m;

            lamps.clear();
            gaps.clear();
            lamp_num_to_pos.clear();

            for (int i = 1; i <= m; i++) {
                int x;
                cin >> x;
                lamps.insert(x);
                lamp_num_to_pos[i] = x;
            }

            last_m = m;

            if (lamps.size() >= 2) {
                set<int>::iterator it = lamps.begin();
                set<int>::iterator next_it = it;
                ++next_it;

                while (next_it != lamps.end()) {
                    add_gap(*it, *next_it);
                    ++it;
                    ++next_it;
                }
            }
        }
        else if (command == 200) {
            add_lamp();
        }
        else if (command == 300) {
            int target;
            cin >> target;
            delete_lamp(target);
        }
        else if (command == 400) {
            cout << get_r() << '\n';
        }
    }

    return 0;
}