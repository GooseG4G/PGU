import sys
from threading import Thread
from multiprocessing import Process
from time import time
import urllib.request

urls = [
    'https://www.pnzgu.ru/',
    'https://moodle.pnzgu.ru/my/',
    'https://lk.pnzgu.ru/portfolio/my',
]


def urlstatus(url):
    with urllib.request.urlopen(url) as u:
        print(f'{url} status: {u.getcode()}')
        return u.getcode()


if __name__ == '__main__':
    # SINGLE WORKER
    start = time()
    for url in urls:
        urlstatus(url)
    print(f'single-time: {time() - start}')

    # THREADS WORKER
    workers = list()
    start = time()
    if '-thread' in sys.argv:
        workers = [Thread(target=urlstatus, args=(url,))
                   for url in urls]
    elif '-process' in sys.argv:
        workers = [Process(target=urlstatus, args=(url,))
                   for url in urls]
    for worker in workers:
        worker.start()
    for worker in workers:
        worker.join()
    if workers:
        print(f'thread-time: {time() - start}')
