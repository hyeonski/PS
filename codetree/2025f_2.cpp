#include <iostream>
#include <set>
#include <map>
using namespace std;

struct Interval {
    int left;
    int right;
};

struct IntervalCmp {
    bool operator()(const Interval& a, const Interval& b) const {
        int lenA = a.right - a.left;
        int lenB = b.right - b.left;

        if (lenA != lenB) return lenA > lenB;
        if (a.left != b.left) return a.left < b.left;
        return a.right < b.right;
    }
};

set<int> lamps;
map<int, int> lamp_num_to_pos;
set<Interval, IntervalCmp> intervals;

int last_m = 0;
int n = 0, m = 0;

void add_interval(int left, int right) {
    if (left >= right) return;

    Interval interval;
    interval.left = left;
    interval.right = right;
    intervals.insert(interval);
}

void erase_interval(int left, int right) {
    if (left >= right) return;

    Interval interval;
    interval.left = left;
    interval.right = right;

    set<Interval, IntervalCmp>::iterator it = intervals.find(interval);
    if (it != intervals.end()) {
        intervals.erase(it);
    }
}

void add_lamp() {
    if (intervals.empty()) return;

    Interval best = *intervals.begin();
    int left = best.left;
    int right = best.right;

    erase_interval(left, right);

    int new_pos = (left + right + 1) / 2;

    lamps.insert(new_pos);
    ++last_m;
    lamp_num_to_pos[last_m] = new_pos;

    add_interval(left, new_pos);
    add_interval(new_pos, right);

    ++m;
}

void delete_lamp(int target) {
    map<int, int>::iterator map_it = lamp_num_to_pos.find(target);
    if (map_it == lamp_num_to_pos.end()) return;

    int target_pos = map_it->second;
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
        erase_interval(*prev_it, target_pos);
    }
    if (has_next) {
        erase_interval(target_pos, *next_it);
    }
    if (has_prev && has_next) {
        add_interval(*prev_it, *next_it);
    }

    lamps.erase(it);
    lamp_num_to_pos.erase(map_it);
    --m;
}

int get_r() {
    if (m == 0) return 0;

    int answer = 0;

    int left_edge = (*lamps.begin() - 1) * 2;
    int right_edge = (n - *lamps.rbegin()) * 2;

    if (answer < left_edge) answer = left_edge;
    if (answer < right_edge) answer = right_edge;

    if (!intervals.empty()) {
        Interval best = *intervals.begin();
        int max_len = best.right - best.left;
        if (answer < max_len) answer = max_len;
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {
        int command;
        cin >> command;

        if (command == 100) {
            cin >> n >> m;

            lamps.clear();
            lamp_num_to_pos.clear();
            intervals.clear();

            for (int i = 1; i <= m; i++) {
                int x;
                cin >> x;
                lamps.insert(x);
                lamp_num_to_pos[i] = x;
            }

            last_m = m;

            if (m >= 2) {
                set<int>::iterator it = lamps.begin();
                set<int>::iterator next_it = it;
                ++next_it;

                while (next_it != lamps.end()) {
                    add_interval(*it, *next_it);
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