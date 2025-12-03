#include <iostream>
#include <string>
#include <sstream>
long long count_digits_log(long long n) {
    if (n == 0) return 1;
    long long x = n;
    if (x < 0) x = -x;
    return static_cast<long long>(std::floor(std::log10(static_cast<long long>(x)))) + 1;
}



// return true if s is equal to some substring repeated >= 2 times
bool is_invalid_id(const std::string &s) {
    int n = (int)s.size();
    if (n < 2) return false; 

    std::vector<int> pi(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) j = pi[j-1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }

    int period = n - pi[n-1];
    return (period < n) && (n % period == 0);
}


long long calculate_range(std::string start, std::string end){
    long long sum = 0;
    long long start_num = std::stoll(start);
    long long end_num = std::stoll(end);


    // looping through each number
    for (long long i = start_num; i <= end_num; i++)
    {
        if (is_invalid_id(std::to_string(i)))
        {
            sum+= i;
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

                

                long long result = calculate_range(start_str, end_str);
                total+= result;
            }
        }
    }
    std::cout << "Total = " << total << std::endl;
    return 0;
}
