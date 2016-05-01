import re
input_file = "input_file"
# Read an input file line by line and analyze it lexically by separating
# it into constants, keywords and identifiers

# Obviously, first the whole string will be matched for the largest regex
# After that the rules of precedence follow
keywords = 'int|float|double|real|bool|do|while|if|then|else|return|main|switch\
        |char|byte|static|void|printf|print|true|false|NULL|extern'

regexList = [
    (re.compile("[\(\)]"), 'PARENTHESIS'),
    (re.compile('\.(\S)+'), 'ACCESSOR METHOD'),
    (re.compile('\"(.*?)\"'), 'STRING LITERAL'),
    (re.compile('\[.*\]'), 'SUBSCRIPT OPERATOR'),
    (re.compile("[-+]?[0-9]*\.?[0-9]+"), 'CONSTANT'),
    (re.compile("(==)|=|\-\-|\-|\+\+|\+|\*|\/|%|&|\^"), 'OPERATOR'),
    (re.compile(keywords), 'KEYWORD'),
    (re.compile("(_|[a-zA-Z])\w*"), 'IDENTIFIER')
]


class Token:
    """define what a token actually is"""

    def __init__(self, type, val, pos):
        self.type = type
        self.val = val
        self.pos = pos

    def __str__(self):
        return '\t%s => %s at %s' % (self.type, self.val, self.pos)


class UndefinedTokenError(Exception):
    """Throw error when an unidentifiable input is achieved"""

    def __init__(self, pos):
        self.pos = pos


class LexicalAnalyzer:
    """Create a lexical analyzer"""

    def __init__(self, regexList):
        """Initialize the constructor"""
        self.regexList = regexList
        self.non_whitespace = re.compile("\S")

    def input(self, line):
        """Feed a new line input to the lexical analyzer"""
        self.line = line
        self.pos = 0

    def tokenStream(self):
        """Generate tokens one by one"""
        if self.pos >= len(self.line):
            return None  # done analyzing the last symbol

        # else check if there exists any non whitespace character
        match = self.non_whitespace.search(self.line[self.pos:])
        if match:
            self.pos += match.start()
        else:
            return None

        # For all the pairs <regular expressions, type>, search for each
        # if match is found, then increment position uptill where the match is
        # found + 1 so that the scanning may continue later
        for regex, type_identifier in self.regexList:
            match = regex.match(self.line[self.pos:])

            if match:
                val = self.line[self.pos +
                                match.start(): self.pos + match.end()]
                curToken = Token(type_identifier, val, self.pos)
                self.pos += match.end()
                return curToken

        #  not a single regular expressions matched the string
        raise UndefinedTokenError(self.pos)

    def tokens(self):
        """Generate tokens one by one"""
        while True:
            currentToken = self.tokenStream()
            if not currentToken:
                break
            yield currentToken
