#include <iostream>
#include <string> 
#include <vector>

using std::vector;
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long pisano_period(long long m) {
    long long i = 2;
    long long j = 0;
    long long k = 1;
    while (true) {
        long long temp = j;
        j = k;
        k = (temp + k)%m;
        if (j == 0 && k == 1) {
            return i - 1;
        }
        i++;
    }
}


long long get_fibonacci_huge_fast(long long n, long long m) {
    
    if (n > m){
        long long period = pisano_period(m);
        n = n%period;
      //  std::cout << "Period: " << std::to_string(period) << "\n";
      //  std::cout << "N: " << std::to_string(n) << "\n";
        
    }

    /*long long previous = 0;
    long long current  = 1;
    for (long long i = 2; i < n + 1; i++) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }
*/
    if (n<=1) 
        return n;
    long long a = 0;
    long long b = 1;
    for (long long i = 2; i < n + 1; i++) {
        long long c = a;
        a = b;
        b = (b + c)%m;
    }
    return b % m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
