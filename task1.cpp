#include <iostream>
#include <string>


int calculate(int start_num) {
    int count = 0;
    std::string input;
    int my_num;
    while (std::cin >> input)
    {
        my_num = std::stoi(input.substr(1));
        
        // adding count for going over 100
        count+= (my_num - (my_num%100))/100;
        my_num %= 100;
        

        if (input[0] == 'L')
        {
            if (start_num - my_num < 0)
            {
                if(start_num != 0) count++; 
                start_num = 100 - (my_num - start_num);
                
            }
            else start_num -= my_num;
        }

        else {
            if (start_num + my_num > 99)
            {
                start_num = 0 + ((start_num + my_num) - 100);
                if(start_num != 0) count++; 
            }
            else start_num += my_num;
        }


        if (start_num == 0)
        {
            count++;
        }
    }
    
    return count;
}


int main() {
    int num = 50;
    int final_count = calculate(num);
    std::cout << final_count << std::endl;
}