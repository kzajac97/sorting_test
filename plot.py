import numpy as np
import matplotlib.pyplot as plt
 
with open ("data.txt") as f:
    data = f.read()

data = data.split('\n')

#sizes
s = [row.split(' ')[0] for row in data]
#soreted percentage
p = [row.split(' ')[1] for row in data]
#times in micro seconds
t = [row.split(' ')[2] for row in data]
#algorithm used
a = [row.split(' ')[3] for row in data]

fig = plt.figure()

ax1 = fig.add_subplot(111)

ax1.set_title('Title')
ax1.set_xlabel('size')
ax1.set_ylabel('time [$\mu s]')

ax1.plot(s,t, c='r')

leg = ax1.legend()
#save plot to .png file
plt.savefig('plot.png', bbox_inches='tight')