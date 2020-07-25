#TC
arr = [ 12, 11, 13, 5, 6, 7] 

def heapify(node, heap):
    if len(heap)==0 or 2*node+1>=len(heap) or node<0:
        return 
    # next = 2*node+1 if heap[2*node+1]<heap[2*node+2] else 2*node+2
    try:
        next = 2*node+1 + int(heap[2*node+1]>heap[2*node+2])
    except IndexError:
        next = 2*node+1
    if heap[node]>heap[next]:
        heap[node], heap[next] = heap[next], heap[node]
        heapify(next, heap)

def extractMin(heap):
    if len(heap)==0:
        return None
    min = heap[0]
    heap[0] = heap[-1]
    heap.pop()
    heapify(0, heap)
    return min

def insert(ele, heap):
    heap.append(ele)
    point = len(heap)-1
    while heap[(point-1)//2]>heap[point] and point>=0:
        heap[(point-1)//2], heap[point] = heap[point], heap[(point-1)//2]
        point = (point-1)//2

def buildHeap(heap):
    for node in range((len(heap)+1)//2, -1, -1):
        heapify(node, heap)

def heapSort(heap):
    sorted=[]
    buildHeap(heap)
    while len(heap):
        sorted.append(extractMin(heap))
    
    return sorted


print(heapSort(arr))
