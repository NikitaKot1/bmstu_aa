import matplotlib.pyplot as plt
fig1 = plt.figure(figsize=(10, 7))
plot = fig1.add_subplot()
values = [1, 2, 3, 4, 5, 6, 7]
very_short = [1, 5/6, 1/6, 0, 0, 0, 0]
short = [2/6, 1, 3/6, 1/6, 0, 0, 0]
average = [0, 3/6, 1, 1/6, 0, 0, 0]
high = [0, 0, 0, 1/6, 1, 3/6, 2/6]
very_high = [0, 0, 0, 0, 2/6, 1, 4/6]
vv = [0, 0, 0, 0, 2/6, 5/6, 1]

def expert_opinion(feature):
    if feature == 'пара норок':
        return 1
    elif feature == '':
        return 2
    elif feature == '':
        return 3
    elif feature == '':
        return 4
    elif feature == '':
        return 5
    elif feature == '':
        return 6
    return None

plot.plot(values, very_short, label = "«пара норок»")
plot.plot(values, short, ":", label="«земляное решето»", marker="o")
plot.plot(values, average, "--", label="«куча»", marker="v")
plot.plot(values, high, "--", label="«пара кучек»", marker="^")
plot.plot(values, very_high, "--", label="«большая куча»", marker="s")
plot.plot(values, vv, "--", label="«гора ужаса»", marker="*")

plt.legend()
plt.grid()
plt.title("Графики функций принадлежности числовых значений \nпеременной термам, описывающим группы значений лингвистической переменной")
plt.ylabel("μ")
plt.xlabel("размер муравейника, муравьев: 10^x")

plt.show()