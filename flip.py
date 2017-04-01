def flip_byte_order(string):
    flipped = "".join(reversed([string[i:i+2] for i in range(0, len(string), 2)]))
    return flipped

string1 = "031f5855"

print(flip_byte_order(string1))
