# -*- coding: utf-8 -*-

from sys import stdin


if __name__ == "__main__":
    n = int(stdin.read().rstrip())

    for i in range(1, n + 1):
      fizz = i % 3 == 0
      buzz = i % 5 == 0

      if not (fizz or buzz):
        print(i)
      elif fizz and buzz:
        print('FizzBuzz')
      elif fizz:
        print('Fizz')
      else:
        print('Buzz')
