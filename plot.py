import matplotlib.pyplot as plt
import re

pdata = [[], [], [], [], []]

with open('test.csv', 'r') as f:
    counter = 0
    for l in f.readlines():
        counter += 1
        if (counter > 5) and (l != '\n'):
            res = re.findall(r'(.*);(.*);(.*);(.*);(.*);(.*)', l)
            for i in range(len(res[0])-1):
                pdata[i].append(int(res[0][i]))

fig, ax = plt.subplots(nrows=len(pdata), ncols=1)

for index, row in enumerate(ax):
    row.plot(pdata[index])

plt.show()
