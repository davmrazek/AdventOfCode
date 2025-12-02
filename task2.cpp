#include <iostream>
#include <string>
#include <sstream>
long long count_digits_log(long long n) {
    if (n == 0) return 1;
    long long x = n;
    if (x < 0) x = -x;
    return static_cast<long long>(std::floor(std::log10(static_cast<long long>(x)))) + 1;
}


long long calculate_range(long long start, long long end){
    // only odd-digits numbers
    if((count_digits_log(start) == count_digits_log(end)) && (count_digits_log(start) %2 == 1)) {
        return 0;
    }
    long long sum = 0;
    
    for (size_t i = start; i <= end; i++)
    {
        long long digits = count_digits_log(i);
        if (digits % 2 == 0) {
            std::string my_string = std::to_string(i);
            // checking similarity
            long long midpoint = digits/2;
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
    std::string input_line;
    long long total = 0;
    if (std::getline(std::cin, input_line)) {
        
        std::stringstream ss(input_line);
        std::string segment;

        while (std::getline(ss, segment, ',')) {
            
            size_t dash_pos = segment.find('-');
            
            if (dash_pos != std::string::npos) {
                std::string start_str = segment.substr(0, dash_pos);
                std::string end_str = segment.substr(dash_pos + 1);

                
                long long start = std::stoll(start_str);
                long long end = std::stoll(end_str);

                long long result = calculate_range(start, end);
                total+= result;
            }
        }
    }
    std::cout << "Total = " << total << std::endl;
    return 0;
}
