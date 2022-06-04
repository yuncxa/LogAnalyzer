#include <stdio.h>
#include <string.h>
#include "include/Structure.h"
#include "include/ReadFile.h"
#include "include/TimeList.h"
#include "include/RegionList.h"

int main() {
    int logNum = 1000;
    Structure logList;
    // strcpy(logList.s1[0], "147.213.41.162");
    // strcpy(logList.s2[0], "macejkovic4607");
    // strcpy(logList.s3[0], "[01/Jun/2022:19:47:07 +0800]");
    
    
    logList = readFileTest(logList, logNum);
    // int temp = 1;
    // printf("%s, %s, %s are saved successfully!\n", logList.s1[temp], 
    //         logList.s2[temp], logList.s3[temp]);
    generateTimelist(logList, logNum);
    generateRegionline(logList, logNum);
    return 0;
}