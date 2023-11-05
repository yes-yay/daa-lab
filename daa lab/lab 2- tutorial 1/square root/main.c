#include <stdio.h>

//sri rama jayam
//sri rama jayam


#include <stdio.h>

double sqrt_babylonian(double n) {
    double guess = n / 2.0;

    for (int i = 0; i < 10; i++) {
        guess = 0.5 * (guess + n / guess);
    }

    return guess;
}

int main() {
    double n;
    printf("Enter a number: ");
    scanf("%lf", &n);

    double result = sqrt_babylonian(n);
    printf("Square root of %lf is approximately %lf\n", n, result);

    return 0;
}



/*
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++)
    {
        if (i * i > n)
        {
            i = i - 1;

            for (double j = 0; j < 1; j = j + 0.1)
            {
                double k = i + j;
                if (k * k > n)
                {
                    j = j - 0.1;
                    k = i + j;

                    for (double l = 0; l < 0.1; l = l + 0.01)
                    {
                        double m = k + l;
                        if (m * m > n)
                        {
                            l = l - 0.01;
                            m = k + l;

                            printf("Approximate square root of %d: %.3lf\n", n, m);
                            return 0;
                        }
                    }
                }
            }
        }
    }

    return 0;
}
*/
