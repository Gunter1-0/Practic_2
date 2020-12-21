//1. Цель работы: практическое закрепление знаний об инструментальных средствах, используемых при разработке про-
// грамм в среде Linux
// 2. Порядок выполнения:
// (a) в процессе разработки используйте средство контроля версий git, средство отслеживания ошибок (bitbucket.org);
// (b) напишите программу в соответствии с вашим вариантом, разбив ее на различные исходные файлы (не менее
// трех исходных файлов);
// (c) осуществите компиляцию с использованием транслятора и редактора связей gcc, а также программы автомати-
// зации сборки make (Makefile необходимо написать грамотно, чтобы перекомпиляция исходных файлов осуществ-
// лялась только в той части, что изменилась)
// (d) осуществите статический анализ кода с использованием средства cppcheck (используйте опцию --enable=all).
// Исправьте найденные недочеты в вашей программе или подготовьте объяснение того, почему исправление неко-
// торых недочетов не требуется. Включите в отчет скриншоты результатов статического анализа до и после ис-
// правлений. Если изначально не было найдено замечаний, то второй скриншот не требуется.
// (e) осуществите UNIT-тестирование нескольких подпрограмм с помощью [check]https://libcheck.github.io/check/ или
// аналогичного средства. Тестовый набор должен содержать минимум 10 отдельных тестов для минимум трех
// отдельных подпрограмм. Для запуска UNIT-теста создайте соответствующую цель в Makefile.
// (f) осуществите подготовку профиля работы вашей программы (время выполнения и частота вызова каждой подпро-
// граммы) с использованием valgrind и какого-либо средства для демонстрации результатов его работы (например,
// kcachegrind).
// (g) осуществите подготовку распространяемого пакета с использованием autotools (см. http://blablacode.ru/linux/
// 500). В результате у вас должны работать все обычные цели make, включая dist.
// (h) подготовьте документацию вашего продукта с использованием wiki, встроенном в bitbucket.
//
//
// Напишите файловую базу данных, управляемую в консольном интерактивном режиме (квазиоконный интерфейс де-
// лать не нужно) с возможностями: добавление, удаление, изменение информации соответственно вашему варианту (на
// языке С). Необходимо осуществить проверку всех возможных ошибок в части некорректных действий пользователя
// и при работе с файлами.
//
//Напишите файловую базу данных, управляемую в консольном интерактивном режиме (квазиоконный интерфейс де-
// лать не нужно) с возможностями: добавление, удаление, изменение информации соответственно вашему варианту (на
// языке С). Необходимо осуществить проверку всех возможных ошибок в части некорректных действий пользователя
// и при работе с файлами.
//8 База данных электричек, поля: вокзал, номер поезда, количество вагонов, тип (экспресс/обычный/спутник),
//станция назначения.
//
//
//
//allocate() Выделение памяти под тип Train  
//goToEnd() Перемещает каретку на последний элемент списка
//lastButOne() Перемещает каретку на предпоследний элемент списка
//goHere() Перемещает указатель в позицию n
//add() Добавляет в конец элемент списка
//count() Считает количество элементов
//daletAt() Удалет элемент в позиции n из списка list
//insertTo() Добавляет элемент в позицию n
//createTrain() Создание нового элемента
//chekStringSize() Проверяет размер строки перед присвоением строке с ограниченным размером
//chekLongNumberSize() Проверяет размер строки числом типа long
//chekIntNumberSize() Проверяет размер строки числом типа int
//sizeOfString() Считает длину строки
//makeRecord() Считывает ввод с клавиатуры и создаёт новую ячейку списка 
//
//
#include"RManager.h"
#include"ChekData.h"
#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Trains.h"

void helper(){
    printf("1. Добаить \n");
    printf("2. Изменить\n");
    printf("3. Удалить\n");
    printf("4. Вывести всё\n");
    printf("5. Справка\n");
    printf("0. Выход \n");    
}

int main(){
    int ch;
    Train* list = NULL;
    Train* el;
    helper();
    do{
        printf("Введите число: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:{/*Добавить*/
            el = makeRecord();
            if(el!=NULL)list = addElement(list, el);
            else printf("\nНекорректный ввод\n");            
        }
            break;
        case 2:/*Изменить*/

            break;
        case 3:/*Удалить*/
            list = deleteElement(list);
            break;
        case 4:/*Вывести всё*/
            showAll(list);
            break;
        case 5: /*Подсказка*/
            helper();
            break;
        case 0: /*Выход*/
            break;    
        default:
            printf("\nВведено неправильное число\n");
            break;
        }    
    }while(ch!=0);
    
    return 0;
}
