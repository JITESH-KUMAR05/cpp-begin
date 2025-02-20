#include<bits/stdc++.h>
using namespace std;
void pat1(int n){
    
    for(int i= 0 ; i< n; i++){
        for(int j = 0; j<n;j++){
            cout << "*";
        }
        cout << endl;
    }
}
void pat2(int n){
    for(int i= 0 ; i< n; i++){
        for(int j = 0; j<=i;j++){
            cout << "*";
        }
        cout << endl;
    }
}
void pat3(int n){
    for(int i= 1 ; i<= n; i++){
        for(int j = 1; j<=i;j++){
            cout << j;
        }
        cout << endl;
    }
}
void pat4(int n){
    for(int i= 1 ; i<= n; i++){
        for(int j = 1; j<=i;j++){
            cout << i;
        }
        cout << endl;
    }
}
void pat5(int n){
    for(int i= 1 ; i<= n; i++){
        for(int j = n; j>=i;j--){
            cout << "*" << " ";
        }
        cout << endl;
    }
}
void pat6(int n){
    for(int i= n ; i>= 1; i--){
        for(int j = 1; j<=i;j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void pat7(int n){
    for(int i= 0 ; i< n; i++){
        // space 
        for(int j = 0;j < n-i-1;j++){
            cout << " ";
        }
        // star
        for(int k = 0;k<2*i+1;k++){
            cout << "*";
        }
        // space
        for(int j = 0;j < n-i-1;j++){
            cout << " ";
        }
        cout << endl;
    }
}
void pat8(int n){
    
    for(int i= n ; i> 0; i--){
        // space 
        for(int j = 0;j < n-i;j++){
            cout << " ";
        }
        // star
        for(int k = 0;k<2*i-1;k++){
            cout << "*";
        }
        // space
        for(int j = 0;j < n-i;j++){
            cout << " ";
        }
        cout << endl;
    }
}
void pat9(int n){
    for(int i= 0 ; i< n; i++){
        // space 
        for(int j = 0;j < n-i-1;j++){
            cout << " ";
        }
        // star
        for(int k = 0;k<2*i+1;k++){
            cout << "*";
        }
        // space
        for(int j = 0;j < n-i-1;j++){
            cout << " ";
        }
        cout << endl;
    }
    for(int i= n ; i> 0; i--){
        // space 
        for(int j = 0;j < n-i;j++){
            cout << " ";
        }
        // star
        for(int k = 0;k<2*i-1;k++){
            cout << "*";
        }
        // space
        for(int j = 0;j < n-i;j++){
            cout << " ";
        }
        cout << endl;
    }
}
void pat10(int n){
    for(int i=0;i<n;i++){
        for(int j = 0; j<=i ; j++){
            cout << "*";

        }
        cout << endl;
    }
    for(int i = n-1;i>0;i--){
        for(int j = i;j>0;j--){
            cout << "*";
        }
        cout << endl;
    }
    
}
void pat11(int n){
    int st = 1;
    for(int i = 0;i<n;i++){
        if(i % 2 == 0){
            st = 1;
        }
        else{
            st = 0;
        }
        for(int j = 0;j<=i;j++){
            cout << st << " ";
            st = 1 - st;
        }
        cout << endl;  
    }
    

}

void pat12(int n){
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << j;
        }
        for(int k = 1;k<=2*n-2*i;k++){
            cout << " ";
        }
        for(int k = i;k>=1;k--){
            cout << k;
        }
        cout << endl;

    } 
}

void pat13(int n){
    int st = 1;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=i;j++){
            cout << st;
            st = st + 1;
        }
        cout << endl;
    }
}
void pat14(int n){
    
    for(int i = 0;i<n;i++){
        for(char ch = 'A';ch <= 'A' + i; ch++){
            cout << ch;
        }
        cout << endl;
    }
}
void pat15(int n){
    
    for(int i = 0;i<n;i++){
        for(char ch = 'A';ch < 'A' + (n-i); ch++){
            cout << ch;
        }
        cout << endl;
    }
}
void pat16(int n){
    char ch = 'A'  ;  
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=i;j++){
            cout << ch;
        }
        ch = ch + 1;
        cout << endl;
    }
}
void pat17(int n){
    
    for(int i= 0 ; i< n; i++){
        // space 
        for(int j = 0;j < n-i-1;j++){
            cout << " ";
        }
        // characters
        char ch = 'A';
        int breakpoint = (2*i+1)/2;
        for(int k = 1;k<=2*i+1;k++){
            cout << ch;
            if(k <= breakpoint){
                ch = ch + 1;
            }
            else{
                ch--;
            }
        }
        // space
        for(int j = 0;j < n-i-1;j++){
            cout << " ";
        }
        cout << endl;
    }

}
void pat18(int n){
    for(int i = 0;i<n;i++){
        char ch = 'A' + (n-1);
        for(int j = 0;j<=i;j++){
            cout << ch << " ";
            ch--;
        }
        cout << endl;
    }
}

void pat19(int n){
    for(int i = 0;i<n;i++){
        // stars
        for(int j=0;j<n-i;j++){
            cout << "*";

        }
        // spaces
        for(int k = 0;k<2*i;k++){
            if(i != 0){
                cout << " ";
            }
        }
        // stars
        for(int j=0;j<n-i;j++){
            cout << "*";

        }
        cout << endl;
    }
    // symmetry pattern
    int ins = n * 2 - 2;
    for(int i = 0;i<n;i++){
        // stars
        for(int j=0;j<=i;j++){
            cout << "*";

        }
        // spaces
        for(int k = 0;k<ins;k++){
                cout << " ";
        }
        
        // stars
        for(int j=0;j<=i;j++){
            cout << "*";

        }
        ins = ins - 2;
        cout << endl;
    }
}

void pat20(int n){
    int spaces = 2*n - 2;
    for(int i = 1; i<=2 * n - 1;i++){
        int stars = i;
        if(i>n) stars = 2*n - i;
        // stars
        for(int j = 1;j<=stars;j++){
            cout << "*";
        }


        // spaces
        for(int k = 1;k<=spaces;k++){
            cout << " ";
        }

        // stars
        for(int j = 1;j<=stars;j++){
            cout << "*" ;
        }
        cout << endl;   
        if(i < n) spaces -= 2;
        else spaces += 2;
    }
}
void pat21(int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(i==0 || j == 0 || i == n-1 || j == n-1){
                cout << "*";
            }
            else cout << " ";
        }
        cout << endl;
    }
}
void pat22(int n){
    for(int i = 0;i< 2*n-1;i++){
        for(int j = 0;j< 2*n - 1; j++){
            int top = i;
            int left = j;
            int right = (2*n-2) - j;
            int down = (2*n- 2) - i;
            cout << (n- min(min(top,down),min(left,right)));
            
        }
        cout << endl;
    }
}
int main(){
    int n;
    cout << "Enter the n value : ";
    cin >> n;
    cout << "Pattern 1" << endl;
    pat1(n);
    cout << "Pattern 2" << endl;
    pat2(n);
    cout << "Pattern 3" << endl;
    pat3(n);
    cout << "Pattern 4" << endl;
    pat4(n);
    cout << "Pattern 5" << endl;
    pat5(n);
    cout << "Pattern 6" << endl;
    pat6(n);
    cout << "Pattern 7" << endl;
    pat7(n);
    cout << "Pattern 8" << endl;
    pat8(n);
    cout << "Pattern 9" << endl;
    pat9(n);
    cout << "Pattern 10" << endl;
    pat10(n);
    cout << "Pattern 11" << endl;
    pat11(n);
    cout << "Pattern 12" << endl;
    pat12(n);
    cout << "Pattern 13" << endl;
    pat13(n);
    cout << "Pattern 14" << endl;
    pat14(n);
    cout << "Pattern 15" << endl;
    pat15(n);
    cout << "Pattern 16" << endl;
    pat16(n);
    cout << "Pattern 17" << endl;
    pat17(n);
    cout << "Pattern 18" << endl;
    pat18(n);
    cout << "Pattern 19" << endl;
    pat19(n);
    cout << "Pattern 20" << endl;
    pat20(n);
    cout << "Pattern 21" << endl;
    pat21(n);
    cout << "Pattern 22" << endl;
    pat22(n);
}