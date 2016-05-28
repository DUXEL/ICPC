// Includes
#include <bits/stdc++.h>

using namespace std;

//Macros

#define EPSILON 0.0000000001
#define INF 1000000000
#define MOD 10000000000

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;


//Global variables.
vector<vi> graph;
int startNode, endNode, currNode;

int n, m, f;
int mapI[] = {-1, 0};
int mapJ[] = {0, -1};
char currMat[101][101];
char prevMat[101][101];

//Functions

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void swapArrays() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prevMat[i][j] = currMat[i][j];
        }
    }
}

int bfs() {
    vi d(n*m*f, INF);
    d[startNode] = 0;
    queue<pi> q;
    q.push(make_pair(startNode, 0));
    while (!q.empty()) {
        pi u = q.front();
        q.pop();
        for (int j = 0; j < (int) graph[u.first].size(); j++) {
            int v = graph[u.first][j];
            if(d[v] == INF) {
                d[v] = 1;
                if(v == endNode) {
                    return u.second+1;
                }else {
                    q.push(make_pair(v, u.second+1));
                }
            }
        }
    }
    return -1;
}

//Main




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    char readChar;
    int neighbor;
    while (cin >> n >> m >> f, n) {
        currNode = 0;
        graph.assign((unsigned long) (n * m * f), vi());
        for (int floors = 0; floors < f; floors++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cin >> readChar;
                    currMat[i][j] = readChar;
                    if (readChar == '#') {
                        currNode++;
                        continue;
                    }
                    else if (readChar == 'S') startNode = currNode;
                    else if (readChar == 'E') endNode = currNode;
                    else if (readChar == '-') {
                        if(floors > 0) {
                            if (prevMat[i][j] == '-') {
                                neighbor = currNode - (n * m);
                                addEdge(currNode, neighbor);
                            }
                        }
                    }
                    for (int mapIndex = 0; mapIndex < 2; mapIndex++) {
                        if (i + mapI[mapIndex] < n && i + mapI[mapIndex] >= 0 &&
                            j + mapJ[mapIndex] < m && j + mapJ[mapIndex] >= 0 &&
                            currMat[i + mapI[mapIndex]][j + mapJ[mapIndex]] != '#') {
                            if (mapIndex == 0) neighbor = currNode - ((m - (j + 1)) + (j + 1));
                            else neighbor = currNode - 1;
                            addEdge(currNode, neighbor);
                        }
                    }
                    currNode++;
                }
            }
            swapArrays();
        }
        cout << bfs() << "\n";
    }
    return 0;
}