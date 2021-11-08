from functools import total_ordering

import wisdom_helper


@total_ordering
class Aphorizm:
    def __init__(self, text="", author=""):
        self.text = text
        self.author = author

    def __lt__(self, other):
        return self.text < other.text

    def print(self, ostream):
        wisdom_helper.print(ostream, wisdom_type="Aphorizm", data_type="author", text=self.text, data=self.author)

    def input(self, istream):
        self.text, self.author = wisdom_helper.input(istream)

    def punctuation_divide(self):
        wisdom_helper.punctuation_divide(self.text)
