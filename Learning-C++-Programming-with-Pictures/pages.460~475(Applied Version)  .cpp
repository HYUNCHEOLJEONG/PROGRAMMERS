#include<iostream>
#include<iterator>
using namespace std;
class Point {
private:
    int x, y;

public:
    // 기본 생성자
    Point() : x(0), y(0) {}

    // 매개변수 생성자
    Point(int a, int b) : x(a), y(b) {}

    // 복사 생성자
    Point(const Point& other) {
        x = other.x;
        y = other.y;
    }

    // 대입 연산자 오버로딩
    Point& operator=(const Point& other) {
        if (this == &other) return *this; // 자기 자신을 대입하는 경우 방지
        x = other.x;
        y = other.y;
        return *this;
    }

    // 덧셈 연산자 오버로딩 (Point + Point)
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // 뺄셈 연산자 오버로딩 (Point - Point)
    Point operator-(const Point& other) const {
        return Point(x - other.x, y - other.y);
    }

    // 곱셈 연산자 오버로딩 (Point * 숫자)
    Point operator*(int scalar) const {
        return Point(x * scalar, y * scalar);
    }

    // 곱셈 연산자 오버로딩 (Point * Point) - 좌표끼리 곱하는 경우
    Point operator*(const Point& other) const {
        return Point(x * other.x, y * other.y);
    }

    // 비교 연산자 오버로딩 (Point == Point)
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    // 출력 스트림 연산자 오버로딩 (cout << Point)
    friend ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    Point p1(3, 7);
    Point p2(5, 2);
    Point p3;
    // 대입 연산
    p3 = p1;
    cout << "p3 after assignment: " << p3 << endl;
    // 덧셈 연산 (Point + Point)
    Point sum = p1 + p2;
    cout << "Sum: " << sum << endl;
    // 뺄셈 연산 (Point - Point)
    Point diff = p1 - p2;
    cout << "Difference: " << diff << endl;
    // 스칼라 곱 (Point * 숫자)
    Point scaled = p1 * 2;
    cout << "Scaled (p1 * 2): " << scaled << endl;

    // 좌표별 곱셈 (Point * Point)
    Point multiplied = p1 * p2;
    cout << "Multiplied (p1 * p2): " << multiplied << endl;

    // 비교 연산 (==)
    cout << "p1 == p2? " << (p1 == p2 ? "True" : "False") << endl;
    cout << "p1 == p3? " << (p1 == p3 ? "True" : "False") << endl;

    return 0;
}