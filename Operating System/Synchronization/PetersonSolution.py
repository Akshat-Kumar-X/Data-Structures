import threading
import time

flag = [False, False]
turn = 0

def process(id):
    global flag, turn
    other = 1 - id

    flag(id) = True
    turn = other
    while flag[other] and turn == other:
        pass

    print(f"Process {id} is in the critical Section")
    time.sleep(1)

    flag[id] = False
    print(f"Process {id} is leaving the critical Section")

if __name__ == "__main__":
    t1 = threading.Thread(target=process, args=(0,))
    t2 = threading.Thread(target=process, args=(1,))

    t1.start()
    t2.start()

    t1.join()
    t2.join()