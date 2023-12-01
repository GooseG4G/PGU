import sys
from threading import Thread
from multiprocessing import Process
from time import time

from file_generator import fill


if __name__ == '__main__':
    # PARAMS HANDLER
    PARAMS = {'--size': 2, '--suff': 'MB', '--encoding': 'latin-1', '--count': 5}
    sys.argv.append('--size')
    sys.argv.append('8')
    for n, param in enumerate(sys.argv):
        if param in PARAMS:
            try:
                PARAMS[param] = float(sys.argv[n + 1])
            except TypeError:
                PARAMS[param] = sys.argv[n + 1]

    # SINGLE WORKER
    start = time()
    for i in range(PARAMS['--count']):
        fill(PARAMS['--size'], PARAMS['--suff'], PARAMS['--encoding'])
    print(f'single-time: {time() - start}')

    # THREADS WORKER
    workers = list()
    start = time()
    if '-thread' in sys.argv:
        workers = [Thread(target=fill, args=(PARAMS['--size'], PARAMS['--suff'], PARAMS['--encoding']))
                   for i in range(PARAMS['--count'])]
    elif '-process' in sys.argv:
        workers = [Process(target=fill, args=(PARAMS['--size'], PARAMS['--suff'], PARAMS['--encoding']))
                   for i in range(PARAMS['--count'])]
    for worker in workers:
        worker.start()
    for worker in workers:
        worker.join()
    if workers:
        print(f'thread-time: {time() - start}')
