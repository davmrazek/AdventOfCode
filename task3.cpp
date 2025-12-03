#include <iostream>
#include <string>
#include <sstream>


int main(){
    std::string row;
    long long sum = 0;
    // looping through all the rows
    while (std::cin >> row)
    {
        char nums [13];
        // filling with 0s
        for(int i = 0; i < 13; i++){
            nums[i] = '0';
        }
        int length = row.size();

        // looping through each character
        for(int i = 0; i < length; i++) {
            char current = row[i];
            int next = 1;
            int index = 0;
            while (next && index < 13)
            {
                // rewriting num
                // i = 7, current = 1
                if (nums[index] < current && (length - i >= 13 - index))
                {
                    nums[index] = current;
                    next = 0;
                }
                else {
                    index++;
                }
            }
        }
        
        // adding to sum
        long long multiplier = 100000000000;
        for(char num : nums){
            sum+= (num - '0') * multiplier;
            multiplier /= 10;
        }
    }

    std::cout << sum << std::endl;
    return 1;
}