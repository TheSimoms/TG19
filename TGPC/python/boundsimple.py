# -*- coding: utf-8 -*-

from sys import stdin


if __name__ == "__main__":
    n = int(stdin.readline().strip())
    x_points = []
    y_points = []

    x_min = 0
    x_max = 0
    y_min = 0
    y_max = 0

    for line in stdin:
        stripped = line.strip().split(' ')

        x = int(stripped[0])
        y = int(stripped[1])

        x_min = min(x_min, x)
        x_max = max(x_max, x)
        y_min = min(y_min, y)
        y_max = max(y_max, y)

    print(abs(x_min - x_max) * abs(y_min - y_max))
