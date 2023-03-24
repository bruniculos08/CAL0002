import matplotlib.pyplot as plt
import numpy as np
import math
plt.style.use("seaborn-deep")

# (1) Caminho da pasta do trabalho:
generalPath = "C:\\Users\\bruni\\OneDrive\\Documentos\\GitHub\\CAL0002\\Trabalho 02\\"

# (2) Gráfico de teste do Quick Sort:

with open(generalPath + "QuickSort\\PerformanceTestCase.txt", 'r') as f:
    lines = f.readlines()

vectorQuickSort = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        vectorQuickSort[j] += float(vector[j])/10

xpointsQuickSort = np.array([x for x in range(0, len(vectorQuickSort))])
ypointsQuickSort = np.array(vectorQuickSort)

plt.xticks(range(0, len(xpointsQuickSort)+1, 100))
plt.plot(xpointsQuickSort, ypointsQuickSort, label="QuickSort", linewidth=0.6)
plt.title("QuickSort")
plt.xlabel("Elementos")
plt.ylabel("Etapas")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics\\QuickSort.png")
plt.close()
f.close()

# (2) Gráfico de testes do Insertion Sort:

with open(generalPath + "InsertionSort\\PerformanceTestCase.txt", 'r') as f:
    lines = f.readlines()

vectorInsertionSort = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        vectorInsertionSort[j] += float(vector[j])/10

xpointsInsertionSort = np.array([x for x in range(0, len(vectorInsertionSort))])
ypointsInsertionSort = np.array(vectorInsertionSort)

plt.plot(xpointsInsertionSort, ypointsInsertionSort, label="InsertionSort", linewidth=0.6)
plt.title("InsertionSort")
plt.xlabel("Elementos")
plt.ylabel("Etapas")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics\\InsertionSort.png")
plt.close()
f.close()

# (3) Gráfico de testes do BubbleSort:

with open(generalPath + "BubbleSort\\PerformanceTestCase.txt", 'r') as f:
    lines = f.readlines()

vectorBubbleSort = [0 for i in range(len(lines[0].split()))]

for line in lines:
    vector = line.split()
    for j in range(len(vector)):
        vectorBubbleSort[j] = float(vector[j])

xpointsBubbleSort = np.array([x for x in range(0, len(vectorBubbleSort))])
ypointsBubbleSort = np.array(vectorBubbleSort)

plt.plot(xpointsBubbleSort, ypointsBubbleSort, label="BubbleSort", linewidth=0.6)
plt.title("BubbleSort")
plt.xlabel("Elementos")
plt.ylabel("Etapas")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics\\BubbleSort.png")
plt.close()
f.close()

# (8) Plotando todos os gráficos em um só:

plt.plot(xpointsQuickSort, ypointsQuickSort, label="QuickSort", linewidth=0.6)
plt.plot(xpointsInsertionSort, ypointsInsertionSort, label="InsertionSort", linewidth=0.6)
plt.plot(xpointsBubbleSort, ypointsBubbleSort, label="xpointsBubbleSort", linewidth=0.6)

plt.title("All Sorting Algorithms")
plt.xlabel("Elementos")
plt.ylabel("Etapas")
plt.legend(loc="upper left")
plt.savefig(generalPath + "Graphics\\AllSorting.png")
plt.close()