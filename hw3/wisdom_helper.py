import string


def input(istream):
    text = istream.readline.strip()
    data = istream.readline.strip()
    return text, data


def print(ostream, wisdom_type: str, data_type: str, text: str, data: str):
    ostream.write(f"result of PunctuationDivide function: {punctuation_divide(text)}\n")
    ostream.write(f"{wisdom_type}\ntext: {text}\n{data_type}: {data}\n")


def punctuation_divide(text: str):
    return sum(map(text.count, string.punctuation)) / len(text)
