import numpy as np
import matplotlib.pyplot as plt

datax, datay = np.loadtxt("datos.txt", unpack = True)

fig, ax = plt.subplots()
ax.plot(datax, datay,'r-o', label="Data")
ax.legend()
ax.set_xlabel("n_terminos")
ax.set_ylabel("Delta %")

fig.savefig("fig.pdf")
