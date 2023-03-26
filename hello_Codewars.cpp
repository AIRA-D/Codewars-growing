//My first 3 kata. Two of them: 7kyu, one - 6kyu.
#include <iostream>

unsigned int countBits(unsigned long long n, int tmp = 0);
int square_digits(int num);
int square_digits_analogue(int n);
int get_sum(int a, int b, int res = 0);

int main() {
    countBits(7);
    square_digits(9119);
    square_digits_analogue(9119);
    std::cout << get_sum(-1, 2);
    return 0;
}

unsigned int countBits(unsigned long long int n, int tmp) {
    while (n > 0) {
        if (n % 2 == 1) {
            tmp ++;
        }
        n /= 2;
    }
    return tmp;
}

int square_digits(int num) {
    std::string num_str = std::to_string(num);
    std::string result;
    for (char& c: num_str) {
        int digitSqr = (c - '0') * (c - '0');
//        [EXPLANATION] p.s. for myself LOL
//        Yes, you are correct that `c` is a `char` variable.
//        However, in C++, characters are internally represented as integers using their ASCII codes.
//        The ASCII code for the character '0' is 48, and the ASCII codes for the characters '1' to '9' are 49 to 57, respectively.
//        When you subtract the ASCII code for '0' from the ASCII code for any digit character, you get the integer value of that digit.
//        For example, the ASCII code for the character '3' is 51, and `51 - 48` is equal to `3`.
//        This is how we can convert a digit character into its corresponding numerical value.

        std::string sqrString = std::to_string(digitSqr);
        result += sqrString;
    }

    return stoi(result);
}

int square_digits_analogue(int n) {
    int a = 1;
    int m = 0;
    while (n > 0) {
        int d = n % 10;
        m += a * d * d;

        //Learned a new syntax. It smells like python, idk why. -_-
        a *= d <= 3 ? 10 : 100; // if d <= 3 than a *= 10, else d > 3 means a *= 100 ( because sqr(d > 3) will have 2 or more digits)
        n /= 10;
    }
    return m;
}

int get_sum(int a, int b, int res)
{
    if (a < b) { for (int i = a; i <= b; i++){res += i;} }
    else {for (int i = b; i <= a; i++){res += i;}}
    return res;
}