# showlist = [1, 2, 3]
# print(sum(showlist)) # 6
# print(len(showlist)) # 3

def calculate_mean(numbers):
    S = sum(numbers)
    N = len(numbers)
    mean = S/N
    return mean

if __name__ == '__main__':
    donations = [100, 60, 70, 900, 100, 200, 500, 500, 503, 600, 1000, 1200]
    mean = calculate_mean(donations)
    N = len(donations)
    print('Mean donation over last {0} days is {1}'.format(N, mean))
