# -*- coding: utf-8 -*-

import re

from sys import stdin


if __name__ == "__main__":
    string = stdin.readline().strip()
    pattern = stdin.readline().strip().replace('_', '.')

    matches = re.finditer(pattern, string)
    match_starts = []
    match_string = ""

    for match in matches:
        match_starts.append(match.span()[0])
        match_string += '{}\n'.format(match.group())

    print(match_starts)
    print(match_string)
