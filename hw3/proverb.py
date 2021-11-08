from functools import total_ordering

import wisdom_helper


@total_ordering
class Proverb:
    def __init__(self, text="", country=""):
        self.text = text
        self.country = country

    def __lt__(self, other):
        return self.text < other.text

    def print(self, ostream):
        wisdom_helper.print(ostream, wisdom_type="Proverb", data_type="country", text=self.text, data=self.country)

    def input(self, istream):
        self.text, self.country = wisdom_helper.input(istream)

    def punctuation_divide(self):
        wisdom_helper.punctuation_divide(self.text)
