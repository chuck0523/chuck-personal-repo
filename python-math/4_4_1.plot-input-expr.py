from sympy import Symbol, sympify, solve
from sympy.plotting import plot

def plot_expression(expr):
    y = Symbol('y')
    solutions = solve(expr, y)
    expr_y = solutions[0]
    return expr_y

if __name__ == '__main__':
    expr1 = input('Enter your expression in terms of x and y: ')
    expr2 = input('Enter your expression in terms of x and y: ')

    try:
        expr1 = sympify(expr1)
        expr2 = sympify(expr2)
    except SympifyError:
        print('Invalid input')
    else:
        expr1 = plot_expression(expr1)
        expr2 = plot_expression(expr2)
        plot(expr1, expr2)
