import turtle
t = turtle.Turtle()
t.shape("turtle")
t.speed(0)
count = 0
alpha = 2
angle = 25

t.penup()
t.lt(90)
t.backward(200)

def tree(length, level):
    global count
    if level > 0 :
        t.pendown()
        t.forward(length)
        count += 1
        t.penup()

        t.rt(angle)
        tree(length/alpha, level - 1)
        t.lt(angle*2)
        tree(length/alpha, level - 1)
        t.rt(angle)
        t.backward(length)
        t.rt(angle)
        tree(length/alpha, level - 1)
        t.lt(angle)

tree(200,4)
print(count)
turtle.exitonclick()

