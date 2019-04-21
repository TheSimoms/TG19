# -*- coding: utf-8 -*-

from sys import stdin


if __name__ == "__main__":
    swap_factor = int(stdin.readline().rstrip())
    input_string = stdin.readline().rstrip()
    strings = ['', '']

    for i in range(0, len(input_string), swap_factor):
        strings[i % (swap_factor * 2) != 0] += input_string[i:i+swap_factor]

    string_0_length = len(strings[0])
    string_1_length = len(strings[1])

    longest_common_size = 0
    longest_common_index = None
    matches = [
        [0 for i in range(string_1_length + 1)]
        for j in range(string_0_length + 1)
    ]

    for i in range(string_0_length + 1):
        for j in range(string_1_length + 1):
            if i == 0 or j == 0:
                matches[i][j] = 0
            elif strings[0][i - 1] == strings[1][j - 1]:
                matches[i][j] = matches[i - 1][j - 1] + 1

                if (matches[i][j] > longest_common_size) {
                    longest_common_size = matches[i][j]
                    longest_common_index = j
                }
            else:
                matches[i][j] = 0

    if longest_common_index is None:
        print(None)
    else:
        print(strings[0][longest_common_index - longest_common_size:longest_common_index])
