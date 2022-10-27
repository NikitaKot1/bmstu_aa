from collections import defaultdict
from typing import DefaultDict

import algos
import random
import time

import matplotlib.pyplot as plt
#import streamlit as st
import pandas as pd

y_time_quick = []
y_time_shaker = []
y_time_count = []
len_arr = []

def test(len, tag):
    time_quick = 0
    time_shaker = 0
    time_count = 0

    for i in range(1, len + 1):
        for times in range(100):
            arr = []
            if (tag == 1):
                arr = [j for j in range(i * 100)]
            elif (tag == 2):
                arr = [j for j in range(i * 100, 0, -1)]
            else:
                arr = [random.randint(0, 1000) for j in range(i * 100)]


            arr1 = [arr[j] for j in range(i * 100)]
            arr2 = [arr[j] for j in range(i * 100)]
            arr3 = [arr[j] for j in range(i * 100)]

            start = time.process_time()
            algos.quick_sort(arr1)
            stop = time.process_time()
            time_quick += stop - start

            start = time.process_time()
            algos.shaker_sort(arr2)
            stop = time.process_time()
            time_shaker += stop - start

            start = time.process_time()
            algos.counting_sort(arr3)
            stop = time.process_time()
            time_count += stop - start
        len_arr.append(i * 100)
        y_time_count.append(time_count * 10000,)
        y_time_quick.append(time_quick * 10000,)
        y_time_shaker.append(time_shaker * 10000,)
        print("{:4d} & {:8.3f} & {:8.3f} & {:8.3f}\\\\\n\\hline".format(i * 100, time_count * 10000, time_quick * 10000, time_shaker * 10000))



if __name__ == "__main__":
    #test(100)

    alg_choices = '''Выбор пункта меню: 
1. Сортировка перемешиванием
2. Сортировка посчетом (только положительные целые числа)
3. Сортировка быстрая
4. Протестировать время'''
    print(alg_choices)
    tag = int(input())
    arr = []
    if (tag == 1 or tag == 2 or tag == 3) :
        print("Введите массив:")
        arr = [int(el) for el in input().split()]
    if (tag == 1):
        arr = algos.shaker_sort(arr)
    if (tag == 2):
        arr = algos.counting_sort(arr)
    if (tag == 3):
        arr = algos.quick_sort(arr)
    if (tag == 1 or tag == 2 or tag == 3) :
        print("Отсортированный массив:\n", arr)
    
    if (tag == 4):
        sort_choices ='''Выбор типа массива:
1. Отсортированный массив
2. Обратно отсортированный массив
3. Массив состоящий из случайных чисел'''
        print(sort_choices)
        tag2 = int(input())
        n = int(input("Введите максимальное количество элементов массива, деленое на 100\n"))
        test(n, tag2)

        plt.figure(1)
        plt.plot(len_arr, y_time_shaker, label = "Сортировка перемешиванием")
        plt.plot(len_arr, y_time_count, label = "Сортировка посчетом")
        plt.plot(len_arr, y_time_quick, label = "Быстрая сортировка")
        plt.legend()
        plt.grid()
        plt.title("Временные характеристики алгоритмов сортировки")
        plt.ylabel("Затраченное время (мкс)")
        plt.xlabel("Длина массива")
        plt.show()