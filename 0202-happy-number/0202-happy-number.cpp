class Solution {
public:
    bool isHappy(int n) {
        auto getNext = [](int number) {
            int total = 0;
            while (number > 0) {
                int digit = number % 10;
                total += digit * digit;
                number /= 10;
            }
            return total;
        };

        int slow = n, fast = getNext(n);
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }
};
