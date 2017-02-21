#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n){
    if (n <= 1)
        return n;

    int a = 0;
    int b = 1;
    for (int i = 2; i <= n; i++) {
        int c = (a + b)%10;
        a = b;
        b = c;
    }
    return b;
}


int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    }
