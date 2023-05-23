#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"
#include <time.h>
#include <GL/gl.h>

#include <stdbool.h>

/**
 * Camera, as a moving point with direction
 */
typedef struct Camera
{
    vec3 position;
    vec3 rotation;
    vec3 speed;
    bool is_preview_visible;
    bool is_manual_visible;
    clock_t last_print_time; // Add this line
    GLuint user_manual;
    
} Camera;

/**
 * Initialize the camera to the start position.
 */
void init_camera(Camera* camera);

/**
 * Update the position of the camera.
 */
void update_camera(Camera* camera, double time);

/**
 * Apply the camera settings to the view transformation.
 */
void set_view(const Camera* camera);

/**
 * Set the horizontal and vertical rotation of the view angle.
 */
void rotate_camera(Camera* camera, double horizontal, double vertical);

/**
 * Set the speed of forward and backward motion.
 */
void set_camera_speed(Camera* camera, double speed);

void show_manual_preview(Camera* camera);

void switch_manual(Camera* camera);

/**
 * Set the speed of left and right side steps.
 */
void set_camera_side_speed(Camera* camera, double speed);

#endif /* CAMERA_H */
