from __future__ import print_function
import re

# --------------Source Assembly Files---------------
sourceCode = "sourceFile.as"
mcOpTableFile = "mcOpTable"
passOneOutput = "pass I"
passTwoOutput = "pass II"
# --------------Source Assembly Files---------------


# --------------instruction Classes---------------
imperativeInstructions = ['MOVEM', 'MOVER',
                          'ADD', 'SUB', 'MUL', 'BC', 'LTORG']

ASS_DIRECTIVES = ['START', 'END', 'ORIGIN',  'EQU', 'LTORG',
                  'PURGE', 'USING', 'SEGMENT', 'END', 'ASSUME',
                  'PUBLIC', 'EXTERN', 'BALR']

REGISTER_LIST = ['AREG', 'BREG', 'CREG', 'DREG']

declarativeInstructions = ['DS', 'DC']
# --------------instruction Classes---------------

# location Counter defaults to 0
LC = 0
patternLiteral = re.compile("='(\w)'")

# PASS 1 uses OPTAB, SYMTAB, LITTAB, POOLTAB

OPTAB = {}
# --------------Pass I O/P---------------
SYMTAB = {}
LITTAB = {}
# --------------Pass I O/P---------------


def startswithAssDirective(line):
    """Determines whether the line starts not with a label"""

    for i in ASS_DIRECTIVES + imperativeInstructions + declarativeInstructions:
        if line[0] == i:
            return True
    return False


def getAddressFromSymTab(reqdSymbol):
    """Gets the required address of the symbol from SYMTABLE"""
    try:
        return SYMTAB[reqdSymbol]
    except KeyError:
        return None


def updateSymTab(reqdSymbol, reqdAdd):
    """Updates the address of the symbol with the reqdAdd"""
    SYMTAB[reqdSymbol] = reqdAdd


def imperativeStatement(line):
    """Returns true if the line is an imperative statement"""
    for i in imperativeInstructions:
        if i in line:
            return True
    return False


def declarativeStatement(line):
    """Returns true if line is a declarative statement"""
    for i in declarativeInstructions:
        if i in line:
            return True
    return False


def getSizeFromMOT(line):
    """Given an opcode and its type, return its machine size"""
    for i in line:
        if i in OPTAB:
            return OPTAB[i][1]


def getCodeFromMOT(line):
    """Given an opcode and its type, return its machine code"""
    for i in line:
        if i in OPTAB:
            return OPTAB[i][0]


def isLiteral(s):
    """Returns true if a string contains a literal"""
    p = patternLiteral.search(s)
    if p is None:
        return (False, None)
    return (True, p.groups()[0])


def literalImmediate(line):
    """Returns true if  a line contains a literal string"""
    literalList = []
    for i in line:
        res = isLiteral(i)
        if res[0]:
            literalList.append(res[1])
    return literalList


def passOne(fileHandle):
    """Generates SYMTAB LITTAB POOLTAB given a source file"""
    global LC
    LTORG_SET = False

    # Open source file for reading
    f = file(sourceCode)
    literalPending = []

    for i in f.readlines():
        line = i.split()

        if 'END' in line:
            # process remaining literals in the literal pool
            for i in literalPending:
                LITTAB[i] = LC
                literalPending.remove(i)
                LC += 1
            break

        LC += 1
        literalPending.extend(literalImmediate(line))

        # if symbol is present in lable field
        if not startswithAssDirective(line) and len(line) != 1:
            # An only literal is not a label
            SYMTAB[line[0]] = LC

        for lit in literalPending:
            # if there's a literal in the line
            # Check entry in littable whether it has been mapped to a loc
            # if no entry, create a new entry as None.
            if lit not in LITTAB:
                LITTAB[lit] = None

        if LTORG_SET:
            # Then revisit the mapping to the current location and increase LC
            if not isLiteral(line[0]):
                LTORG_SET = False
                break
            for i in literalPending:
                LITTAB[i] = LC
                literalPending.remove(i)
                LC += 1

        if 'LTORG' in line:
            LTORG_SET = True

        # if a start statement
        elif 'START' in line:
            # Update LC to denote main program
            LC = int(line[1])
            SYMTAB[line[0]] = LC

        elif 'EQU' in line:
            # place the address of the third value as that of the first
            currAdd = getAddressFromSymTab(line[2])
            updateSymTab(line[0], currAdd)

        elif imperativeStatement(line) or declarativeStatement(line):
            size = getSizeFromMOT(line)
            LC += size

    # Close source file
    f.close()

    # ------------OUTPUT OF PASS-1 ----------------
    fileHandle.write('\nSYMBOL TABLE: ')
    for i in SYMTAB.iteritems():
        fileHandle.writelines(('\n' + str(i[0]) + '\t' + str(i[1])))

    fileHandle.write('\n\nLITERAL TABLE ')
    for i in LITTAB.iteritems():
        fileHandle.writelines(('\n' + str(i[0]) + '\t' + str(i[1])))
    # -----------OUTPUT OF PASS 2 -------------------


def passTwo(fileHandle):
    """Generates final machine code using symbol table, literal table"""
    global LC

    # Open source file for reading
    f = file(sourceCode)

    for i in f.readlines():
        line = i.split()
        if 'END' in line:
            break

        if 'START' in line:
            LC = SYMTAB['START']

        elif imperativeStatement(line) or declarativeStatement(line):
            # Process Operands carefully
            operands = []
            for possibleOp in line:
                if possibleOp in REGISTER_LIST:
                    operands.append(REGISTER_LIST.index(possibleOp) + 1)
                elif possibleOp in SYMTAB:
                    operands.append(SYMTAB[possibleOp])
                elif possibleOp in LITTAB:
                    operands.append(LITTAB[possibleOp])

            opcode = getCodeFromMOT(line)
            length = getSizeFromMOT(line)
            fileHandle.write(('\n' + str(LC) + '\t'))
            for i in operands:
                fileHandle.write(str(i) + '\t')
            fileHandle.write(('\t' + str(opcode) + '\t' + str(length)))
            LC += length

    f.close()


def main():
    # Read input source Files, mcOPtable and pseudoOptable
    fOp = file(mcOpTableFile)
    for i in fOp.readlines():
        l = i.split()
        OPTAB[l[0]] = (l[1], int(l[2]))
    fOp.close()

    pA = file(passOneOutput, 'w')
    pA.writelines('\n-----------OUTPUT OF PASS I------------\n')
    passOne(pA)
    pA.writelines('\n\n-----------OUTPUT OF PASS I-----------\n')
    # Read symbol table, literal table and machine opcode table and produce
    # final code
    pB = file(passTwoOutput, 'w')
    pB.write('\n-----------OUTPUT OF PASS II-----------\n')
    passTwo(pB)
    pB.write('\n\n-----------OUTPUT OF PASS II-----------\n')

if __name__ == '__main__':
    main()
