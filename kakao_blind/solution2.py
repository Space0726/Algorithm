def get_balanced(string):
    cnt = 0
    for i, char in enumerate(string):
        if char == '(':
            cnt += 1
        else:
            cnt -= 1
        if not cnt:
            return string[:i+1], string[i+1:]

def is_collect(string):
    cnt = 0
    for _, char in enumerate(string):
        if char == '(':
            cnt += 1
        else:
            cnt -= 1
        if cnt < 0:
            return False
    if not cnt:
        return True
    return False

def main(w):
    if not w:
        return ''
    u, v = get_balanced(w)
    if is_collect(u):
        u += main(v)
        return u
    else:
        new_str = '(' + main(v) +')'
        new_str += ''.join([')' if char == '(' else '(' for char in u[1:-1]])
        return new_str

a = '()))((()'
print(main(a))
