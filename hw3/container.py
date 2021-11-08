import string

from aphorizm import Aphorizm
from puzzle import Puzzle
from proverb import Proverb
import random


class Container:
    def __init__(self):
        self.store = []

    def print(self, ostream):
        ostream.write(f"Container size: {len(self.store)}\n")
        for i in range(len(self.store)):
            ostream.write(f"{i}:\n")
            self.store[i].print(ostream)

    def input(self, istream):
        lines = [i.strip() for i in istream.readlines()]
        objects = zip(lines[0::3], lines[1::3], lines[2::3])
        wismap = {"Aphorism": Aphorizm, "Puzzle": Puzzle, "Proverb": Proverb}
        for wisdom_type, text, data in objects:
            self.store.append(wismap[wisdom_type](text, data))

    def rnd_input(self, n, max_data_size=100):
        def rnd_str():
            st = ""
            while len(st) == 0:
                st = "".join(random.choices(string.punctuation + string.ascii_letters + string.digits + " ",
                                            k=random.randint(1, max_data_size))).strip()
            return st

        wisarr = [Aphorizm, Puzzle, Proverb]
        for i in range(n):
            obj = random.choice(wisarr)(rnd_str(), rnd_str())
            self.store.append(obj)

    def sort(self):
        self.store.sort()
