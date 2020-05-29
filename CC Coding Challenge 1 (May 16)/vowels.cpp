// link: https://www.codechef.com/WETS0120/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, vowels[5], cons, n;
    string s;
    cin >> t;
    while (t--){
        cin >> s;
        n = s.length();
        memset(vowels, 0, sizeof(vowels));
        cons=0;
        for (char c : s){
            switch (c){
                case 'a': vowels[0]++; 
                          break;
                case 'e': vowels[1]++; 
                          break;
                case 'i': vowels[2]++; 
                          break;
                case 'o': vowels[3]++; 
                          break;
                case 'u': vowels[4]++; 
                          break;
                default: cons++;
            }
        }
        if (cons == n)
            cout << cons << "\n";
        else{
            sort(vowels, vowels + 5);
            int i, ans;
            for(i=0; i < 5 && vowels[i]==0;i++);
            if (i == 4)
                cout << n << "\n";
            else {
                ans = vowels[i];
                int c;
                for(c = 1; i < 4 && cons > 0; i++,c++){
                    int diff = vowels[i + 1] - vowels[i];
                    if (diff > cons/c){
                        ans = vowels[i] + cons/c;
                        cons = 0;
                    }
                    else{
                        ans = vowels[i+1];
                        cons -= (diff*c);
                    }
                }
                cout << (ans+cons/c) << "\n";
            }
        }
    }
    return 0;
}