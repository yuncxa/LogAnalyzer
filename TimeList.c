#include "include/Structure.h"
#include "include/TimeList.h"
#include <string.h>
#include <stdio.h>

void generateTimelist(Structure logList, int logNum) {
    Structure timeline = newStructure(0);
    strcpy(timeline.s1[0], logList.s3[0]);
    timeline.num[0] = 1;
    timeline.n = 1;
    for (int i = 1; i < logNum; i++) {
        int flag = 0;
        for (int j = 0; j < timeline.n; j++) {
            if (!strcmp(timeline.s1[j], logList.s3[i])) {
                timeline.num[j]++;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            strcpy(timeline.s1[timeline.n], logList.s3[i]);
            timeline.num[timeline.n] = 1;
            timeline.n++;   
        }
    }
    printTimeline(timeline);
}
void printTimeline(Structure timeline) {
    printf("access num\t\ttime\n");
    for (int i = 0; i < timeline.n; i++) {
        printf("%d\t\t%s\t%d\n", timeline.num[i], timeline.s1[i], i);
    }
}