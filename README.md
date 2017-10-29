# wm_color_detector

This ROS node is used to recognise the dominant color of a picture.

## HOW TO

### List of colors availables

| **Color ID** | **Color Name** |
|:------------:|:--------------:|
| 0            | ´Black´        |
| 1            | ´Grey´         |
| 2            | ´White´        |
| 3            | ´Red´          |
| 4            | ´Yellow´       |
| 5            | ´Green´        |
| 6            | ´Cyan´         |
| 7            | ´Blue´         |
| 8            | ´Magenta´      |

## Dependencies

 - [OpenCV 3.x](http://opencv.org/releases.html) (Tested with OpenCV 3._ *(To Change)*)
 
 - [OpenCV 3.x dependencies](https://www.learnopencv.com/install-opencv3-on-ubuntu/)
 
 > Follow the tutorial linked above to install openCV the same way as me.
 
## Services

### `recognise_color`

 - **@param** `image` The input should be formated as an image message.

 - **@return** Return the color of the input. The ouput is a ´std::string message´ and contain the name of the color.

## Nodes

 - TODO
