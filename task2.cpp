#include <iostream>
#include <string>
int count_digits_log(int n) {
    if (n == 0) return 1;
    long long x = n;
    if (x < 0) x = -x;
    return static_cast<int>(std::floor(std::log10(static_cast<double>(x)))) + 1;
}


int calculate_range(int start, int end){
    // only odd-digits numbers
    if((count_digits_log(start) == count_digits_log(end)) && (count_digits_log(start) %2 == 1)) {
        return 0;
    }
    int sum = 0;
    
    for (size_t i = start; i <= end; i++)
    {
        int digits = count_digits_log(i);
        if (digits % 2 == 0) {
            std::string my_string = std::to_string(i);
            // checking similarity
            int midpoint = digits/2;
            int valid = 1;
            for (size_t j = 0; j < midpoint; j++)
            {
                if (my_string[j] != my_string[j+midpoint])
                {
                    valid = 0;
                }
            }
            if(valid){
                sum += i;
            }
        }
    }
    return sum;
}


int main() {
    int result = calculate_range(95, 115);
    std::cout << result << std::endl;
    return 0;
}