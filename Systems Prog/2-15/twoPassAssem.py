sourceCode = "sourceFile.as"
mcOpTableFile = "mcOPtable"
pseudoOptable = "pseudoOptable"

LC = 0  # location Counter defaults to 0
# PASS 1 uses OPTAB, SYMTAB, LITTAB, POOLTAB
OPTAB = [
    ['MOVER', '04', 1],
    ['MOVEM', '14', 2],
    ['ADD', '3E', 2],
    ['SUB', '4D', 2],
    ['MUL', '1F', 2],
    ['DS', 'R#7', 1],
    ['DC', 'R#9', 1],
    ['START', 'R#3', 1]
]

SYMTAB = []
LITTAB = []
POOLTAB = []

# Initialise pointers
LITTAB_PTR = POOLTAB_PTR = 0
POOLTAB.append([1, 0])


def startswithAssDirective(line):
    ASS_DIRECTIVES = ['START', 'END', 'ORIGIN', 'LOOP', 'EQU', 'LTORG',
                      'PURGE', 'USING', 'SEGMENT', 'END', 'ASSUME',
                      'PUBLIC', 'EXTERN', 'BALR']
    imperativeInstructions = ['MOVEM', 'MOVER',
                              'ADD', 'SUB', 'MUL', 'BC', 'LTORG']
    for i in ASS_DIRECTIVES + imperativeInstructions:
        if line[0] == i and not isLiteral(line[0]):
            return True
    return False


def getAddressFromSymTab(reqdSymbol, SYMTAB):
    """Gets the required address of the symbol from SYMTABLE"""
    for symbol in SYMTAB:
        if symbol[0] == reqdSymbol:
            return symbol[1]


def updateSymTab(reqdSymbol, reqdAdd, SYMTAB):
    """Updates the address of the symbol with the reqdAdd"""
    for symbol in SYMTAB:
        if symbol[0] == reqdSymbol:
            symbol[1] = reqdAdd
            return


def imperativeStatement(line):
    """Returns true if the line is an imperative statement"""
    imperativeInstructions = ['MOVEM', 'MOVER',
                              'ADD', 'SUB', 'MUL', 'BC', 'LTORG']
    for i in imperativeInstructions:
        if i in line:
            return True
    return False


def declarativeStatement(line):
    """Returns true if line is a declarative statement"""
    if 'DS' in line or 'DC' in line:
        return True
    return False


def getSizeFromMOTUtil(opcode):
    """Given an opcode, return its machine size helper"""
    for i in OPTAB:
        if i[0] == opcode:
            return i[2]


def getSizeFromMOT(line, typeofLine):
    """Given an opcode and its type, return its machine size"""
    if typeofLine == 'declarative':
        for i in line:
            if i == 'DS':
                return getSizeFromMOTUtil('DS')
            elif i == 'DC':
                return getSizeFromMOTUtil('DC')
    elif typeofLine == 'imperative':
        imperativeInstructions = ['MOVEM', 'MOVER',
                                  'ADD', 'SUB', 'MUL', 'BC', 'LTORG']
        for opcode in imperativeInstructions:
            if opcode in line:
                return getSizeFromMOTUtil(opcode)


def isLiteral(s):
    import re
    p = re.compile("='\w'")
    if p.match(s) is None:
        return False
    return True


def passOne():
    """Generates SYMTAB LITTAB POOLTAB"""
    global LC

    # Open source file for reading
    f = file(sourceCode)
    for i in f.readlines():
        line = i.split()
        # while next statement is not an end statement
        if 'END' not in line:
            print line
            # if symbol is present in lable field
            if not startswithAssDirective(line):
                SYMTAB.append([line[0], LC, -1])

            # if a start statement
            if 'START' in line:
                # Update LC
                LC = int(line[1])

            elif 'EQU' in line:
                currAdd = getAddressFromSymTab(line[2], SYMTAB)
                updateSymTab(line[0], currAdd, SYMTAB)

            elif declarativeStatement(line):
                # invoke the routine whose id is in mnemonicInfo of OPTAB
                # get the size of instruction from MOT as well as the routine
                size = getSizeFromMOT(line, "declarative")

                # if symbol is present in label, update symtab entry
                if len(line) == 3:
                    SYMTAB.append([line[0], LC, size])
                # Generate intermediate code for declaration statement

            elif imperativeStatement(line):
                # code = machine opcode from MOT's mnemonicInfo field
                # LC = LC + size from mnemonicInfoField of Opcode TAble
                size = getSizeFromMOT(line, "imperative")
                # if operand is a literal, then follow steps

    # Close source file
    f.close()

    print '\nSYMBOL TABLE: '
    for i in SYMTAB:
        print i

    print '\nLITERAL TABLE: '
    for i in LITTAB:
        print i

    print '\nPOOL TABLE: '
    for i in POOLTAB:
        print i

    print '\nOP TABLE: '
    for i in OPTAB:
        print i

    print LITTAB_PTR, POOLTAB_PTR


def main():
    # Read input source Files, mcOPtable and pseudoOptable
    passOne()

if __name__ == '__main__':
    main()
