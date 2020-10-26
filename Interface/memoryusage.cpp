#include "memoryusage.h"

MemoryUsage::MemoryUsage()
{
}
int MemoryUsage::parseLine(char* line){
    // This assumes that a digit will be found and the line ends in " Kb".
    int i = strlen(line);
    const char* p = line;
    while (*p <'0' || *p > '9') p++;
    line[i-3] = '\0';
    i = atoi(p);
    return i;
}

QString MemoryUsage::getValue(){ //Note: this value is in KB!
    FILE* file = fopen("/proc/self/status", "r");
    int resultInt = -1;
    char line[128];

    while (fgets(line, 128, file) != NULL){
        if (strncmp(line, "VmSize:", 7) == 0){
            resultInt = parseLine(line);
            break;
        }
    }
    fclose(file);

    QString resultStr;
    resultStr.setNum(resultInt);
    emit valueChanged(resultStr+" KB");
    return resultStr+" KB";
}
