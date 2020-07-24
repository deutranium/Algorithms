#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define ll long long

vector<ll> counting_sort(vector<ll> v, ll k)
{
	vector<ll> w;
	w.reserve(v.size());

	vector<int> table(k+10, 0);

	for(auto i : v)
		table[i]++;

	for(ll i=0; i<=k+5; i++)
		if(table[i])
			while(table[i]--)
				w.push_back(i);

	return w;
}

int main()
{
	vector<ll> v = {10, 9, 4, 5, 7};

	for(auto i : v)
		cout<<i<<" ";

	v=counting_sort(v, 11);

	cout<<"\n Sorted:\n";
	for(auto i : v)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}
