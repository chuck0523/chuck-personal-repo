import sys

def isValidNumber(num):
    return float(num).is_integer()

def isEven(num):
    return (num%2 == 0)

def printNums(num):
    for i in range(0, 10):
        print(num + i * 2)

if __name__ == '__main__':
    num = input('Enter a number: ')

    if type(num) != 'int':
        print('Input number.')
        sys.exit()

    intNum = int(num)

    if isEven(num):
        print('It\'s even number.')
    else:
        print('It\'s odd number.')

    printNums(num)
