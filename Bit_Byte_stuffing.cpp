#include <bits/stdc++.h>
using namespace std;
int j;
vector<int> bitStuffing(int N, int arr[])
{
    vector<int> brr(30);
    int i, k;
    i = 0;
    j = 0;
    int count = 1;
    while (i < N)
    {
        if (arr[i] == 1)
        {
            brr[j] = arr[i];
            for (k = i + 1; arr[k] == 1 && k < N && count < 5; k++)
            {
                j++;
                brr[j] = arr[k];
                count++;
                if (count == 5)
                {
                    j++;
                    brr[j] = 0;
                }
                i = k;
            }
        }
        else
        {
            brr[j] = arr[i];
        }
        i++;
        j++;
    }
    return brr;
}

void byteStuffing()
{
    char a[50], b[100] = "", sd, ed;
    int size, j = 0;
    cout << "\n Enter input string :";
    cin >> a;
    size = strlen(a);
    cout << " \n Enter starting delimiter : ";
    cin >> sd;
    cout << " \n Enter ending delimiter : ";
    cin >> ed;
    b[j++] = sd;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == sd)
            b[j++] = sd;
        b[j++] = a[i];
    }
    b[j++] = ed;
    cout << "\n After Character Stuffing :";
    cout << b << endl;
}

int main()
{
    int choice;
    cout << "\nEnter the choice:-\n1. Bit Stuffing\n2. Byte Stuffing ";
    cin >> choice;
    if (choice == 2)
    {
        byteStuffing();
        return 0;
    }
    else if (choice == 1)
        goto BIT;
    else
        return 0;

BIT:
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    vector<int> temp;
    temp = bitStuffing(N, arr);
    for (int i = 0; i < j; i++)
        cout << temp[i];
    return 0;
}
