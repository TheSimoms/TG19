# -*- coding: utf-8 -*-

from sys import stdin, stdout


if __name__ == "__main__":
    string = stdin.read().rstrip().lower()

    for character in string:
      number = ord(character) + 3

      if number > 122:
        number -= 26

      stdout.write(chr(number))

    stdout.write('\n')
    stdout.flush()
