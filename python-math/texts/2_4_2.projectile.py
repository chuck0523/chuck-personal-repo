from matplotlib import pyplot as plt
import math

def draw_graph(x, y):
    plt.plot(x, y)
    plt.xlabel('x-coordinate')
    plt.ylabel('y-coordinate')
    plt.title('Projectile motion of a ball')

def frange(start, final, increment):
    numbers = []
    while start < final:
        numbers.append(start)
        start = start + increment
    return numbers

def draw_trajectory(u, theta):
    theta = math.radians(theta)
    g = 9.8
    # Time of flight
    t_flight = 2*u*math.sin(theta)/g
    # Find time intervals
    intervals = frange(0, t_flight, 0.001)
    # list of x and y coordinates
    x = []
    y = []
    for t in intervals:
        x.append(u*math.cos(theta)*t)
        y.append(u*math.sin(theta)*t - 0.5*g*t*t)
    draw_graph(x, y)

if __name__ == '__main__':
    try:
        u1 = float(input('Enter the initial velocity (m/s): '))
        u2 = float(input('Enter the initial velocity (m/s): '))
        u3 = float(input('Enter the initial velocity (m/s): '))
        theta = float(input('Enter the angle of projectile (degrees): '))
    except ValueError:
        print('You entered an invalid input')
    else:
        u_list = [u1, u2, u3]
        for u in u_list:
            draw_trajectory(u, theta)
        plt.legend(['u1', 'u2', 'u3'])
        plt.show()
