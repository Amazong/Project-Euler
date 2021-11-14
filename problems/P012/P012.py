import time

known_divisors = {}


def get_num_divisors(n):
    end = int(n**0.5)
    result = sum(2 for i in range(1, end + 1) if n % i == 0)
    if end**2 == n:
        result -= 1
    return result


def generate_triangle_numbers():
    triangle_number = 1
    n = 2
    while True:
        yield triangle_number
        triangle_number += n
        n += 1


def main():
    target_divisors = 500
    gen = generate_triangle_numbers()
    best_number = 0
    best_num_divisors = 0

    start_time = time.time()
    while True:
        triangle_number = next(gen)

        num_divisors = get_num_divisors(triangle_number)

        if num_divisors > best_num_divisors:
            best_num_divisors = num_divisors
            best_number = triangle_number

        if num_divisors > target_divisors:
            answer_str = f'ANSWER: {triangle_number}'
            num_divs_str = f'NUMBER OF DIVISORS: {num_divisors}'
            len_str = max(len(answer_str), len(num_divs_str))

            print('*' * (len_str + 4))
            print('* ' + str.center(answer_str, len_str) + ' *')
            print('* ' + str.center(num_divs_str, len_str) + ' *')
            print('*' * (len_str + 4))
            break

        print(
            f'Current best: {best_number:7} has {best_num_divisors:3} divisors',
            end='\t|\t',
        )
        print(
            f'{time.time() - start_time:6.2f} seconds elapsed...',
            end='\t|\t',
        )
        print(f'{triangle_number} has {num_divisors} divisors...')


if __name__ == '__main__':
    main()
