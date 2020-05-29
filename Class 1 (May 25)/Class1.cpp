#include <iostream>
using namespace std;

int binarySearch(int l, int r, int a[], int x){
    int mid = (l)

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, c=0;
    cin >> n;
    int a[n], pre[n]={0};
    for (int i = 0; i < n; i++){
        cin >> a[i];
        pre[i] = a[i] + (i > 0 ? pre[i-1] : 0);
    }
    cin >> x;
    for(int i = 0; i < n; i++){
        if(binarySearch(i+1, n, pre, pre[i]+x))
            c++;
    }
    return 0;
}