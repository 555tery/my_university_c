//
// Created by Egor Kapov on 09.11.2023.
//
#include "stdio.h"

typedef struct DateTime_s {
    int year, month, day;
    int hours, minutes, seconds;
} DateTime;

DateTime min(const DateTime *arr, int cnt) {
    DateTime min = arr[0];
    for (int i = 0; i < cnt; ++i) {
        if (arr[i].year < min.year) {
            min = arr[i];
        } else if (arr[i].year == min.year) {
            if (arr[i].month < min.month) {
                min = arr[i];
            } else if (arr[i].month == min.month) {
                if (arr[i].day < min.day) {
                    min = arr[i];
                } else if (arr[i].day == min.day) {
                    if (arr[i].hours < min.hours) {
                        min = arr[i];
                    } else if (arr[i].hours == min.hours) {
                        if (arr[i].minutes < min.minutes) {
                            min = arr[i];
                        } else if (arr[i].minutes == min.minutes) {
                            if (arr[i].seconds < min.seconds) {
                                min = arr[i];
                            }
                        }
                    }
                }
            }
        }
    }
    return min;
}

    int MinimalDate() {
        int number_of_dates = 0;
        DateTime arr[50010];
        DateTime min_date;
        scanf("%d", &number_of_dates);
        for (int i = 0; i < number_of_dates; ++i) {
            scanf("%d%d%d%d%d%d", &arr[i].year, &arr[i].month, &arr[i].day, &arr[i].hours, &arr[i].minutes,
                  &arr[i].seconds);
        }
        min_date = min(arr, number_of_dates);
        printf("%d %d %d %d %d %d", min_date.year, min_date.month, min_date.day, min_date.hours, min_date.minutes,
               min_date.seconds);
    }