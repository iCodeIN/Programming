cont = 1
while True:

    n,k = map(int,raw_input().split())
    if(n == 0): break

    lista = [0]*n
    for i in xrange(n):
        lista[i] = int(raw_input())

    lista.sort()
    m = {}
    for i in xrange(len(lista)):
        if not lista[i] in m:
            m[lista[i]] = i+1
    print "CASE#" + " " + str(cont) + ":"
    for i in xrange(k):
        x = int(raw_input())
        if(x in m):
            print str(x) + " found at " + str(m[x])
        else: print str(x) + " not found"

    cont += 1
