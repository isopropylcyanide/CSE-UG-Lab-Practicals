import lexical_anal as my_lexical

"""
A program to implement shift reduce parser which takes an input a context free
grammar G and an input string to test whether the input string lies within the
set of rules denotes by G. Several cases lie:
    ** Grammar is incorrect
    ** Input string is not parseable
    ** Error while specifying format
In such cases, raise error accordingly
"""

GRAMMAR_FILE = "grammar_file"


class IllegalProductionError(Exception):
    """raise an error when a production doesn't satisfy CFG requirements"""

    def __init__(self, line, msg):
        self.msg = msg
        self.line = line


class ParsingError(Exception):
    """Raise an error on unsuccessful parsing of a line"""

    def __init__(self, msg):
        self.msg = msg


class Grammar:
    """
    A grammar is a set of production rules of the form A -> B
    where,
        A is the set of non terminals
        B is the set of terminals and non terminals and is not empty
    Each production rule can be represented by a key value pair where key: A
    and value: list of individual subrules
    """

    def __init__(self):
        """Initialize a grammar"""
        self.startSymbol = ''
        self.productions = {}

    def __str__(self):
        """Allow grammar to be printed onto the screen"""
        string = '********GRAMMAR **********\n'
        string += '\n Start Symbol: %s' % (self.startSymbol)
        string += '\n Production Rules := '
        for i in self.productions:
            string += '\n\t%s -> %s' % (i, self.productions[i])

        string += '\n***********************\n'
        return string

    def addProduction(self, line):
        """Add a production rule as parsed from the gven line"""
        if not line:
            raise IllegalProductionError(line, 'Empty production')

        line = map(lambda x: x.strip(), line.split('->'))
        if len(line) != 2:
            raise IllegalProductionError(line, 'Wrong Non Terminal format')

        leftProd, rightProd = line[0], line[1]
        possibleProd = map(lambda x: x.strip(), rightProd.split('|'))

        if len(possibleProd) < 1:
            raise IllegalProductionError(
                line, 'Empty production values are not allowed')

        # set start symbol for the first valid production
        if len(self.productions) == 0:
            self.startSymbol = leftProd

        self.productions[leftProd] = possibleProd


class ShiftReduceParser:
    """
    A shift reduce parser that takes an input a grammar G according to which
    any string is matched. It initializes its structures, namely:
        * A stack for processing read terminals
        * A marker to indicate the current position in stack
    """

    def __init__(self, grammar):
        self.grammar = grammar  # A grammar defining the parsing stages
        self.stack = []  # A stack to maintain the currently read symbols
        self.pos = 0  # denotes the current position of the input symbol
        self.end = 0    # denotes the end of the input symbol

    def isReducible(self, string):
        """Find if a string occurs in rhs of some production"""
        for rule in self.grammar.productions:
            for RHS in self.grammar.productions[rule]:
                if RHS == string:
                    return rule
        return None

    def print_action(self, pos, nextInp, action):
        """Show what action has been taken by the parser"""
        s = (pos,  ', '.join(self.stack), nextInp, action)
        print '\n Pos: %2d \tStack: %35s\t next: %20s \t action: %s ' % s

    def parseInput(self, inp):
        """Core function that parses a given list of symbols on input string
           Only two operations : Shift and reduce
           Only reduce at handles i.e viable prefixes
           Use an NFA to determine whether the state of the parser contains
            a viable prefix.
           Initially, stack is empty. So shift
        """

        inp.append('$')     # Mark the end of the input
        self.stack = ['$']  # Mark the start of the stack
        self.pos, self.end = 0, len(inp) - 1
        action = ''

        if inp is None or len(inp) == 0:
            raise ParsingError('Can\'t parse an empty string')

        self.print_action(self.pos, ' '.join(
            inp), 'Shift %s' % (inp[self.pos]))

        while self.pos != self.end:
            # Check if the current stack symbol can be reduced
            # if not then shift the next symbol
            curVal = inp[self.pos]
            reducedVal = self.isReducible(curVal)

            if reducedVal is not None:
                # Always reduce before shift in shift-reduce conflict
                action = 'Reduce %s -> %s' % (curVal, reducedVal)
                self.stack.append(reducedVal)
            else:  # shift
                action = 'Shift %s' % (curVal)
                self.stack.append(curVal)

            self.pos += 1
            self.print_action(self.pos, ' '.join(inp[self.pos:]), action)
            # After this, check all reducible suffixes of the stack

            while True:
                anyReducible = False
                for i in xrange(1, len(self.stack)):
                    wholeVal = ' '.join(self.stack[i:self.pos + 1])
                    popLength = len(self.stack) - i
                    reducedVal = self.isReducible(wholeVal)

                    if reducedVal is not None:  # reduce
                        anyReducible = True
                        for j in xrange(popLength):
                            self.stack.pop()
                        action = 'Reduce %s -> %s' % (wholeVal, reducedVal)
                        self.stack.append(reducedVal)
                        self.print_action(
                            self.pos, ' '.join(inp[self.pos:]), action)

                if not anyReducible:
                    break

        if len(self.stack) == 2 and self.stack[-1] == self.grammar.startSymbol:
            return True
        return False


def parseUserInput(user_input):
    """Given a user input, use the lexical analyzer to generate tokens
       Return a list containing the value of these tokens"""
    lex = my_lexical.LexicalAnalyzer(my_lexical.regexList)
    lex.input(user_input)

    val = []
    try:
        for tok in lex.tokens():
            val.append(tok.val)
    except my_lexical.UndefinedTokenError:
        print 'Invalid user input: '
    return val


def main():
    """Read grammar from a file and user string
     and  Parseit accordingly"""
    g = Grammar()
    gFile = file(GRAMMAR_FILE, 'r')

    # Setup the grammar from the file
    map(lambda x: g.addProduction(x.strip()), gFile.readlines())
    print g

    srParser = ShiftReduceParser(g)

    user_input = parseUserInput(raw_input("\n Enter a string to parse: "))
    print 'Tokens are : ', ' , '.join(user_input)

    if srParser.parseInput(user_input):
        print '\n***ACCEPTED***'
    else:
        print '\n***REJECTED***'

    gFile.close()

if __name__ == '__main__':
    main()
    print
