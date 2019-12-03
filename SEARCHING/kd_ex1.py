import numpy as np
from sklearn.neighbors import KDTree
from pylab import plot,xlabel,ylabel,show
import time

NRAND = 10000 # how many randoms?

# get the randoms in this box (32 Mpc/h on a side)
rng = np.random.RandomState(0)
ran = rng.random_sample((NRAND, 3))*32
ran[:,2] = ran[:,2]*4./32.

# logarithmically-spaced bins
r = np.linspace(-1, 0.3, 10)
r = 10.0**r
print(r)
tree = KDTree(ran)
xi = tree.two_point_correlation(ran, r)

# remove self-pairs
xi = xi - NRAND

# make these a bin, rather than Npairs(<r)
nbin = len(r)
for i in range(nbin-1):
    xi[i+1] = xi[i+1] - xi[i]

print(xi)
print(r)



