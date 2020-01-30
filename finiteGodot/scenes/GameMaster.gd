extends Node2D

var food_scene = preload("res://scenes/Food.tscn")

func random_pos(x1: float, y1: float, x2: float, y2: float):
	return Vector2(rand_range(x1, x2), rand_range(y1, y2))

func _ready():
	var foodi = randi() % 20 + 1
	for _i in range(foodi):
		var food_node = food_scene.instance()
		add_child(food_node)
		# Generate Vector2 coords between with 20 pixels margin
		# (20, 20) to (620, 460)
		var rand_pos = random_pos(20, 20, 620, 460)
		food_node.set_position(rand_pos)
