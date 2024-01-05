#include <iostream>
#include <iomanip>
using namespace std;
int max(int x, int y)
{
    return (x > y) ? x : y; 
}

int knapSack(int k_capacity, int w[], int p[], int n)
{
    int i, j;
    int A[n + 1][k_capacity + 1]; 
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= k_capacity; j++)
        {
            if (i == 0 || j == 0)
                A[i][j] = 0;                                                  
            else if (w[i - 1] <= j)                                            
                A[i][j] = max(A[i - 1][j], p[i - 1] + A[i - 1][j - w[i - 1]]); 
            else
                A[i][j] = A[i - 1][j]; 
        }
    }
    cout << "Matrix generated for Dynamic programming:"
         << "\n"
         << "\n";
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= k_capacity; j++)
        {
            cout << setw(2) << A[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    int profit = A[n][k_capacity];
    
    int wt = k_capacity;
    for (i = n; i > 0 && profit > 0; i--)
    {
        if (profit == A[i - 1][j])
            cout << "This item is not included" << i << "->0"
                 << "\n";
        else
        {
            cout << "This item is included" << i << "->1"
                 << "\n";
            profit = profit - p[i - 1];
            wt = wt - w[i - 1];
        }
    }
    cout << "Maximum Profit for a 0/1 knapsack is: ";
    return A[n][k_capacity];
}
int main()
{
    cout << "Enter the number of objects for a Knapsack: "; 
    int n, K_capacity;
    cin >> n;
    int p[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Profit and weight for item using space " << i << ": "; 
        cin >> p[i];
        cin >> w[i];
    }
    cout << "Enter the capacity of knapsack: "; 
    cin >> K_capacity;
    cout << knapSack(K_capacity, w, p, n); 
    return 0;
}
