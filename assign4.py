def decToBin(n):
        if n > 1:
                decToBin(n//2)
        print(n % 2, end = '')

def statMode():
	num1 = int(input("Please input any number"))
	num2 = int(input("please input any number"))
	if stat == "+":
		print(num1 + num2)
	elif stat == "-":
		print(num1 - num2)
	elif stat == "*":
		print(num1 * num2)
	elif stat == "/":
		print(num1 / num2)
	elif stat == "**":
		print(num1 ** num2)

def mainPro():
	mode = str(input("Type Bmode for Binary Calculator or Smode for Sientific Calculatr: "))	
	if mode == "Bmode":
		global random
		random = None
		while random is None:
			dec = input("Please input any positive number: ")
			try:
				random = int(dec)
			except ValueError:
				print("Input not valid")
			i = 0
			while i < 1:
        			if dec < 0:
                			dec = int(input("Please try again: "))
        			elif dec >= 0:
                			i+=1
               				decToBin(dec)
               				print()
	elif mode == "Smode":
		global stat
		stat = str(input("Please choose +,-,*,/,or **. Chose by typing the symbol: "))
		i = 0
		while i < 1:
			if stat == "+":
				i += 1
				statMode()
			elif stat == "-":
				i += 1
				statMode()
			elif stat == "*":
				i += 1
				statMode()
			elif stat == "/":
				i += 1
				statMode()
			elif stat == "**":
				i += 1
				statMode()
			else:
				stat = str(input("Please try again: "))	
	else:
		mainPro()
while True:
	mainPro()

