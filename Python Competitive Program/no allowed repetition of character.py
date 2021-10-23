# Function to print words which can be created using given set of characters 



def charCount(word): 
	dict = {} 
	for i in word: 
		dict[i] = dict.get(i, 0) + 1
	return dict


def possible_words(lwords, charSet): 
	for word in lwords: 
		flag = 1
		chars = charCount(word) 
		for key in chars: 
			if key not in charSet: 
				flag = 0
			else: 
				if charSet.count(key) != chars[key]: 
					flag = 0
		if flag == 1: 
			print(word) 

if __name__ == "__main__": 
	input = ['goo', 'bat', 'me', 'eat', 'goal', 'boy', 'run'] 
	charSet = ['e', 'o', 'b', 'a', 'm', 'g', 'l'] 
	possible_words(input, charSet) 
