class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Count required set bits from num2
        int required = __builtin_popcount(num2);
        // Count set bits in num1
        int current = __builtin_popcount(num1);
        // We start with x equal to num1.
        int x = num1;

        // If num1 has more 1-bits than required,
        // we need to remove some ones.
        if (current > required) {
            // Iterate from least significant bit to most significant.
            // Removing lower bits minimizes the XOR difference.
            for (int i = 0; i < 32 && current > required; i++) {
                if (x & (1 << i)) {
                    // Turn off the bit at position i.
                    x &= ~(1 << i);
                    current--;  // One less set bit.
                }
            }
        }
        // If num1 has fewer 1-bits than required,
        // we need to add some ones.
        else if (current < required) {
            // Again, iterate from least significant bit upward.
            // Adding bits in lower positions minimizes additional XOR cost.
            for (int i = 0; i < 32 && current < required; i++) {
                if (!(x & (1 << i))) {
                    // Set the bit at position i.
                    x |= (1 << i);
                    current++;  // One more set bit.
                }
            }
        }
        // Now, x has the same number of set bits as num2.
        return x;
    }
};
