#include <stdio.h>
#include <stdlib.h> // srand(), rand()
#include <time.h> // time(NULL)
#include <math.h> // void math()

double degree_to_rad(double deg)
{
  return deg * (3.14 / 180);
}

double randomizer()
{
  srand(time(NULL));
  printf("Random number 0-9: %d\n", rand() % 10);
  printf("Random number 80-100: %d\n", 80 + rand() % (100 - 80 + 1));
  printf("Random number 80-100: %d\n", 80 + rand() % (100 - 79));
  printf("Random number 80-100: %d\n", 80 + rand() % (100 - 79));
  return rand() % 360; 
}

void math()
{
  double rad;
  double degree;
  degree = 30;
  rad = degree_to_rad(degree);
  printf("rad: %f\n", rad);
  printf("sin 30 degree: %f\n", sin(rad));
  printf("2 in power of 8: %d\n", (int)pow(2, 8));
 
  degree = randomizer();
  rad = degree_to_rad(degree);
  printf("rad: %lf\n", rad);
  printf("random degree: %d\n", (int)degree);
  printf("sin %d degree: %lf\n", (int)degree, sin(rad));

  printf("floor 3.14: %d\n", (int)floor(3.14));
  printf("sqrt 64: %d\n", (int)sqrt(64));
}

int main(void) 
{
  randomizer();
  math();
  return 0;
}