#include <iostream>
#include <stack>
#include <fstream>
#include <vector>

using namespace std;

const int direction[4][2] = {{0,  -1},
                             {0,  1},
                             {1,  0},
                             {-1, 0}};

int maxOfTwo(int a, int b) {
    return a > b ? a : b;
}

int find(vector<vector<int>> &snowMountain, vector<vector<int>> &f, int i, int j, int r, int c) {
    int x, y;
    if (f[i][j] != -1)
        return f[i][j];

    f[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        x = i + direction[k][0];
        y = j + direction[k][1];

        //valid direction
        if (x >= 0 && x < r && y >= 0 && y < c && snowMountain[i][j] > snowMountain[x][y]) {
            f[i][j] = maxOfTwo(f[i][j], find(snowMountain, f, x, y, r, c) + 1);
        }
    }
    return f[i][j];
}

int main() {

    ifstream fin("a.in");
    ofstream fout("a.out");
    double startTime = clock();

    int i, j, r, c, maxHeight = 0;

    fin >> r >> c;

    vector<vector<int>> snowMountain(r, vector<int>(c, 0));
    vector<vector<int>> f(r, vector<int>(c, -1));

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            fin >> snowMountain[i][j];

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            maxHeight = maxOfTwo(maxHeight, find(snowMountain, f, i, j, r, c));
        }

    fout << maxHeight << endl;
    double endTime = clock();
    fout << "The run time is: " << (double) (endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    fin.close();
    fout.close();
    return 0;
}

int find() {
    for (int i=0;i < 1;++i) {

    }
}