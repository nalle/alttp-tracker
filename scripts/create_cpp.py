import re
import os 
import sys

image_template = '''   <widget class="QLabel" name="{}Image">
    <property name="geometry">
     <rect>
      <x>{}</x>
      <y>{}</y>
      <width>62</width>
      <height>62</height>
     </rect>
    </property>
    <property name="autoFillBackground">
     <bool>false</bool>
    </property>
    <property name="styleSheet">
     <string notr="true"/>
    </property>
    <property name="text">
     <string/>
    </property>
    <property name="pixmap">
     <pixmap>images/{}.png</pixmap>
    </property>
   </widget>
'''

overlay_template = '''   <widget class="QLabel" name="{}Overlay">
    <property name="geometry">
     <rect>
      <x>{}</x>
      <y>{}</y>
      <width>62</width>
      <height>62</height>
     </rect>
    </property>
    <property name="autoFillBackground">
     <bool>true</bool>
    </property>
    <property name="styleSheet">
     <string notr="true">background-color: rgba(0,0,0,60%);</string>
    </property>
    <property name="text">
     <string/>
    </property>
   </widget>

'''

button_template = '''   <widget class="QPushButton" name="{}OverlayPush">
    <property name="geometry">
     <rect>
      <x>{}</x>
      <y>{}</y>
      <width>62</width>
      <height>62</height>
     </rect>
    </property>
    <property name="autoFillBackground">
     <bool>true</bool>
    </property>
    <property name="flat">
     <bool>true</bool>
    </property>
    <property name="styleSheet">
     <string notr="true">background-color: rgba(0,0,0,60%);</string>
    </property>
    <property name="text">
     <string/>
    </property>
   </widget>
'''

items = open("items.txt").readlines()

i = 0
x = 0
y = 0
widgets = ""
template = open("ui.template").read()

for item in items:
    item = item.strip()
    x += 62
    if i % 7 == 0:
        x = 0
        y += 62 
    
    widgets += image_template.format(item, x, y, "{}1".format(item))
    widgets += overlay_template.format(item, x, y)
    widgets += button_template.format(item, x, y)
    i += 1

print template.format(widgets)
