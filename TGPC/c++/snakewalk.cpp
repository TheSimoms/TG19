#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

using namespace std;


string multiply(string a, string b) {
    int aLength = a.size();
    int bLength = b.size();

    if (aLength == 0 || bLength == 0) {
        return "0";
    }

    // Vector to hold the final result
    vector<int> result(aLength + bLength, 0);

    // Below two indexes are used to find positions in result.
    int indexA = 0;
    int indexB = 0;

    // Multiply from the right
    for (int i = aLength - 1; i >= 0; i--) {
        int carry = 0;
        int aLength = a[i] - '0';

        indexB = 0;

        // Multiply from right to left
        for (int j = bLength - 1; j >= 0; j--) {
            // Next digit
            int bLength = b[j] - '0';

            // Multiply the parts
            int sum = aLength * bLength + result[indexA + indexB];

            // Add the carry
            sum += carry;

            // Divide carry by 10 for next digit
            carry = sum / 10;

            // Store the result
            result[indexA + indexB] = sum % 10;

            // Next digit
            indexB++;
        }

        // Carry is added to the next digit
        if (carry > 0) {
            result[indexA + indexB] += carry;
        }

        // Next digit
        indexA++;
    }

    int i = result.size() - 1;

    // Trim zeros from the right
    while (i >= 0 && result[i] == 0) {
        i--;
    }

    // All zeroes, exit
    if (i == -1) {
        return "0";
    }

    // Build the final result
    string resultString = "";

    while (i >= 0) {
        resultString += to_string(result[i--]);
    }

    return resultString;
}


string divide(string number, int divisor) {
    string result;

    // Part of the number that is bigger than the divisor
    long unsigned int index = 0;
    int part = number[index] - '0';

    // Build a part of the number that is bigger than the divisor
    while (part < divisor) {
       part = part * 10 + (number[++index] - '0');
    }

    // Partially divide, one digit at the time
    while (number.size() > index) {
        // Update result
        result += (part / divisor) + '0';

        // Next digit
        part = (part % divisor) * 10 + number[++index] - '0';
    }

    // If divisor is greater than number, exit
    if (result.length() == 0) {
        return "0";
    }

    return result;
}


string nCr(int n, int r) {
    string res = "1";

    // C(n, k) = C(n, n-k)
    if (r > n - r) {
        r = n - r;
    }

    for (int i = 0; i < r; i++) {
        res = multiply(res, to_string(n - i));
        res = divide(res, i + 1);
    }

    return res;
}

int main() {
    int startX, startY, endX, endY;

    scanf("%d,%d", &startX, &startY);
    scanf("%d,%d", &endX, &endY);

    int distanceX = abs(startX - endX);
    int distanceY = abs(startY - endY);
    int minDistance = distanceX + distanceY;

    string numberOfPaths = nCr(minDistance, distanceX);;

    cout << minDistance << endl << numberOfPaths << endl;

    return 0;
}
