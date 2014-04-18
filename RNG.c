#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  // This program will generate pseudorandom numbers using
  // a linear feedback shift. 
  
  // Variable Declaration
  int i, j, k, input, nums, tempTap;
  unsigned int seed, f;
  unsigned int taps[32];
  unsigned int displayMask = 1;  
  
  
  // initialize entries of taps[] to 0
  for(i = 0; i < 10; i++)
  taps[i] = 0;
 
  // initialize counter and temp variables to 0
  i = 0;
  seed = 0;
  tempTap = 0;
  nums = 0;
  f = 0;
  k = 0;
  
  
  // Get User Input & Validate Data
  
  //Prompt the user for an integer
  puts("Please enter a positive integer:");
  scanf("%d", &input);
  
  // ask the user how many random numbers they want to generate
  puts("How many random numbers should be generated?:");
  scanf("%d", &nums);
  
  
  // we must print at LEAST 1 number, if the user enters anything less,
  // print an error and exit
  if(nums < 1)
  {
  puts("ERROR: Must generate at LEAST 1 random number");
  exit(1);
  } // end if


  // validate that the integer is greater than 0
  if(input > 0)
  {
    seed = (unsigned int) input;
    // prompt the user for taps
    puts("Enter taps between 0 and 31.");
    
    // give n-1 as the first tap
    tempTap = 31;
    // loop until a tap out of range is entered
    while((tempTap > -1) && (tempTap < 32))
    {
      // store the tap
      taps[i] = tempTap;
    
      // increment counter
      i++;
    
      // get next tap
      scanf("%d", &tempTap);
    
    }// end while
   
  for(k = 0; k < nums; k++)
  {
  
    // Begin Calculating Random Numbers Using Linear Feedback
    puts("");
   
    // Get the value of the BIT at each tap
     for(j = 0; j < i; j++)
     {
      // if the tap bit & 1 = 1, the value is 1
      if( (seed&(displayMask<<taps[j])) != 0) // displayMask<<taps[j] (where taps[j] = 2) = 000000000000000000000000000100
     {
      f = f ^ 1; // every time we get a 1, xor f with it
     }
    } // end inner for 
    // Shift the seed number's bits to the right to lose the leftmost bit
    seed = seed << 1;

    // Change the rightmost bit to f
    seed = seed|f; 
    
    // print the new seed
    printf("%u \n", seed);
    } // end outer for
  } // end if
  else
  {
   puts("Seed must be an unsigned integer.");
  } // end else
  return 0;
}
