from functools import total_ordering

import wisdom_helper


@total_ordering
class Puzzle:
    def __init__(self, text="", answer=""):
        self.text = text
        self.answer = answer

    def __lt__(self, other):
        return self.text < other.text

    def print(self, ostream):
        wisdom_helper.print(ostream, wisdom_type="Puzzle", data_type="answer", text=self.text, data=self.answer)

    def input(self, istream):
        self.text, self.answer = wisdom_helper.input(istream)

    def punctuation_divide(self):
        wisdom_helper.punctuation_divide(self.text)
