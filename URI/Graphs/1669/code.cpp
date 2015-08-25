#include <bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define qi queue<int>
#define MAX 100001

using namespace std;

vi graph[MAX];
int indegree1[MAX], indegree2[MAX], n1, n2, d;

void saturate (qi q[], int indegree[], int flag){
    while (q[flag].size()){
        int v = q[flag].front();
        q[flag].pop();
        for (int i = 0; i < graph[v].size(); i++){
            int u = graph[v][i];
            indegree[u]--;
            if (indegree[u] == 0) q[u > n1].push(u);
        }
    }
}

int topSort (int indegree[], int flag){
    int changes = 0;
    qi q[2];

    for (int i = 1; i <= n1 + n2; i++)
        if (indegree[i] == 0)
            q[i > n1].push(i);

    while (!q[0].empty() || !q[1].empty()){

        if (q[flag].size()) changes++;
        saturate(q, indegree, flag);
        if (q[flag ^ 1].size()) changes++;
        saturate(q, indegree, flag ^ 1);
    }

    return changes + 1;
}

int main(){

    while(scanf ("%d %d %d", &n1, &n2, &d) && n1){
        for(int i = 1; i <= n1 + n2; i++) graph[i].clear();
        while(d--){
            int x, y;
            scanf("%d %d", &x, &y);
            graph[y].pb(x);
            indegree1[x]++;
            indegree2[x]++;
        }
        printf ("%d\n", min (topSort(indegree1, 0), topSort(indegree2, 1)));
    }

    return 0;
}

