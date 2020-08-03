import random
import curses
import serial

arduino = serial.Serial("/dev/cu.usbmodem14201", timeout=1)
curses.curs_set(0)
sh, sw = curses.initscr().getmaxyx()
w = curses.newwin(sh, sw, 0, 0)
w.keypad(1)
w.timeout(60)

snk_x = sw/4
snk_y = sh/2
snake = [
    [snk_y, snk_x],
    [snk_y, snk_x-1],
    [snk_y, snk_x-2]
]

food = [sh/2, sw/2]
w.addch(food[0], food[1], curses.ACS_DIAMOND)

key = curses.KEY_RIGHT
D = 0

while True:
    next_key = w.getch()

    X=''
    Y=''
    rawdata = arduino.readline()[:-2].decode("utf-8") 
    for i in range(len(rawdata)):
        if rawdata[i] != ';':
            X += rawdata[i]
        else:
            Y = rawdata[i+1:][:-2]
            break

    if snake[0][0] in [0, sh] or snake[0][1]  in [0, sw] or snake[0] in snake[1:]:
        curses.endwin()
        quit()

    new_head = [snake[0][0], snake[0][1]]
    try:
        if int(X) >= 500 and int(X) <= 550 and int(Y) >= 500 and int(Y) <= 550:
            if D == 3:
                new_head[0] += 1
            if D == 1:
                new_head[0] -= 1
            if D == 2:
                new_head[1] -= 1
            if D == 0:
                new_head[1] += 1

        if int(X) < 500:
            new_head[0] += 1
            D = 3
        if int(X) > 550:
            new_head[0] -= 1
            D = 1
        if int(Y) < 500:
            new_head[1] -= 1
            D = 2
        if int(Y) > 550:
            new_head[1] += 1
            D = 0
    except ValueError:
        curses.endwin()

    snake.insert(0, new_head)

    if snake[0] == food:
        food = None
        while food is None:
            nf = [
                random.randint(1, sh-1),
                random.randint(1, sw-1)
            ]
            food = nf if nf not in snake else None
        w.addch(food[0], food[1], curses.ACS_DIAMOND)
    else:
        tail = snake.pop()
        w.addch(tail[0], tail[1], ' ')
    try:
        w.addch(snake[0][0], snake[0][1], curses.ACS_CKBOARD)
    except:
        curses.endwin()
        quit()