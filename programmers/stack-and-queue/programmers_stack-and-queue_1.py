def solution(arrangement):
    count = 0
    result = 0
    lv = ''
    listArr = list(arrangement)
    while listArr:
        v = listArr.pop()
        if v == ')':
            count += 1
        else:
            if v != lv:
                count -= 1
                result += count
            else:
                result += 1
                count -= 1
        lv = v
    return result
