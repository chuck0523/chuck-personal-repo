from sympy import FiniteSet
import random

def find_prob(target_score, max_rolls):
    die_sides = FiniteSet(1,2,3,4,5,6)

    # sample space
    s = die_sides**max_rolls

    # find the event set
    if max_rolls > 1:
        success_rolls = []
        for elem in s:
            if sum(elem) >= target_score:
                success_rolls.append(elem)
    else:
        if target_score > 6:
            success_rolls = []
        else:
            for roll in die_sides:
                if roll >= target_score:
                    success_rolls.append(roll)
    e = FiniteSet(*success_rolls)

    # calculate the probability of reaching target score

    return len(e)/len(s)

def roll():
    return random.randint(1, 6)

if __name__ == '__main__':
    target_score = int(input('Target Score: '))
    max_rolls = int(input('Maximum rolls count: '))
    p = find_prob(target_score, max_rolls)
    print('Probability: {0:.5f}'.format(p))
