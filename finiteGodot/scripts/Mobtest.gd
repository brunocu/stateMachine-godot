extends Node2D

var blue_node = preload("res://scenes/skins/Blue.tscn")
var green_node = preload("res://scenes/skins/Green.tscn")
var red_node = preload("res://scenes/skins/Red.tscn")
var enemy_var = [blue_node, green_node, red_node]

var touchy = 0

export var speed = 5
var direction: Vector2

func _ready():
	speed *= 10
	# choosing a random skin
	var skin = enemy_var[ randi() % 3 ]
	var child = skin.instance()
	add_child(child)
	
	# connecting signals
	child.connect("area_entered", self, "_on_Enemy_area_entered")
	
	# movement setup
	direction = Vector2(1, 1)
	direction = direction.normalized()
	
	# animation
	child.get_child(2).play("walk")

func _on_Enemy_area_entered(_area: Area2D):
	# touching something
	touchy += 1
	print("Touchy %d" % touchy)

func _process(delta):
	var screen_size = get_viewport_rect().size
	# wander
	if position.x <= 0:
		direction = direction.rotated(PI / 2)
	if position.x >= screen_size.x:
		direction = direction.rotated(PI / 2)
	if position.y <= 0:
		direction = direction.rotated(PI / 2)
	if position.y >= screen_size.y:
		direction = direction.rotated(PI / 2)
	position += direction * speed * delta
