import re
input_file = "input_file"

# Read an input file line by line and analyze it lexically by separating
# it into constants, keywords and identifiers

keywords = set(['int', 'float', 'double', 'real', 'bool', 'do', 'while', 'if',
                'then', 'else', 'return', 'main', 'switch', 'char', 'byte', 'static',
                'void', 'printf', 'true', 'false', 'NULL', 'extern'])

identifiers = re.compile("(_|[a-zA-Z])(\w|_)*")
operator = re.compile("[\=\(==)\+\-\*\/\%\(++)\(--)\^\&]")
constant = re.compile("[+-]?\d*(\.\d+)?")


def matcher(token):
    """Given an input token, return its type as an identifier, keyword or a constant"""
    if token in keywords:
        return "KEYWORD"

    elif identifiers.match(token):
        return "IDENTIFIER"

    elif operator.match(token):
        return "OPERATOR"

    elif constant.match(token):
        return "CONSTANT" if token not in ['+', '-'] else None

    else:
        return None


def main():
    """Reads an input file and does lexical analysis"""

    f = file(input_file, 'r')
    for i in f.readlines():
        print '\n For line: \t', i.strip(), '\n'
        i = i.replace(';', '')
        i = i.replace('\"', '')

        line = i.strip().split(' ')

        for token in line:
            status = matcher(token)
            print token, ' : ', status

    f.close()

if __name__ == '__main__':
    main()
