#include <iostream>
#include <string>
#include <sstream>


int main(){
    std::string row;
    int sum = 0;

    // looping through all the rows
    while (std::cin >> row)
    {
        char first = '0', second = '0';
        int length = row.size();
        // looping through each character
        for(int i = 0; i < length; i++) {
            char current = row[i];
            if (current > first && (i + 1 < length)) {
                first = current;
                second = 0;
            }
            else if (current > second){
                second = current;
            }
        }
        sum += ((first - '0') * 10 + (second - '0'));
    }

    std::cout << sum << std::endl;
    return 1;
}