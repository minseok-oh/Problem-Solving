class Solution {
    final int MAX = 10000000;
    private boolean[] visited = {false, false, false, false, false, false, false};
    private boolean[] isPrime = new boolean[MAX];
    private boolean[] isCount = new boolean[MAX];
    
    private void initPrime() {
        for (int i = 0; i < MAX; i++) {
            isPrime[i] = true;
            isCount[i] = false;
        }
        
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < MAX; i++) {
            if (isPrime[i]) {
                for (int j = 2; i * j < MAX; j++) {
                    isPrime[i * j] = false;
                }
            }
        }
    }
    
    private void getPrimeNumberCount(String numbers, String here) {
        if (here.length() != 0) {
            int value = Integer.valueOf(here);
            if (isPrime[value]) isCount[value] = true;
        }
        
        for (int i = 0; i < numbers.length(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            String next = here + numbers.charAt(i);
            getPrimeNumberCount(numbers, next);
            visited[i] = false;
        }
    }
    
    private int getCount() {
        int result = 0;
        for (int i = 0; i < MAX; i++) {
            if (isCount[i]) result++;
        }
        return result;
    }
    
    public int solution(String numbers) {
        initPrime();
        getPrimeNumberCount(numbers, "");
        int answer = getCount();
        return answer;
    }
}