#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long fib(long long f[], long long n)
{
    f[0] = 0;
    f[1] = 1;
 
    for (long long i = 2; i <= n; i++)
        f[i] = (f[i-1] + f[i-2])%10;
 
    return f[n];
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

long long fibonacci_sum_fast(long long n){
    int a = get_fibonacci_last_digit_fast((n+2)%60);
    if (a == 0) {
        a = 9;
    } else {
        a--;
    }
    return a;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
}
