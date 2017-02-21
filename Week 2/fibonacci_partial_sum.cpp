#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
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

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    int a = (get_fibonacci_last_digit_fast((from-1+2)%60)-1)%10; // last digit of first `from - 1` series
    // std::cout << "a is " << std::to_string(a) << "\n";
    int b = (get_fibonacci_last_digit_fast((to+2)%60)-1)%10; // partial_sum = (b - a)'s last digit
    // std::cout << "b is " << std::to_string(b) << "\n";
    return (b-a+20) % 10;
}


int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
