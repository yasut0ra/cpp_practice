#include <iostream>
#include <string>
#include <utility>

using namespace std;

/*
    このファイルで学ぶこと:
      - template function
      - template class
      - 型をあとから決める書き方

    入力:
      a b word

    ミニ入力例:
      3 7 hello

    ミニ出力例:
      max_value: 7
      sum_value: 10
      holder_value: hello
*/

template <class T>
T max_value(const T& left, const T& right) {
    return (left < right ? right : left);
}

template <class T>
T add_values(const T& left, const T& right) {
    return left + right;
}

template <class T>
class Holder {
public:
    explicit Holder(T value) : value_(std::move(value)) {}

    const T& get() const {
        return value_;
    }

private:
    T value_;
};

int main() {
    int a, b;
    string word;
    cin >> a >> b >> word;

    Holder<string> holder(word);

    cout << "max_value: " << max_value(a, b) << '\n';
    cout << "sum_value: " << add_values(a, b) << '\n';
    cout << "holder_value: " << holder.get() << '\n';
    return 0;
}
