import sys

tab_label={}
compteurImmediat = 0


def operation(element):
    op = element[0][:3]  # on enleve le 's'
    if op == 'lsl' or op == 'lsr' or op == 'asr':
        if len(element) == 4:
            return shift_add_sub_mov(element)
        else:
            return data_processing(op)
    elif op == 'add' or op == 'sub':
        if len(element) == 4:
            return shift_add_sub_mov(element)
        else:
            return miscellaneous(op)
    elif op == 'mov':
        return shift_add_sub_mov(element)

    elif op == 'and' or op == 'eor' or op == 'adc' or op == 'sbc' or op == 'ror' or op == 'tst' or op == 'rsb' or op == 'cmp' or op == 'cmn' or op == 'orr' or op == 'mul' or op == 'bic' or op == 'mvn':
        return data_processing(op)

    elif op == 'str' or op == 'ldr':
        return load_store(op)

    elif op[0] == 'b':
        return branchement(op)


def shift_add_sub_mov(element):
    op = element[0][:3]
    if op == 'lsl':
        return '00000'
    elif op == 'lsr':
        return '00001'
    elif op == 'asr':
        return '00010'
    elif op == 'add':
        if element[3][0] != '#':
            return '0001100'
        else:
            return '0001110'
    elif op == 'sub':
        if element[3][0] != '#':
            return '0001101'
        else:
            return '0001111'
    if op == 'mov':
        return '00100'


def data_processing(op):
    if op == 'and':
        return '0100000000'
    elif op == 'eor':
        return '0100000001'
    elif op == 'lsl':
        return '0100000010'
    elif op == 'lsr':
        return '0100000011'
    elif op == 'asr':
        return '0100000100'
    elif op == 'adc':
        return '0100000101'
    elif op == 'sbc':
        return '0100000110'
    elif op == 'ror':
        return '0100000111'
    elif op == 'tst':
        return '0100001000'
    elif op == 'rsb':
        return '0100001001'
    elif op == 'cmp':
        return '0100001010'
    elif op == 'cmn':
        return '0100001011'
    elif op == 'orr':
        return '0100001100'
    elif op == 'mul':
        return '0100001101'
    elif op == 'bic':
        return '0100001110'
    elif op == 'mvn':
        return '0100001111'


def load_store(op):
    if op == 'str':
        return '10010'
    elif op == 'ldr':
        return '10011'


def miscellaneous(op):
    if op == 'add':
        return '101100000'
    elif op == 'sub':
        return '101100001'


def branchement(op):
    op = op[1:]
    if op == 'eq':
        return '11010000'
    elif op == 'ne':
        return '11010001'
    elif op == 'cs':
        return '11010010'
    elif op == 'cc':
        return '11010011'
    elif op == 'mi':
        return '11010100'
    elif op == 'pl':
        return '11010101'
    elif op == 'vs':
        return '11010110'
    elif op == 'vc':
        return '11010111'
    elif op == 'hi':
        return '11011000'
    elif op == 'ls':
        return '11011001'
    elif op == 'ge':
        return '11011010'
    elif op == 'lt':
        return '11011011'
    elif op == 'gt':
        return '11011100'
    elif op == 'le':
        return '11011101'
    elif op == 'al' or op == '':
        return '11011110'
    else:
        return '11011110'


def complement_deux(binaire):
    return binaire


def immediat(imm, lg):
    imm=imm[1:]

    return format(int(imm), '#0' + str(lg + 2) + 'b')[2:]



def loadstore(imm8):
    if len(imm8) == 4:
        return format(int(0), '#010b')[2:]
    i = 0
    while imm8[i] != '#':
        i += 1
    imm8 = imm8[(i + 1):-1]
    return format(int(imm8), '#010b')[2:]


def convertir_registre(r):
    if r == 'sp':
        return ''
    else:
        return format(int(r[1:]), '#05b')[2:]


def coller(element):
    s = ""
    for i in range(len(element)):
        s += element[i]
    return s


def convertir_hexa(binaire):
    string = ''
    for i in range(4):
        string += hex(int('0b' + str(binaire[4 * i:4 * (i + 1)]), 2))[2:]
    return string


def formater(line):
    element = []
    if line[3] == 's' and line[3:4] != 'sp':
        element.append(line[:4])
    else:
        element.append(line[:3])
    line = line.replace(' ', '')
    i = len(element[0])
    j = i
    boolean = False
    while i < len(line):
        if line[i] == ',':
            if not boolean:
                element.append(line[j:i])
                j = i + 1
        if line[i] == '[':
            boolean = True
        if line[i] == ']':
            boolean = False
        i += 1
    element.append(line[j:i])
    for i in range(len(element)):
        element[i] = element[i].strip()
    return element


def traduire(element, compteurDeLigne):
    global tmp
    element[0] = operation(element)
    if element[0][:4] == '1101':
        if (element[1][0]=='.'):
            element[1]=element[1][1:]
        if tab_label[element[1]] - compteurDeLigne < 0:
            if element[0][4:8] == '1110':
                element[1] = format(255 -(compteurDeLigne - tab_label[element[1]]), '#010b')[2:]
            else:
                element[1] = format(compteurDeLigne - tab_label[element[1]], '#010b')[2:]
        else:
            if element[0][4:8] == '1110':
                element[1] = format(255 - (tab_label[element[1]] - compteurDeLigne -1 ), '#010b')[2:]
            else:
                element[1] = format(tab_label[element[1]] - compteurDeLigne - 1, '#010b')[2:]
        return element
    if len(element) == 3:
        if element[1][0] == 'r' or element[1] == 'sp':
            tmp = convertir_registre(element[1])
        if element[2][0] == 'r' or element[2] == 'sp':
            element[1], element[2] = convertir_registre(element[2]), tmp
        else:
            element[1] = tmp
        if element[2][0] == '#':
            if element[0] == '101100000' or element[0] == '101100001':
                element[2] = immediat(element[2], 7)
            else:
                element[2] = immediat(element[2], 8)
        elif element[2][:3] == '[sp':
            element[2] = loadstore(element[2])
    elif len(element) == 4:
        if element[-1][0] == '#':
            element[1], element[2], element[3] = immediat(element[3], 3), convertir_registre(element[2]), convertir_registre(element[1])
        else:
            if element[0]=='0100001101':
                element[1], element[2], element[3] = convertir_registre(element[2]), convertir_registre(element[1]), ''
            else:
                element[1], element[2], element[3] = convertir_registre(element[3]), convertir_registre(element[2]), convertir_registre(element[1])
    return element


def bin_to_hexa(element, final):
    final.append(convertir_hexa(coller(element)))


def ecrire(final):
    logisim = open("logisim.txt", "w")
    logisim.write("v2.0 raw\n")
    for e in final:
        logisim.write(e + " ")
    logisim.close()


def fisrt_read():
    g = sys.stdin
    compteurDeLigne = 0
    boolean=False
    line = g.readline()
    line = line.lower()
    line = line.strip()
    while line[:3] not in ['lsl','lsr','asr','add','sub','mov','and','eor','adc','sbc','ror','tst','rsb','cmp','cmn','orr','mul','bic','mvn','str','ldr']:
        line = g.readline()
        line = line.lower()
        line = line.strip()
    while True:
        line = g.readline()
        if not line:
            break
        line = line.lower()
        line = line.strip()
        if line == '.lfunc_end0:':
            boolean=True
        if line and line[0]=='.' and not boolean:
            i=0
            while line[i]!=':':
                i+=1
            tab_label[line[1:i]] = compteurDeLigne
            compteurDeLigne-=1
        compteurDeLigne+=1
    g.seek(0) # remonter le fichier a la premiere ligne

def parseur():
    f = sys.stdin
    fisrt_read()
    final = []
    compteurDeLigne = 0
    while True:
        line = f.readline()
        if not line:
            break
        line = line.lower()
        line = line.strip()
        if line == '' or line[0] == '.' or ':' in line or line[0] == '@':  # c'est un label ou un commentaire
            continue
        else:
            compteurDeLigne += 1
            element = formater(line)
            element = traduire(element, compteurDeLigne)
            bin_to_hexa(element, final)
    f.close()
    ecrire(final)


parseur()
