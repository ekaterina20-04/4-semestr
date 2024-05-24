#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Дана лекционная аудитория, в которой несколько профессоров хотят прочесть свои лекции. Для составления расписания
профессора подали заявки, вида [si,fi) – время начала и конца лекции. Лекция считается открытым полуинтервалом, то 
есть какая-то лекция может начаться в момент окончания другой, без перерыва. Составьте расписание занятий так, чтобы
выполнить максимальное количество заявок.
Входные данные 
В первой строке вводится натуральное число N, не более 1000 – общее количество заявок. Затем вводится N строк с 
описаниями заявок - по два числа в каждом si и fi.
Гарантируется, что si<fi<. Время начала и окончания лекции – натуральное число, не превышает 
1440 (в минутах с начала суток :) )
Выходные данные
Выведите одно число – максимальное количество заявок, которые можно выполнить.*/

/*Пример: Input:
3 - n (число заявок)
1 5 - заявки
2 3
3 4
Output:
2 - максимальное число заявок*/

struct Lecture {
    int start;
    int end;
};

bool compareLectures(const Lecture& a, const Lecture& b) {
    return a.end < b.end;
}

int main() {
    int N;
    cin >> N;

    vector<Lecture> lectures(N);
    for (int i = 0; i < N; i++) {
        cin >> lectures[i].start >> lectures[i].end;
    }

    sort(lectures.begin(), lectures.end(), compareLectures);

    int maxLectures = 1;
    int endTime = lectures[0].end;

    for (int i = 1; i < N; i++) {
        if (lectures[i].start >= endTime) {
            maxLectures++;
            endTime = lectures[i].end;
        }
    }

    cout << maxLectures << endl;

    return 0;
}