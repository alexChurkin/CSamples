#include "D:\Projects\CVSCode\easyoutput.h"
#include <string.h>

int main() {
    float one = 1.0f;
    float two = 2.0f;
    println("Hey!");
    printInt(123);
    ln();
    printFloat(one + two);
    ln();
    printDouble(321.123);
    ln();
    char firststr[] = "123_";
    char secondstr[] = "_321";
    println(strcat(firststr, secondstr));
    return 0;
}