import threading
import time
import random

# Shared variables and semaphores
read_count = 0
read_count_mutex = threading.Semaphore(1)  # Protects `read_count`
write_mutex = threading.Semaphore(1)      # Ensures mutual exclusion for writers

# Reader function
def reader(id):
    global read_count
    while True:
        # Entry Section
        read_count_mutex.acquire()
        read_count += 1
        if read_count == 1:
            write_mutex.acquire()  # First reader locks the writer
        read_count_mutex.release()

        # Critical Section
        print(f"Reader {id} is reading.")
        time.sleep(random.random())  # Simulate reading time

        # Exit Section
        read_count_mutex.acquire()
        read_count -= 1
        if read_count == 0:
            write_mutex.release()  # Last reader unlocks the writer
        read_count_mutex.release()

        # Simulate delay before reading again
        time.sleep(random.random())

# Writer function
def writer(id):
    while True:
        # Entry Section
        write_mutex.acquire()  # Only one writer can write at a time

        # Critical Section
        print(f"Writer {id} is writing.")
        time.sleep(random.random())  # Simulate writing time

        # Exit Section
        write_mutex.release()

        # Simulate delay before writing again
        time.sleep(random.random())

# Main function
if __name__ == "__main__":
    num_readers = 5
    num_writers = 2

    # Create and start threads for readers and writers
    threads = []
    for i in range(num_readers):
        t = threading.Thread(target=reader, args=(i,))
        threads.append(t)

    for i in range(num_writers):
        t = threading.Thread(target=writer, args=(i,))
        threads.append(t)

    for t in threads:
        t.start()

    for t in threads:
        t.join()
