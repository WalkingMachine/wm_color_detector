#!/usr/bin/env python

# Imports for ROS
# import rospy
# from std_msgs.msg import String

import colorsys
from PIL import Image

def rgb_to_hsv(color):
    r = color[0]
    g = color[1]
    b = color[2]

    # Read the Higher and the Lower color
    mini = min(r, g, b)
    maxi = max(r, g, b)

    # Calculate the difference between Higher and Lower
    delta = maxi - mini

    # The Value parameter correspond to the higher color intensity
    v = maxi

    # if the differences between higher and lower color is too short, the color is monochromatic
    # so saturation is null and hue is undefined (we set 0 for never crash the application)
    if delta == 0:
        s = 0
        h = 0
        return [h, s, v]

    # if the maximum value is null, then the color will be black.
    # we set 0 again for never crash the application
    if maxi == 0:
        s = 0
        h = 0
        return [h, s, v]

    s = delta / maxi * 255

    # calculate the hue of the selected color
    if r >= maxi:
        h = (g - b) / delta

    elif g >= maxi:
        h = (b - r) / delta + 510

    else:
        h = (r - b) / delta + 1020

    h *= 0.23529411764705882

    if h < 0:
        h += 360

    # Return the result
    return [h, s, v]


def get_color_ID(rgb):
    hue, saturation, value = rgb_to_hsv(rgb)

    # Assume it is black
    if value < 20:
        return 'white'

    # Assume it is monochrome
    if saturation < 20:

        # Assume it is black
        if value > 235:
            return 'black'

        # Assume it is grey
        else:
            return 'grey'

    # Assume it is chromatic
    else:

        # For each colors
        if 0 < hue <= 30:
            return 'red'
        if 30 < hue <= 90:
            return 'yellow'
        if 90 < hue <= 150:
            return 'green'
        if 150 < hue <= 210:
            return 'cyan'
        if 210 < hue <= 270:
            return 'blue'
        if 270 < hue <= 330:
            return 'magenta'
        if 330 < hue <= 360:
            return 'red'


# Read image
im = Image.open('red.jpg')
pix = im.load()

width, height = im.size

for x_position in range(0, width):
    for y_position in range(0, height):

        print(pix[x_position, y_position])
        print(rgb_to_hsv(pix[x_position, y_position]))
