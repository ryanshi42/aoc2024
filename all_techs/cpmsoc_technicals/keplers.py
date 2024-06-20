from matplotlib import pyplot as plt
from math import floor

from scipy.special import ellipkinc
import cmath

data1 = [-4.590294 + 6.225986j, 51.446238 - 5.523002j]
data2 = [-3.582742 + 14.723887j, 114.739008 - 57.888165j]
data3 = [-2.303329 + 5.60463j, 39.624335 - 17.755224j]
data4 = [-1.260132 + 1.116731j, 16.818653 - 5.81005j]
data5 = [-8.94983j, -47.74764 - 47.74764j]
data6 = [3.000334j, -18.375494 + 18.375494j]
data7 = [0.378225 + 4.923768j, -24.802618 + 28.222322j]
data8 = [2.303329 + 5.60463j, -17.755224 + 39.624335j]
data9 = [2.933247 + 3.817621j, -8.532803 + 32.240556j]
data10 = [2.965209 - 7.215164j, 20.196769 + 52.121386j]
data11 = [8.045719 + 4.202393j, -25.615465 - 42.416083j]

data = [data1,
        data2,
        data3,
        data4,
        data5,
        data6,
        data7,
        data8,
        data9,
        data10,
        data11]

fig, ax = plt.subplots(2, 5)

for i in range(10):
    m = (i + 1)/10
    for d in data:
        point1 = d[0]
        point2 = d[1]
        r1 = abs(point1)
        theta1 = cmath.phase(point1)
        r2 = abs(point2)
        theta2 = cmath.phase(point2)
        result1 = ellipkinc(theta1, m)
        result2 = ellipkinc(theta2, m)
        ax[floor(i/5), i%5].scatter(result1, result2)
        ax[floor(i/5), i%5].set_title(f"m = {m}")
plt.show()