extends Area2D

var foods = ["apple", "coke", "pizza", "ice", "bread"]

func _ready():
	var idx = randi() % 5
	$Sprite.texture = load("res://textures/%s.tres" % foods[idx])
