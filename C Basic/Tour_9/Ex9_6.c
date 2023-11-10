//
// Created by Egor Kapov on 09.11.2023.
//
#include <stdio.h>

typedef struct List { // созадем структуру списка
    char value[8]; // значение в ячейке(узле) (строки в нашем слкучае)
    int next; // индекс (в общем массиве) следующего за ним в списке
} List;


int OneConnectedList() {
    List arr[200010]; // создаем массив пар чар-инт
    int test_numbers, current_elements_number, first_elem_index, operation_number, operation, index; // переменные
    scanf("%d", &test_numbers); // сканируем колво тестов
    for (int j = 0; j < test_numbers; j++) { // запускаем тест
        scanf("%d%d%d", &current_elements_number, &first_elem_index, &operation_number); // сканим начальные данные списка
        for (int i = 0; i < current_elements_number; i++) { // сканим начальные элементы списка в массив типа лист
            scanf("%s%d", arr[i].value, &arr[i].next);
        }
        for (int i = 0; i < operation_number; i++) { // добавляем/убираем
            scanf("%d%d", &operation, &index); // сканируем тип операции и индекс, после которого применяем
            if (operation == 1) { // если это удаление узла
                if (index == -1) { // если элемент первый
                    printf("%s\n", arr[first_elem_index].value); // принтим значение первого элпемента в списке(не в массиве)
                    first_elem_index = arr[first_elem_index].next; // первым становится тот, который был после него
                } else { // иначе
                    printf("%s\n", arr[arr[index].next].value); // принтим значение следующего(после не первого)
                    arr[index].next = arr[arr[index].next].next; // теперь следующий равен следущему за тем, который мы удалили
                }
            } else { // если это добавление, а не удаление
                scanf("%s", arr[current_elements_number].value); // сканим новый жлемент в ячейку массива с индексом текущего колва элементов
                printf("%d\n", current_elements_number); // принтим индекс, в который записан новый желемент
                if (index == -1) { // если вставляем в начало
                    arr[current_elements_number].next = first_elem_index; // втыкаем хлемент в коннец массива присваивая ему в некст индекс элемента, который был первым
                    first_elem_index = current_elements_number; // и теперь связываем последний индекс массива, делая его первым в списке
                } else { // если вставляем не в начало
                    arr[current_elements_number].next = arr[index].next; // присваиваем последнему элементу в массиве некст того, индекс которго мы указали
                    arr[index].next = current_elements_number; // некст того, который указали равен индексу послежнего элемента массива?
                }
                current_elements_number++; // у нас увеличилось общее количество жлементов в масииве
            }
        }
        printf("===\n");// принтим конец теста
        for (int i = first_elem_index; i != -1; i = arr[i].next) { // идем по элементам списка(НЕ МАССИВА!!!)
            printf("%s\n", arr[i].value); // принтим значения списка
        }
        printf("===\n");// принтим конец теста
    }
    return 0;

}