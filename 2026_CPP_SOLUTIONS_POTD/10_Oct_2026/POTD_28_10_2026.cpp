/*
1. The function finds the nth digit in the sequence of positive integers: 123456789101112...
2. length represents the number of digits in the current group of numbers.
3. count stores how many numbers belong to the current digit-length group.
4. start represents the first number in the current group, initially 1.
5. The while loop skips digit groups until the nth digit falls within the current group.
6. targetNumber identifies the exact number containing the required digit.
7. digitIndex identifies the digit's position, which is returned as a character.
*/
class Solution {
  public:
    char nthCharacter(int n) {
        // code here

        long long length = 1;
        long long count = 9;
        long long start = 1;

        while (n > length * count) {
            n -= length * count;
            length++;
            count *= 10;
            start *= 10;
        }

        long long targetNumber = start + (n - 1) / length;

        string numberStr = to_string(targetNumber);
        int digitIndex = (n - 1) % length;

        return numberStr[digitIndex];
    }
};

/*
7 Key Points:
1. The sequence contains all positive integers concatenated together.
2. One-digit numbers contribute 9 digits to the sequence.
3. Two-digit numbers contribute 90 * 2 = 180 digits.
4. The loop subtracts complete groups until the target digit is located.
5. Integer division calculates the number containing the target digit.
6. The modulo operator determines the digit's index within that number.
7. Time complexity is O(log n) for locating the digit group, with O(log n)
   auxiliary space for storing the target number as a string.
*/