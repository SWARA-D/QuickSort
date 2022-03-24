#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> l,vector<int> e,vector<int> g,vector<int> temp)
{

	while(l.empty() == false)
	{
		temp.push_back(l.front());
		l.erase(l.begin());
	}
	while(e.empty() == false)
	{
		temp.push_back(e.front());
		e.erase(e.begin());
	}
	while(g.empty() == false)
	{
		temp.push_back(g.front());
		g.erase(g.begin());
	}
	return temp;
}
vector<int> QuickSort(vector<int> v)
{
	if(v.empty())
	{
		return v;
	}
	
	else
	{
		int pivot = v.front();
	
		vector<int> L;
		vector<int> E;
		vector<int> G;
	
		while(v.empty() == false)
		{
			if(v.front() < pivot)
			{
				L.push_back(v.front());
				v.erase(v.begin());
			}
			else if(v.front() == pivot)
			{
				E.push_back(v.front());
				v.erase(v.begin());
			}
			else
			{
				G.push_back(v.front());
				v.erase(v.begin());
			}
		}
		L = QuickSort(L);
		G = QuickSort(G);
	
		v = merge(L,E,G,v);
		return v;
	}
}
int main()
{
	vector<int> A;
	A.push_back(16);
	A.push_back(6);
	A.push_back(1);
	A.push_back(-30);
	A.push_back(100);
	A.push_back(4);
	A.push_back(12);
	A.push_back(50);
	A.push_back(38);
	A.push_back(58);
	A.push_back(-4);

	A = QuickSort(A);
	
	for(int i = 0; i < A.size(); i++)
	{
		cout << A[i] << endl;
	}	
	
	return EXIT_SUCCESS;
}
