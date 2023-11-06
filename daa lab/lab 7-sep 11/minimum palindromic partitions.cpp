//sri rama jayam 
#include<iostream>
#include<climits>
using namespace std;

int minPalindromicPartitions(string text) {
    int length = text.length();
    int count = 0;
    bool isPalindromic[length][length]; // 2D array to store palindromic information

    // Initialize the isPalindromic array
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            isPalindromic[i][j] = false;
        }
    }

    // All substrings of length 1 are palindromic
    for (int i = 0; i < length; i++) {
        isPalindromic[i][i] = true;
    }

    // Check for palindromic substrings of length 2 or more
    for (int i = length - 1; i >= 0; i--) {
        for (int j = i + 1; j < length; j++) {
            if (text[i] == text[j]) {
                if (j - i == 1 || isPalindromic[i + 1][j - 1]) {
                    isPalindromic[i][j] = true;
                }
            }
        }
    }

    // Calculate the minimum partitions
    int minPartitions[length];

    for (int i = 0; i < length; i++) {
        if (isPalindromic[0][i]) {
            minPartitions[i] = 0;
        } else {
            minPartitions[i] = INT_MAX;
            for (int j = 0; j < i; j++) {
                if (isPalindromic[j + 1][i] && 1 + minPartitions[j] < minPartitions[i]) {
                    minPartitions[i] = 1 + minPartitions[j];
                }
            }
        }
    }

    return minPartitions[length - 1];
}

int main()
{
    string text="AbbAbbA";
    
    cout<<minPalindromicPartitions(text);
}
