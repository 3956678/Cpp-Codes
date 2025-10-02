#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
struct dfa {
    vector<int> parent, rank;
    dfa(int n) {
        parent.resize(n + 1);
        rank.assign(n + 1, 1);
        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;
    }
    int U_parent(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = U_parent(parent[x]);
    }
    void Union(int a, int b) {
        int p1 = U_parent(a);
        int p2 = U_parent(b);
        if (p1 != p2) {
            if (rank[p1] < rank[p2]) {
                swap(p1, p2);
            }
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
    }
};
pair<int, int> comp(vector<string> &words) {
    int n = words.size();
    vector<int> masks(n, 0);
    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (char c : words[i]) {
            mask |= 1 << (c - 'a');
        }
        masks[i] = mask;
    }
    unordered_map<int, int> mp;
    dfa d(n);
    for (int i = 0; i < n; i++) {
        if (mp.count(masks[i])) {
            d.Union(i, mp[masks[i]]);
        } else {
            mp[masks[i]] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        int mask = masks[i];
        for (int j = 0; j < 26; j++) {
            if (mask & (1 << j)) {
                int newMask = mask ^ (1 << j); 
                if (mp.count(newMask)) {
                    d.Union(i, mp[newMask]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int mask = masks[i];
        for (int j = 0; j < 26; j++) {
            if (mask & (1 << j)) {
                int removed = mask ^ (1 << j);
                for (int k = 0; k < 26; k++) {
                    if (!(removed & (1 << k))) {
                        int newMask = removed | (1 << k);
                        if (mp.count(newMask)) {
                            d.Union(i, mp[newMask]);
                        }
                    }
                }
            }
        }
    }
    unordered_map<int, int> count;
    int maxSize = 0, comps = 0;
    for (int i = 0; i < n; i++) {
        int p = d.U_parent(i);
        count[p]++;
        maxSize = max(maxSize, count[p]);
    }
    comps = count.size();
    return {comps, maxSize};
}
int main() {
    vector<string> words = {"abc", "abd", "acd", "xyz", "xzz"};
    auto ans = comp(words);
    cout << "Components: " << ans.first << " , Largest group size: " << ans.second << endl;
    return 0;
}
