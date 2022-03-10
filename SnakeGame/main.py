from turtle import Screen
from snake import Snake
from food import Food
from scoreboard import Scoreboard
import time

screen = Screen()
screen.setup(width=600, height=600)
screen.bgcolor("#1c1c1c")
screen.title("Snake Game")
screen.tracer(0)
game_running = True


snake = Snake()
food = Food()
scoreboard = Scoreboard()
screen.listen()
screen.onkey(snake.up, "Up")
screen.onkey(snake.down, "Down")
screen.onkey(snake.left, "Left")
screen.onkey(snake.right, "Right")

snake.spawn_section(3)
snake.create_snake()

while game_running:
    time.sleep(0.1)
    screen.update()
    snake.move()

    if snake.head.distance(food) < 15:
        food.respawn()
        snake.spawn_section(1)
        scoreboard.increase_score()

    if snake.head.xcor() > 280 or snake.head.xcor() < -280 \
            or snake.head.ycor() > 280 or snake.head.ycor() < -280:
        game_running = False
        scoreboard.game_over()

    for section in snake.sections[1:]:
        if snake.head.distance(section) < 10:
            game_running = False
            scoreboard.game_over()


screen.exitonclick()
