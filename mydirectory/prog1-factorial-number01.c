/*write a c program to find  factorial of  no by recursion */

#include <stdio.h>
int fact(int n)
{
    int f;
    if (n == 0)
    {
        return (1);
    }
    else
    {
        f = n * fact(n - 1);
        return (f);
    }
}
int main()
{
    int num;
    printf("\n HUMESH DESHMUKH\n ROLL NO. 34");
    printf("\n enter number :");
    scanf("%d", &num);
    printf("\n factorial of number =%d", fact(num));
}