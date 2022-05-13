#include<iostream>
#include<queue>
using namespace std;
int const MAX_SIZE = 10;
queue<int> q;

int graph[MAX_SIZE][MAX_SIZE] = { 0 };
int node, edge;
bool visited[MAX_SIZE];
int level[MAX_SIZE];
int previous[MAX_SIZE];

void Initialize() {
    for (int i = 0; i < node; i++)
        visited[i] = false;
}

void AdjacentNode(int source) {
    for (int i = 0; i < node; i++) {
        if (graph[source][i] == 1)
            cout << i << " ";
    }
}

void DFS(int source) {
    visited[source] = true;
  
   cout<<source<<" ";

    for (int i = 0; i < node; i++) {
        if (graph[source][i] == 1) {
            if (visited[i] == false) {
                DFS(i);
            }
        }
    }    
}

void BFS(int source) {
    
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int x = q.front();
        cout << x << " ";

        for (int i = 0; i < node; i++) {
            if (graph[x][i] == 1) {
                if (visited[i] == false) {
                    q.push(i);
                    visited[i] = true;
                    level[i] = level[x] + 1;
                    previous[i]=x;
                }
            }
        }
        q.pop();
    }
}

int main() {
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int m, n;
        cin >> m >> n;
        graph[m][n] = 1;
        //To get the directed graph we need to erase this opposite part
        graph[n][m] = 1;
    }

    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    /*
 0 1 1 0 0 0 0 
 1 0 0 0 0 0 0
 1 0 0 1 1 0 0
 0 0 1 0 0 1 0
 0 0 1 0 0 0 0
 0 0 0 1 0 0 0
 0 0 0 0 0 0 0
    
    */

  //  AdjacentNode(3);
    /* 2 5 */
    cout<<endl;
    DFS(0);
    /* 0 1 2 3 5 4 */
    cout << endl;
    Initialize();
     BFS(0);
     /*0 1 2 3 4 5*/
     cout<<endl;
    
     
    return 0;
}

/*
7 6
0 1
0 2
2 3
2 4
3 5
6 7
*/

/*
9 14
0 1
0 3
2 3
2 8
3 7
4 8
5 4
5 6
6 1
6 4
6 8
7 2
7 5
8 7
*/
