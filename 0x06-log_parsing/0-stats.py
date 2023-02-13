import random
import sys
from time import sleep
import datetime

# loop counter
counter = 0

# Infinite loop
while True:
    # wait for a random time
    sleep(random.random())

    # Write a random log line to the standard output
    sys.stdout.write("{:d}.{:d}.{:d}.{:d} - [{}] \"GET /projects/260 HTTP/1.1\" {} {}\n".format(
        random.randint(1, 255), random.randint(1, 255), random.randint(1, 255), random.randint(1, 255),
        datetime.datetime.now(),
        random.choice([200, 301, 400, 401, 403, 404, 405, 500]),
        random.randint(1, 1024)
    ))
    sys.stdout.flush()

    # increment counter
    counter += 1

    # exit loop after 10000 iterations
    if counter == 10000:
        break
