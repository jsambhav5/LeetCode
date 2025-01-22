class Solution {
    public int countPrimes(int n) {
        boolean[] isPrime = new boolean[n];

        for (int i = 2; i < n; i++) {
            isPrime[i] = true;
        }

        for (int p = 2; p * p < n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i < n; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        int result = 0;
        for (int i = 1; i < n; i++) {
            if (isPrime[i]) {
                result++;
            }
        }

        return result;
    }
}
