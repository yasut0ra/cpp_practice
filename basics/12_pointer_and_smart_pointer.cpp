#include <iostream>
#include <memory>

using namespace std;

/*
    このファイルで学ぶこと:
      - pointer の基本
      - * と & の意味
      - unique_ptr
      - smart pointer で所有権を管理する考え方

    入力:
      a b

    ミニ入力例:
      10 20

    ミニ出力例:
      pointed_values: 10 20
      after_increment: 11 21
      sum_after_increment: 32
*/

void increment(int* value) {
    ++(*value);
}

int main() {
    int a, b;
    cin >> a >> b;

    int* raw_pointer = &a;
    unique_ptr<int> smart_pointer = make_unique<int>(b);

    cout << "pointed_values: " << *raw_pointer << ' ' << *smart_pointer << '\n';

    increment(raw_pointer);
    increment(smart_pointer.get());

    cout << "after_increment: " << a << ' ' << *smart_pointer << '\n';
    cout << "sum_after_increment: " << a + *smart_pointer << '\n';
    return 0;
}
