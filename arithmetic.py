class ArithTree:
    def __init__(self, op, left_oprd, right_oprd):
        self.op = op
        self.left_oprd = left_oprd
        self.right_oprd = right_oprd

    def __repr__(self):
        return self.op + ': ' + str(self.left_oprd) + ', ' + str(self.right_oprd)

    def operate(self):
        if not isinstance(self.left_oprd, int):
            self.left_oprd = self.left_oprd.operate()
        if not isinstance(self.right_oprd, int):
            self.right_oprd = self.right_oprd.operate()
        if self.op == '+':
            return self.left_oprd + self.right_oprd
        elif self.op == '-':
            return self.left_oprd - self.right_oprd
        elif self.op == '*':
            return self.left_oprd * self.right_oprd
        elif self.op == '/':
            return self.left_oprd / self.right_oprd


def find_op(str_):
    for i, c in enumerate(str_):
        if c == '+' or c == '-' or c == '*' or c == '/':
            return i, c
    return None

def make_tree(arith_str):
    ops = find_op(arith_str)
    if ops is None:
        return int(arith_str)
    return ArithTree(ops[1], int(arith_str[:ops[0]]), make_tree(arith_str[ops[0]+1:]))

arith_str = input()
ops = find_op(arith_str)
if ops is not None:
    arith_root = ArithTree(ops[1], int(arith_str[:ops[0]]), make_tree(arith_str[ops[0]+1:]))
print(arith_root)
print(arith_root.operate())
