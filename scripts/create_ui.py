import re
import os 
import sys

# Order of items
items = open("items.txt").readlines()

i = 0
j = 0
x = 0
y = 0
k = 0
widgets = ""

# Header and footer templates
template = open("ui.template").read()

# Each items widget in template form (they're all the same)
widget = open("widget.template").read()
dungeon_template = open("dungeon.template").read()
medallion_template = open("medallion.template").read()
widgets = ""
medallion_order = ['bombos','ether','quake']
dungeon_order = ['easternpalace','desertpalace','towerofhera','palaceofdarkness','swamppalace','skullwoods','thievestown','icepalace','miserymire','turtlerock']


for item in items:
    item = item.strip()
    if i % 7 == 0 and i != 0:
        x = 0
        y += 62 
    
    if "dungeon" in item:
        dungeon = dungeon_order[k]
        k += 1
        widgets += dungeon_template.format(dungeon=dungeon, item=item, x=x, y=y)
    elif "medallion" in item:
        medallion = medallion_order[j]
        j += 1
        widgets += medallion_template.format(medallion=medallion, item=item, x=x, y=y)
    else:
        widgets += widget.format(item=item, x=x, y=y)
    x += 62
    i += 1

print template.format(widgets)
