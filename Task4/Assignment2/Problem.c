#include<stdio.h>
typedef enum operations{
  ADDITION,
  SUBTRACTION,
  MULTIPLICATION,
  DIVISION,
  BITWISE_AND,
  BITWISE_OR,
  LOGICAL_NOT,x2
}operation;
int main(){
    int operand1,operand2;
    char op_char;
    operation oper;
    printf("Enter First Number: ");
    scanf("%d",&operand1);
    printf("Enter Second Number: ");
    scanf("%d",&operand2);
    printf("Enter operation (+, -, *, /, &, |, !): ");
    getchar();
    op_char=getchar();
    switch(op_char){
    case '+':
      oper = ADDITION;
      break;
    case '-':
      oper = SUBTRACTION;
      break;
    case '*':
      oper = MULTIPLICATION;
      break;
    case '/':
      oper = DIVISION;
      break;
    case '&':
      oper = BITWISE_AND;
      break;
    case '|':
      oper = BITWISE_OR;
      break;
    case '!':
      oper = LOGICAL_NOT;
      break;
    default:
      printf("Invalid operation\n");
      break; 
    }
    switch (oper) {
    case ADDITION:
      printf("%d + %d = %d\n", operand1, operand2, operand1 + operand2);
      break;
    case SUBTRACTION:
      printf("%d - %d = %d\n", operand1, operand2, operand1 - operand2);
      break;
    case MULTIPLICATION:
      printf("%d * %d = %d\n", operand1, operand2, operand1 * operand2);
      break;
    case DIVISION:
      if (operand2 == 0) {
        printf("Error: division by zero\n");
        return 1;
      }
      printf("%d / %d = %d\n", operand1, operand2, operand1 / operand2);
      break;
    case BITWISE_AND:
      printf("%d & %d = %d\n", operand1, operand2, operand1 & operand2);
      break;
    case BITWISE_OR:
      printf("%d | %d = %d\n", operand1, operand2, operand1 | operand2);
      break;
    case LOGICAL_NOT:
      printf("!%d = %d\n", operand1, !operand1);
      printf("!%d = %d\n", operand2, !operand2);
      break;
  }
  printf("Size of enum = %d bytes",sizeof(oper));
    /*size of enum is the same size of int[4 bytes] so when we add extra members 
    the size remains 4 bytes */
    return 0;
}