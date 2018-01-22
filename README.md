# wm_color_detector

This ROS node is used to recognise the dominant color of a picture.

## HOW TO

### List of colors availables

| **Color ID** | **Color Name** |
|:------------:|:--------------:|
| 0            | Black          |
| 1            | Grey           |
| 2            | White          |
| 3            | Red            |
| 4            | Yellow         |
| 5            | Green          |
| 6            | Cyan           |
| 7            | Blue           |
| 8            | Magenta        |

## Dependencies

 - [OpenCV 3.x](http://opencv.org/releases.html) (Tested with OpenCV 3._ *(To Change)*)
 
 - [OpenCV 3.x dependencies](https://www.learnopencv.com/install-opencv3-on-ubuntu/)
 
 > Follow the tutorial linked above to install openCV the same way as me.

## Nodes

 - `wm_color_detector/ColorationAnalyser` : The node which advertise the service.

## Services

### `get_bounding_boxes_color`

 - **@req** :

 `sensor_msgs/Image image` : The image containing the bound boxes.
 
 `BoundingBox[] boundingBoxes` : The bounding boxes.

- **@res** :

`Coloration[] colors` : The color of each boxes.
 
## Messages

### `Coloration`

 - `string color`
 - `int32 colorID`

### `BoundingBox`

 - `int32 xmin`
 - `int32 ymin`
 - `int32 xmax`
 - `int32 xymax`
