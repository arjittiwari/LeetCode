bool isAnagram(char* s, char* t) {
   int count[26] = {0}, i =0;
   while (s[i] != '\0' && t[i] != '\0') {
    count[(int)s[i]-97]++;
    count[(int)t[i]-97]--;
    i++;
   }
   if (s[i] != '\0' || t[i] != '\0') {
    return(false);
   }
   i = 0;
   while(i < 26) {
    if (count[i] !=0) {
        return(false);
    }
    i++;
   }
   return(true);

}