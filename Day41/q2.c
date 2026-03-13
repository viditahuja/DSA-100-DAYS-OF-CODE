int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};

    for(int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    int maxFreq = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] > maxFreq) maxFreq = freq[i];
    }

    int maxCount = 0;
    for(int i = 0; i < 26; i++) {
        if(freq[i] == maxFreq) maxCount++;
    }

    int partCount = maxFreq - 1;
    int partLength = n - (maxCount - 1);
    int emptySlots = partCount * partLength;
    int availableTasks = tasksSize - maxFreq * maxCount;
    int idles = emptySlots - availableTasks;

    if(idles < 0) idles = 0;

    return tasksSize + idles;
}