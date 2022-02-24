number_to_words = {
    1: 'one',
    2: 'two',
    3: 'three',
    4: 'four',
    5: 'five',
    6: 'six',
    7: 'seven',
    8: 'eight',
    9: 'nine',
    10: 'ten',
    11: 'eleven',
    12: 'twelve',
    13: 'thirteen',
    14: 'fourteen',
    15: 'fifteen',
    16: 'sixteen',
    17: 'seventeen',
    18: 'eighteen',
    19: 'nineteen',
    20: 'twenty',
    30: 'thirty',
    40: 'forty',
    50: 'fifty',
    60: 'sixty',
    70: 'seventy',
    80: 'eighty',
    90: 'ninety',
    100: 'one hundred',
    200: 'two hundred',
    300: 'three hundred',
    400: 'four hundred',
    500: 'five hundred',
    600: 'six hundred',
    700: 'seven hundred',
    800: 'eight hundred',
    900: 'nine hundred',
    1000: 'one thousand'
}


def int_to_string(i: int):
    if i in number_to_words:
        return number_to_words[i]

    if i < 100:
        return int_to_string(i - i % 10) + ' ' + int_to_string(i % 10)
    else:
        return int_to_string(i - i % 100) + ' and ' + int_to_string(i % 100)


def string_to_number_of_letters(s: str):
    return sum(len(i) for i in s.split(' '))


def main():
    s = 0

    for i in range(1, 1001):
        word = int_to_string(i)
        num_letters = string_to_number_of_letters(word)
        print(word, ': ', num_letters)
        s += num_letters

    print(s)


if __name__ == '__main__':
    main()