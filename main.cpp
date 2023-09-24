#include <bits/stdc++.h>
using namespace std;


// Minimum Cost
int minCostPath(int m, int n)
{
    int table[m][n];
    for (int i = 0; i < m; i++){
        table[i][0] = 1;
    }

    for (int j = 0; j < n; j++){
         table[0][j] = 1;
    }



    // first row and first column
    for (int i = 1; i < m; i++) {
        table[i][0] += table[i - 1][0];
    }
    for (int j = 1; j < n; j++) {
        table[0][j] += table[0][j - 1];
    }

    //  recurrence
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            table[i][j] += min(table[i - 1][j],
                              min(table[i][j - 1],
                                table[i - 1][j - 1]));
        }
    }

    cout << "Minimum cost path matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    return table[m - 1][n - 1];
}




// Path Cost
int numberOfPaths(int m, int n)
{
    int table[m][n];


    for (int i = 0; i < m; i++){
        table[i][0] = 1;
    }

    for (int j = 0; j < n; j++){
         table[0][j] = 1;
    }



    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            table[i][j] = table[i - 1][j] +  table[i][j - 1]   +    table[i-1][j-1];
        }
    }


    cout << "Table of counts:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    return table[m - 1][n - 1];
}





int main()
{
    int m,n;
    cout<<"Enter the row and col value:"<<endl;
    cin>>m>>n;
    cout << "Total paths: " << numberOfPaths(m, n) << endl;


    cout << "Minimum cost:" << minCostPath(m, n)<< endl;
    return 0;
}
