/* Required header files for ADC Example 1 */
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/system/clock.h"

#define FCY CLOCK_PeripheralFrequencyGet()
#include <libpic30.h>


#include "mcc_generated_files/uart/uart1.h"
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/pwm_hs/pwm.h"
#include "mcc_generated_files/timer/tmr1.h"
#include <math.h>
///************************<<<< PWM generate code >>>>>>*********************************/
static uint16_t sineIndex = 0;
static uint16_t sineIndex2 = 0;
#define SINE_TABLE_SIZE 262

const uint16_t sineTable[SINE_TABLE_SIZE] = {
    
50, 53, 56, 59, 62, 65, 68, 71,
74, 77, 79, 82, 84, 86, 89, 90,
92, 94, 95, 96, 98, 98, 99, 100,
100, 100, 100, 100, 99, 98, 98, 96,
95, 94, 92, 90, 89, 86, 84, 82,
79, 77, 74, 71, 68, 65, 62, 59,
56, 53, 50, 47, 44, 41, 38, 35,
 31, 30, 29, 28, 26, 25, 24, 23,
 22, 21, 20, 19, 18, 17, 16, 16,
 15, 14, 13, 12, 11, 11, 10, 9,
 8, 8, 7, 6, 6, 5, 5, 4,
 4, 3, 3, 2, 2, 1, 1, 0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0, 0, 0, 0, 0, 0, 0, 1,
2, 4, 4, 5, 6, 6, 7, 8,
8, 9, 10, 11, 11, 12, 13, 14,
15, 16, 16, 17, 18, 19, 20, 21,
16, 18, 21, 23, 26, 29, 32, 35,//8
38, 41, 44, 47,48,49//6
    
    
    
//    
////    50, 51, 52, 54, 55, 56, 57, 59,
//    60, 61, 62, 63, 65, 66, 67, 68,
//    69, 70, 71, 72, 74, 75, 76, 77,
//    78, 79, 80, 81, 82, 83, 84, 84,
//    85, 86, 87, 88, 89, 89, 90, 91,
//    92, 92, 93, 94, 94, 95, 95, 96,
//    96, 97, 97, 97, 98, 98, 99, 99,
//    99, 99, 99, 100, 100, 100, 100, 100,
//    100, 100, 100, 100, 100, 100, 99, 99,
//    99, 99, 99, 98, 98, 97, 97, 97,
//    96, 96, 95, 95, 94, 94, 93, 92,
//    92, 91, 90, 89, 89, 88, 87, 86,
//    85, 84, 84, 83, 82, 81, 80, 79,
//    78, 77, 76, 75, 74, 72, 71, 70,
//    69, 68, 67, 66, 65, 63, 62, 61,60,
////    60, 59, 57, 56, 55, 54, 52, 51,
////    50, 49, 48, 46, 45, 44, 43, 41,
//    40, 39, 38, 37, 35, 34, 33, 32,
//    31, 30, 29, 28, 26, 25, 24, 23,
//    22, 21, 20, 19, 18, 17, 16, 16,
//    15, 14, 13, 12, 11, 11, 10, 9,
//    8, 8, 7, 6, 6, 5, 5, 4,
//    4, 3, 3, 3, 2, 2, 1, 1,
//    1, 1, 1, 0, 0, 0, 0, 0,
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
//    0, 0, 0, 0, 0, 0, 1, 1,
////    1, 1, 1, 2, 2, 3, 3, 3,
////    4, 4, 5, 5, 6, 6, 7, 8,
////    8, 9, 10, 11, 11, 12, 13, 14,
//    15, 16, 16, 17, 18, 19, 20, 21,
//    22, 23, 24, 25, 26, 28, 29, 30,
//    31, 32, 33, 34, 35, 37, 38, 39,
//    40, 41, 43, 44, 45, 46, 48, 49
    
    
// 50, 51, 52, 54, 55, 56, 57, 59,
//    60, 61, 62, 63, 65, 66, 67, 68,
//    69, 70, 71, 72, 74, 75, 76, 77,
//    78, 79, 80, 81, 82, 83, 84, 84,
//    85, 86, 87, 88, 89, 89, 90, 91,
//    92, 92, 93, 94, 94, 95, 95, 96,
//    96, 97, 97, 97, 98, 98, 99, 99,
//    99, 99, 99, 100, 100, 100, 100, 100,
//    100, 100, 100, 100, 100, 100, 99, 99,
//    99, 99, 99, 98, 98, 97, 97, 97,
//    96, 96, 95, 95, 94, 94, 93, 92,
//    92, 91, 90, 89, 89, 88, 87, 86,
//    85, 84, 84, 83, 82, 81, 80, 79,
//    78, 77, 76, 75, 74, 72, 71, 70,
//    69, 68, 67, 66, 65, 63, 62, 61,
//    60, 59, 57, 56, 55, 54, 52, 51,
//    50, 49, 48, 46, 45, 44, 43, 41,
//    40, 39, 38, 37, 35, 34, 33, 32,
//    31, 30, 29, 28, 26, 25, 24, 23,
//    22, 21, 20, 19, 18, 17, 16, 16,
//    15, 14, 13, 12, 11, 11, 10, 9,
//    8, 8, 7, 6, 6, 5, 5, 4,
//    4, 3, 3, 3, 2, 2, 1, 1,
//    1, 1, 1, 0, 0, 0, 0, 0,0,0,0,0,
//0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 
//    0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,1, 1,
//    1, 1, 1, 2, 2, 3, 3, 3,
//    4, 4, 5, 5, 6, 6, 7, 8,
//    8, 9, 10, 11, 11, 12, 13, 14,
//    15, 16, 16, 17, 18, 19, 20, 21,
//    22, 23, 24, 25, 26, 28, 29, 30,
//    31, 32, 33, 34, 35, 37, 38, 39,
//    40, 41, 43, 44, 45, 46, 48, 49
};



#define SINE_TABLE_SIZE2 262

const uint16_t sineTable2[SINE_TABLE_SIZE2] = {

0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 3, 4, 5, 6,
7, 8, 8, 9, 10, 11, 11, 12,
13, 14, 15, 16, 17, 19, 20, 21,
24, 25, 21, 26, 28, 29, 30, 31,
35, 38, 44, 41,44,47, 50, 53, 56, 
 59, 62, 65, 68, 71,
74, 77, 79, 82, 84, 86, 89, 90,
92, 94, 95, 96, 98, 98, 99, 100,
100, 100, 100, 100, 99, 98, 98, 96,
95, 94, 92, 90, 89, 86, 84, 82,
79, 77, 74, 71, 68, 65, 62, 59,
56, 53, 50, 47, 44, 41, 38, 35,
 31, 30, 29, 28, 26, 25, 24, 23,
 22, 21, 20, 19, 18, 17, 16, 16,
 15, 14, 13, 12, 11, 11, 10, 9,
 8, 8, 7, 6, 5, 5, 4, 4,
 3, 3, 2, 2,
   1, 0, 0, 0,
0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,   
   0,0,0,0 
    
    
    
    
    
    
    
    
    
    

//0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0, 0, 0, 0, 0, 0, 0, 0,
//0, 1, 1, 2, 5, 6, 7, 8,
//8, 9, 10, 11, 11, 12, 13, 14,
//15, 16, 16, 17, 18, 19, 20, 21,
//16, 18, 21, 23, 26, 29, 32, 35,
//38, 41, 44, 47,48,49, 50, 53, 56, 
// 59, 62, 65, 68, 71,
//74, 77, 79, 82, 84, 86, 89, 90,
//92, 94, 95, 96, 98, 98, 99, 100,
//100, 100, 100, 100, 99, 98, 98, 96,
//95, 94, 92, 90, 89, 86, 84, 82,
//79, 77, 74, 71, 68, 65, 62, 59,
//56, 53, 50, 47, 44, 41, 38, 35,
// 31, 30, 29, 28, 26, 25, 24, 23,
// 22, 21, 20, 19, 18, 17, 16, 16,
// 15, 14, 13, 12, 11, 11, 10, 9,
// 8, 8, 7, 6, 3, 2, 1, 1,
// 1, 1, 0, 0,
//   0, 0, 0, 0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
// 0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,   
//   0,0,0,0 
//    
    
    
    
    
    
//  50, 53, 56, 59, 62, 65, 68, 71,
//74, 77, 79, 82, 84, 86, 89, 90,
//92, 94, 95, 96, 98, 98, 99, 100,
//100, 100, 100, 100, 99, 98, 98, 96,
//95, 94, 92, 90, 89, 86, 84, 82,
//79, 77, 74, 71, 68, 65, 62, 59,
//56, 53, 50, 47, 44, 41, 38, 35,
// 31, 30, 29, 28, 26, 25, 24, 23,
// 22, 21, 20, 19, 18, 17, 16, 16,
// 15, 14, 13, 12, 11, 11, 10, 9,
// 8, 8, 7, 6, 6, 5, 5, 4,
// 4, 3, 2, 1, 0, 0, 0, 0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0,0,0,0,0,0,0,0,
//0, 0, 0, 0, 0, 0, 1, 2,
//3, 4, 5, 5, 6, 6, 7, 8,
//8, 9, 10, 11, 11, 12, 13, 14,
//15, 16, 16, 17, 18, 19, 20, 21,
//16, 18, 21, 23, 26, 29, 32, 35,
//38, 41, 44, 47,48,49 
    
    
    
    
    
    

// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//15 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//18 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//18 
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //18
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //18
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //18
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //18
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //18
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //18
// 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, //18
// 0, 0, 0, 0, 0, 0, 0,0,0,0,0,0,1, 1,   //18
// 50, 51, 52, 54, 55, 56, 57, 59,//8
//    60, 61, 62, 63, 65, 66, 67, 68,//8
//    69, 70, 71, 72, 74, 75, 76, 77,//8
//    78, 79, 80, 81, 82, 83, 84, 84,//8
//    85, 86, 87, 88, 89, 89, 90, 91,//8
//    92, 92, 93, 94, 94, 95, 95, 96,//8
//    96, 97, 97, 97, 98, 98, 99, 99,//8
//    99, 99, 99, 100, 100, 100, 100, 100,//8
//    100, 100, 100, 100, 100, 100, 99, 99,//8
//    99, 99, 99, 98, 98, 97, 97, 97,//8
//    96, 96, 95, 95, 94, 94, 93, 92,//8
//    92, 91, 90, 89, 89, 88, 87, 86,//8
//    85, 84, 84, 83, 82, 81, 80, 79,//8
//    78, 77, 76, 75, 74, 72, 71, 70,//8
//    69, 68, 67, 66, 65, 63, 62, 61,//8
//    60, 59, 57, 56, 55, 54, 52, 51,//8
//    50, 49, 48, 46, 45, 44, 43, 41,//8
//    40, 39, 38, 37, 35, 34, 33, 32,//8
//    31, 30, 29, 28, 26, 25, 24, 23,//8
//    22, 21, 20, 19, 18, 17, 16, 16,//8
//    15, 14, 13, 12, 11, 11, 10, 9,//8
//    8, 8, 7, 6, 6, 5, 5, 4,//8
//    4, 3, 3, 3, 2, 2, 1, 1,//8
//    1, 1, 1, 0, 0, 0, 0, 0,//8
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//15
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//15
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//15
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//15
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//15
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//15
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//15
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//15
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//15
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//15
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//15
//    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,//15
//    0, 0, 0, 0, 0, 0, 1, 1,//8
//    1, 1, 1, 2, 2, 3, 3, 3,//8
//    4, 4, 5, 5, 6, 6, 7, 8,//8
//    8, 9, 10, 11, 11, 12, 13, 14,//8
//    15, 16, 16, 17, 18, 19, 20, 21,//8
//    22, 23, 24, 25, 26, 28, 29, 30,//8
//    31, 32, 33, 34, 35, 37, 38, 39,//8
//    40, 41, 43, 44, 45, 46, 48, 49   //8
// 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
//    
//     50, 51, 52, 54, 55, 56, 57, 59,
//    60, 61, 62, 63, 65, 66, 67, 68,
//    69, 70, 71, 72, 74, 75, 76, 77,
//    78, 79, 80, 81, 82, 83, 84, 84,
//    85, 86, 87, 88, 89, 89, 90, 91,
//    92, 92, 93, 94, 94, 95, 95, 96,
//    96, 97, 97, 97, 98, 98, 99, 99,
//    99, 99, 99, 100, 100, 100, 100, 100,
//    100, 100, 100, 100, 100, 100, 99, 99,
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
//    99, 99, 99, 98, 98, 97, 97, 97,
//    96, 96, 95, 95, 94, 94, 93, 92,
//    92, 91, 90, 89, 89, 88, 87, 86,
//    85, 84, 84, 83, 82, 81, 80, 79,
//    78, 77, 76, 75, 74, 72, 71, 70,
//    69, 68, 67, 66, 65, 63, 62, 61,
//    60, 59, 57, 56, 55, 54, 52, 51,
//    50, 49, 48, 46, 45, 44, 43, 41,
//    40, 39, 38, 37, 35, 34, 33, 32,
//    31, 30, 29, 28, 26, 25, 24, 23,
//    22, 21, 20, 19, 18, 17, 16, 16,
//    15, 14, 13, 12, 11, 11, 10, 9,
//    8, 8, 7, 6, 6, 5, 5, 4,
//    4, 3, 3, 3, 2, 2, 1, 1,
    
    
    
//    1, 1, 1, 2, 2, 3, 3, 3,
//    4, 4, 5, 5, 6, 6, 7, 8,
//    8, 9, 10, 11, 11, 12, 13, 14,
//    15, 16, 16, 17, 18, 19, 20, 21,
//    22, 23, 24, 25, 26, 28, 29, 30,
//    31, 32, 33, 34, 35, 37, 38, 39,
//    40, 41, 43, 44, 45, 46, 48, 49
};




const struct TIMER_INTERFACE * Timer = &Timer1;

void Timer_Callback(void) {

    //LED_Toggle();
    //   PWM_DutyCycleSet(PWM_GENERATOR_1, sineTable[sineIndex]);
    //    sineIndex = (sineIndex + 1) % SINE_TABLE_SIZE;
    //    static uint16_t sineIndex = 0;

    // Update PWM duty cycle from sine table
    PWM_DutyCycleSet(PWM_GENERATOR_1, sineTable[sineIndex]);
    
// __delay_ms(1);
    PWM_DutyCycleSet(PWM_GENERATOR_2, sineTable2[sineIndex2]);
    
//        __delay_ms();
//    __delay_ms(10);
    sineIndex++;
    if (sineIndex >= SINE_TABLE_SIZE) {
        sineIndex = 0;
    }
      
      sineIndex2++;
    if (sineIndex2 >= SINE_TABLE_SIZE2) {
        sineIndex2 = 0;
    }
    
//       PWM_DutyCycleSet(PWM_GENERATOR_2, 0);
//    __delay_ms(20); 
//    __delay_ms(20);
//    sineIndex++;
//    if (sineIndex >= SINE_TABLE_SIZE) {
//        sineIndex = 0;
//    }
}
///************************<<<< PWM generate code >>>>>>*****************************/

int main(void) {
    SYSTEM_Initialize();
//    pins_initialization();
//    ups_switch = PORTBbits.switch; // here this pin use for ups switch
 
    Timer->TimeoutCallbackRegister(Timer_Callback);
//    PWM_DutyCycleSet(PWM_GENERATOR_2, 100);
//// Timer->Stop();
    while (1) {
// PWM_DutyCycleSet(PWM_GENERATOR_2, 100);
// __delay_ms(10);
//  PWM_DutyCycleSet(PWM_GENERATOR_1, 0);
// __delay_ms(10);
//////        adc->SoftwareTriggerEnable(); //Trigger the ADC conversion via software
//
//        /*****************************************READ ADC PIN****************************************************/
//        ac_input_voltage = adc->ConversionResultGet(Channel_AN2); // RB7 pin here sensing AC input voltage
//        ac_output_voltage = adc->ConversionResultGet(Channel_AN10); // RB8 pin here sensing AC output voltage
//        ac_input_current = adc->ConversionResultGet(Channel_AN9); // RA2 pin here sensing AC input current
//        ac_output_current = adc->ConversionResultGet(Channel_AN3); // RA3 pin here sensing AC output current
//        dc_battery_volt = adc->ConversionResultGet(Channel_AN0); // RA0 pin here sensing battery voltage
//        ac_volt_in();
//        ac_volt_out();
//        Dc_volt_sense();
//        //        printf("acvolt_in: %d\r\n", acvolt_in);
//        /*****************************************READ ADC PIN****************************************************/
//       
//
//        /**************************************  UPS switching start ************************************************/
//
//        if (PORTBbits.switch == 0) { // Double-check if the switch is still pressed
//
//                press_count++;
//
//                PORTBbits.buzzer = 0; // beep buzzer
//                __delay_ms(200);
//                PORTBbits.buzzer = 1; // beep buzzer
//                __delay_ms(20);
//                if (press_count > long_press_threshold) {
//                    ups_switch = !ups_switch; // Toggle ups_switch_on state
//                    press_count = 0; // Reset press count after toggling
//
//                }
//            } else {
//
//            press_count = 0; // Reset press count 
//        }
//        /**************************************  UPS switching END************************************************/
//
//
//        //        printf("\n press_count: %d\r\n", press_count); // Input voltage contain in veff
//        //        printf("\n ups_switch: %d\r\n", ups_switch); // Input voltage contain in veff
//
//        if (ups_switch == 0) { // switch on condition
//            //            Timer->TimeoutCallbackRegister(Timer_Callback);
//            //            printf("\n ups on: %d\r\n");
//
//            PORTBbits.buzzer = 0;
//            if (Veff > 0) {
//                // input power supply greater than 0
//                //                Timer->TimeoutCallbackRegister(Timer_Callback);
//               // printf("\n AC Input voltage: %d\r\n", Veff);
//                sineIndex = 270;
////                __delay_ms(2000);
//                //                printf("\n voltage: %d\r\n", Veff); // Input voltage contain in veff
//                PORTBbits.red_led = 0; // d2 led
//                __delay_ms(10);
//                PORTBbits.green_led = 1; // d3 led
//                __delay_ms(10);
//                PORTBbits.relay2 = 1; // AC bypass on
//                //  printf("\n voltage: %d\r\n", Veff); // Input voltage contain in veff
//                //                printf("\n AC on: %d\r\n"); // Input voltage contain in veff
//                
//                
//            } else {
//                //                printf("\n voltage: %d\r\n", Veff); // Input voltage contain in veff
//                //                Timer->TimeoutCallbackRegister(Timer_Callback);
//                if(dc_vol >= 10.5)
//                {
//                
////                 Timer->TimeoutCallbackRegister(Timer_Callback);
//                 printf("\n dc_battery_volt: %d\r\n", dc_vol); 
//                }else
//                {
//                // Timer->TimeoutCallbackRegister(Timer_Callback)=0;
//                 printf("\n dc_battery_volt: %d\r\n", dc_vol); 
//                }
//                
//                
//             //   printf("\n AC Input voltage: %d\r\n", Veff);
//                PORTBbits.green_led = 0; // d3 led
//                PORTBbits.red_led = 1; // d2 led
//                __delay_ms(10);
//                PORTBbits.relay2 = 0; // AC bypass off
//                //                printf("\n AC OFF: %d\r\n"); // Input voltage contain in veff
//            }
//
//                
//        } else { // switch off condition
//            //            printf("\n ups off: %d\r\n");
//            ups_off_condition();
//            //            Timer->TimeoutCallbackRegister(Timer_Callback);
//
//        }
//
    }
}










































///* Required header files for ADC Example 1 */
//#include "mcc_generated_files/system/system.h"
//#include "mcc_generated_files/system/clock.h"
//
//#define FCY CLOCK_PeripheralFrequencyGet()
//#include <libpic30.h>
//
//
//#include "mcc_generated_files/uart/uart1.h"
//#include "mcc_generated_files/system/pins.h"
//#include "mcc_generated_files/pwm_hs/pwm.h"
//#include "mcc_generated_files/timer/tmr1.h"
//#include <math.h>
///************************<<<< PWM generate code >>>>>>*********************************/
//static uint16_t sineIndex = 0;
//
//#define SINE_TABLE_SIZE 256
//const uint16_t sineTable[SINE_TABLE_SIZE] = {
//100, 102, 105, 107, 110, 112, 115, 117,
//120, 122, 124, 127, 129, 131, 134, 136,
//138, 141, 143, 145, 147, 149, 151, 153,
//156, 158, 160, 162, 163, 165, 167, 169,
//171, 172, 174, 176, 177, 179, 180, 182,
//183, 184, 186, 187, 188, 189, 190, 191,
//192, 193, 194, 195, 196, 196, 197, 198,
//198, 199, 199, 199, 200, 200, 200, 200,
//200, 200, 200, 200, 200, 199, 199, 199,
//198, 198, 197, 196, 196, 195, 194, 193,
//192, 191, 190, 189, 188, 187, 186, 184,
//183, 182, 180, 179, 177, 176, 174, 172,
//171, 169, 167, 165, 163, 162, 160, 158,
//156, 153, 151, 149, 147, 145, 143, 141,
//138, 136, 134, 131, 129, 127, 124, 122,
//120, 117, 115, 112, 110, 107, 105, 102,
//100, 98, 95, 93, 90, 88, 85, 83,
//80, 78, 76, 73, 71, 69, 66, 64,
//62, 59, 57, 55, 53, 51, 49, 47,
//44, 42, 40, 38, 37, 35, 33, 31,
//29, 28, 26, 24, 23, 21, 20, 18,
//17, 16, 14, 13, 12, 11, 10, 9,
//8, 7, 6, 5, 4, 4, 3, 2,
//2, 1, 1, 1, 0, 0, 0, 0,
//0, 0, 0, 0, 0, 1, 1, 1,
//2, 2, 3, 4, 4, 5, 6, 7,
//8, 9, 10, 11, 12, 13, 14, 16,
//17, 18, 20, 21, 23, 24, 26, 28,
//29, 31, 33, 35, 37, 38, 40, 42,
//44, 47, 49, 51, 53, 55, 57, 59,
//62, 64, 66, 69, 71, 73, 76, 78,
//80, 83, 85, 88, 90, 93, 95, 98
//};
//
//
//const struct TIMER_INTERFACE * Timer = &Timer1;
//
//void Timer_Callback(void) {
//
//    //LED_Toggle();
//    //   PWM_DutyCycleSet(PWM_GENERATOR_1, sineTable[sineIndex]);
//    //    sineIndex = (sineIndex + 1) % SINE_TABLE_SIZE;
//    //    static uint16_t sineIndex = 0;
//
//    // Update PWM duty cycle from sine table
//    PWM_DutyCycleSet(PWM_GENERATOR_1, sineTable[sineIndex]);
////    __delay_ms(10);
//    PWM_DutyCycleSet(PWM_GENERATOR_2, sineTable[sineIndex]);
////    __delay_ms(10);
//    sineIndex++;
//    if (sineIndex >= SINE_TABLE_SIZE) {
//        sineIndex = 0;
//    }
//}
///************************<<<< PWM generate code >>>>>>*****************************/
//
//
///**********************ADC interface start**************/
//
//#include "mcc_generated_files/adc/adc1.h"
//const struct ADC_INTERFACE *adc = &ADC1;
//const struct UART_INTERFACE *UartSerial = &UART1_Drv;
//#define ADC_RESOLUTION 4096
////uint16_t volatile adcResult;
//uint16_t volatile ac_input_voltage; // contain data of AN2  - RB7
//uint16_t volatile ac_output_voltage; // contain data of AN10 - RB8
//uint16_t volatile ac_input_current; // contain data of AN9  - RA2
//uint16_t volatile ac_output_current; // contain data of AN3  - RA3
//uint16_t volatile dc_battery_volt; // contain data of AN0  - RA0
//uint16_t volatile acvolt_in;
///**********************ADC interface end**************/
//
///***********************GPIO pins declararion Start****************************/
//
//#define relay1            RB10         // here by this pin battery charging relay on
//#define relay2            RB2        // here by this pin ac bypass in ouput
//#define relay3            RB11        // here by this pin ac out using inverter circuit
//#define buzzer            RB1         // here by this we can control buzzer
//#define switch            RB4         // By this pin switch ON/OFF
//#define red_led           RB9         // Here D2 led control
//#define green_led         RB3         // Here D3 led control
//
///***********************GPIO pins declararion Start****************************/
//
//void pins_initialization() {
//
//    TRISBbits.TRISB2 = 0; // here by this pin battery charging relay on
//    TRISBbits.TRISB10 = 0; // here by this pin ac bypass in ouput
//    TRISBbits.TRISB11 = 0; // here by this pin ac out using inverter circuit
//    TRISBbits.TRISB1 = 0; // here by this we can control buzzer
//
//    TRISBbits.TRISB9 = 0; // Here D2 led control
//    TRISBbits.TRISB3 = 0; // Here D3 led control
//
//    TRISBbits.TRISB4 = 1; // By this pin switch ON/OFF
//
//}
///***********************GPIO pins diclararion END****************************/
//
///*****************************Switch long press ****************************************/
//
//unsigned int press_count = 0; // for switch condition
//unsigned int long_press_threshold = 2; // Threshold for long press (~2 seconds at 1ms intervals) for switch condition
//uint16_t volatile ups_switch;
//
///*****************************Switch long press ****************************************/
//
//
//
///***********************************AC voltage mapping declaration***********************************/
//uint16_t volatile ac_input_voltage = 0;
////double sensorValue2 = 0;
//int crosscount = 0;
//int climb_flag = 0;
//int val[100]; // Array to store sensor values
//int max_v = 0;
//int VmaxD = 0; // Max voltage
//int VeffD = 0; // Effective voltage
//int Veff = 0; // Resulting voltage
//
//void ac_volt_in() {
//    /******************** Ac volt input START ***********************/
//    for (int i = 0; i < 100; i++) {
//
//        if (adc->ConversionResultGet(Channel_AN2) > 2040) {
//            val[i] = ac_input_voltage; // Store sensor value in the array if it's greater than 511
//        } else {
//            val[i] = 0; // Otherwise, set the value to 0
//        }
//        __delay_ms(1); // Short delay for stability
//    }
//
//    // Find the maximum sensor value in the array
//    max_v = 0;
//    for (int i = 0; i < 100; i++) {
//        if (val[i] > max_v) {
//            max_v = val[i]; // Update max_v if a higher value is found
//        }
//        val[i] = 0; // Reset the array element to 0
//    }
//
//    // Calculate effective voltage based on the maximum sensor value
//    if (max_v != 0) {
//        VmaxD = max_v; // Set VmaxD to the maximum sensor value
//        VeffD = VmaxD / sqrt(2); // Calculate effective voltage (RMS) from VmaxD
//        //        Veff = (((VeffD - 2200.27) / -90.24) * -210.2) + 10 ;  // Apply calibration and scaling to Veff//42.76
//        //        Veff = ((VeffD - 2210)/3); // here accurate mapping
//        Veff = ((VeffD - 2587) / 2) + 230; // here accurate mapping
//        //Veff = ((VeffD - 600) / 2) + 230; // here accurate mapping
//                if (Veff <= 100) {
//                    Veff = 0; // If no maximum value, set Veff to 0
//                }
//    } else {
//        Veff = 0; // If no maximum value, set Veff to 0
//
//    }
////    printf("\n VeffD: %d\r\n", VeffD); // Input voltage contain in veff
////    printf("\n voltage: %d\r\n", Veff); // Input voltage contain in veff
//
//    __delay_ms(100);
//    VmaxD = 0; // Reset VmaxD for the next iteration
//
//    // Delay for 100 milliseconds before the next loop
//
//}
//
///***********************************AC voltage INPUT END mapping declaration***********************************/
//
///*****************************AC OUTPUT VOLTAGE START********************************************/
//uint16_t volatile ac_output_voltage = 0;
////double sensorValue2 = 0;
//int crosscount_ac_out = 0;
//int climb_flag_ac_out = 0;
//int val_ac_out[100]; // Array to store sensor values
//int max_v_ac_out = 0;
//int VmaxD_ac_out = 0; // Max voltage
//int VeffD_ac_out = 0; // Effective voltage
//int Veff_ac_out = 0; // Result
//
//void ac_volt_out() {
//    /******************** Ac volt input ***********************/
//    for (int j = 0; j < 100; j++) {
//
//        if (adc->ConversionResultGet(Channel_AN10) > 2040) {
//            val_ac_out[j] = ac_output_voltage; // Store sensor value in the array if it's greater than 511
//        } else {
//            val_ac_out[j] = 0; // Otherwise, set the value to 0
//        }
//        __delay_ms(1); // Short delay for stability
//    }
//
//    // Find the maximum sensor value in the array
//    max_v_ac_out = 0;
//    for (int j = 0; j < 100; j++) {
//        if (val_ac_out[j] > max_v_ac_out) {
//            max_v_ac_out = val_ac_out[j]; // Update max_v if a higher value is found
//        }
//        val_ac_out[j] = 0; // Reset the array element to 0
//    }
//
//    // Calculate effective voltage based on the maximum sensor value
//    if (max_v_ac_out != 0) {
//        VmaxD_ac_out = max_v_ac_out; // Set VmaxD to the maximum sensor value
//        VeffD_ac_out = VmaxD_ac_out / sqrt(2); // Calculate effective voltage (RMS) from VmaxD
//        //        Veff = (((VeffD - 2200.27) / -90.24) * -210.2) + 10 ;  // Apply calibration and scaling to Veff//42.76
//        //        Veff = ((VeffD - 2210)/3); // here accurate mapping
//        Veff_ac_out = ((VeffD_ac_out - 2587) / 2) + 230; // here accurate mapping
//        //Veff = ((VeffD - 600) / 2) + 230; // here accurate mapping
//                if (Veff_ac_out <= 150) {
//                    Veff_ac_out = 0; // If no maximum value, set Veff to 0
//                }
//    } else {
//        Veff_ac_out = 0; // If no maximum value, set Veff to 0
//
//    }
////    printf("\n VeffD: %d\r\n", VeffD); // Input voltage contain in veff
//   // printf("\n AC Output voltage: %d\r\n", Veff_ac_out); // Input voltage contain in veff
//
//    __delay_ms(100);
//    VmaxD_ac_out = 0; // Reset VmaxD for the next iteration
//
//    // Delay for 100 milliseconds before the next loop
//
//}
///*****************************AC OUTPUT VOLTAGE********************************************/
//
//
///********************************DC Volt Sensor start*******************************/
//int dc_vol ;
//void Dc_volt_sense() {
// 
//
// dc_vol =((dc_battery_volt * 3.3/ 4096)*4)+1 ;
//// printf("\n dc_battery_volt: %d\r\n", dc_vol); 
//}
//
//void Dc_current_sense() {
//
//
//}
///********************************DC Volt Sensor End*******************************/
//
///****************************ups off condition***************************/
//void ups_off_condition() {
//
//    PORTBbits.buzzer = 0;
//    __delay_ms(10);
//    PORTBbits.red_led = 1;
//    __delay_ms(10);
//    PORTBbits.green_led = 1;
//    __delay_ms(10);
//    PORTBbits.relay2 = 0; // ac bypass relay off
//    //            printf("\n ups off: %d\r\n"); // Input voltage contain in veff
//    // beep buzzer
//}
//
//int main(void) {
//    SYSTEM_Initialize();
//    pins_initialization();
//    ups_switch = PORTBbits.switch; // here this pin use for ups switch
// Timer->TimeoutCallbackRegister(Timer_Callback);
//// Timer->Stop();
//    while (1) {
//// PWM_DutyCycleSet(PWM_GENERATOR_1, 190);
//        adc->SoftwareTriggerEnable(); //Trigger the ADC conversion via software
//
//        /*****************************************READ ADC PIN****************************************************/
//        ac_input_voltage = adc->ConversionResultGet(Channel_AN2); // RB7 pin here sensing AC input voltage
//        ac_output_voltage = adc->ConversionResultGet(Channel_AN10); // RB8 pin here sensing AC output voltage
//        ac_input_current = adc->ConversionResultGet(Channel_AN9); // RA2 pin here sensing AC input current
//        ac_output_current = adc->ConversionResultGet(Channel_AN3); // RA3 pin here sensing AC output current
//        dc_battery_volt = adc->ConversionResultGet(Channel_AN0); // RA0 pin here sensing battery voltage
//        ac_volt_in();
//        ac_volt_out();
//        Dc_volt_sense();
//        //        printf("acvolt_in: %d\r\n", acvolt_in);
//        /*****************************************READ ADC PIN****************************************************/
//       
//
//        /**************************************  UPS switching start ************************************************/
//
//        if (PORTBbits.switch == 0) { // Double-check if the switch is still pressed
//
//                press_count++;
//
//                PORTBbits.buzzer = 0; // beep buzzer
//                __delay_ms(200);
//                PORTBbits.buzzer = 1; // beep buzzer
//                __delay_ms(20);
//                if (press_count > long_press_threshold) {
//                    ups_switch = !ups_switch; // Toggle ups_switch_on state
//                    press_count = 0; // Reset press count after toggling
//
//                }
//            } else {
//
//            press_count = 0; // Reset press count 
//        }
//        /**************************************  UPS switching END************************************************/
//
//
//        //        printf("\n press_count: %d\r\n", press_count); // Input voltage contain in veff
//        //        printf("\n ups_switch: %d\r\n", ups_switch); // Input voltage contain in veff
//
//        if (ups_switch == 0) { // switch on condition
//            //            Timer->TimeoutCallbackRegister(Timer_Callback);
//            //            printf("\n ups on: %d\r\n");
//
//            PORTBbits.buzzer = 0;
//            if (Veff > 0) {
//                // input power supply greater than 0
//                //                Timer->TimeoutCallbackRegister(Timer_Callback);
//               // printf("\n AC Input voltage: %d\r\n", Veff);
//                sineIndex = 270;
////                __delay_ms(2000);
//                //                printf("\n voltage: %d\r\n", Veff); // Input voltage contain in veff
//                PORTBbits.red_led = 0; // d2 led
//                __delay_ms(10);
//                PORTBbits.green_led = 1; // d3 led
//                __delay_ms(10);
//                PORTBbits.relay2 = 1; // AC bypass on
//                //  printf("\n voltage: %d\r\n", Veff); // Input voltage contain in veff
//                //                printf("\n AC on: %d\r\n"); // Input voltage contain in veff
//                
//                
//            } else {
//                //                printf("\n voltage: %d\r\n", Veff); // Input voltage contain in veff
//                //                Timer->TimeoutCallbackRegister(Timer_Callback);
//                if(dc_vol >= 10.5)
//                {
//                
////                 Timer->TimeoutCallbackRegister(Timer_Callback);
//                 printf("\n dc_battery_volt: %d\r\n", dc_vol); 
//                }else
//                {
//                // Timer->TimeoutCallbackRegister(Timer_Callback)=0;
//                 printf("\n dc_battery_volt: %d\r\n", dc_vol); 
//                }
//                
//                
//             //   printf("\n AC Input voltage: %d\r\n", Veff);
//                PORTBbits.green_led = 0; // d3 led
//                PORTBbits.red_led = 1; // d2 led
//                __delay_ms(10);
//                PORTBbits.relay2 = 0; // AC bypass off
//                //                printf("\n AC OFF: %d\r\n"); // Input voltage contain in veff
//            }
//
//                
//        } else { // switch off condition
//            //            printf("\n ups off: %d\r\n");
//            ups_off_condition();
//            //            Timer->TimeoutCallbackRegister(Timer_Callback);
//
//        }
//
//    }
//}



















