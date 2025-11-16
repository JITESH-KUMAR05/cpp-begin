
while(i<n){
    cnt = 1;
    while(i+1<n && arr[i+1]>=arr[i]){
        i++;
        cnt++;
        c+=cnt;
    }
    i++;
    c++;
}