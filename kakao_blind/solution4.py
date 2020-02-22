import re
def solution(words, queries):
    query_count = {query: 0 for query in queries}
    for key in queries:
        if key[0] == '?' and key[-1] == '?':
            compare_key = ''
        else:
            compare_key = key.replace('?', '\w')
        for word in words:
            if re.fullmatch(compare_key, word):
                query_count[key] += 1
                print(compare_key, word, True)
    return list(query_count.values())

words = ["frodo", "front", "frost", "frozen", "frame", "kakao"]
queries = ["fro??", "????o", "fr???", "fro???", "pro?"]
print(solution(words, queries))