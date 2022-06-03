#include <stdio.h>
#include <string.h>
#include "include/Structure.h"
#include "include/ReadFile.h"

Structure readFileTest(Structure logList, int logNum) {
    FILE *p = fopen("generated.log", "r");
    if(p == NULL)
    {
        printf("the file is close!");
        return logList;
    }
    int temp = 0;
    char str1[200], str2[200], str3[200], str4[200], str5[200], 
        str6[200], str7[200], str8[200], str9[200], str10[200];
    // int status = fscanf(p, "%s %s %s %s %s %s %s %s %s %s", str1, 
    //     str2, str3, str4, str5, str6, str7, str8, str9, str10); 
    int status;
    // while(!feof(p))
    while (temp < logNum)
    {
        status = fscanf(p, "%s %s %s %s %s %s %s %s %s %s", str1, 
        str2, str3, str4, str5, str6, str7, str8, str9, str10);
        strcpy(logList.s1[temp], str1);
        strcpy(logList.s2[temp], str3);
        char strTemp[400] = "";
        strcat(strTemp, str4);
        strcat(strTemp, " ");
        strcat(strTemp, str5);
        strcpy(logList.s3[temp], strTemp);
        logList.n = temp;
        // saveLogList(logList, temp, str1, str3, str4, str5);
        // printf("%s %s %s %s %s %s %s %s %s %s status = %d\n", str1,
        //  str2, str3, str4, str5, str6, str7, str8, str9, str10, status);
        // printf("%s, %s, %s are saved successfully!\n", logList.s1[temp], 
        //     logList.s2[temp], logList.s3[temp]);
        temp++; 
    }
    fclose(p);
    return logList;
// ————————————————
// 版权声明：本文为CSDN博主「dlpmmk」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/dlpmmk/article/details/123689664
}

// void saveLogList(Structure logList, int temp, char *str1, char *str2, 
//         char *str3, char *str4) {
//     strcpy(logList.s1[temp], str1);
//     strcpy(logList.s2[temp], str2);
//     char strTemp[400] = "";
//     strcat(strTemp, str3);
//     strcat(strTemp, " ");
//     strcat(strTemp, str4);
//     strcpy(logList.s3[temp], strTemp);
//     logList.n = temp;
//     // printf("%s, %s, %s are saved successfully!\n", logList.s1[temp], 
//             // logList.s2[temp], logList.s3[temp]);
// }