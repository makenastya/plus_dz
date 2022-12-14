#include <iostream>
#include <vector>

using namespace std;

vector <int> a;
vector <int> b;

void merge(int l1, int r1, int l2, int r2)
{
    int k = 0;
    int i1 = l1;
    int i2 = l2;
    while ((i1 < r1) && (i2 < r2))
    {
        if (a[i1] < a[i2])
        {
            b[k] = a[i1];
            i1++;
            k++;
        }
        else
        {
            b[k] = a[i2];
            i2++;
            k++;
        }
    }
    while (i1 < r1)
    {
        b[k] = a[i1];
        i1++;
        k++;
    }
    while (i2 < r2)
    {
        b[k] = a[i2];
        i2++;
        k++;
    }
    for (int i = 0; i < k; i++)
        a[l1 + i] = b[i];

}

void merge_sort(int l, int r)
{
    int x = (l + r) / 2;
    if (x - l > 1)
        merge_sort(l, x);
    if (r - x > 1)
        merge_sort(x, r);
    merge(l, x, x, r);
}

int main()
{
    int n;
    int t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
        b.push_back(0);
    }
    merge_sort(0, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}
