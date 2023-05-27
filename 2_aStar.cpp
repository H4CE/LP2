#include <bits/stdc++.h>
using namespace std;
using intl = long long int;

struct Node
{
    int g, f, h;
    Node *parent;
    pair<int, int> position;
    Node(Node *prnt, pair<int, int> psn, int ga, int ha)
    {
        parent = prnt;
        position = psn;
        g = ga;
        h = ha;
        f = g + h;
    }
};

vector<pair<int, int>> aStar(vector<vector<int>> &matrix, pair<int, int> start, pair<int, int> end)
{
    Node *startNode = new Node(NULL, start, 0, 0);
    Node *endNode = new Node(NULL, end, 0, 0);

    vector<Node *> openList;
    vector<Node *> closedList;

    openList.push_back(startNode);

    while (!openList.empty())
    {

        Node *currNode = openList[0];
        int currIndex = 0;

        for (int i = 0; i < openList.size(); i++)
        {
            if (openList[i]->f < currNode->f)
            {
                currNode = openList[i];
                currIndex = i;
            }
        }

        openList.erase(openList.begin() + currIndex);
        closedList.push_back(currNode);

        if (currNode->position == endNode->position)
        {
            vector<pair<int, int>> path;
            Node *ptr = currNode;
            while (ptr != NULL)
            {
                path.push_back(ptr->position);
                ptr = ptr->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }
        vector<pair<int, int>> deltaMoves = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

        for (auto &x : deltaMoves)
        {
            pair<int, int> newPosition = {currNode->position.first + x.first, currNode->position.second + x.second};

            if (newPosition.first >= 0 && newPosition.first < matrix.size() && newPosition.second >= 0 && newPosition.second < matrix[0].size() && matrix[newPosition.first][newPosition.second] == 0)
            {
                Node *newNode = new Node(currNode, newPosition, currNode->g + 1, (abs(newPosition.first - end.first) + abs(newPosition.second - end.second)));

                bool inOpenList = false;
                for (auto &node : openList)
                {
                    if (node->position == newNode->position)
                    {
                        inOpenList = true;
                        if (newNode->g < node->g)
                        {
                            node->g = newNode->g;
                            node->parent = newNode->parent;
                            node->f = node->g + node->h;
                        }
                        delete newNode;
                        break;
                    }
                }
                bool inclosedList = false;
                for (auto &node : closedList)
                {
                    if (node->position == newNode->position)
                    {
                        inclosedList = true;
                        delete newNode;
                        break;
                    }
                }

                if (inclosedList == false && inOpenList == false)
                {
                    openList.push_back(newNode);
                }
            }
        }
    }
    return {};
}
int main()
{
    vector<vector<int>> matrix = {
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
    };

    cout << "  ";
    for (int i = 0; i < matrix[0].size(); i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = 0; i < matrix.size(); ++i)
    {
        cout << i << " ";
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j])
            {
                cout << "| ";
            }
            else
            {
                cout << "_ ";
            }
        }
        cout << "\n";
    }
    cout << "\n";

    pair<int, int> start(4, 1);
    pair<int, int> end(2, 3);

    vector<pair<int, int>> path = aStar(matrix, start, end);

    if (!path.empty())
    {
        cout << "Path found: ";
        for (const auto &coord : path)
        {
            cout << "(" << coord.first << " " << coord.second << "), ";
        }
        cout << endl;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (find(path.begin(), path.end(), make_pair(i, j)) != path.end())
                {
                    cout << "* ";
                    continue;
                }
                if (matrix[i][j])
                {
                    cout << "| ";
                }
                else
                {
                    cout << "_ ";
                }
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "No path found." << endl;
    }

    return 0;
}