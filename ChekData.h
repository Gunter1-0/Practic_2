#ifndef _ADD_H
#define _ADD_H
#include <stdbool.h>
    //Проверяет размер строки 
    //перед присвоением строке 
    //с ограниченным размером
    bool chekStringSize(char *str[]);
    //Проверяет размер строки числом типа long
    bool chekLongNumberSize(char *str[]);
    //Проверяет размер строки числом типа int
    bool chekIntNumberSize(char *str[]);
    //Считает длину строки
    int sizeOfString(char number[4096]);
#endif