// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct trieNode
{
    trieNode *sons[26];
    int wt = 0;
    trieNode()
    {
        for (int i = 0; i < 25; i++)
            sons[i] = NULL;
        wt = 0;
    }
};

void insert(trieNode *root, string s, int w)
{
    // cout<<"in insert"<<endl;
    trieNode *node = root;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (node->sons[s[i] - 'a'] == NULL)
        {
            trieNode *newNode = new trieNode;
            newNode->wt = max(newNode->wt, w);
            node->sons[s[i] - 'a'] = newNode;
        }
        node = node->sons[s[i] - 'a'];
        node->wt = max(node->wt, w);
    }
    return;
}

int search(trieNode *node, string s)
{
    int ans = -1;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (node->sons[s[i] - 'a'] == NULL)
            return -1;
        node = node->sons[s[i] - 'a'];
        ans = node->wt;
    }
    return ans;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    int wt;
    trieNode *root = new trieNode;
    while (n--)
    {
        cin >> s >> wt;
        insert(root, s, wt);
    }
    // cout<<"done inserting"<<endl;
    while (q--)
    {
        cin >> s;
        cout << search(root, s) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
