# -*- coding: utf-8 -*-

from sys import stdin


if __name__ == "__main__":
    found = {}
    number_of_matches = 0

    for c in stdin.read().rstrip():
        if c not in found:
            found[c] = 1
            number_of_matches += 1

    print(number_of_matches)
