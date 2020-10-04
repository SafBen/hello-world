import multiprocessing as mp
import time


def f(n):
    a = time.time()
    x = 0
    for i in range(n):
        for j in range(n):
            for k in range(n):
                x += 1
    print("x = ", x, time.time() - a)
    #print('parent process:', os.getppid())
    #print('process id:', os.getpid())


# f(350)

def test():
    a = time.time()
    p1 = mp.Process(target=f, args=(350,))
    p2 = mp.Process(target=f, args=(350,))
    p1.start()
    p2.start()
    p1.join()
    p2.join()
    print("temps global = ", time.time() - a)


def temoin():
    a = time.time()
    f(350)
    f(350)
    print(time.time() - a)


test()
temoin()