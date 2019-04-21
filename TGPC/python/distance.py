# -*- coding: utf-8 -*-

import re

from sys import stdin
from collections import defaultdict


cities = defaultdict(dict)

min_distance = None
max_distance = 0


def generate_paths():
    for city, neighbours in cities.items():
        generate_path(city, neighbours, list(), 0)


def generate_path(city, neighbours, current_path, current_distance):
    global min_distance, max_distance

    current_path = list(current_path) + [city]

    if len(current_path) == len(cities.keys()):
        if min_distance is None or current_distance < min_distance:
            min_distance = current_distance

        if current_distance > max_distance:
            max_distance = current_distance

        return

    for neighbour in neighbours.keys():
        if neighbour in current_path:
            continue

        new_distance = current_distance + cities[city][neighbour]

        generate_path(neighbour, cities[neighbour], list(current_path), new_distance)


if __name__ == "__main__":
    city_names = []

    for line in stdin:
        first, second, distance = re.match('(\w+) til (\w+) = (\d+)', line).groups()

        if first not in city_names:
            city_names.append(first)

        if second not in city_names:
            city_names.append(second)

        distance = int(distance)

        cities[first][second] = distance
        cities[second][first] = distance

    generate_paths()

    print(min_distance)
    print(max_distance)
