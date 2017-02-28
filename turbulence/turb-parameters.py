#!/usr/bin/python
# ************************************************
# Estimate Initial Turbulence Parameters
# S. Huq, 06 Fe06 Feb
# ************************************************

# import numpy as np
# import math

# Variable
U = 0.1335
I = 0.01
dia = 2
yPlus = 200

# Constant
Cmu = 0.09
K = 0.4               # von Karman constant
nu  = 1.5 * 10 ** -5


# Charachteristic Length Scale

L = 0.07 * dia

# Reynold's number

Re = U * L / nu

# Skin Fric Coeff

Cf = 0.0359 * Re ** -0.2

# TKE

TKE = (3/2.) * ( U * I )** 2
# TKE = ustar ** 2 / Cmu ** 0.5

# USTAR

# ustar = U * Cf ** 0.5
ustar = Cmu ** 0.25 * TKE**0.5

# TDE

eps = Cmu**0.75 * TKE**1.5 / L

# NUT

nut = Cmu * TKE **2 / eps

# DELTA -Y
delY = yPlus * nu / ustar

print ('LEN    ', L)
print ('RE     ', Re)
print ('TKE    ', TKE)
print ('USTAR  ', ustar)
print ('EPS    ', eps)
print ('NUT    ', nut)
print ('Cf     ', Cf)
print ('Y      ', delY)


# References
# http://www.esi-cfd.com/esi-users/turb_parameters/
# https://www.sharcnet.ca/Software/Fluent6/html/ug/node217.htm
# http://www.calpoly.edu/~kshollen/ME554/FLUENT_Summary.pdf
