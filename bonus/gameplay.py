# -*- coding: Utf-8 -*
##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## gameplay.py
##

import sys
import time
import curses
from threading import Thread
from map import Map

class Gameplay:

    def __init__(self, window, map_file, nb_player):
        if nb_player == 1:
            self.players = [
                Player(window, map_file, (curses.KEY_UP, curses.KEY_DOWN, curses.KEY_LEFT, curses.KEY_RIGHT), 0)
            ]
        else:
            self.players = [
                Player(window, map_file, (ord('z'), ord('s'), ord('q'), ord('d')), -1),
                Player(window, map_file, (curses.KEY_UP, curses.KEY_DOWN, curses.KEY_LEFT, curses.KEY_RIGHT), 1)
            ]

    def run(self):
        for player in self.players:
            player.start()
        while any(player.is_active() for player in self.players):
            time.sleep(0.05)
            for player in self.players:
                player.show()
        for player in self.players:
            player.join()

class Player(Thread):

    def __init__(self, window, map_file, key_to_move, map_pos):
        Thread.__init__(self)
        if map_pos == 0:
           self.window = window
        else:
            size = window.getmaxyx()
            h = size[0]
            w = size[1] // 2
            x = 0 if map_pos < 0 else w + 1
            self.window = curses.newwin(h, w, 0, x)
            self.window.keypad(True)
            self.window.nodelay(True)
        self.map = Map(map_file)
        self.key_to_move = key_to_move
        self.done = False
        self.start_chrono = time.time()

    def is_active(self):
        return not self.done

    def run(self):
        while not self.done:
            time.sleep(0.05)
            self.handle_key_event(self.window.getch())

    def show(self):
        self.window.clear()
        x, y, w, h = self.map.draw(self.window)
        chrono = int(time.time() - self.start_chrono)
        seconds = chrono % 60
        minuts = chrono // 60
        hours = chrono // 3600
        chrono = "{0:02}:{1:02}:{2:02}".format(hours, minuts, seconds)
        self.window.addstr(y - 2, x, chrono)
        self.window.refresh()

    def handle_key_event(self, key):
        if key == -1:
            return
        if key == ord('w'):
            self.done = True
        direction = [
            bool(key == self.key_to_move[0]),
            bool(key == self.key_to_move[1]),
            bool(key == self.key_to_move[2]),
            bool(key == self.key_to_move[3])
        ]
        self.map.move_player(direction)
