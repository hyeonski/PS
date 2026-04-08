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

bool compare_ready(Ship *a, Ship *b)
{
	if (a->p == b->p)
	{
		return a->id > b->id;
	}
	return a->p < b->p;
}

bool compare_wait(Ship *a, Ship *b)
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

void move_available_ships_to_ready()
{
	while (!waitq.empty() && waitq.front()->last_shot + waitq.front()->r <= timestamp)
	{
		Ship *temp = waitq.front();
		pop_heap(waitq.begin(), waitq.end(), compare_wait);
		waitq.pop_back();
		if (temp == ships[temp->id])
		{
			readyq.push_back(temp);
			push_heap(readyq.begin(), readyq.end(), compare_ready);
		}
		else
		{
			delete temp;
		}
	}
}

void collect_ready_candidates(vector<Ship *> &candid, int limit)
{
	int count = 0;
	while (!readyq.empty() && count < limit)
	{
		Ship *temp = readyq.front();
		pop_heap(readyq.begin(), readyq.end(), compare_ready);
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
}

void push_back_to_waitq(Ship *ship)
{
	waitq.push_back(ship);
	push_heap(waitq.begin(), waitq.end(), compare_wait);
}

void push_back_to_readyq(Ship *ship)
{
	readyq.push_back(ship);
	push_heap(readyq.begin(), readyq.end(), compare_ready);
}

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
			make_heap(readyq.begin(), readyq.end(), compare_ready);
			break;
		case 200:
			cin >> id >> p >> r;
			temp = new Ship(id, p, r);
			ships[id] = temp;
			push_back_to_readyq(temp);
			break;
		case 300:
			cin >> id >> pw;
			temp = ships[id];
			ships[id] = new Ship(id, pw, temp->r, temp->last_shot);
			if (temp->last_shot + temp->r <= timestamp)
			{
				push_back_to_readyq(ships[id]);
			}
			else
			{
				push_back_to_waitq(ships[id]);
			}
			break;
		case 400:
			{
				vector<Ship *> candid;
				vector<Ship *> selected;
				int sum = 0;

				move_available_ships_to_ready();
				collect_ready_candidates(candid, 5);

				sort(candid.begin(), candid.end(), compare_ready);

				int size = min(5, static_cast<int>(candid.size()));
				for (int i = (int)candid.size() - 1; i >= (int)candid.size() - size; --i)
				{
					selected.push_back(candid[i]);
					sum += candid[i]->p;
				}

				cout << sum << ' ' << size;
				for (int i = 0; i < size; ++i)
				{
					cout << ' ' << selected[i]->id;
					selected[i]->last_shot = timestamp;
					push_back_to_waitq(selected[i]);
				}
				cout << '\n';

				for (int i = 0; i < (int)candid.size() - size; ++i)
				{
					push_back_to_readyq(candid[i]);
				}
				break;
			}
		}
		++timestamp;
	}
}
