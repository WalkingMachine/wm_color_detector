#!/usr/bin/env python

# Values for colors :
# 0    black
# 1    grey
# 2    white
# 3    red
# 4    yellow
# 5    green
# 6    cyan
# 7    blue
# 8    magenta

# Imports for ROS
# import rospy

from colorsys import rgb_to_hsv
from PIL import Image

# Declaration of constants
nbr_of_colors = 9

# Colors array
color_name = [""] * nbr_of_colors
color_name[0] = "black"
color_name[1] = "grey"
color_name[2] = "white"
color_name[3] = "red"
color_name[4] = "yellow"
color_name[5] = "green"
color_name[6] = "cyan"
color_name[7] = "blue"
color_name[8] = "magenta"


def _rgb_to_hsv(_color):
    r = _color[0]
    g = _color[1]
    b = _color[2]

    h, s, v = rgb_to_hsv(r / 255., g / 255., b / 255.)

    h *= 360.
    s *= 100.
    v *= 100.

    # Return the result
    return [h, s, v]


def get_color_id(_rgb):
    hue, saturation, value = _rgb_to_hsv(_rgb)

    # Assume it is black
    if value < 15:
        return 0

    # Assume it is monochrome
    if saturation < 20:

        # Assume it is white
        if value > 90:
            return 2

        # Assume it is grey
        else:
            return 1

    # Assume it is chromatic
    else:

        # For each colors
        if 0 <= hue <= 30:
            return 3
        if 30 < hue <= 90:
            return 4
        if 90 < hue <= 150:
            return 5
        if 150 < hue <= 210:
            return 6
        if 210 < hue <= 270:
            return 7
        if 270 < hue <= 330:
            return 8
        if 330 < hue <= 360:
            return 3


def get_mean_color(_pixels, _width, _height):
    color_list = [0] * nbr_of_colors
    for x_position in range(0, _width):
        for y_position in range(0, _height):
            _color_id = get_color_id(_pixels[x_position, y_position])
            color_list[_color_id] += 1

    nbr_of_pixels = _width * _height / 100
    for _color_id in range(0, nbr_of_colors):
        color_list[_color_id] = color_list[_color_id] / nbr_of_pixels

    return color_list


# Read image
im = Image.open('red.png')
pix = im.load()
width, height = im.size

color_list = get_mean_color(pix, width, height)

for color_id in range(0, nbr_of_colors):
    print( "Color " + color_name[color_id] + ":  \t" + str(color_list[color_id]) + "%")

