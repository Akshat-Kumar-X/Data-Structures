import threading
import time
import random

NUM_PHILOSOPHERS = 5

# Semaphore for each chopstick
chopsticks = [threading.Semaphore(1) for _ in range(NUM_PHILOSOPHERS)]

def philosopher(id):
    while True:
        print(f"Philosopher {id} is thinking.")
        time.sleep(random.random())  # Simulate thinking

        # Pick up chopsticks
        left = id
        right = (id + 1) % NUM_PHILOSOPHERS

        chopsticks[left].acquire()
        chopsticks[right].acquire()

        # Eating
        print(f"Philosopher {id} is eating.")
        time.sleep(random.random())  # Simulate eating

        # Put down chopsticks
        chopsticks[right].release()
        chopsticks[left].release()

if __name__ == "__main__":
    threads = [threading.Thread(target=philosopher, args=(i,)) for i in range(NUM_PHILOSOPHERS)]

    # Start all threads
    for t in threads:
        t.start()

    # Wait for all threads to complete
    for t in threads:
        t.join()
