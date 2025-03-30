#define MAX_FROG 100000
#define MAX_SOUND 5
#define FAILURE -1
int frogCount[MAX_FROG];
int count =0,freed=0;
bool checkSound(int sound){
    if (sound==0) {
        if (freed == 0){
            count++;
        } else {
            freed--;
        }
        frogCount[sound]++;
        return(true);
    } else if (sound == MAX_SOUND -1) {
        if (frogCount[sound-1]<=0) {
            return(false);
        } else {
            frogCount[sound-1]--;
            freed++;
            return(true);
        }
    }
    if (frogCount[sound-1]<=0) {
        return(false);
    } else {
        frogCount[sound-1]--;
        frogCount[sound]++;
    }
    return(true);
}
int minNumberOfFrogs(char* croakOfFrogs) {
    int i =0,val=0;
    count=0;
    freed=0;
    memset(frogCount,0,sizeof(int)*MAX_FROG);
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
        if (!checkSound(val)) {
            return(FAILURE);
        }
        i++;
    }
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