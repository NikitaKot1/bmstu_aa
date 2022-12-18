#include "incterface.h"

void logging(*queue qu) {
    auto l = qu->queue;
    auto start = l[0].start_generate;

    cout << "STARTING TIME\n\n";
    cout << "|N|Генерация|Умножение|Запись|\n";
    for (int i = 0; i < l.size(); i++) {
        cout << "|" << i << "|" << l[i].start_generate << "|" << l[i].start_mul << "|" << l[i].start_write << "|\n";
    }

    cout << "FINISHING TIME\n\n";
    cout << "|N|Генерация|Умножение|Запись|\n";
    for (int i = 0; i < l.size(); i++) {
        cout << "|" << i << "|" << l[i].stop_generate << "|" << l[i].stop_mul << "|" << l[i].stop_write << "|\n";
    }
}