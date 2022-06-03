#include "include/Structure.h"
// const int MAXNUM = 1010;
// typedef struct Structure {
//     char s1[MAXNUM][256];
//     char s2[MAXNUM][256];
//     char s3[MAXNUM][256];
//     char s4[MAXNUM][256];
//     int n;
//     int num[MAXNUM];
// } Structure;

Structure newStructure(int n) {
    Structure a;
    a.n = n;
    return a;
}

