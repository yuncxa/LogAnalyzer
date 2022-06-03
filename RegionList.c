#include "include/Structure.h"
#include "include/RegionList.h"
#include "include/IPLocator.h"
#include <stdio.h>
#include <string.h>

void generateRegionline(Structure logList, int logNum) {
    Structure regionline = newStructure(0);
    unsigned int start_ip,end_ip;
	unsigned char addr[256];
    get_ip_addr(str2ip(logList.s1[0]), addr, 256, &start_ip, &end_ip);
    // printf("This IP %s belongs to %s\n",logList.s1[0], addr);
    strcpy(regionline.s1[0], addr);
    regionline.n = 1;
    regionline.num[0] = 1;
    for (int i = 1; i < logNum; i++) {
        int flag = 0;
        get_ip_addr(str2ip(logList.s1[i]), addr, 256, &start_ip, &end_ip);
        // printf("This IP %s belongs to %s\n",logList.s1[0], addr);
        for (int j = 0; j < regionline.n; j++) {
            if (!strcmp(regionline.s1[j], addr)) {
                regionline.num[j]++;
                flag = 1;
                break;
            }
        }
        if (!flag) {
            strcpy(regionline.s1[regionline.n], addr);
            regionline.num[regionline.n] = 1;
            regionline.n++;   
        }
    }
    printRegionline(regionline);
}

void printRegionline(Structure regionline) {
    printf("access num\t\tregion\n");
    for (int i = 0; i < regionline.n; i++) {
        printf("%d\t\t%s\t%d\n", regionline.num[i], regionline.s1[i], i);
    }
}