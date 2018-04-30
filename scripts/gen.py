import os
import re


template = '''
    Item *{item} = new Item();
    setupObject({item}, this, {x}, {y}, {{ {images} }});
    connect({item}->button, &QPushButton::released, [=]{{
        toggle({item});
    }});'''

x = 0
y = 0 
nonecounter = 0
items = open("items.txt").readlines()
    
for dir, other, files in os.walk("images/"):
    pass

for item in items:
    item = item.strip()
    if x > 6:
        y += 1
        x = 0
    tmp = []
    if item.strip() == "none":
        item = "none"+str(nonecounter)
        nonecounter += 1
    for file in files:
        if item.strip() in file:
            tmp.append(file)
    images = '"'+'","'.join(tmp)+'"'
    print template.format(item=item, images=images, x=((x*62)), y=((y*62)))
    x += 1
