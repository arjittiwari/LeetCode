#define MAX_FROG 100000
#define MAX_SOUND 5
#define FAILURE -1
int frogCount[MAX_FROG];
int count =0,freed=0;
bool checkSound(int sound){
    // printf("\n sound is %d with count %d",sound,count);
    if (sound==0) {
        if (freed == 0){
            count++;
        } else {
            freed--;
        }
        frogCount[sound]++;
        // printf("\ninc %d with count %d and freed %d",sound, count, freed);
        return(true);
    } else if (sound == MAX_SOUND -1) {
        if (frogCount[sound-1]<=0) {
            printf("\nfail1");
            return(false);
        } else {
            frogCount[sound-1]--;
            // printf("\nfrog sound at %d is %d with count %d",sound,frogCount[sound],count);
            freed++;
            return(true);
        }
    }
    if (frogCount[sound-1]<=0) {
        printf("\nfail2 sound at %d is %d",sound-1,frogCount[sound-1]);
        return(false);
    } else {
        frogCount[sound-1]--;
        frogCount[sound]++;
    }
    // printf("\nfrog sound at %d is %d",sound,frogCount[sound]);
    return(true);
}
int minNumberOfFrogs(char* croakOfFrogs) {
    int i =0,val=0;
    count=0;
    freed=0;
    memset(frogCount,0,sizeof(int)*MAX_FROG);
    // i=0;
    // while (i<MAX_FROG){
    //     printf(" %d",frogCount[i]);
    //     i++;
    // }
    // i=0;
    while (i < strlen(croakOfFrogs)) {
        switch (croakOfFrogs[i]) {
            case 'c':
                val = 0;
                break;
            case 'r':
                val = 1;
                break;
            case 'o':
                val = 2;
                break;
            case 'a':
                val = 3;
                break;
            case 'k':
                val = 4;
                break;
            case 'default':
                return(FAILURE);
        }
        // printf("\ncount check %d",count);
        if (!checkSound(val)) {
            // printf("\n%d",val);
            return(FAILURE);
        }
        i++;
    }
    printf("\nreached here");
    printf("\n");
    i=0;
    while (i<MAX_FROG){
        // printf(" %d",frogCount[i]);
        i++;
    }
    printf("\n");
    i=0;
    val=0;
    while (i < MAX_FROG) {
        if (frogCount[i]>0) {
            return(FAILURE);
        }
        i++;
    }
    return(count);
}