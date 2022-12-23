import nltk
from string import punctuation
from termcolor import colored

conties_murav = {
    'Дачный участок 1': 3,
    'Дачный участок 2': 1,
    'Дачный участок 3': 2,
    'Дачный участок 4': 6,
    'Дачный участок 5': 4,
    'Дачный участок 9': 3,
    'Дачный участок 8': 2,
    'Дачный участок 11': 3,
    'Дачный участок 12': 5,
    'Дачный участок 13': 6,
    'Дачный участок 15': 1,
    'Дачный участок 17': 2,
    'Дачный участок 19': 3,
    'Дачный участок 20': 3,
    'Дачный участок 21': 4,
    'Дачный участок 25': 5,
    'Дачный участок 34': 1
}


def expert_opinion(feature):
    if feature == 'пара норок':
        return 1
    elif feature == 'земляное решето':
        return 2
    elif feature == 'куча':
        return 3
    elif feature == 'пара кучек':
        return 4
    elif feature == 'большая куча':
        return 5
    elif feature == 'гора ужаса':
        return 6
    return None

def mass_to_feature(mass):
    ret = []
    prov = []
    for i in mass:
        if i not in prov:
            prov.append(i)
    for i in prov:
        if i == 1:
            ret.append('пара норок')
        if i == 2:
            ret.append('земляное решето')
        if i == 3:
            ret.append('куча')
        if i == 4:
            ret.append('пара кучек')
        if i == 5:
            ret.append('большая куча')
        if i == 6:
            ret.append('гора ужаса') 
    return ret

def perror(*msg):
    if not isinstance(msg, str):
        msg = " ".join([str(m) for m in msg if not isinstance(m, str) or m])
    print(colored(msg, 'red'))

def take_murav(feature):
    slov = 'муравейник'
    for i in range(len(slov)):
        if slov[i] != feature[i]:
            return False
    return True

def take_murav_from_tokens(tokens):
    for i in tokens:
        if take_murav(i):
            return True
    return False


def find_terms(tokens):
    ret = []
    flag = 0
    for token in tokens:
        if flag == 1:
            if token == 'норок':
                ret.append(1)
            elif token == 'кучек':
                ret.append(4)
            else:
                flag = 0
        elif flag == 2:
            if token == 'решето':
                ret.append(2)
            else:
                flag = 0
        elif flag == 3:
            if token == 'куча':
                ret.append(5)
            else:
                flag = 0
        elif flag == 4:
            if token == 'ужаса':
                ret.append(6)
            else:
                flag = 0

        if token == 'пара':
            flag = 1
        elif token == 'земляное':
            flag = 2
        elif token == 'куча':
            ret.append(3)
            flag = 0
        elif token == 'большая':
            flag = 3
        elif token == 'гора':
            flag = 4
        else:
            flag == 0
    return ret

text = "гора ужаса куча муравейников"
text = input()

tokens = nltk.word_tokenize(text.lower(), language="russian")
tokens = [token for token in tokens if token not in punctuation]

# В вопросе спрашивают про муравейники?
print('Разбитые токены:', tokens)

if not take_murav_from_tokens(tokens):
    perror("В вопросе нет слова 'муравейник'")
    exit(1)

mass = find_terms(tokens)
terms = mass_to_feature(mass)

print('Найденные термы: ')
for i in range(len(terms) - 1):
    print('>   ' + terms[i] + '(%d), '%mass[i])
print('>   ' + terms[len(terms) - 1] + '(%d)'%mass[len(terms) - 1])

print('Подпадающие под условия участки:')
for uch, mur in conties_murav.items():
    if mur in mass:
        print(uch + ' с ' + mass_to_feature([mur])[0] + '(%d)'%mur)