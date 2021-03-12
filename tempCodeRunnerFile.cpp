int countPrimes(int n) {
        if (n <= 1) {
            return 0;
        }
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[mul] = false;
                }
            }
        }
        return count_if(isPrime.begin(), isPrime.end(), [&](bool a){return a;});
    }