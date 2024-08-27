#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T1, typename T2>
class compare
{
    public:
    bool operator()(const pair<T1, T2>&a, const pair<T1, T2>&b)
    {
        return a.second > b.second;
    }
};

int main()
{
	int N, cnt;
	vector<pair<int,int> > v;
	priority_queue<pair<int,int>, vector<pair<int, int> >, compare<int, int> > pq;

    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    v.reserve(N);
    while (N--)
    {
        int start, end;
        cin >> start >> end;
        v.push_back(make_pair(start, end));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (pq.empty())
            pq.push(v[i]);
        else
        {
            pq.push(v[i]);
            if (pq.top().second <= v[i].first)
                pq.pop();
        }
    }
    cout << pq.size();
}