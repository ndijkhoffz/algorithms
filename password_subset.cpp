// my first program in c++
#include <iostream>
#include <stdint.h>
using namespace std;

uint8_t solution(string &S);

int main(void)
{
	/** Here we declare the string, although
	 *  This could also be an input from the user.
	 */
	string str = "laskjflkGkslGa0fa1adHj5";
    
    solution(str);
    
    return 0;
}


uint8_t solution(string &S) 
{
    // write your code in C++14 (g++ 6.2.0)
	static uint16_t n = 0;
	static uint16_t current_max_subset = 0;
	static uint16_t largest_max_subset_found = 0;
	bool uppercase_in_subset = false;
    
    while(S.length() >= n)
    {
        if(isupper(S[n]))
        {
        	current_max_subset += 1;
        	if(!uppercase_in_subset)
        	{
        		uppercase_in_subset = true;
			}
        }
        
        // check if char is lower case
        if(islower(S[n]))
        {
        	current_max_subset += 1;        	
		}
		
		if(!(isupper(S[n])) && !(islower(S[n])))
		{
			if (largest_max_subset_found < current_max_subset)
			{
				if(uppercase_in_subset)
				{
					largest_max_subset_found = current_max_subset;
				}
				// reset uppercase flag
				uppercase_in_subset = false;
				current_max_subset = 0;
			}
		}
		
		//increase counter
		++n;
	}

    cout << largest_max_subset_found;
}
