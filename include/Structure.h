#ifndef _STRUCTURE_H
#define _STRUCTURE_H

// const int MAXNUM = 1010;
typedef struct Structure {
    char s1[1010][50];
    char s2[1010][50];
    char s3[1010][50];
    char s4[1010][50];
    int n;
    int num[1010];
} Structure;
Structure newStructure(int n);

#endif