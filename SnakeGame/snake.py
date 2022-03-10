from turtle import Turtle

MOVE_DISTANCE = 20
UP = 90.0
DOWN = 270.0
LEFT = 180.0
RIGHT = 0.0


class Snake:
    def __init__(self):
        self.sections = []
        self.head = Turtle(visible=False)
        self.create_snake()

    def create_snake(self):
        x_pos = 0
        for i in self.sections:
            i.showturtle()
            i.goto(x_pos, 0)
            x_pos -= 21

    def spawn_section(self, number):
        for _ in range(number):
            new_section = Turtle("square", visible=False)
            new_section.penup()
            new_section.color("#34EBEB")
            self.sections.append(new_section)
        self.head = self.sections[0]

    def move(self):
        for section_num in range(len(self.sections) - 1, 0, -1):
            new_x = self.sections[section_num - 1].xcor()
            new_y = self.sections[section_num - 1].ycor()
            self.sections[section_num].goto(new_x, new_y)
            if not self.sections[section_num].isvisible():
                self.sections[section_num].showturtle()
        self.sections[0].forward(MOVE_DISTANCE)

    def up(self):
        if self.head.heading() != DOWN:
            self.sections[0].setheading(UP)

    def down(self):
        if self.head.heading() != UP:
            self.sections[0].setheading(DOWN)

    def left(self):
        if self.head.heading() != RIGHT:
            self.sections[0].setheading(LEFT)

    def right(self):
        if self.head.heading() != LEFT:
            self.sections[0].setheading(RIGHT)
