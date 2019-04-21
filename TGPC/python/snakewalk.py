# -*- coding: utf-8 -*-

from math import factorial as f
from sys import stdin


if __name__ == "__main__":
    start_x, start_y = [int(pos) for pos in stdin.readline().rstrip().split(',')]
    end_x, end_y = [int(pos) for pos in stdin.readline().rstrip().split(',')]

    x_distance = abs(end_x - start_x)
    y_distance = abs(end_y - start_y)

    min_distance = x_distance + y_distance

    if not (x_distance and y_distance):
        number_of_paths = 1
    else:
        number_of_paths = int(1.0 * f(min_distance) / f(x_distance) / f(y_distance))

    print(min_distance)
    print(number_of_paths)
