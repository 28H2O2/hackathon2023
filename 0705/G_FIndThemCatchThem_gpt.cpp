#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int parent;   // 父节点的索引
    int rank;     // 该节点所在树的秩
    int relation; // relation=0 表示与根节点在同一个gang, relation=1 表示与根节点在不同的gang
};

vector<Node> nodes;

int findSet(int i, int &relation)
{
    // 路径压缩
    if (nodes[i].parent != i)
    {
        int prev_relation = nodes[i].relation;
        nodes[i].parent = findSet(nodes[i].parent, nodes[i].relation);
        // 更新关系 (XOR)
        nodes[i].relation = (prev_relation ^ nodes[i].relation) % 2;
    }
    relation = nodes[i].relation;
    return nodes[i].parent;
}

void unionSet(int i, int j)
{
    int relation_i, relation_j;
    int ri = findSet(i, relation_i);
    int rj = findSet(j, relation_j);

    // 按秩合并，并设置关系为不同的gang
    if (ri != rj)
    {
        if (nodes[ri].rank < nodes[rj].rank)
        {
            nodes[ri].parent = rj;
            nodes[ri].relation = (relation_i ^ relation_j ^ 1) % 2;
        }
        else
        {
            nodes[rj].parent = ri;
            nodes[rj].relation = (relation_i ^ relation_j ^ 1) % 2;
            if (nodes[ri].rank == nodes[rj].rank)
            {
                nodes[ri].rank++;
            }
        }
    }
}

int main()
{
    int T, N, M;
    cin >> T;

    for (int t = 0; t < T; ++t)
    {
        cin >> N >> M;

        nodes.resize(N + 1);
        for (int i = 1; i <= N; ++i)
        {
            nodes[i].parent = i;
            nodes[i].rank = 0;
            nodes[i].relation = 0;
        }

        char queryType;
        int x, y;

        for (int i = 0; i < M; ++i)
        {
            cin >> queryType >> x >> y;

            if (queryType == 'A')
            {
                int relation;
                if (findSet(x, relation) == findSet(y, relation))
                {
                    if (relation == 0)
                    {
                        cout << "In the same gang." << endl;
                    }
                    else
                    {
                        cout << "In different gangs." << endl;
                    }
                }
                else
                {
                    cout << "Not sure yet." << endl;
                }
            }
            else
            { // queryType == 'D'
                unionSet(x, y);
            }
        }
    }
    return 0;
}
