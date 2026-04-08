#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int timestamp = 0;

struct Ship
{
	int id;
	int p;
	int r;
	int last_shot;
	Ship(int id, int p, int r)
	{
		this->id = id;
		this->p = p;
		this->r = r;
		this->last_shot = timestamp - r;
	}
	Ship(int id, int p, int r, int last_shot)
	{
		this->id = id;
		this->p = p;
		this->r = r;
		this->last_shot = last_shot;
	}
};

bool compare_p(Ship *a, Ship *b)
{
	if (a->p == b->p)
	{
		return a->id > b->id;
	}
	return a->p < b->p;
}

bool compare_t(Ship *a, Ship *b)
{
	int atime = a->last_shot + a->r, btime = b->last_shot + b->r;
	if (atime == btime)
	{
		return a->p < b->p;
	}
	return atime > btime;
}

unordered_map<int, Ship *> ships;
vector<Ship *> waitq;
vector<Ship *> readyq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, command;
	int n, id, p, r, pw;
	Ship *temp;
	cin >> t;
	while (t--)
	{
		cin >> command;
		switch (command)
		{
		case 100:
			cin >> n;
			while (n--)
			{
				cin >> id >> p >> r;
				temp = new Ship(id, p, r);
				ships[id] = temp;
				readyq.push_back(temp);
			}
			make_heap(readyq.begin(), readyq.end(), compare_p);
			break;
		case 200:
			cin >> id >> p >> r;
			temp = new Ship(id, p, r);
			ships[id] = temp;
			readyq.push_back(temp);
			push_heap(readyq.begin(), readyq.end(), compare_p);
			break;
		case 300:
			cin >> id >> pw;
			temp = ships[id];
			ships[id] = new Ship(id, pw, temp->r, temp->last_shot);
			if (temp->last_shot + temp->r <= timestamp)
			{
				readyq.push_back(ships[id]);
				push_heap(readyq.begin(), readyq.end(), compare_p);
			}
			else
			{
				waitq.push_back(ships[id]);
				push_heap(waitq.begin(), waitq.end(), compare_t);
			}
			break;
		case 400:
			vector<Ship *> candid;
			while (waitq.size() > 0 && waitq[0]->last_shot + waitq[0]->r <= timestamp)
			{
				temp = waitq[0];
				pop_heap(waitq.begin(), waitq.end(), compare_t);
				waitq.pop_back();
				if (temp == ships[temp->id])
				{
					candid.push_back(temp);
				}
				else
				{
					delete temp;
				}
			}
			for (int count = 0; !readyq.empty() && count < 5;)
			{
				temp = readyq[0];
				pop_heap(readyq.begin(), readyq.end(), compare_p);
				readyq.pop_back();
				if (temp == ships[temp->id])
				{
					candid.push_back(temp);
					++count;
				}
				else
				{
					delete temp;
				}
			}
			sort(candid.begin(), candid.end(), compare_p);
			int sum = 0;
			int size = min(5, static_cast<int>(candid.size()));
			int count = 0;
			for (auto it = candid.end() - 1; count < size && it >= candid.begin(); --it)
			{
				sum += (*it)->p;
				++count;
			}
			cout << sum << ' ' << size;
			count = 0;
			for (auto it = candid.end() - 1; count < size && it >= candid.begin(); --it)
			{
				cout << ' ' << (*it)->id;
				(*it)->last_shot = timestamp;
				waitq.push_back(*it);
				push_heap(waitq.begin(), waitq.end(), compare_t);
				candid.pop_back();
				++count;
			}
			cout << '\n';
			for (auto ship : candid)
			{
				readyq.push_back(ship);
				push_heap(readyq.begin(), readyq.end(), compare_p);
			}
			candid.clear();
			break;
		}
		++timestamp;
	}
}
