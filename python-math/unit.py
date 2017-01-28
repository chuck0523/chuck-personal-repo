# convert inch to meter
def inchToMeter(inch):
    return (inch * 2.54) / 100

print(inchToMeter(25.5)) # 0.6476999999999999

# convert mile to kilo meter
def mileToKM(mile):
    return mile * 1.609

print(mileToKM(650)) # 1045.85

# convert F templature to C templature
def FtoCTemp(F):
    return (F - 32) * ( 5 / 9 )

print(FtoCTemp(98.6)) # 37.0

def CtoFTemp(C):
    return C * ( 9 / 5 ) + 32

print(CtoFTemp(37)) # 98.60000000000001
