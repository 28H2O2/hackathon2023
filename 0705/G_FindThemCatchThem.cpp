// G
// 并查集
#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <list>
#include <queue>
using namespace std;

// struct node
// {
//     // int num;
//     int level = 0;
//     int root_num;
//     node *pa = this;
//     vector<node *> son;
// };

struct node
{
    int level = 0;
    int root_num;
    node *pa = this;
    list<node *> son; // 使用list替代vector来存储子节点
};

// 修正之后（减小内存）的代码
void Compress(node *x, int level, int root) // 将以x为root的树压缩到level <= 2
{
    queue<pair<node *, int>> nodesQueue; // 使用队列来进行层次遍历
    nodesQueue.push({x, level});

    while (!nodesQueue.empty())
    {
        node *currentNode = nodesQueue.front().first;
        int currentLevel = nodesQueue.front().second;
        nodesQueue.pop();

        currentNode->root_num = root;
        currentNode->level = currentLevel;

        if (currentLevel == 3)
        {
            currentLevel = 1;
            currentNode->level = 1;
            currentNode->pa = currentNode->pa->pa->pa;
        }

        for (auto son : currentNode->son)
        {
            nodesQueue.push({son, currentLevel + 1});
        }
    }
}
void judge(int x1, int x2, int i, vector<node> &Nodes)
{
    // cout << "Node[x1].root_num = " << Nodes[x1].root_num << endl;
    // cout << "Node[x2].root_num = " << Nodes[x2].root_num << endl;
    if (i == 0)
    {
        cout << "Not sure yet." << endl;
        return;
    }
    if (Nodes[x1].root_num != Nodes[x2].root_num)
    {
        cout << "Not sure yet." << endl;
        return;
    }
    if (abs(Nodes[x1].level - Nodes[x2].level) == 1)
    {
        cout << "In different gangs." << endl;
        return;
    }
    else
    {
        cout << "In the same gang." << endl;
        return;
    }
}

// void Compress(node *x, int level, int root) // 将以x为root的树压缩到level <= 2
// {
//     // int temp_root = root;
//     x->root_num = root;
//     x->level = level;
//     if (x->son.empty())
//     {
//         x->root_num = root;
//         return;
//     }
//     // int temp = level;
//     if (level == 3)
//     {
//         level = 1;
//         x->level = 1;
//         x->pa = x->pa->pa->pa;
//     }
//     for (auto son : x->son)
//     {
//         Compress(son, level + 1, root);
//     }
// }
void insert(int x1, int x2, vector<node> &Nodes)
{

    Nodes[x1].root_num = x1;
    Nodes[x2].root_num = x2;
    if (Nodes[x1].level == 0 && Nodes[x2].level == 0)
    {
        Nodes[x2].pa = &Nodes[x1];
        Nodes[x1].son.push_back(&Nodes[x2]);
        Nodes[x1].root_num = x1;
        Nodes[x2].root_num = x1;
        Compress(&Nodes[x1], 0, x1);
    }
    else if (Nodes[x1].level == 0 && Nodes[x2].level == 1)
    {
        Nodes[x1].pa = &Nodes[x2];
        Nodes[x2].son.push_back(&Nodes[x1]);
        Compress(Nodes[x2].pa, 0, Nodes[x2].pa->root_num);
    }
    else if (Nodes[x1].level == 1 && Nodes[x2].level == 0)
    {
        Nodes[x2].pa = &Nodes[x1];
        Nodes[x1].son.push_back(&Nodes[x2]);
        Compress(Nodes[x1].pa, 0, Nodes[x1].pa->root_num);
    }
    else if (Nodes[x1].level == 1 && Nodes[x2].level == 1)
    {
        Nodes[x2].pa->pa = Nodes[x1].pa;
        Nodes[x1].pa->son.push_back(Nodes[x2].pa);
        Compress(Nodes[x1].pa, 0, Nodes[x1].pa->root_num);
        // if (!Nodes[x2].son.empty())
        // {
        //     for (auto son : Nodes[x2].son)
        //     {
        //         son->pa = Nodes[x1].pa;
        //     }
        //     Nodes[x2].son.clear();
        // }
    }
    else if (Nodes[x2].level == 2)
    {
        Nodes[x2].pa->pa->pa = &Nodes[x1];
        Nodes[x1].son.push_back(Nodes[x2].pa->pa->pa);
        Compress(Nodes[x1].pa->pa, 0, Nodes[x1].pa->pa->root_num);
    }
    else if (Nodes[x1].level == 2)
    {
        Nodes[x1].pa->pa->pa = &Nodes[x1];
        Nodes[x2].son.push_back(Nodes[x1].pa->pa->pa);
        Compress(Nodes[x2].pa->pa, 0, Nodes[x2].pa->pa->root_num);
        // for (auto son : Nodes[x1].pa->son)
        // {
        //     son->pa = &Nodes[x2];
        // }
        // Nodes[x1].pa->son.clear();
        // if (Nodes)
    }
    else
    {
        cout << "Unknown Error" << endl;
    }
}
int main()
{
    int M, N;
    int T;
    cin >> T;
    vector<node> Nodes;
    for (int i = 0; i < T; ++i)
    {
        cin >> N >> M;
        // vector<char> type(N);
        // vector<node> Nodes(N + 1);
        // type.clear();
        Nodes.clear();
        Nodes.resize(N + 1);
        char t;
        // Nodes.clear();
        int x1, x2;
        int A_num = 0;
        int D_num = 0;
        for (int i = 0; i < M; ++i)
        {
            // cin >> type[i];
            cin >> t;
            cin >> x1 >> x2;
            // if (type[i] == 'A')
            if (t == 'A')
            {
                judge(x1, x2, i, Nodes);
                A_num++;
            }
            else
            {
                insert(x1, x2, Nodes);
            }
        }
    }
}