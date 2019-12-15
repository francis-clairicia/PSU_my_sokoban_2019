# -*- conding: Utf-8 -*
##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## menu.py
##

import os
import curses
from gameplay import Gameplay

BLACK = curses.COLOR_BLACK
RED = curses.COLOR_RED
YELLOW = curses.COLOR_YELLOW
CYAN = curses.COLOR_CYAN

TITLE_COLOR = 1
TEXT_COLOR = 2
CURSOR_COLOR = 3

class Menu:

    def __init__(self, win):
        self.window = win
        self.title = "My Sokoban"
        self.option_list = [
            ("1 player mode", lambda mode=1 : self.show_available_maps(mode)),
            ("2 player mode", lambda mode=2 : self.show_available_maps(mode)),
            ("Exit", self.quit)
        ]
        self.cursor = 0
        self.maps_folder = "./maps"
        curses.init_pair(TITLE_COLOR, RED, BLACK)
        curses.init_pair(TEXT_COLOR, YELLOW, BLACK)
        curses.init_pair(CURSOR_COLOR, CYAN, BLACK)

    def run(self):
        self.done = False
        while not self.done:
            self.window.clear()
            self.print_main_menu(0.5, True)
            self.window.refresh()
            self.handle_event(self.window.getch(), self.option_list)

    def quit(self):
        self.done = True

    def print_main_menu(self, cols_factor, show_cursor):
        title = (self.title, curses.A_BOLD | curses.A_UNDERLINE | curses.color_pair(TITLE_COLOR))
        options = [
            [option[0], curses.color_pair(TEXT_COLOR)] for option in self.option_list
        ]
        y, x, h, w = self.print_menu(cols_factor, title, ("", 0), *options)
        if not show_cursor:
            return
        for i, option in enumerate(options):
            if self.cursor == i:
                self.window.addstr(y + 2 + i, x + 3, ">", curses.color_pair(CURSOR_COLOR))

    def print_menu(self, cols_factor, *lines_to_print):
        nb_lines_menu = len(lines_to_print)
        nb_lines_border = nb_lines_menu + 4
        nb_cols_border = max(len(line[0]) for line in lines_to_print) + 10
        first_line = (self.window.getmaxyx()[0] // 2) - (nb_lines_menu // 2)
        for j in range(nb_lines_border):
            line = ""
            y = first_line - 2 + j
            for i in range(nb_cols_border):
                if j == 0 or j == nb_lines_border - 1:
                    line += "#"
                elif i == 0 or i == nb_cols_border - 1:
                    line += "#"
                else:
                    line += " "
            first_col = self.print(line, y, cols_factor)
        for i, line in enumerate(lines_to_print):
            self.print(line[0], first_line + i, cols_factor, line[1])
        return first_line, first_col, nb_lines_border, nb_cols_border

    def print(self, str_to_print, line, cols_factor, *args):
        cols = (self.window.getmaxyx()[1] * cols_factor) - (len(str_to_print)) / 2
        self.window.addstr(int(line), int(cols), str(str_to_print), *args)
        return int(cols)

    def handle_event(self, key, option_list):
        if key == -1:
            return
        if key == ord('\n'):
            option_list[self.cursor][1]()
            self.cursor = 0
            self.show_map = False
        if key in [curses.KEY_UP, curses.KEY_DOWN]:
            self.move_cursor(key, option_list)

    def move_cursor(self, key, option_list):
        self.cursor += -1 if key == curses.KEY_UP else 1
        if self.cursor < 0:
            self.cursor = len(option_list) - 1
        elif self.cursor >= len(option_list):
            self.cursor = 0

    def show_available_maps(self, gameplay_mode):
        self.show_map = True
        self.cursor = 0
        if not os.path.isdir(self.maps_folder):
            os.mkdir(self.maps_folder)
        if len(os.listdir(self.maps_folder)) == 0:
            lines = [("There is no map in 'maps' folder.", curses.color_pair(TEXT_COLOR)),
                ("", 0),
                ("You need to create maps to play.", curses.color_pair(TEXT_COLOR))]
            while self.show_map:
                self.window.clear()
                self.print_main_menu(0.25, False)
                self.print_menu(0.75, *lines)
                self.window.refresh()
                if (self.window.getch() == ord('\n')):
                    self.show_map = False
            return
        title = ("Maps", curses.A_BOLD | curses.A_UNDERLINE | curses.color_pair(TITLE_COLOR))
        option_list = [
            (file, lambda window=self.window, file=os.path.join(self.maps_folder, file), mode=gameplay_mode: Gameplay(window, file, mode).run())
            for file in os.listdir(self.maps_folder)
        ]
        option_list.append(("Return", lambda: True))
        options = [
            [option[0], curses.color_pair(TEXT_COLOR)] for option in option_list
        ]
        while self.show_map:
            self.window.clear()
            self.print_main_menu(0.25, False)
            y, x, h, w = self.print_menu(0.75, title, ("", 0), *options)
            for i, option in enumerate(options):
                if self.cursor == i:
                    self.window.addstr(y + 2 + i, x + 3, ">", curses.color_pair(CURSOR_COLOR))
            self.window.refresh()
            self.handle_event(self.window.getch(), option_list)
