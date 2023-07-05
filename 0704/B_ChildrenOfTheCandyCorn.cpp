// B - Accepted
// 最短路或许使用bfs来计算比较合适
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
int start_wid;
int start_height;
int end_wid;
int end_height;

typedef enum
{
    init_dir = -1,
    left_dir,
    up_dir,
    right_dir,
    down_dir
} dir;

typedef enum
{
    WHITE,
    GRAY,
    BLACK
} color_def;

typedef struct
{
    color_def color;
    int distance;
    int wid;
    int height;
    // dir direction;
} node;

node init = {WHITE, 1, -1, -1};

int left(vector<vector<char>> &Graph)
{
    int ans = 1;
    int current_wid = start_wid;
    int current_height = start_height;
    dir current_dir = init_dir;
    while (!(current_wid == end_wid && current_height == end_height))
    {
        if (current_dir == init_dir || current_dir == up_dir)
        {
            if (current_wid - 1 >= 0 && Graph[current_height][current_wid - 1] != '#')
            {
                current_wid -= 1;
                ans += 1;
                current_dir = left_dir;
            }
            else if (current_height - 1 >= 0 && Graph[current_height - 1][current_wid] != '#')
            {
                current_height -= 1;
                ans += 1;
                current_dir = up_dir;
            }
            else if (current_wid + 1 < Graph[0].size() && Graph[current_height][current_wid + 1] != '#')
            {
                current_wid += 1;
                ans += 1;
                current_dir = right_dir;
            }
            else if (current_height + 1 < Graph.size() && Graph[current_height + 1][current_wid] != '#')
            {
                current_height += 1;
                ans += 1;
                current_dir = down_dir;
            }
            else
            {
                break;
            }
        }
        else if (current_dir == right_dir)
        {
            if (current_height - 1 >= 0 && Graph[current_height - 1][current_wid] != '#')
            {
                current_height -= 1;
                ans += 1;
                current_dir = up_dir;
            }
            else if (current_wid + 1 < Graph[0].size() && Graph[current_height][current_wid + 1] != '#')
            {
                current_wid += 1;
                ans += 1;
                current_dir = right_dir;
            }
            else if (current_height + 1 < Graph.size() && Graph[current_height + 1][current_wid] != '#')
            {
                current_height += 1;
                ans += 1;
                current_dir = down_dir;
            }
            else if (current_wid - 1 >= 0 && Graph[current_height][current_wid - 1] != '#')
            {
                current_wid -= 1;
                ans += 1;
                current_dir = left_dir;
            }
            else
            {
                break;
            }
        }
        else if (current_dir == down_dir)
        {
            if (current_wid + 1 < Graph[0].size() && Graph[current_height][current_wid + 1] != '#')
            {
                current_wid += 1;
                ans += 1;
                current_dir = right_dir;
            }
            else if (current_height + 1 < Graph.size() && Graph[current_height + 1][current_wid] != '#')
            {
                current_height += 1;
                ans += 1;
                current_dir = down_dir;
            }
            else if (current_wid - 1 >= 0 && Graph[current_height][current_wid - 1] != '#')
            {
                current_wid -= 1;
                ans += 1;
                current_dir = left_dir;
            }
            else if (current_height - 1 >= 0 && Graph[current_height - 1][current_wid] != '#')
            {
                current_height -= 1;
                ans += 1;
                current_dir = up_dir;
            }
            else
            {
                break;
            }
        }
        else if (current_dir == left_dir)
        {
            if (current_height + 1 < Graph.size() && Graph[current_height + 1][current_wid] != '#')
            {
                current_height += 1;
                ans += 1;
                current_dir = down_dir;
            }
            else if (current_wid - 1 >= 0 && Graph[current_height][current_wid - 1] != '#')
            {
                current_wid -= 1;
                ans += 1;
                current_dir = left_dir;
            }
            else if (current_height - 1 >= 0 && Graph[current_height - 1][current_wid] != '#')
            {
                current_height -= 1;
                ans += 1;
                current_dir = up_dir;
            }
            else if (current_wid + 1 < Graph[0].size() && Graph[current_height][current_wid + 1] != '#')
            {
                current_wid += 1;
                ans += 1;
                current_dir = right_dir;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    return ans;
}
int right(vector<vector<char>> &Graph)
{
    int ans = 1;
    int current_wid = start_wid;
    int current_height = start_height;
    dir current_dir = init_dir;
    while (!(current_wid == end_wid && current_height == end_height))
    {
        // cout << "current_wid = " << current_wid << ", current_height = " << current_height << endl;
        // cout << "current_dir = " << current_dir << endl;
        if (current_dir == init_dir || current_dir == up_dir)
        {
            if (current_wid + 1 < Graph[0].size() && Graph[current_height][current_wid + 1] != '#')
            {
                current_wid += 1;
                ans += 1;
                current_dir = right_dir;
            }
            else if (current_height - 1 >= 0 && Graph[current_height - 1][current_wid] != '#')
            {
                current_height -= 1;
                ans += 1;
                current_dir = up_dir;
            }
            else if (current_wid - 1 >= 0 && Graph[current_height][current_wid - 1] != '#')
            {
                current_wid -= 1;
                ans += 1;
                current_dir = left_dir;
            }
            else if (current_height + 1 < Graph.size() && Graph[current_height + 1][current_wid] != '#')
            {
                current_height += 1;
                ans += 1;
                current_dir = down_dir;
            }

            else
            {
                break;
            }
        }
        else if (current_dir == right_dir)
        {
            if (current_height + 1 < Graph.size() && Graph[current_height + 1][current_wid] != '#')
            {
                current_height += 1;
                ans += 1;
                current_dir = down_dir;
            }
            else if (current_wid + 1 < Graph[0].size() && Graph[current_height][current_wid + 1] != '#')
            {
                current_wid += 1;
                ans += 1;
                current_dir = right_dir;
            }
            else if (current_height - 1 >= 0 && Graph[current_height - 1][current_wid] != '#')
            {
                current_height -= 1;
                ans += 1;
                current_dir = up_dir;
            }
            else if (current_wid - 1 >= 0 && Graph[current_height][current_wid - 1] != '#')
            {
                current_wid -= 1;
                ans += 1;
                current_dir = left_dir;
            }

            else
            {
                break;
            }
        }
        else if (current_dir == down_dir)
        {
            if (current_wid - 1 >= 0 && Graph[current_height][current_wid - 1] != '#')
            {
                current_wid -= 1;
                ans += 1;
                current_dir = left_dir;
            }
            else if (current_height + 1 < Graph.size() && Graph[current_height + 1][current_wid] != '#')
            {
                current_height += 1;
                ans += 1;
                current_dir = down_dir;
            }
            else if (current_wid + 1 < Graph[0].size() && Graph[current_height][current_wid + 1] != '#')
            {
                current_wid += 1;
                ans += 1;
                current_dir = right_dir;
            }

            else if (current_height - 1 >= 0 && Graph[current_height - 1][current_wid] != '#')
            {
                current_height -= 1;
                ans += 1;
                current_dir = up_dir;
            }

            else
            {
                break;
            }
        }
        else if (current_dir == left_dir)
        {
            if (current_height - 1 >= 0 && Graph[current_height - 1][current_wid] != '#')
            {
                current_height -= 1;
                ans += 1;
                current_dir = up_dir;
            }
            else if (current_wid - 1 >= 0 && Graph[current_height][current_wid - 1] != '#')
            {
                current_wid -= 1;
                ans += 1;
                current_dir = left_dir;
            }
            else if (current_height + 1 < Graph.size() && Graph[current_height + 1][current_wid] != '#')
            {
                current_height += 1;
                ans += 1;
                current_dir = down_dir;
            }
            else if (current_wid + 1 < Graph[0].size() && Graph[current_height][current_wid + 1] != '#')
            {
                current_wid += 1;
                ans += 1;
                current_dir = right_dir;
            }

            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    return ans;
}
int shortest(vector<vector<char>> &Graph, vector<vector<node>> &Node) //* bfs
{
    int ans = 1;
    queue<node> q;
    int current_wid = start_wid;
    int current_height = start_height;

    Node[start_height][start_wid].color = GRAY;
    Node[start_height][start_wid].distance = 1;
    q.push(Node[start_height][start_wid]);
    while (1)
    {
        node current = q.front();
        current_height = current.height;
        current_wid = current.wid;
        ans = current.distance;
        q.pop();
        if (current_height + 1 < Graph.size() && Graph[current_height + 1][current_wid] != '#' && Node[current_height + 1][current_wid].color == WHITE)
        {
            Node[current_height + 1][current_wid].color = GRAY;
            Node[current_height + 1][current_wid].distance = ans + 1;
            q.push(Node[current_height + 1][current_wid]);
            if (current_height + 1 == end_height && current_wid == end_wid)
            {
                return ans + 1;
            }
        }
        if (current_wid + 1 < Graph[0].size() && Graph[current_height][current_wid + 1] != '#' && Node[current_height][current_wid + 1].color == WHITE)
        {
            Node[current_height][current_wid + 1].color = GRAY;
            Node[current_height][current_wid + 1].distance = ans + 1;
            q.push(Node[current_height][current_wid + 1]);
            if (current_height == end_height && current_wid + 1 == end_wid)
            {
                return ans + 1;
            }
        }
        if (current_height - 1 >= 0 && Graph[current_height - 1][current_wid] != '#' && Node[current_height - 1][current_wid].color == WHITE)
        {
            Node[current_height - 1][current_wid].color = GRAY;
            Node[current_height - 1][current_wid].distance = ans + 1;
            q.push(Node[current_height - 1][current_wid]);
            if (current_height - 1 == end_height && current_wid == end_wid)
            {
                return ans + 1;
            }
        }
        if (current_wid - 1 >= 0 && Graph[current_height][current_wid - 1] != '#' && Node[current_height][current_wid - 1].color == WHITE)
        {
            Node[current_height][current_wid - 1].color = GRAY;
            Node[current_height][current_wid - 1].distance = ans + 1;
            q.push(Node[current_height][current_wid - 1]);
            if (current_height == end_height && current_wid - 1 == end_wid)
            {
                return ans + 1;
            }
        }
    }
    return ans;
}
int main()
{
    int n = 0;
    cin >> n;
    int w, h;
    for (int i = 0; i < n; ++i)
    {
        cin >> w >> h;
        vector<vector<char>> Graph(h);
        vector<vector<node>> Node(h);

        for (int i = 0; i < h; ++i)
        {
            Graph[i].insert(Graph[i].begin(), w, 0);  //* init
            Node[i].insert(Node[i].begin(), w, init); //* init
        }
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> Graph[i][j];
                if (Graph[i][j] == 'S')
                {
                    start_wid = j;
                    start_height = i;
                }
                if (Graph[i][j] == 'E')
                {
                    end_wid = j;
                    end_height = i;
                }
                Node[i][j].height = i;
                Node[i][j].wid = j;
            }
        }
        int left_ans = left(Graph);

        // std::cout << left_ans << endl;
        int right_ans = right(Graph);

        // std::cout << right_ans << endl;
        int shortest_ans = shortest(Graph, Node);
        // std::cout << shortest_ans  << endl;
        cout << left_ans << " " << right_ans << " " << shortest_ans << endl;
    }
}