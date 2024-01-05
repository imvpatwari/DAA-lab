#include <iostream>
#include <algorithm>
using namespace std;
struct Item
{
    int profit, weight;
    Item(int profit, int weight) : profit(profit), weight(weight)
    {
    }
};
int compareByProfit(struct Item a, struct Item b)
{
    float r1 = (float)a.profit / a.weight;
    float r2 = (float)b.profit / b.weight;
    return r1 > r2;
}
int compareByWeight(struct Item a, struct Item b)
{
    float r1 = (float)a.profit;
    float r2 = (float)b.profit;
    return r1 > r2;
}
int compareByRatio(struct Item a, struct Item b)
{
    float r1 = (float)a.weight;
    float r2 = (float)b.weight;
    return r1 < r2;
}
double fractionalKnapsack_1(struct Item arr[],
                            int knapsack_capacity, int size)
{
    sort(arr, arr + size, compareByWeight); 
    int curWeight = 0;                      
    float Total_profit = 0.0;               
    for (int i = 0; i < size; i++)
    {
        if (curWeight + arr[i].weight <= knapsack_capacity)
        {
            curWeight += arr[i].weight;
            Total_profit += arr[i].profit;
        }
        else
        {
            float remain = knapsack_capacity - curWeight;
            Total_profit += arr[i].profit * (remain / arr[i].weight);
            break;
        }
     }
    return Total_profit; 
}

double fractionalKnapsack_2(struct Item arr[],
                            int knapsack_capacity, int size)
{
    sort(arr, arr + size, compareByRatio); 
    int curWeight = 0;                     
    float Total_profit = 0.0;              
    for (int i = 0; i < size; i++)
    {
        if (curWeight + arr[i].weight <= knapsack_capacity)
        {
            curWeight += arr[i].weight;
            Total_profit += arr[i].profit;
        }
        else
        {
            float remain = knapsack_capacity - curWeight;
            Total_profit += arr[i].profit * (remain / arr[i].weight);
            break;
        }
    }
    return Total_profit; 
}
double fractionalKnapsack(struct Item arr[],
                          int knapsack_capacity, int size)
{
    sort(arr, arr + size, compareByProfit); 
    int curWeight = 0;                      
    float Total_profit = 0.0;               
    for (int i = 0; i < size; i++)
    {
        if (curWeight + arr[i].weight <= knapsack_capacity)
        {
            curWeight += arr[i].weight;
            Total_profit += arr[i].profit;
        }
        else
        {
            float remain = knapsack_capacity - curWeight;
            Total_profit += arr[i].profit * (remain / arr[i].weight);
            break;
        }
    }
    return Total_profit; 
}
int main()
{
    int knapsack_capacity = 25;
    Item arr[] = {{24, 24},
                  {18, 10},
                  {18, 10},
                  {10, 7}};
    int size = sizeof(arr) / sizeof(arr[0]); 
    cout << "Maximum profit earned in case 1 (Maximum profit)="
         << fractionalKnapsack_1(arr, knapsack_capacity, size) << endl;
    cout << "Maximum profit earned in case 2 (Minimum Weight)= "
         << fractionalKnapsack_2(arr, knapsack_capacity, size) << endl; 
    cout << "Maximum profit earned in case 3 (Profit/weight ratio)= "
         << fractionalKnapsack(arr, knapsack_capacity, size) << endl; 
    return 0;
}
