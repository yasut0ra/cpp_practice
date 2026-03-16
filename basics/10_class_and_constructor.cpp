#include <iostream>

using namespace std;

/*
    このファイルで学ぶこと:
      - class の基本
      - constructor で初期値を入れる方法
      - member function
      - private なデータを外から隠す考え方

    入力:
      width height scale_factor

    ミニ入力例:
      3 4 2

    ミニ出力例:
      initial_area: 12
      initial_perimeter: 14
      scaled_area: 48
*/

class Rectangle {
public:
    Rectangle(int width, int height) : width_(width), height_(height) {}

    int area() const {
        return width_ * height_;
    }

    int perimeter() const {
        return 2 * (width_ + height_);
    }

    void scale(int factor) {
        width_ *= factor;
        height_ *= factor;
    }

private:
    int width_;
    int height_;
};

int main() {
    int width, height, scale_factor;
    cin >> width >> height >> scale_factor;

    Rectangle rect(width, height);
    cout << "initial_area: " << rect.area() << '\n';
    cout << "initial_perimeter: " << rect.perimeter() << '\n';

    rect.scale(scale_factor);
    cout << "scaled_area: " << rect.area() << '\n';
    return 0;
}
