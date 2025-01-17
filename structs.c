#include <stdio.h>
#include <stdlib.h> // for memory allocation

/*
Code from:
https://www.youtube.com/watch?v=w5XM1N7hLgc
"Arrow Operator For Pointers To Structs | C Programming Tutorial"
*/

typedef struct {
    int x;
    int y;
} Point;    // Alias of struct

int main(void){
    Point p1;

    p1.x = 3;
    p1.y = 2;

    printf("p1: (%d, %d)\n", p1.x, p1.y);   // "p1:(3, 2)"

    Point *p2;
    p2 = &p1;   // p2 points to p1

    p2->x = 5;  // change member x of whatever p2 points to
    p2->y = 4;  // ^ for member y

    printf("p1: (%d, %d)\n", p1.x, p1.y);   // "p1:(5, 4)"
    printf("p1: (%d, %d)\n", p2->x, p2->y); // "p1:(5, 4)"

    Point *p3;
    p3 = malloc(sizeof(Point)); // Allocate memory for size of struct Point

    p3->x = 5;
    p3->y = 10;

    printf("p3: (%d, %d)\n", p3->x, p3->y);   // "p3:(5, 10)"

    (*p3).x = 2;    // bracket notation attains whatever ptr points to
    (*p3).y = 4;        // does not operate w/o the brackets
    // *p3.y = 4; <-- segfault

    printf("p3: (%d, %d)\n", (*p3).x, (*p3).y);   // "p3:(2, 4)"

    return 0;
}