class Solution {
    private int getTargetsCount(int[] numbers, int target, int here, int index) {
        if (index == numbers.length) {
            if (here == target) return 1;
            return 0;
        }
            
        int result = 0;
        result += getTargetsCount(numbers, target, here + numbers[index], index + 1);
        result += getTargetsCount(numbers, target, here - numbers[index], index + 1);
        return result;
    }
    
    public int solution(int[] numbers, int target) {
        int answer = getTargetsCount(numbers, target, 0, 0);
        return answer;
    }
}