import matplotlib.pyplot as plt


damlevrec = [0.199, 0.235, 0.404, 0.596, 1.766, 7.747, 43.69, 263.9, 1281.0, 7181.0]
damlevcash = [0.726, 0.876, 1.126, 1.407, 1.763, 2.200, 2.605, 3.273, 3.892, 4.573]
damlevmatr = [0.585, 0.770, 0.879, 1.328, 1.385, 1.617, 1.782, 2.476, 2.845, 3.379]
levmatr = [0.575, 0.768, 0.873, 1.218, 1.273, 1.602, 1.697, 2.449, 2.651, 3.155]

tm = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

plt.figure(1)

plt.plot(tm, damlevcash, label='Д.-Л., алгоритм рекурсивный без кеша')
plt.plot(tm, damlevrec, label='Д.-Л., алгоритм рекурсивный c кешем')
plt.legend()
plt.grid()
plt.title("Временные характеристики алгоритмов вычисления расстояния")
plt.ylabel("Затраченное время (мск)")
plt.xlabel("Длина (символы)")

plt.show()

# plt.figure(1)

# plt.plot(tm, levmatr, label='Л., алгоритм матричный')
# plt.plot(tm, damlevmatr, label='Д.-Л., алгоритм матричный')
# plt.legend()
# plt.grid()
# plt.title("Временные характеристики алгоритмов вычисления расстояния")
# plt.ylabel("Затраченное время (мск)")
# plt.xlabel("Длина (символы)")

# plt.show()

# plt.figure(1)

# plt.plot(tm, damlevcash, label='Д.-Л., алгоритм рекурсивный с кешем')
# plt.plot(tm, damlevmatr, label='Д.-Л., алгоритм матричный')
# plt.legend()
# plt.grid()
# plt.title("Временные характеристики алгоритмов вычисления расстояния")
# plt.ylabel("Затраченное время (мск)")
# plt.xlabel("Длина (символы)")

# plt.show()