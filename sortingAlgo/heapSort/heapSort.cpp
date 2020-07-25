// Heapsort and Min heap in C++
#include<iostream>
#include<vector>

using namespace std;

#define ll long long 

void heapify(int i, vector<ll> &v)
{
	if(v.empty() || 2*i+1>=v.size() || i<0)
		return;

	// int k=v[2*i+1]<v[(2*i)+2]?(2*i+1):(2*i+2);
	int k= 2*i+1;
	if(k+1<v.size())
		k+=	int(v[k]>v[k+1]);

	if(v[i]>v[k]){
	swap(v[i], v[k]);
	heapify(k, v);
	}
}

void build_heap(vector<ll> &v)
{
	if(v.empty())
		return;
	int i=(v.size()+1)/2;
	while(i--)
		heapify(i, v);
}

void insert(ll n, vector<ll> &v)
{
	if(v.empty())
		return;

	v.push_back(n);
	int i=v.size()-1;
	
	while(i && v[(i-1)/2]>v[i])
	{
		swap(v[i], v[(i-1)/2]);
		i=(i-1)/2;
	}
}

ll extract_min(vector<ll> &v)
{
	if(v.empty())
		return -1;

	ll min=v[0];
	v[0]=v.back();
	v.pop_back();
	heapify(0, v);

	return min;
}

ll find_min(const vector<ll> v){
	return v.empty()?-1:v[0];
}

vector<ll> heap_sort(vector<ll> v)
{
	vector<ll> w;
	w.reserve(v.size());

	build_heap(v);
	while(!v.empty())
		w.push_back(extract_min(v));
	
	return w;
}

int main()
{
	//driver code

	vector<ll> v = {12, 11, 13, 5, 6, 7}; 
    
	for(auto i : v)
		cout<<i<<" ";
	v=heap_sort(v); 

    cout<<"\nSorted array is \n"; 
  
	for(auto i : v)
		cout<<i<<" ";

	cout<<endl;
	return 0;
}

