
/*
***********************
Author : Mohamed Eraky
***********************
Problem Requirement :- 

1. Prompt the user to input a positive integer from the keyboard. 
   (Example: "Please enter a positive integer: ")

2. Read in the positive integer from keyboard. 
   (Example n = 5) 
   (Error handling for incorrect input types is not required)

3. If the number is odd, multiply it by 3 and add 1.
   If the number is even, divide by 2.

   Repeat these rules on each result until the number converges to 1. 

   If done properly, any positive integer will converge to 1.

4. Display ALL intermediate values with either a space, tab, or newline 
   between them, and the final result.
*/

#include <iostream>

int main()
{
    int x;

    std::cout << "Please enter a positive integer : " << std::endl;
    std::cin >> x;

    while (x != 1)
    {
        if (x % 2 != 0)
        {
            x = x * 3 + 1;
        }
        else
        {
            x = x / 2;
        }
        std::cout << "x = " << x << std::endl;
    }
    std::cout << "Final result: " << x << std::endl;

    return 0;
}