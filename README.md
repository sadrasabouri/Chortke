# Chortke
Chortke is a scientific calculator giving you the opportunity to facilitate your calculations and studies.

This is a project done by three undergraduate students at Sharif University of Technology.
## Run
Simply :
```
make
```
## How to wotk with :sunglasses:
You can surf in program so easily.
For the very first step you should choose your favorite mode in bellow-like menu.
```
Welcome to "Chortke"! :D
Choose a character to surf into different parts of Chortke:
e : for entering numerical equation
g : for graphing function(y = f(x))
p : for plotting equation(0 = f(x,y))
s : for solving equation for x
c : for see/change configure your plot
i : for evaluating integral of y = f(x) from a to b
q : for quiting from Chortke :(
```
* you can escape from each part with simply entering "quit".
* feel free from using ( , ) , + , - , ! , ^ , * , / , exp , ln , sin , cos , tan , abs and so on in all parts of program.
* Note using parentheses while using functions(ex: 2*(sin(pi)) instead of 2*sin(pi)). 

**Numerical equation mode :**
This mode allows you to see the numerical answer of your numerical equation. 
Fallow the samples bellow and you'll catch everything about this mode.
```
= 2 + 2
``` 
Result is : 4.000000
```
= (5 + 3) / 5.6
```
Result is : 1.428571
```
= (5*(9.2/2-(5+6)))/(-6)
```
Result is : 5.333333
```
= sin(pi/2)
```
Result is : 1.000000
```
= sin(ln(sin(pi/4)))
```
Result is : -0.339677
```
= (sin(pi/4))^2 + (cos(pi/4))^2
```
Result is : 1.000000

**Graphing functions :**
Enter a function equals to y (like the example bellow) and you'll see it's plot in Domain of -r < x < r (where r is defined as a configuration in 'c' mode)
```
y = ln(x^2)
```
also it's .bmp plot picture will save here in Chortke directory till you decide to plot newer function.

**Graphing none-functions :**
This time you should enter a function of x and y equals to 0 and Da Daaa :smile: here you are, testing example bellow will help you find how it's work.
```
0 = sin(x*y)
``` 

**Graphing equation for x :**
enter your x desired equation and makes it in a shape that is f(x) = 0 then you'll have it's Real answer(s) in determined x domain in mode 'c'.
```
0 = x^2 - 1
```
Result is : 
```
X1 = -1.000
X2 =  1.000
``` 
```
0 = x^2 + 1
```
Result is :
```
No answer for x in the domain with accurecy of 0.010000.
```

**Integrating from function :**
First you enter your function of x then you can enter your first and end points of integration domain then you will have the amount of function's integration.
```
y = x
a = 0
b = 1
```
Result is :
```
S(x)dx = 0.5000
```
Or in a more complex way :
```
y = x^2 + (sin(x))
a = (2^2 - 4*2)*(-2)
b = pi ^ e
```
Result is :
```
S(x^2 + (sin(x)))dx = 3607.0842
```

**Configuration menu :**
This menu whill show your plotting configuration and ask you if you want to change any of them.
```
---------------------Configuration---------------------
x Domain : -10.00 < x < 10.00
axis color: 0xa000a0
screen color:0xffffff
plot color: 0x00ff00
-------------------------------------------------------
```
* Note that colors should be entered in HexaDecimal #RGB for example #ff0000 is fully red while #00ff00 is fully Green. 
## Developers

* **Sadra Sabouri** [Sadra Sabouri](https://github.com/sadrasabouri)
* **Haniyeh Tajer** [Haniyeh Tajer](https://github.com/haniyehtajer)
* **Amirali Ekhteraee** [Amirali Ekhteraee](https://github.com/AmiraliEkhteraee)

