#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD=1000000007;

signed main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#endif
#ifndef ONLINE_JUDGE
    freopen("d.txt", "r", stdin);
    freopen("foutput.out", "w", stdout);
#endif

    int D; cin>>D;
    int I; cin>>I;
    int S; cin>>S;
    int V; cin>>V;
    int F; cin>>F;
    int B[S]; int E[S];
    char s[S][31]; //names of s streets
    int L[S];
    for (int i=0; i<S; i++) {
        cin>>B[i]>>E[i]>>s[i]>>L[i];
    }
    int P[V];
    vector <int> streets[V]; //holds id of that street
    for (int i=0; i<V; i++) {
        cin>>P[i];
        for (int j=0; j<P[i]; j++) {
            char t[31]; cin>>t;
            for (int k=0; k<S; k++) {
                if (strcmp(t,s[k])==0) {
                    streets[i].push_back(k);
                }
            }
        }
    }
    vector <pair <int,int> > sumL; //sum of that path, id of that car
    for (int i=0; i<V; i++) {
        int sum=0;
        for (int j=0; j<streets[i].size(); j++) {
            sum+=L[streets[i][j]];
        }
        //sum*=P[i];
        sumL.push_back(make_pair(sum/log2(P[i]) ,i));
    }
    sort(sumL.begin(),sumL.end());
    vector <pair <int,int> > inter[I]; //street id, time for each intersection
    unordered_set <int> opened[I]; //if that street id has been opened once
    for (int i=0; i<V; i++) {
        for (int j=0; j<streets[sumL[i].second].size(); j++) {
            int id=streets[sumL[i].second][j];
            if (opened[E[id]].count(id)==0) {
                opened[E[id]].insert(id);
                inter[E[id]].push_back(make_pair(id,L[id]));
            }
        }
    }
    int count=0;
    for (int i=0; i<I; i++) {
        if (inter[i].size()>0)
            count++;
    }
    cout<<count<<endl;
    for (int i=0; i<I; i++) {
        if (inter[i].size()>0) {
            cout<<i<<endl;
            cout<<inter[i].size()<<endl;
            for (int j=0; j<inter[i].size(); j++) {
                cout<<s[inter[i][j].first]<<' '<<1<<endl;
            }
        }
    }
}