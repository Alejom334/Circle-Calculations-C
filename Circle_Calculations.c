
/*=============================================================================$
|   Source code:  Circle_Calculations.c
|   Author:  Alejandro Martinez
|   Student ID: 3625175
|   Assignment:  Program #1 Circle Calculations
|
|   Course:  [COP 4338 (Programming 3)]
|   Section:  [U04 1198]
|   Instructor:  William Feild
|   Due Date:  [09/17/2019], at the beginning of class
|
|    I hereby certify that this collective work is my own
|   and none of it is the work of any other person or entity.
|   ______________________________________ [Alejandro Martinez]
|
|  Language:  [C]
|  Compile/Run:
|             gcc Circle_Calculations.c -o Circle.out
|             ./Circle.out
|  +-------------------------------------------------------------------------
|
|  Description:  This program determines the diameter, circumference,
|                and area of a circle given a 'step' value that steps through
|                a radius range that goes from 0 - 50.
|
|                The user is required to enter a 'step' ranging from 1 to 9
|                including both 1 and 9. Think of a 'step' that jumps through
|                a count of numbers. For example, if the user picks 2 as the
|                'step' value and the counter goes from 0-10, the numbers
|                printed would be [0,2,4,6,8,10].
|
|                After the user is prompt to put a 'step' value,
|                the program will print a table with the calculations of the
|                radius, diameter, circumference and area. The radius values
|                will go from 0 to 50, including both 0 and 50. For example,
|                if the user put a radius step of 5, the first entries of the
|                table will look like this:
|
|
|                      Radius     Diameter  Circumference   Area
|                   —————————————————————————————————————————————————
|                       0.000        0.000	 0.000       0.000
|                       5.000       10.000	31.416      78.540
|                      10.000       20.000	62.832     314.159
|
|
|        Input:  The user is required to enter a 'step' value. It is expected
|                that the user inputs a value that ranges from 0-9, including
|                0 and 9. If the user does not input a values within this
|                range, the program will ask again until the user inputs a
|                value within the range.
|
|	Output:  The program will print an explanation of its purpose,
|                will prompt the user for the input, if the input is correct,
|                it will print a table that has the radius, diameter,
|                circumference and area as displayed in the description of
|                the program.
|
|     Process:   The program's steps are as follows:
|
|                1. The program displays its purpose
|                2. The user its prompt to enter an integer from the range 1-9
|                3. If the input is in the range the properties of diameter,
|                   circumference, and area are computed.
|                4. A table with the outputs of radius, diameter,
|                   circumference, and area is shown.
| 
|.  Source of Formulas Required For Calculations:
|                Refer to the link below for full explanation of the formulas
|                used in calculations.
|                http://www.math.com/tables/geometry/circles.htm
|
|                Formulas used are:
|                    - diameter = radius * 2
|                    - circumference = M_PI * radius * 2.0
|                    - area = M_PI * radius * radius
|
|   Required Features Not Included:
|                Not included: All required features are included.
|
|   Known Bugs:  This program only is able to accept integers as the prompt
|                explains to the user. If you put a chracter, string, or a
|                number combined with a character might either terminate the
|                program or through an infinite loop. Accepting characters,
|                and strings is not required for this assignment but it is
|                good to mention.
|
|
|
|  *=====================================================================
|  */



#include <stdio.h>

#include <math.h>    /* required for constant M_PI used in circle */
                     /* calculations */

#define NO_ERROR 0   /* zero for no erros */

#define LOWEST_USER_INPUT 1 /* 1 is the lowest bound of the */
                            /* input range from the user */

#define HIGHEST_USER_INPUT 9 /* 9 is the highest bound of the */
                             /*  input range from the user */

#define HIGHEST_RADIUS_VALUE 50 /* 50 is highest number the radius can be */

#define ITERATION_0_START_POINT 0 /* 0 is where the lower bound for the table */
                                  /* display */

#define ITERATION_10_BLANK_LINE 10 /* 10 is the maximum amount of displays */
                                   /* the table will show before printing */
                                   /* a blank line */

/*	 * Function Prototypes    */
int userInput();
void printCircleCalculations(int input);
float calculateDiameter(float radius);
float calculateCircumference(float radius);
float calculateArea(float radius);
void blankLineForLineTen (int linesPrinted);

int main (void)
{

  /* Prompt & Read input from the keyboard, */
  /* assign this input to variable input   */

   int input = userInput();

  /* Process-compute the properties of the circle and print the output */

   printCircleCalculations (input);

   return NO_ERROR;


} // end of main

/*---------------------------- userInput ----------------------------
    |  Function userInput ()
    |
    |  Purpose:  Input and validate integer 'step' value input by the user
    |
    |  @param  none
    |
    |  @return  input, int, validated integer 'step' value
 *-------------------------------------------------------------------*/

 int userInput ()
{
   int input = 0;

   printf ("%s", "\nWelcome to the circle properties calculator program!\n"
                 "The intend of this program is to calculate\n"
                 "the diameter, the circumference and the area of\n"
                 "a circle based on a radius that will range from 0 to 50.\n"
                 "You will be required to input a 'step' value\n"
                 "which will jump through the radius range in order\n"
                 "to calculate the properties mentioned.\n\n");

   do{

      printf("%s","Please enter an integer as the radius step.\n"
                  "The range must be from 1-9, including 1 and 9.\n.");

      scanf("%d", &input);

     } while ( (input < LOWEST_USER_INPUT) || (input > HIGHEST_USER_INPUT) );

     return input;

} // end function


/*---------------------------- calculations  ----------------------------
        |  Function: calculations (int input)
        |
	      |  Purpose:  Display the table with the calculations of the diameter,
        |            circumference and area until the radius gets to 50.
        |            Calculations shown will be shown according to the
        |            'step' value.
        |
	      | @param  input, int, validated integer 'step' value
        |
	      | @return  none
        *---------------------------------------------------------------*/

void printCircleCalculations (int input)
{
   float radius = 0;                   

   int linesPrinted = 0;       /* Variable used to count output lines */

   printf ("    Radius         Diameter       Circumference	  Area\n");

   printf ("———————————————————————————————————————————————————————————————\n");

   do{

      linesPrinted = linesPrinted + 1;

      printf (" %7.3f\t %9.3f\t %11.3f\t %11.3f\n",
                radius, calculateDiameter(radius),
                calculateCircumference(radius), calculateArea(radius));

      blankLineForLineTen (linesPrinted); /* Check if blank line counter */

      radius = radius + input;

   } while ( radius <= HIGHEST_RADIUS_VALUE ); //end of while

} // end function


/*------------------------- calculateDiameter ----------------------------
        |  Function: calculateDiameter(float radius)
        |
	      |  Purpose: Compute the diameter for the given radius with the
        |            the given formula:
        |
	      |  Formula: diameter = radius * 2
        |
	      | Citation: http://www.math.com/tables/geometry/circles.htm
        |
	      |  @param radius, float, radius that ranges from [0-50] depending
        |                        on the 'step' value
        |
	      |  @return diameter, float, formula in Soruce of Formula
        *---------------------------------------------------------------*/


float calculateDiameter (float radius)
{

   float diameter = 2.0 * radius; /* Refer to formula on function description*/

   return diameter;

} // end function

/*------------------------- calculateCircumference ----------------------
        |  Function: calculateCircumference(float radius)
        |
	      |  Purpose:  compute the circumference for the given radius
        |            with the given formula:
        |                                 
        |  Formula:  circumference = M_PI * radius * 2.0
        |
	      | Citation:  http://www.math.com/tables/geometry/circles.htm
        |
	      |  @param radius, float, radius that ranges from [0-50] depending
        |                        on the 'step' value
        |
	      |  @return  circumference, float, formula in Source of Formula
	*---------------------------------------------------------------*/

float calculateCircumference (float radius)
{

   float circumference = 2.0 * M_PI * radius; /* Refer to formula on function*/
                                              /* description */

   return circumference;

} // end function

/*------------------------- calculateArea -----------------------------
        |  Function: calculateArea(float radius)
        |
	      |  Purpose:  compute the area for the given radius
        |            with the given formula:
        |
	      |  Formula:  area = M_PI * radius * radius
        |
	      | Citation:  http://www.math.com/tables/geometry/circles.htm 
        |                                
	      |  @param radius, float, radius that ranges from [0-50] depending
        |                        on the 'step' value
        |
	      |  @return area, float, formula in Source of Formula
        *-------------------------------------------------------------*/

float calculateArea (float radius)
{

   float area = M_PI * radius * radius; /* Refer tp formula on function */
                                        /*  description */

   return area;

} // end function


/*-------------------------blankLineForLineTen -----------------------------
        |  Function: blankLineForLineTen (int linesPrinted)
        |
        |  Purpose:  Print a blank line if the linesPrinted is equal to 10
	      |            
        |  @param linesPrinted, int, counter for lines printed
        |
	      |  @return none
        *-------------------------------------------------------------*/

void blankLineForLineTen (int linesPrinted)
{
   if ( (linesPrinted != ITERATION_0_START_POINT) &&
        (linesPrinted % ITERATION_10_BLANK_LINE == 0) ){

      printf("%s","\n");

   } else {

   }

}








