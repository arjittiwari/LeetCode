#define TotalChar 26
bool checkInclusion(char* s1, char* s2) {
    int count[TotalChar]={0};
    int j, sum=0;
    if (strlen(s1) > strlen(s2)) {
        return(false);
    }
    if (strlen(s2) == 1) {
        if (s1[0]==s2[0]) {
            return(true);
        } else {
            return(false);
        }
    }
    for (int i=0;i<=strlen(s2)-strlen(s1);i++) {
        j=0;
        while (j<strlen(s1)) {
            count[s1[j]-'a']++;
            count[s2[i+j]-'a']--;
            j++;
        }
        j=0;
        while(j<TotalChar) {
            if(count[j]!=0) {
                break;
            }
            j++;
        }
        if (j == TotalChar) {
            return(true);
        }
        memset(count,0,TotalChar*sizeof(count[0]));
    }
    return(false);
}