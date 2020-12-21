#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<string.h>
#include"Trains.h"

// typedef struct Train Train;
//   struct Train
//   {
//     long index;
//     char station[4096];
//     long trainNumber;
//     int countOfCar;
//     char trainType[4096];
//     char destination[4096];
//     struct Train * next;    
//   };
//Считывает ввод с клавиатуры и
//создаёт новую ячейку списка 
Train* makeRecord(){
    Train *t = allocate();              //Возвращаемый элемент
    t->next = NULL;                     //Заполнение указателя
    char stationName[4096];             //Название станции
    long trainNumber;                   //Номер поезда
    int countOfCars;                    //Количество вагонов
    char trainType[4096];               //Тип поезда
    char destination[4096];             //Пункт назначения
    int res1, res2, res3, res4, res5;   //Коды ошибок/успеха

    printf("Введите название станции: ");
    res1 = scanf("%s", stationName);
    
    printf("Введите номер поезда: ");
    res2 = scanf("%ld", &trainNumber);
    
    printf("Введите количество вагонов: ");
    res3 = scanf("%d", &countOfCars);
    
    printf("Введите тип поезда: ");
    res4 =scanf("%s", trainType);
    
    printf("Введтите пункт назначения: ");
    res5 = scanf("%s", destination);
    
    if(res1 == EOF && res2 == EOF && res3 == EOF && res4 == EOF && res5 == EOF){
    
        perror("\nError is EOF: \n");
        return NULL;
    }
    else if(res1 != 1 && res2 != 1&& res3 != 1&& res4 != 1&& res5 != 1)
    {
        perror("\nError: \n");
        return NULL;
    }
    else{
        strcpy(t->station, stationName);
        t->trainNumber = trainNumber;
        t->countOfCar=countOfCars;
        strcpy(t->trainType, trainType);
        strcpy(t->destination, destination);
    }
    return t;
}

//Добавление нового эелемента
//в список
Train* addElement(Train* list, Train* el){ return add(list, el);}
//Вывод всех элементов
void showAll(Train* list){
    if(list == NULL) {printf("\nСписок пустой\n"); return;}
    while (list!=NULL)
    {
        printf("%ld. ", list->index+1);
        printf("%s ", list->station);
        printf("%ld ", list->trainNumber);
        printf("%d ", list->countOfCar);
        printf("%s ", list->trainType);
        printf("%s\n", list->destination);
        list = list->next;
    }
    
}
//
//Удаляет элемент списка
    Train* deleteElement(Train* list){
        int res;
        int number;
        printf("Номер записи: ");
        res = scanf("%d",&number);
        if(res == EOF)perror("\nError EOF: \n");
        else if(res!=1) perror("\nError: res!= 1\n");
        else list = deleteAt(list, (long)number-1); //Передаём индекс в списке
        
        return list;
    }
