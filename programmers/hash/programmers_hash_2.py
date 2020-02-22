'''
p = ['119', '97674223', '1195524421']

def first_solution(phone_book):
	phone_book.sort()
	for i in range(len(phone_book)):
		if phone_book[(i+1) % len(phone_book)].startswith(phone_book[i]):
			return False
		else:
			break
	return True

'''
def solution(phone_book):
	phone_book.sort()
	for p1, p2 in zip(phone_book, phone_book[1:]):
		if p2.startswith(p1):
			return False
	return True
