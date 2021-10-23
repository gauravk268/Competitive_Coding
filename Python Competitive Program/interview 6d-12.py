s1=input('enter string 1: ')
s2=input('enter string 2: ')
s=''
for i in range(min(len(s1),len(s2))):
	if s1[i]==s2[i]:
		s+=s1[i]
	else:
		break

print(s)
