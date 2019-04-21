# -*- coding: utf-8 -*-

from sys import stdin


if __name__ == "__main__":
    inventory = [int(part) for part in stdin.readline().rstrip().split(' ')]
    required_parts = [int(part) for part in stdin.readline().rstrip().split(' ')]
    number_of_parts = len(inventory)

    number_of_robots = max(inventory)

    for i in range(number_of_parts):
        parts_per_robot = required_parts[i]

        if parts_per_robot == 0:
            continue

        max_robots = inventory[i] // parts_per_robot

        if max_robots < number_of_robots:
            number_of_robots = max_robots

    print(number_of_robots)
    print(' '.join([
        str(inventory[i] - number_of_robots * required_parts[i]) for i in range(number_of_parts)
    ]))
