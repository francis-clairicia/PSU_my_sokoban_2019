# -*- coding: Utf-8 -*
##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## map.py
##

import sys
import curses

class Map:

    def __init__(self, file):
        with open(file, "r") as map_file:
            buffer = map_file.read()
        self.default_map = buffer.splitlines()
        self.player = (-1, -1)
        self.boxes = list()
        self.nb_lines = 0
        self.nb_columns = list()
        self.reset()

    def reset(self):
        self.map = self.default_map.copy()
        self.map = [[char for char in line] for line in self.map]
        nb_holes = 0
        for y in range(len(self.map)):
            if len(self.map[y]) == 0:
                sys.exit(84)
            self.nb_columns.append(len(self.map[y]))
            for x in range(len(self.map[y])):
                if self.map[y][x] == "P":
                    self.player = (x, y)
                    self.map[y][x] = " "
                elif self.map[y][x] == "X":
                    self.boxes.append([x, y, True])
                    self.map[y][x] = " "
                elif self.map[y][x] == "O":
                    nb_holes += 1
        if (self.player[0] < 0) or (self.player[1] < 0):
            sys.exit(84)
        if (nb_holes == 0) or (len(self.boxes) == 0) or (len(self.boxes) < nb_holes):
            sys.exit(84)
        self.nb_lines = len(self.map)

    def draw(self, window):
        first_line = (window.getmaxyx()[0] - self.nb_lines) // 2
        first_column = (window.getmaxyx()[1] - max(self.nb_columns)) // 2
        for i, line in enumerate(self.map):
            window.addstr(first_line + i, first_column, "".join(line))
        window.addstr(first_line + self.player[1], first_column + self.player[0], "P")
        for box_x, box_y, movable in self.boxes:
            window.addstr(first_line + box_y, first_column + box_x, "X")
        return first_column, first_line, max(self.nb_columns), self.nb_lines

    def move_player(self, direction):
        move = [
            (0, -1),
            (0, 1),
            (-1, 0),
            (1, 0)
        ]
        for i in range(4):
            if direction[i] is True:
                self.move_player_coords(move[i])

    def move_player_coords(self, move):
        new_pos = (self.player[0] + move[0], self.player[1] + move[1])
        if new_pos[1] < 0 or new_pos[1] >= self.nb_lines:
            return
        if new_pos[0] < 0 or new_pos[0] >= self.nb_columns[new_pos[1]]:
            return
        if self.map[new_pos[1]][new_pos[0]] == "#":
            return
        if not self.move_boxes(self.find_boxes(*new_pos), move):
            return
        self.player = new_pos

    def find_boxes(self, x, y):
        for i, box in enumerate(self.boxes):
            if box[0] == x and box[1] == y:
                return i
        return -1

    def move_boxes(self, index_box, move):
        if index_box < 0:
            return True
        new_pos = (self.boxes[index_box][0] + move[0], self.boxes[index_box][1] + move[1])
        if self.map[new_pos[1]][new_pos[0]] == "#" or self.find_boxes(*new_pos) >= 0:
            return False
        self.boxes[index_box][0] = new_pos[0]
        self.boxes[index_box][1] = new_pos[1]
        self.check_box_movable(index_box)
        return True

    def check_box_movable(self, index_box):
        x = self.boxes[index_box][0]
        y = self.boxes[index_box][1]
        left = self.map[y][x - 1]
        right = self.map[y][x + 1]
        top = self.map[y - 1][x]
        bottom = self.map[y + 1][x]
        if (left in ["#", "X"] and (top in ["#", "X"] or bottom in ["#", "X"])) \
        or (right in ["#", "X"] and (top in ["#", "X"] or bottom in ["#", "X"])):
            self.boxes[index_box][2] = False
