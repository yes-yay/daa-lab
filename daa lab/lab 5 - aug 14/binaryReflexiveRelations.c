#include <stdio.h>
#include <math.h>
#include <stdbool.h> // Include the boolean type
//sri rama jayam

struct element {
    int xValue;
    int yValue;
};

void tostring(char str[], int num, int n);

void subsets(struct element set[], int n);
int binary(int decimal);



int set[20];

int main() {
    int numberOfElements;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &numberOfElements);

    for (int i = 0; i < numberOfElements; i++) {
        printf("Enter the value of %d element: ", i + 1);
        scanf("%d", &set[i]);
    }
    

    struct element allElements[numberOfElements][numberOfElements];

    for (int i = 0; i < numberOfElements; i++) {
        for (int j = 0; j < numberOfElements; j++) {
            allElements[i][j].xValue = set[i];
            allElements[i][j].yValue = set[j];
        }
    }

    struct element diagonalElements[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        diagonalElements[i].xValue = set[i];
        diagonalElements[i].yValue = set[i];
    }

    struct element nonDiagonalElements[200];
    int k = 0;
    for (int i = 0; i < numberOfElements; i++) {
        for (int j = 0; j < numberOfElements; j++) {
            if (i != j) {
                nonDiagonalElements[k].xValue = set[i];
                nonDiagonalElements[k].yValue = set[j];
                k++;
            }
        }
    }

    printf("The reflexive subsets are: \n");
    printf("{}");

    subsets(nonDiagonalElements,numberOfElements*(numberOfElements-1));

    return 0;
}

void tostring(char str[], int num, int n) {
    int i, rem, len = 0, temp;

    temp = num;
    while (temp != 0) {
        len++;
        temp /= 10;
    }

    if (len < n) {
        int zerosToAdd = n - len;
        for (i = 0; i < zerosToAdd; i++) {
            str[i] = '0';
        }
        for (int j = 0; j < len; j++) {
            rem = num % 10;
            num = num / 10;
            str[zerosToAdd + len - (j + 1)] = rem + '0';
        }
        str[n] = '\0';
    } else {
        for (i = 0; i < len; i++) {
            rem = num % 10;
            num = num / 10;
            str[len - (i + 1)] = rem + '0';
        }
        str[len] = '\0';
    }
}

void subsets(struct element set[], int n) {
    int numSubsets = pow(2, n);
    for (int i = 0; i < numSubsets; i++) {
        int x = binary(i);
        char z[20];
        tostring(z, x, n);

        bool isReflexive = true;

        for (int j = 0; j < n; j++) {
            if (z[j] == '1')
                printf("(%d %d) ", set[j].xValue, set[j].yValue);

            // if (set[j].xValue != set[j].yValue && z[j] == '0') {
            //     isReflexive = false;
            }
            printf("\n");
        }

        // if (isReflexive)
        //     printf("(Reflexive)");

        printf("\n");
    // }
}

int binary(int decimal) {
    int binary = 0;
    int base = 1;

    while (decimal > 0) {
        int remainder = decimal % 2;
        binary += remainder * base;
        base *= 10;
        decimal /= 2;
    }

    return binary;
}
