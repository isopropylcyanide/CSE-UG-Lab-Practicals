
import sys
inputFile = "mixedInput"
MIN = -sys.maxint
MAX = sys.maxint

# A tuple in input file is a list of elements
# input Matrix is a list of tuples


class Element:
    """Defines what each Element is"""

    def __init__(self, elType, val):
        self._type = elType
        self.val = val
        if elType in ['O', 'N']:
            self.val = float(self.val)


class Tuple:
    """A tuple is a collection of elements"""

    def __init__(self):
        self.elements = []
        self.length = 0

    def addElement(self, element):
        self.elements.append(element)
        self.length += 1


class Record:
    """A record is a collection of tuples"""

    def __init__(self):
        self.tuples = []
        self.numAttributes = 0
        self.attribTypes = []

    def addTuple(self, tup):
        # For brevity, add equal type tuples
        self.tuples.append(tup)
        self.numAttributes = max(self.numAttributes, tup.length)
        if self.attribTypes == []:
            for el in tup.elements:
                self.attribTypes.append(el._type)

    def dissimilarityMatrix(self):
        """Prepare a dissimilarity matrix of the record
            Record contains of number of attributes p
            D(i, j) = E($(i, j, f) * d(i, j, f))/(E($(i, j, f))) for all f in p

            if attributes is nominal/binary:
                then d(i,j) = 1 if val(i) == val(j) else 0
            if attributes is ordinal:
                Convert them into numeric using a map and use numeric
            if attribute is numeric:
                d(i, j) = abs(val(i) - val(j)) / (maxValue - minValue)

            $(i,j) = 0 if attribute is missing or assymetric with xi = xj
                    else 1
        """
        # There are no extras required for nominal or binary
        # For ordinal, normalize them given their ranks
        # For numeric, find max value and minValue
        extras = {}

        for att, i in enumerate(self.attribTypes):
            # print att, i
            if i == 'O' or i == 'N':
                # Find min and max
                _min, _max = MAX, MIN
                for tup in self.tuples:
                    _min = min(_min, tup.elements[att].val)
                    _max = max(_max, tup.elements[att].val)
                extras[att] = {'MAX': _max, 'MIN': _min}

            if i == 'O':
                # Once found, normalize them
                for tup in self.tuples:
                    tup.elements[att].val = (
                        tup.elements[att].val - _min) / (_max - _min)
        # Now prepare the dissimilarity matrix

        n = len(self.tuples)
        M = [[0] * n for i in xrange(n)]
        for i in xrange(n):
            for j in xrange(i + 1):
                if i == j:
                    continue
                # else find dissim matrix
                numr, deno = 0, 0
                for att, f in enumerate(self.attribTypes):
                    deno += 1
                    if f == 'C':
                        # categorical
                        a = self.tuples[i].elements[att].val
                        b = self.tuples[j].elements[att].val
                        if a is None or b is None:
                            # Here missing attributes: $(i,j) = 0
                            deno -= 1
                        elif a == b:
                            numr += 1

                    if f in ['O', 'N']:
                        # ordinal or numeric
                        a = self.tuples[i].elements[att].val
                        b = self.tuples[j].elements[att].val
                        if a is None or b is None:
                            # Here missing attributes: $(i,j) = 0
                            deno -= 1
                        else:
                            _max = extras[att]['MAX']
                            _min = extras[att]['MIN']
                            numr += abs(a - b) / (_max - _min)
                M[i][j] = M[j][i] = numr / deno

        return M


def readInput():
    # Read input from file
    _record = Record()

    try:
        f = file("mixedInput")
        for i in f.readlines():
            _tuple = Tuple()
            line = i.strip().split(' ')

            for word in line:
                val, elType = word.split("->")
                if len(elType) > 1:
                    # This value is ordinal with a rank which becomes its val
                    elType, val = elType.split(',')
                    _tuple.addElement(Element(elType, val))
                else:
                    _tuple.addElement(Element(elType, val))
            _record.addTuple(_tuple)

    except IOError:
        print 'I/P File Error'
    finally:
        f.close()
    return _record

if __name__ == '__main__':
    # Read input from file and prepare a record
    _record = readInput()

    print "\n*********GIVEN INPUT MATRIX:*********"
    for i in _record.tuples:
        for j in i.elements:
            print j._type, j.val, '\t',
        print
    print '************************************\n'

    print "\n*********DISSIMILARITY MATRIX:*********"
    M = _record.dissimilarityMatrix()
    for i in M:
        for j in i:
            print '{:8.4f}'.format(j),
        print
    print '************************************\n'
