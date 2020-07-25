#include<iostream>
#include<vector>
#include<functional>

using namespace std;

#define ll long long

vector<ll> counting_sort(vector<ll> v, function<ll(ll)> key = [](ll x){return x;},ll k=-1)
{
	vector<ll> w;
	w.reserve(v.size());

	if(k==-1){
		for(auto i : v)
		if(k<i)k=i;
	}

	vector<vector<ll>> table(k+10); //vector<type_of_unsorted_vector>

	for(auto i : v)
		table[key(i)].push_back(i);

	for(ll i=0; i<=k+5; i++)
		for(auto j : table[i])
			w.push_back(j);

	return w;
}

int main()
{
	vector<ll> v = {10, 9, 4, 5, 7};

	for(auto i : v)
		cout<<i<<" ";
	  
	//user defined key for descending order  
	function<ll(ll)> key;
	key = [](ll x) {return 11-x;};

	v=counting_sort(v, key);

	cout<<"\n Sorted:\n";
	for(auto i : v)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}


/*
vector<ll> counting_sort(vector<ll> v, ll k)
{
	vector<ll> w;
	w.reserve(v.size());

	if(k==-1){
		for(auto i : v)
		if(k<i)k=i;
	}

	vector<int> table(k+10, 0);

	for(auto i : v)
		table[i]++;

	for(ll i=0; i<=k+5; i++)
		if(table[i])
			while(table[i]--)
				w.push_back(i);

	return w;
}
*/