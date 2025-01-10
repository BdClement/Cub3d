
# Cub3D 🟫

We developed a real-time display using 3D rendrering raycasting algotithm, including user communication.  
To do so, we used minilibX which is 42 graphical library.

## Features

- Handling window (opening, closing, display)
- Displaying different textures according to walls location
- Displaying different color for floor and ceiling
- Implemnting right and left arrow allow camera rotation
- W, A, S, D allow player to move on the map
- Wall collision
- ESC and window cross allow leaving window proprely

## 👨‍💻 Project 

Mettre des screens

First, we parsed the map given as argument according diffrent map configuration rules such as :
- Map must be surrounded by walls
- Map description must be last in the file and other elements can be in any order
- Element's format must be ID first and path_to_element
- Color must RGB format 
 
After checking errors on the argument file, we init the window as expected with various minilibX function such as mlx_init, mlx_get_screen_size, mlx_hook (to handle event logic), mlx_destroy_image mlx_loop_hook (to handle event logic in a loop) etc.

### Raycasting  

Key Data for Raycasting Logic:  
Each element on the map is represented by a 64x64 tile.

The player's starting position is at the center of a 10x10 tile on the map.  
Represented by coordinates: x, y on the map.

Turn Direction:  
-1: Turn left  
0: Don't turn  
1: Turn right  

Walk Direction:  
-1: Walk backward  
0: Don't move  
1: Move forward  

Rotate Direction:  
-1: Rotate left  
0: Don't rotate  
1: Rotate right  

Rotation Angle (in radians):  
0: Player faces the right side  
π: Player faces the left side  

Field of View (FOV):  
Represents a 60° human-like vision.



Raycasting involves tracing rays at small intervals across the player's field of view (FOV). These rays are projected from the player's position to identify visible walls and obstacles.  

Each ray calculates the distance to the first obstacle it encounters, which is then used to determine the depth of visible elements and adjust the height of the walls rendered on the screen, creating a 3D perspective.


To cast a ray, we identify two collision points, one for each axis:  

Calculate the first intersection on the axis using floor, based on the player's orientation.
Derive the coordinate of the other axis using the tangent of the ray's angle.
From the first point found, progress through the grid cells step by step along that axis until a collision is detected.

Compare the Euclidean distances of each collision point to the player using:
```plaintext
distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
``` 

## 🔧 Build program  
Download, clone repo and use Makefile
```bash
git clone https://github.com/BdClement/Cub3d.git
cd Cub3d
make
```
Run executable file ./cub3d with as argument a .cub file reprensenting the map (you can use map/test.cub for example)



## 💼 Contributors  
- [Bastien Mirlicourtois](https://github.com/bmirlico)


Check si Build program fonctionne 
Finish 
