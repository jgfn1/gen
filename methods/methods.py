from sympy import sympify

def euler(y, t, h, n, f):
	for i in range(n):
		k1 = f(t, y) #step 6 start
		y = y + h*k1
		t = t + h #step 6 ends
	print('t: ' + t, 'y: ' + y)

def euler_inverso(y, t, h, n, f):

def euler_aprimorado(y, t, h, n, f):
	for i in range(n):
		k1 = f(t, y)
		k2 = f(t + h, y + h*k1)
		y = y + (h/2.0)*(k1 + k2)
		t = t + h
	print('t: ' + t, 'y: ' + y)

def runge_kutta(y, t, h, n, f):
	for i in range(n):
		k1 = f(t, y)
		k2 = f(t + 0.5*h, y + 0.5*h*k1)
		k3 = f(t + 0.5*h, y + 0.5*h*k2)
		k4 = f(t + h, y + h*k3)
		y = y + (h/6.0)*(k1 + 2*k2 + 2*k3 + k4)
		t = t + h
	print('t: ' + t, 'y: ' + y)

def adam_bashforth(y, t, h, n, f, ord):
	if(ord == 1):

	elif(ord == 2):

	elif(ord == 3):

	elif(ord == 4):

	elif(ord == 5):

	elif(ord == 6):

	elif(ord == 7):

	elif(ord == 8):

def adam_bashforth_by_euler():
	if(ord == 1):

	elif(ord == 2):

	elif(ord == 3):

	elif(ord == 4):

	elif(ord == 5):

	elif(ord == 6):

	elif(ord == 7):

	elif(ord == 8):
	
def adam_bashforth_by_euler_inverso():
	if(ord == 1):

	elif(ord == 2):

	elif(ord == 3):

	elif(ord == 4):

	elif(ord == 5):

	elif(ord == 6):

	elif(ord == 7):

	elif(ord == 8):

def adam_bashforth_by_euler_aprimorado():
	if(ord == 1):

	elif(ord == 2):

	elif(ord == 3):

	elif(ord == 4):

	elif(ord == 5):

	elif(ord == 6):

	elif(ord == 7):

	elif(ord == 8):

def adam_bashforth_by_runge_kutta():
	if(ord == 1):

	elif(ord == 2):

	elif(ord == 3):

	elif(ord == 4):

	elif(ord == 5):

	elif(ord == 6):

	elif(ord == 7):

	elif(ord == 8):

def adam_multon():
	if(ord == 1):

	elif(ord == 2):

	elif(ord == 3):

	elif(ord == 4):

	elif(ord == 5):

	elif(ord == 6):

	elif(ord == 7):

	elif(ord == 8):

def adam_multon_by_euler():
	if(ord == 1):

	elif(ord == 2):

	elif(ord == 3):

	elif(ord == 4):

	elif(ord == 5):

	elif(ord == 6):

	elif(ord == 7):

	elif(ord == 8):

def adam_multon_by_euler_inverso():
	if(ord == 1):

	elif(ord == 2):

	elif(ord == 3):

	elif(ord == 4):

	elif(ord == 5):

	elif(ord == 6):

	elif(ord == 7):

	elif(ord == 8):

def adam_multon_by_euler_aprimorado():
	if(ord == 1):

	elif(ord == 2):

	elif(ord == 3):

	elif(ord == 4):

	elif(ord == 5):

	elif(ord == 6):

	elif(ord == 7):

	elif(ord == 8):
