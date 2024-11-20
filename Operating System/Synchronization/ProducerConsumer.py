import threading
import time
import random

buffer = []
BUFFER_SIZE = 5

empty = threading.Semaphore(BUFFER_SIZE)
full = threading.Semaphore(0)
mutex = threading.Semaphore(1)

def producer():
    while True:
        item = random.randint(1,100)
        empty.acquire()
        mutex.acquire()
        buffer.append(item)
        print(f"Producer Produced: {item}")
        mutex.release()
        full.release()
        time.sleep(random.random())

def consumer():
    while True:
        full.acquire()
        mutex.acquire()
        item = buffer.pop(0)
        print(f"Consumer Consumed: {item}")
        mutex.release()
        empty.release()
        time.sleep(random.random())

if __name__ == "__main__":
    producer_thread = threading.Thread(target=producer)
    consumer_thread = threading.Thread(target=consumer)

    producer_thread.start()
    consumer_thread.start()

    producer_thread.join()
    consumer_thread.join()
    