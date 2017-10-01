//Panturu Gloria Sara
// HTL Leonding - 2AHIF - 17/18
//PocketCalculator
#include <stdio.h>
#include <float.h>
int menu();
int prove_choice();
void operations();
double enter_operands();
void add();void substract();void multiply(); void divide();
char prove_max_and_min();
void print_result(double first_operand, double second_operand, double result, char operation_sign);
int main(int argc, char* argv[])
{
  int choice = 0;
  while (choice != -1)
  {
    double first_operand;
    double second_operand;
    choice = menu();
    if (choice != -1)
    {
      second_operand = enter_operands(&first_operand);
      prove_choice(choice);
      operations(choice, first_operand, second_operand);
    }
  }
    return 0;
}

int menu()
{
  int choice = 0;
  printf("Choose one of the following operations:\n" );
  printf("Add (1)\nSubtract (2)\nMultiply (3)\nDivide (4)\nStop program (-1)\nEnter your choice: \n" );
  scanf("%d",&choice );
  choice = prove_choice(choice);
  return choice;
}

int prove_choice(int choice)
{
  while (choice == 0 ||  choice > 4 || choice < -1 )
  {
    printf("Input not allowed, please try again\n" );
    printf("Add (1)\nSubtract (2)\nMultiply (3)\nDivide (4)\nStop program (-1)\nEnter your choice: \n" );
    scanf("%d", &choice );
  }
  return choice;
}

double enter_operands( double* first_operand)
{
  double second_operand;
  printf("Please enter the first operand: " );
  scanf("%lf", &*first_operand );
  printf("Please enter the second operand: " );
  scanf("%lf", &second_operand );
  return second_operand;
}

void operations(int choice, double first_operand, double second_operand)
{
  switch (choice)
  {
    case 1: add(first_operand, second_operand); break;
    case 2: substract(first_operand, second_operand); break;
    case 3: multiply(first_operand, second_operand); break;
    case 4: divide(first_operand, second_operand); break;
    default: break;
  }
  printf("\n" );
}

void print_result( double first_operand, double second_operand, double result, char operation_sign)
{
  printf("%.2lf %c %.2lf = %.2lf\n",first_operand, operation_sign, second_operand, result );
}

void add (double first_operand, double second_operand)
{
  double result;
  char answer;
  char operation_sign;
  operation_sign = '+';
  result = first_operand + second_operand;
  answer = prove_max_and_min(first_operand, second_operand);
  if (answer == 'k')
  {
    print_result(first_operand, second_operand, result, operation_sign);
  }
}

void substract(double first_operand, double second_operand)
{
  double result;
  char answer;
  char operation_sign;
  operation_sign = '-';
  result = first_operand - second_operand;
  answer = prove_max_and_min(first_operand, second_operand);
  if (answer == 'k')
   {
    print_result(first_operand, second_operand, result, operation_sign);
   }
}

void multiply(double first_operand, double second_operand)
{
  double result;
  char answer;
  char operation_sign;
  operation_sign = '*';
  result = first_operand * second_operand;
  answer = prove_max_and_min(first_operand, second_operand);
  if (answer == 'k')
  {
    print_result(first_operand, second_operand, result, operation_sign);
  }
}

void divide (double first_operand, double second_operand)
{
  double result;
  char answer;
  char operation_sign;
  operation_sign = '/';
  if (second_operand != 0)
  {
    result = first_operand / second_operand;
    answer = prove_max_and_min(first_operand, second_operand);
    if (answer == 'k')
    {
    print_result(first_operand, second_operand, result, operation_sign);
    }
  }
  else
  {
    printf("Division by zero\n" );
  }
}

char prove_max_and_min(double first_operand, double second_operand)
{
  if (first_operand > 0 && second_operand > DBL_MAX - first_operand)
  {
    printf("Result overflow\n");
    return 'o';
  }
  else if (first_operand > 0 && second_operand > DBL_MAX - first_operand)
  {
    printf("Result underflow\n");
    return 'u';
  }
  return 'k';
}
