# -*- coding: utf-8 -*-

from sys import stdin


consonants = 'wnjxzqhmdtlbksrpfvgc'


if __name__ == "__main__":
    word = stdin.read().rstrip()
    result = ''

    for character in word:
        if character.lower() in consonants:
            result += '{}o{}'.format(character, character.lower())
        else:
            result += character

    print(result)
