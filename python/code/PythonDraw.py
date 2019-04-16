'''
PythonDraw.py
to draw a moving python picture with turtle package
'''
import turtle
turtle.setup(650, 350, 200, 200) # width = 650, height = 350, lefttop point = (200, 200)
turtle.penup()
turtle.fd(-250) # fd ~ forward
turtle.pendown()
turtle.pensize(25)
turtle.pencolor("blue")
turtle.seth(-40) # seth ~ setheading(angle)
for i in range(4):
    turtle.circle(40, 80) # r = 40(center at left side), angle = 80 
    turtle.circle(-40, 80)# r = 40(center at right side), angle = 80 
turtle.circle(40, 80 / 2)
turtle.fd(40)
turtle.circle(16, 180)
turtle.fd(40 * 2 / 3)
turtle.done()
