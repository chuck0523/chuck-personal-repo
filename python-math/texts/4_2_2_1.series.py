from sympy import Symbol, pprint, init_printing
def print_series(n):
    # initialize printing system with reverse order
    init_printing(order='rev-lex')
    x = Symbol('x')
    series = x
    for i in range(2, n + 1):
        series = series + (x**i)/i
    pprint(series)

if __name__ == '__main__':
    n = input('Enter the number of terms you want in the series: ')
    print_series(int(n))
